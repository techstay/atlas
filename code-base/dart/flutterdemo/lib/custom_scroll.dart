import 'package:flutter/material.dart';
import 'package:flutterdemo/shared_component.dart';

class CustomScrollApp extends StatelessWidget {
  const CustomScrollApp({super.key});
  static const name = 'Custom Scroll';

  @override
  Widget build(BuildContext context) {
    return const MyScaffoldApp(navName: name, view: CustomScrollViewExample());
  }
}

class CustomScrollViewExample extends StatefulWidget {
  const CustomScrollViewExample({super.key});

  @override
  State<CustomScrollViewExample> createState() =>
      _CustomScrollViewExampleState();
}

class _CustomScrollViewExampleState extends State<CustomScrollViewExample> {
  @override
  Widget build(BuildContext context) {
    // building a sliver extent list
    var list = SliverPrototypeExtentList(
      delegate: SliverChildBuilderDelegate(
        (context, index) => ListTile(
          title: Text('Item ${index + 1}'),
        ),
        childCount: 10,
      ),
      prototypeItem: const ListTile(
        title: Text('Item 1'),
      ),
    );
    // then add them to the custom scroll view
    return CustomScrollView(
      slivers: [
        list,
        list,
        list,
      ],
    );
  }
}
