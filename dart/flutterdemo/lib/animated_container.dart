import 'dart:math';

import 'package:flutter/material.dart';
import 'package:flutterdemo/shared_component.dart';

class AnimatedContainerApp extends StatelessWidget {
  static const name = 'Animated Container';

  const AnimatedContainerApp({super.key});

  @override
  Widget build(BuildContext context) {
    return const MyScaffoldApp(
      navName: name,
      view: AnimatedContainerView(),
    );
  }
}

class AnimatedContainerView extends StatefulWidget {
  const AnimatedContainerView({super.key});

  @override
  State<StatefulWidget> createState() => _AnimatedContainerViewState();
}

class _AnimatedContainerViewState extends State<AnimatedContainerView> {
  var _color = Colors.pink;
  var _colorIndex = 0;
  double _width = 100;
  double _height = 100;
  double _roundedCornerRadius = 20;
  final _random = Random(42);

  @override
  void initState() {
    super.initState();
  }

  @override
  void dispose() {
    super.dispose();
  }

  void _onChange() {
    setState(() {
      _color = Colors.primaries[_colorIndex++ % Colors.primaries.length];
      _width = (_random.nextInt(500) + 10).toDouble();
      _height = (_random.nextInt(500) + 10).toDouble();
      _roundedCornerRadius = (_random.nextInt(100) + 10).toDouble();
    });
  }

  @override
  Widget build(BuildContext context) {
    return Center(
      child: GestureDetector(
        onTap: _onChange,
        child: Tooltip(
          message: 'Click to change the container',
          child: AnimatedContainer(
            curve: Curves.easeInOut,
            duration: const Duration(milliseconds: 700),
            width: _width,
            height: _height,
            decoration: BoxDecoration(
              color: _color,
              borderRadius: BorderRadius.circular(_roundedCornerRadius),
            ),
          ),
        ),
      ),
    );
  }
}
