import 'package:flutter/material.dart';
import 'package:flutterdemo/shared_component.dart';

class ListWheelScrollViewApp extends StatelessWidget {
  const ListWheelScrollViewApp({super.key});
  static const String name = 'List Wheel Scroll View';

  @override
  Widget build(BuildContext context) {
    return const MyScaffoldApp(
      navName: name,
      view: ListWheelScrollViewDemo(),
    );
  }
}

class ListWheelScrollViewDemo extends StatelessWidget {
  const ListWheelScrollViewDemo({super.key});

  @override
  Widget build(BuildContext context) {
    return Center(
      child: ListWheelScrollView(
        itemExtent: 48,
        children: List.generate(
          30,
          (index) => ListTile(
            title: Text('Item ${index + 1}'),
            onTap: () {},
            leading: const Icon(Icons.star),
            trailing: const Icon(Icons.menu),
          ),
        ),
      ),
    );
  }
}
