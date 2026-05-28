import 'package:flutterdemo/shared_component.dart';
import 'package:flutter/material.dart';

class MyGridApp extends StatelessWidget {
  static const name = 'Grid View';

  const MyGridApp({super.key});

  @override
  Widget build(BuildContext context) {
    return const MyScaffoldApp(
      navName: name,
      view: MyGridView(),
    );
  }
}

class MyGridView extends StatefulWidget {
  const MyGridView({super.key});

  @override
  State<MyGridView> createState() => _MyGridViewState();
}

class _MyGridViewState extends State<MyGridView> {
  late final List<Color> _gridItems = [];

  @override
  void initState() {
    super.initState();
    _generateGridItems();
  }

  void _generateGridItems() {
    Future.delayed(
      const Duration(milliseconds: 200),
      () {
        setState(() {
          var gridCount = _gridItems.length;
          _gridItems.addAll(
            List.generate(
              8,
              (index) => Color.fromRGBO(
                255 - gridCount - index,
                255 - gridCount - index,
                255 - gridCount - index,
                1,
              ),
            ),
          );
        });

        debugPrint(_gridItems.length.toString());
      },
    );
  }

  @override
  Widget build(BuildContext context) {
    return GridView.builder(
      gridDelegate: const SliverGridDelegateWithFixedCrossAxisCount(
        crossAxisCount: 8,
        childAspectRatio: 1.0,
        crossAxisSpacing: 0,
        mainAxisSpacing: 0,
      ),
      itemCount: _gridItems.length,
      itemBuilder: (context, index) {
        if (index == _gridItems.length - 1 && index < 255) {
          _generateGridItems();
        }
        return Container(
          padding: EdgeInsets.zero,
          decoration: BoxDecoration(
            color: _gridItems[index],
            border: Border.all(color: _gridItems[index], width: 0),
          ),
        );
      },
    );
  }
}
