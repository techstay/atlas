import 'package:flutter/material.dart';
import 'package:flutterdemo/shared_component.dart';

class RefreshIndicatorApp extends StatefulWidget {
  const RefreshIndicatorApp({super.key});
  static const name = 'Refresh Indicator';

  @override
  State<RefreshIndicatorApp> createState() => _RefreshIndicatorAppState();
}

class _RefreshIndicatorAppState extends State<RefreshIndicatorApp> {
  var _listSize = 5;
  final _refreshIndicatorKey = GlobalKey<RefreshIndicatorState>();
  final _listKey = GlobalKey<AnimatedListState>();
  final _colors = [...Colors.accents];

  @override
  Widget build(BuildContext context) {
    return MyScaffoldApp(
      navName: RefreshIndicatorApp.name,
      view: RefreshIndicator(
        key: _refreshIndicatorKey,
        child: AnimatedList(
          key: _listKey,
          initialItemCount: _listSize,
          itemBuilder: (context, index, animation) => SizeTransition(
            sizeFactor: animation,
            axis: Axis.vertical,
            key: ValueKey(index),
            child: Container(
              color: _colors[index % _colors.length],
              child: ListTile(
                title: Text('Item ${index + 1}'),
              ),
            ),
          ),
        ),
        onRefresh: () async {
          await Future.delayed(const Duration(seconds: 1));
          _listSize++;
          _listKey.currentState!.insertItem(_listSize - 1);
        },
      ),
      floatingActionButton: FloatingActionButton.extended(
          onPressed: () {
            _refreshIndicatorKey.currentState!.show();
          },
          tooltip: 'Refresh',
          label: const Icon(Icons.refresh)),
    );
  }
}
