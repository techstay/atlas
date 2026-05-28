import 'package:flutter/material.dart';
import 'package:flutterdemo/shared_component.dart';

class StreamBuilderApp extends StatelessWidget {
  const StreamBuilderApp({super.key});
  static const name = 'Stream Builder';

  @override
  Widget build(BuildContext context) {
    return const MyScaffold(
      navName: name,
      view: StreamBuilderView(),
    );
  }
}

class StreamBuilderView extends StatefulWidget {
  const StreamBuilderView({super.key});

  @override
  State<StreamBuilderView> createState() => _StreamBuilderViewState();
}

class _StreamBuilderViewState extends State<StreamBuilderView> {
  @override
  Widget build(BuildContext context) {
    return Center(
      child: Padding(
        padding: const EdgeInsets.symmetric(horizontal: 30),
        child: DefaultTextStyle(
          style: Theme.of(context).textTheme.headlineMedium!,
          child: StreamBuilder<int>(
            stream: _getStream(),
            builder: (context, snapshot) {
              Widget child = switch (snapshot.connectionState) {
                ConnectionState.active =>
                  LinearProgressIndicator(value: snapshot.data! / 100),
                ConnectionState.waiting => const CircularProgressIndicator(),
                ConnectionState.done => const Text('Done'),
                _ => const Text('Error'),
              };
              return AnimatedSwitcher(
                duration: const Duration(milliseconds: 300),
                transitionBuilder: (child, animation) {
                  return FadeTransition(
                    opacity: animation,
                    child: child,
                  );
                },
                child: child,
              );
            },
          ),
        ),
      ),
    );
  }

  Stream<int> _getStream() {
    return Stream.periodic(const Duration(milliseconds: 10), (i) => i + 1)
        .take(100);
  }
}
