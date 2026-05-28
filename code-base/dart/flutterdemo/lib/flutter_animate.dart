import 'package:flutter/material.dart';
import 'package:flutter_animate/flutter_animate.dart';
import 'package:flutterdemo/shared_component.dart';

class FlutterAnimateApp extends StatelessWidget {
  const FlutterAnimateApp({super.key});
  static const name = 'Flutter Animate';
  @override
  Widget build(BuildContext context) {
    return MyScaffoldApp(
      navName: name,
      view: Column(
        children: [
          _widget1(),
          hr,
          ..._widget2(),
          hr,
          _widget3(),
        ],
      ),
      actions: [
        IconButton(
          onPressed: () {
            Navigator.push(
              context,
              MaterialPageRoute(
                builder: (context) => const FlutterAnimateApp(),
              ),
            );
          },
          icon: const Icon(Icons.refresh),
        )
      ],
    );
  }

  Widget _widget1() {
    return const Text(
      'Flutter Animate',
      style: TextStyle(
        fontSize: 40,
        fontWeight: FontWeight.w900,
        color: Colors.green,
      ),
    )
        .animate(
          onPlay: (controller) => controller.repeat(),
        )
        .shimmer(
          duration: 1200.ms,
          color: const Color.fromARGB(192, 218, 37, 24),
        )
        .animate()
        .fadeIn(duration: 1200.ms, curve: Curves.easeOutQuad)
        .slide();
  }

  List<Widget> _widget2() {
    return List.generate(
      4,
      (index) => const ListTile(
        leading: Icon(Icons.menu),
        title: Text(
          'Lorem ipsum dolor sit amet consectetur adipiscing elit',
        ),
      ),
    )
        .animate(
          interval: 400.ms,
        )
        .fadeIn(duration: 800.ms, delay: 400.ms)
        .shimmer(
            blendMode: BlendMode.srcOver,
            color: const Color.fromARGB(218, 248, 238, 99))
        .move(begin: const Offset(-16, 0), curve: Curves.easeOutQuad);
  }

  Widget _widget3() {
    return Wrap(
      spacing: 20,
      crossAxisAlignment: WrapCrossAlignment.center,
      children: [
        Container(
          height: 100,
          width: 100,
          color: Colors.red,
        )
            .animate()
            .fadeIn(duration: 2000.ms)
            .scale(
              curve: Curves.bounceOut,
              duration: 1500.ms,
            )
            .then()
            .tint(
              color: Colors.blue,
            ),
        Container(
          height: 100,
          width: 100,
          decoration: const BoxDecoration(
            gradient: LinearGradient(
              colors: [
                Colors.redAccent,
                Colors.greenAccent,
              ],
              begin: Alignment.topLeft,
              end: Alignment.bottomRight,
            ),
          ),
        )
            .animate(delay: 500.ms)
            .slideX(begin: 2, duration: 1.seconds)
            .fadeIn(duration: 1.seconds)
            .flip(duration: 1.seconds),
      ],
    );
  }

  Widget get hr => Container(
        height: 4,
        color: const Color(0x8080DDFF),
        margin: const EdgeInsets.symmetric(vertical: 16),
      ).animate().scale(duration: 1000.ms, alignment: Alignment.centerLeft);
}
