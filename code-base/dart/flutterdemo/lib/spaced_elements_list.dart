import 'dart:developer';

import 'package:flutter/material.dart';
import 'package:flutterdemo/shared_component.dart';

class SpacedListApp extends StatefulWidget {
  static const name = 'Spaced Elements List View';

  const SpacedListApp({super.key});

  @override
  State<SpacedListApp> createState() => _SpacedListAppState();
}

class _SpacedListAppState extends State<SpacedListApp> {
  bool _toggleLayout = true;

  @override
  Widget build(BuildContext context) {
    return MyScaffoldApp(
      navName: SpacedListApp.name,
      view: _toggleLayout ? const Layout1() : const Layout2(),
      floatingActionButton: FloatingActionButton(
        tooltip: 'Toggle Layout',
        shape: _toggleLayout ? null : const CircleBorder(),
        onPressed: () {
          setState(() {
            _toggleLayout = !_toggleLayout;
            log('Toggle Layout: $_toggleLayout');
          });
        },
        child: const Icon(Icons.swap_vert),
      ),
    );
  }
}

class Layout1 extends StatelessWidget {
  const Layout1({super.key});

  @override
  Widget build(BuildContext context) {
    return LayoutBuilder(builder: (context, constraints) {
      // counts of items
      const itemsCount = 4;
      List<Widget> items = List.generate(
        itemsCount,
        (index) => ItemWidget(text: 'Item ${index + 1}'),
      );

      return SingleChildScrollView(
        child: ConstrainedBox(
          constraints: BoxConstraints(minHeight: constraints.maxHeight),
          child: Column(
            mainAxisAlignment: MainAxisAlignment.spaceBetween,
            crossAxisAlignment: CrossAxisAlignment.stretch,
            children: items,
          ),
        ),
      );
    });
  }
}

class Layout2 extends StatelessWidget {
  const Layout2({super.key});

  @override
  Widget build(BuildContext context) {
    return LayoutBuilder(builder: (context, constraints) {
      return SingleChildScrollView(
        child: ConstrainedBox(
          constraints: BoxConstraints(minHeight: constraints.maxHeight),
          child: const IntrinsicHeight(
            child: Column(
              children: [
                ItemWidget(text: 'Item 1'),
                Spacer(),
                ItemWidget(text: 'Item 2'),
                Expanded(
                  child: ItemWidget(text: 'Item 3'),
                ),
              ],
            ),
          ),
        ),
      );
    });
  }
}

class ItemWidget extends StatelessWidget {
  const ItemWidget({
    super.key,
    required this.text,
  });

  final String text;

  @override
  Widget build(BuildContext context) {
    return Card(
      child: SizedBox(
        height: 100,
        child: Center(child: Text(text)),
      ),
    );
  }
}
