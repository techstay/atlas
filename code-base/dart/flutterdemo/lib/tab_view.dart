import 'package:flutter/material.dart';
import 'package:flutterdemo/shared_component.dart';

class TabApp extends StatelessWidget {
  static const name = 'Tab View';

  const TabApp({super.key});

  @override
  Widget build(BuildContext context) {
    return const MyApp(scaffold: TabScaffold());
  }
}

class TabScaffold extends StatelessWidget {
  const TabScaffold({super.key});

  @override
  Widget build(BuildContext context) {
    const tabs = [
      Tab(
        text: 'Examples',
        icon: Icon(
          Icons.insert_chart,
          color: Colors.pink,
        ),
      ),
      Tab(
        text: 'Layouts',
        icon: Icon(
          Icons.note,
          color: Colors.blue,
        ),
      ),
      Tab(
        text: 'Widgets',
        icon: Icon(
          Icons.view_agenda,
          color: Colors.green,
        ),
      ),
      Tab(
        text: 'Advanced',
        icon: Icon(
          Icons.school,
          color: Colors.orange,
        ),
      )
    ];
    return DefaultTabController(
      length: tabs.length,
      child: Scaffold(
        drawer: myDrawer,
        appBar: AppBar(
          title: const Text(TabApp.name),
          bottom: const TabBar(
            tabs: tabs,
          ),
        ),
        body: const TabBarView(children: [
          Icon(
            Icons.insert_chart,
            color: Colors.pink,
            size: 300,
          ),
          Icon(
            Icons.note,
            color: Colors.blue,
            size: 300,
          ),
          Icon(
            Icons.view_agenda,
            color: Colors.green,
            size: 300,
          ),
          Icon(
            Icons.school,
            color: Colors.orange,
            size: 300,
          ),
        ]),
      ),
    );
  }
}
