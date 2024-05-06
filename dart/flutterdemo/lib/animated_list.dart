// ignore_for_file: unused_field, prefer_final_fields

import 'package:flutter/material.dart';
import 'package:flutterdemo/shared_component.dart';

class AnimatedListApp extends StatelessWidget {
  static const name = 'Animated List';

  const AnimatedListApp({super.key});

  @override
  Widget build(BuildContext context) {
    return const MyApp(
      scaffold: AnimatedListView(),
    );
  }
}

class AnimatedListView extends StatefulWidget {
  const AnimatedListView({super.key});

  @override
  State<AnimatedListView> createState() => _AnimatedListViewState();
}

class _AnimatedListViewState extends State<AnimatedListView> {
  late var _counter = _list.length;
  final _list = List.generate(10, (index) => 'item $index');
  final _key = GlobalKey<AnimatedListState>();
  @override
  Widget build(BuildContext context) {
    return MyScaffold(
      navName: AnimatedListApp.name,
      view: AnimatedList(
        key: _key,
        initialItemCount: _list.length,
        itemBuilder: (context, index, animation) {
          return SizeTransition(
            sizeFactor: animation,
            child: AnimatedContainer(
              duration: const Duration(milliseconds: 500),
              color: index % 2 == 0 ? Colors.white : Colors.blue[50],
              child: ListTile(
                title: Text(_list[index]),
                trailing: IconButton(
                  icon: const Icon(Icons.delete),
                  onPressed: () => _onListItemRemoved(context, index),
                ),
              ),
            ),
          );
        },
      ),
      floatingActionButton: _buildAddButton(),
    );
  }

  Widget _buildAddButton() {
    return FloatingActionButton(
      onPressed: () {
        var item = 'item ${_counter++}';
        _list.add(item);
        _key.currentState!.insertItem(_list.length - 1);
        debugPrint('$item added');
      },
      child: const Icon(Icons.add),
    );
  }

  // In the state of the AnimatedList, we can set the animation of the removed item
  void _onListItemRemoved(BuildContext context, int index) {
    var deletedItem = _list[index];
    _list.removeAt(index);
    _key.currentState!.removeItem(
      index,
      (context, animation) {
        // Here we apply some transitions
        return SizeTransition(
          sizeFactor: animation,
          child: ListTile(
            title: Text(deletedItem),
            trailing: const Icon(Icons.delete),
          ),
        );
      },
      duration: const Duration(milliseconds: 200),
    );
    debugPrint('$deletedItem deleted');
  }
}
