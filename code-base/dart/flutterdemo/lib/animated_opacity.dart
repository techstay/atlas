import 'dart:async';

import 'package:flutter/material.dart';
import 'package:flutterdemo/shared_component.dart';

class AnimatedOpacityApp extends StatelessWidget {
  static const name = 'Animated Opacity';

  const AnimatedOpacityApp({super.key});

  @override
  Widget build(BuildContext context) {
    return const MyScaffoldApp(
      navName: name,
      view: AnimatedOpacityView(),
    );
  }
}

class AnimatedOpacityView extends StatefulWidget {
  const AnimatedOpacityView({super.key});

  @override
  State<StatefulWidget> createState() => _AnimatedOpacityViewState();
}

class _AnimatedOpacityViewState extends State<AnimatedOpacityView> {
  var _visible = true;
  late Timer _timer;
  void _changeVisibility() {
    setState(() {
      _visible = !_visible;
    });
  }

  @override
  void initState() {
    super.initState();
    _timer = Timer.periodic(const Duration(seconds: 1), (timer) {
      _changeVisibility();
    });
  }

  @override
  void dispose() {
    super.dispose();
    _timer.cancel();
  }

  @override
  Widget build(BuildContext context) {
    return Center(
      child: AnimatedOpacity(
        duration: const Duration(milliseconds: 700),
        opacity: _visible ? 1.0 : 0.0,
        child: Container(
          width: 200,
          height: 200,
          color: Colors.purple,
        ),
      ),
    );
  }
}
