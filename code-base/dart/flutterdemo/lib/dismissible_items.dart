import 'dart:developer';

import 'package:flutter/material.dart';
import 'package:flutterdemo/shared_component.dart';

class DismissibleItemsApp extends StatelessWidget {
  static const name = 'Dismissible Items';

  const DismissibleItemsApp({super.key});

  @override
  Widget build(BuildContext context) {
    return const MyScaffoldApp(
      navName: DismissibleItemsApp.name,
      view: DismissibleItemsView(),
    );
  }
}

class DismissibleItemsView extends StatefulWidget {
  const DismissibleItemsView({super.key});

  @override
  State<StatefulWidget> createState() => _DismissibleItemsViewState();
}

class _DismissibleItemsViewState extends State<DismissibleItemsView> {
  final _initialItemsLength = 20;
  late final _items =
      List<String>.generate(_initialItemsLength, (i) => 'Item ${i + 1}');
  late final _key = GlobalKey<AnimatedListState>();
  @override
  Widget build(BuildContext context) {
    return AnimatedList(
      key: _key,
      initialItemCount: _items.length,
      itemBuilder: (context, index, animation) {
        final item = _items[index];
        Color backgroundColor =
            index % 2 == 0 ? Colors.blue[50]! : Colors.white;
        return Dismissible(
          key: Key(item),
          onDismissed: (direction) {
            setState(() {
              _items.removeAt(index);
              _key.currentState!
                  .removeItem(index, (context, animation) => Container());
            });

            // show the snackbar with action to undo the dismissal
            ScaffoldMessenger.of(context).showSnackBar(
              SnackBar(
                content: Text(
                  '$item dismissed',
                ),
                duration: const Duration(milliseconds: 3000),
                action: SnackBarAction(
                  label: 'Undo',
                  onPressed: () {
                    setState(() {
                      _items.insert(index, item);
                      _key.currentState!.insertItem(index);
                    });
                    log('undo removing $item');
                  },
                ),
                behavior: SnackBarBehavior.floating,
              ),
            );

            log('$item dismissed');
          },
          background: Container(
            color: Colors.red,
            alignment: Alignment.centerRight,
            padding: const EdgeInsets.only(right: 10),
            child: const Icon(Icons.delete_rounded),
          ),
          child: SizeTransition(
            sizeFactor: animation,
            child: Container(
              color: backgroundColor,
              child: ListTile(
                title: Text(item),
              ),
            ),
          ),
        );
      },
    );
  }
}
