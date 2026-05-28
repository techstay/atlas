import 'package:flutter/material.dart';
import 'package:flutterdemo/shared_component.dart';

class FutureBuilderApp extends StatelessWidget {
  const FutureBuilderApp({super.key});
  static const name = 'Future Builder';

  @override
  Widget build(BuildContext context) {
    return const MyScaffoldApp(navName: name, view: FutureBuilderView());
  }
}

class FutureBuilderView extends StatefulWidget {
  const FutureBuilderView({super.key});

  @override
  State<FutureBuilderView> createState() => _FutureBuilderViewState();
}

class _FutureBuilderViewState extends State<FutureBuilderView> {
  @override
  Widget build(BuildContext context) {
    return Center(
      child: DefaultTextStyle(
        style: Theme.of(context).textTheme.headlineMedium!,
        child: FutureBuilder<String>(
          future: _mockNetworkData(),
          builder: (BuildContext context, AsyncSnapshot<String> snapshot) {
            Widget child = switch (snapshot.connectionState) {
              ConnectionState.done => Text(snapshot.data!),
              ConnectionState.waiting => const CircularProgressIndicator(),
              _ => const Text('Error'),
            };
            return AnimatedSwitcher(
              duration: const Duration(milliseconds: 500),
              transitionBuilder: (child, animation) {
                return Center(
                  child: ScaleTransition(
                    scale: animation,
                    child: SlideTransition(
                      position: Tween<Offset>(
                        begin: const Offset(0.0, 1),
                        end: const Offset(0.0, 0.0),
                      ).animate(animation),
                      child: FadeTransition(
                        opacity: animation,
                        child: child,
                      ),
                    ),
                  ),
                );
              },
              child: child,
            );
          },
        ),
      ),
    );
  }

  Future<String> _mockNetworkData() async {
    return Future.delayed(const Duration(seconds: 2), () => 'Good luck!');
  }
}
