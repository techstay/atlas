import 'package:flutter/material.dart';
import 'package:flutterdemo/shared_component.dart';

class AnimationControllerApp extends StatelessWidget {
  static const name = 'Animation Controller';

  const AnimationControllerApp({super.key});

  @override
  Widget build(BuildContext context) {
    return const MyScaffoldApp(
      navName: name,
      view: AnimationControllerView(),
    );
  }
}

class AnimationControllerView extends StatefulWidget {
  const AnimationControllerView({super.key});

  @override
  State<StatefulWidget> createState() => _AnimationControllerViewState();
}

class _AnimationControllerViewState extends State<AnimationControllerView>
    with SingleTickerProviderStateMixin {
  late AnimationController _controller;
  late Animation<double> _animation;

  @override
  void initState() {
    super.initState();
    _controller = AnimationController(
      duration: const Duration(seconds: 1),
      vsync: this,
    );
    _animation = Tween<double>(begin: 100, end: 300).animate(_controller)
      ..addListener(() {
        setState(() {});
      })
      ..addStatusListener((status) {
        if (status == AnimationStatus.completed) {
          _controller.reverse();
        } else if (status == AnimationStatus.dismissed) {
          _controller.forward();
        }
      });
    _controller.forward();
  }

  @override
  void dispose() {
    _controller.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Center(
      child: Container(
        margin: const EdgeInsets.all(10),
        width: _animation.value,
        height: _animation.value,
        child: const FlutterLogo(),
      ),
    );
  }
}
