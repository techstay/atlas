import 'dart:developer';

import 'package:flutter/material.dart';
import 'package:flutterdemo/shared_component.dart';

class MyListApp extends StatelessWidget {
  static const name = 'List View';

  const MyListApp({super.key});

  @override
  Widget build(BuildContext context) {
    return const MyScaffoldApp(
      navName: name,
      view: MyListView(),
    );
  }
}

class MyListView extends StatelessWidget {
  const MyListView({super.key});

  @override
  Widget build(BuildContext context) {
    var items = [
      const ListTile(
        leading: Icon(Icons.map),
        title: Text('Map'),
      ),
      const ListTile(
        leading: Icon(Icons.photo_album),
        title: Text('Album'),
      ),
      const ListTile(
        leading: Icon(Icons.phone),
        title: Text('Phone'),
      ),
      const ListTile(
        leading: Icon(Icons.abc),
        title: Text('Abc'),
      )
    ];
    items.addAll(
      List.generate(
        50,
        (index) => ListTile(
          title: Text('Item ${index + 1}'),
          onTap: () {
            var snackBar = SnackBar(
              content: Text('Item ${index + 1}'),
              behavior: SnackBarBehavior.floating,
              duration: const Duration(milliseconds: 500),
            );
            ScaffoldMessenger.of(context).showSnackBar(snackBar);
            log('Item ${index + 1} tapped at ${DateTime.now()}');
          },
        ),
      ),
    );
    return ListView(
      children: items,
    );
  }
}
