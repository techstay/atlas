import 'package:flutter/material.dart';
import 'package:flutterdemo/shared_component.dart';

class SliverAppBarApp extends StatelessWidget {
  const SliverAppBarApp({super.key});
  static const name = 'Sliver App Bar';

  @override
  Widget build(BuildContext context) {
    return MyApp(
        scaffold: Scaffold(
      drawer: myDrawer,
      body: CustomScrollView(
        slivers: [
          SliverAppBar(
            expandedHeight: 160,
            floating: true,
            shadowColor: Colors.black,
            pinned: true,
            flexibleSpace: FlexibleSpaceBar(
              title: const Text('Sliver App Bar'),
              background: Image.asset(
                'images/landscape.jpg',
                fit: BoxFit.cover,
              ),
            ),
            leading: Builder(
              builder: (context) => IconButton(
                icon: const Icon(Icons.menu),
                onPressed: () {
                  Scaffold.of(context).openDrawer();
                },
              ),
            ),
          ),
          SliverList(
            delegate: SliverChildBuilderDelegate(
              (context, index) {
                return ListTile(
                  title: Text('Item $index'),
                );
              },
              childCount: 20,
            ),
          )
        ],
      ),
    ));
  }
}
