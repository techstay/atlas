import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:flutterdemo/shared_component.dart';

class ShortcutsApp extends StatefulWidget {
  const ShortcutsApp({super.key});
  static const name = 'Shortcuts';

  @override
  State<ShortcutsApp> createState() => _ShortcutsAppState();
}

class _ShortcutsAppState extends State<ShortcutsApp> {
  int counter = 0;
  @override
  Widget build(BuildContext context) {
    return MyScaffoldApp(
      navName: ShortcutsApp.name,
      view: Shortcuts(
        shortcuts: {
          LogicalKeySet(LogicalKeyboardKey.arrowUp):
              const IncrementCounterIntent(),
          LogicalKeySet(LogicalKeyboardKey.arrowDown):
              const DecrementCounterIntent(),
        },
        child: Actions(
          actions: {
            IncrementCounterIntent: CallbackAction<IncrementCounterIntent>(
              onInvoke: (IncrementCounterIntent intent) => setState(() {
                counter++;
              }),
            ),
            DecrementCounterIntent: CallbackAction<DecrementCounterIntent>(
              onInvoke: (DecrementCounterIntent intent) => setState(() {
                counter--;
              }),
            ),
          },
          child: Focus(
            child: Center(
              child: Tooltip(
                message: 'Press arrow up and arrow down to change the counter',
                child: AnimatedSwitcher(
                  duration: Durations.medium1,
                  transitionBuilder: (child, animation) => SlideTransition(
                    position: Tween<Offset>(
                      begin: const Offset(0, 0.5),
                      end: Offset.zero,
                    ).animate(animation),
                    child: FadeTransition(opacity: animation, child: child),
                  ),
                  child: Text(
                    key: ValueKey(counter),
                    '$counter',
                    style: const TextStyle(fontSize: 100),
                  ),
                ),
              ),
            ),
          ),
        ),
      ),
    );
  }
}

class IncrementCounterIntent extends Intent {
  const IncrementCounterIntent();
}

class DecrementCounterIntent extends Intent {
  const DecrementCounterIntent();
}
