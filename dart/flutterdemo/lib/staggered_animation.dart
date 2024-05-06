import 'package:flutter/material.dart';
import 'package:flutterdemo/shared_component.dart';

class StaggeredAnimationApp extends StatelessWidget {
  const StaggeredAnimationApp({super.key});

  static const name = 'Staggered Animation';

  @override
  Widget build(BuildContext context) {
    return const MyApp(
      scaffold: StaggeredAnimationView(),
    );
  }
}

class StaggeredAnimationView extends StatefulWidget {
  const StaggeredAnimationView({super.key});

  @override
  State<StaggeredAnimationView> createState() => _StaggeredAnimationViewState();
}

class _StaggeredAnimationViewState extends State<StaggeredAnimationView>
    with SingleTickerProviderStateMixin {
  late final _controller = AnimationController(
    vsync: this,
    duration: const Duration(milliseconds: 2000),
  );

  @override
  void dispose() {
    super.dispose();
    _controller.dispose();
  }

  Animation<T> _buildStaggeredAnimation<T>(
      T begin,
      T end,
      AnimationController parent,
      double intervalBegin,
      double intervalEnd,
      Curve curve) {
    return Tween<T>(begin: begin, end: end).animate(
      CurvedAnimation(
        parent: parent,
        curve: Interval(intervalBegin, intervalEnd, curve: curve),
      ),
    );
  }

  late final _heightAnimation = _buildStaggeredAnimation<double>(
      100, 300, _controller, 0.4, 0.6, Curves.easeInOut);
  late final _widthAnimation = _buildStaggeredAnimation<double>(
      100, 300, _controller, 0.4, 0.6, Curves.easeInOut);
  late final _colorAnimation =
      ColorTween(begin: Colors.red, end: Colors.blue).animate(
    CurvedAnimation(
      parent: _controller,
      curve: const Interval(0.6, 1, curve: Curves.easeInOut),
    ),
  );
  late final _borderRadiusAnimation = _buildStaggeredAnimation<double>(
      0, 200, _controller, 0.6, 1, Curves.easeInOut);
  late final _verticalMoveAnimation = _buildStaggeredAnimation<double>(
      0, 200, _controller, 0.2, 0.4, Curves.easeInOut);
  late final _horizontalMoveAnimation = _buildStaggeredAnimation<double>(
      0, 200, _controller, 0, 0.2, Curves.easeInOut);

  @override
  Widget build(BuildContext context) {
    return MyScaffold(
      navName: StaggeredAnimationApp.name,
      view: AnimatedBuilder(
        animation: _controller,
        builder: (context, child) => Stack(children: [
          Positioned(
            left: _horizontalMoveAnimation.value,
            top: _verticalMoveAnimation.value,
            child: Container(
              alignment: Alignment.center,
              decoration: BoxDecoration(
                color: _colorAnimation.value,
                borderRadius:
                    BorderRadius.circular(_borderRadiusAnimation.value),
              ),
              width: _widthAnimation.value,
              height: _heightAnimation.value,
            ),
          ),
        ]),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: _playAnimation,
        child: const Icon(Icons.play_arrow),
      ),
    );
  }

  void _playAnimation() async {
    try {
      debugPrint('start playing animation...');
      await _controller.forward().orCancel;
      await _controller.reverse().orCancel;
      debugPrint('end playing animation...');
    } on TickerCanceled {
      debugPrint('Animation was canceled');
    }
  }
}
