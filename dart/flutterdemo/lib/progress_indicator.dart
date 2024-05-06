import 'package:flutter/material.dart';
import 'package:flutterdemo/shared_component.dart';

class ProgressIndicatorApp extends StatelessWidget {
  static const name = 'Progress Indicator';

  const ProgressIndicatorApp({super.key});

  @override
  Widget build(BuildContext context) {
    return const MyApp(scaffold: ProgressIndicatorView());
  }
}

class ProgressIndicatorView extends StatefulWidget {
  const ProgressIndicatorView({super.key});

  @override
  State<ProgressIndicatorView> createState() => _ProgressIndicatorViewState();
}

class _ProgressIndicatorViewState extends State<ProgressIndicatorView>
    with SingleTickerProviderStateMixin {
  late AnimationController _controller;

  @override
  void initState() {
    _controller = AnimationController(
      duration: const Duration(seconds: 2),
      vsync: this,
    )..repeat();

    super.initState();
  }

  @override
  void dispose() {
    _controller.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text(ProgressIndicatorApp.name),
      ),
      drawer: myDrawer,
      body: Center(
        child: Padding(
          padding: const EdgeInsets.all(20),
          child: Column(
            children: [
              ProgressIndicatorGroup(
                animation: CurvedAnimation(
                  parent: _controller,
                  curve: Curves.linear,
                ),
              ),
              ProgressIndicatorGroup(
                animation: CurvedAnimation(
                  parent: _controller,
                  curve: Curves.easeInOut,
                ),
              ),
              ProgressIndicatorGroup(
                animation: CurvedAnimation(
                  parent: _controller,
                  curve: Curves.fastOutSlowIn,
                ),
              ),
              ProgressIndicatorGroup(
                animation: CurvedAnimation(
                  parent: _controller,
                  curve: Curves.fastEaseInToSlowEaseOut,
                ),
              ),
            ],
          ),
        ),
      ),
    );
  }
}

class ProgressIndicatorGroup extends StatelessWidget {
  final Animation<double> animation;

  const ProgressIndicatorGroup({super.key, required this.animation});

  @override
  Widget build(BuildContext context) {
    return AnimatedBuilder(
      animation: animation,
      builder: (BuildContext context, Widget? child) {
        return Column(
          crossAxisAlignment: CrossAxisAlignment.center,
          children: [
            LinearProgressIndicator(
              value: animation.value,
            ),
            const SizedBox(height: 20),
            CircularProgressIndicator(
              value: animation.value,
            ),
            const SizedBox(height: 20),
          ],
        );
      },
    );
  }
}
