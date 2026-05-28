import 'package:flutter/material.dart';
import 'package:flutterdemo/shared_component.dart';

class NavigationBarApp extends StatefulWidget {
  const NavigationBarApp({super.key});
  static const name = 'Navigation Bar';

  @override
  State<NavigationBarApp> createState() => _NavigationBarAppState();
}

class _NavigationBarAppState extends State<NavigationBarApp> {
  final _body = [
    const Icon(
      Icons.home,
      size: 200,
    ),
    const Icon(
      Icons.search,
      size: 200,
    ),
    const Icon(
      Icons.person,
      size: 200,
    ),
  ];

  int selectedIndex = 0;
  @override
  Widget build(BuildContext context) {
    return MyScaffoldApp(
      navName: NavigationBarApp.name,
      view: Center(
        child: _body[selectedIndex],
      ),
      navigationBar: BottomNavigationBar(
        currentIndex: selectedIndex,
        onTap: (value) {
          setState(() {
            selectedIndex = value;
          });
        },
        items: const [
          BottomNavigationBarItem(icon: Icon(Icons.home), label: 'Home'),
          BottomNavigationBarItem(icon: Icon(Icons.search), label: 'Search'),
          BottomNavigationBarItem(icon: Icon(Icons.person), label: 'Person'),
        ],
      ),
    );
  }
}
