import 'package:flutter/material.dart';
import 'package:flutterdemo/shared_component.dart';

class AnimatedSwitcherApp extends StatelessWidget {
  const AnimatedSwitcherApp({super.key});
  static const name = 'Animated Switcher';

  @override
  Widget build(BuildContext context) {
    return const MyScaffoldApp(navName: name, view: AnimatedSwitcherView());
  }
}

class AnimatedSwitcherView extends StatefulWidget {
  const AnimatedSwitcherView({super.key});

  @override
  State<AnimatedSwitcherView> createState() => _AnimatedSwitcherViewState();
}

class _AnimatedSwitcherViewState extends State<AnimatedSwitcherView> {
  var value = 0;

  @override
  Widget build(BuildContext context) {
    return Center(
      child: Wrap(
        crossAxisAlignment: WrapCrossAlignment.center,
        direction: Axis.vertical,
        spacing: 20,
        runSpacing: 20,
        children: [
          AnimatedSwitcher(
            duration: const Duration(milliseconds: 200),
            child: Text(
              '$value',
              key: ValueKey(value),
              style: Theme.of(context).textTheme.displayLarge,
            ),
            transitionBuilder: (child, animation) => FadeTransition(
              opacity: animation,
              child: MySlideTransition(
                  position:
                      Tween(begin: const Offset(0, 1), end: const Offset(0, 0))
                          .animate(animation),
                  child: child),
            ),
          ),
          ElevatedButton(
            onPressed: () {
              setState(() {
                value++;
              });
            },
            child: const Text('Switch'),
          ),
        ],
      ),
    );
  }
}

class MySlideTransition extends AnimatedWidget {
  const MySlideTransition({
    super.key,
    required Animation<Offset> position,
    this.transformHitTests = true,
    required this.child,
  }) : super(listenable: position);

  final bool transformHitTests;

  final Widget child;

  @override
  Widget build(BuildContext context) {
    final position = listenable as Animation<Offset>;
    Offset offset = position.value;
    if (position.status == AnimationStatus.reverse) {
      offset = Offset(offset.dx, -offset.dy);
    }
    return FractionalTranslation(
      translation: offset,
      transformHitTests: transformHitTests,
      child: child,
    );
  }
}
