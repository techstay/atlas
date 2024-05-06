import 'package:flutter/material.dart';
import 'package:flutterdemo/shared_component.dart';

class SystemMouseCursorsApp extends StatelessWidget {
  const SystemMouseCursorsApp({super.key});
  static const String name = 'System Mouse Cursors';
  @override
  Widget build(BuildContext context) {
    return MyScaffoldApp(
      navName: name,
      view: SystemMouseCursorsView(),
    );
  }
}

class SystemMouseCursorsView extends StatelessWidget {
  SystemMouseCursorsView({super.key});
  final _cursorStatus = [
    SystemMouseCursors.basic,
    SystemMouseCursors.click,
    SystemMouseCursors.forbidden,
    SystemMouseCursors.help,
    SystemMouseCursors.move,
    SystemMouseCursors.text,
    SystemMouseCursors.wait,
    SystemMouseCursors.cell,
    SystemMouseCursors.grab,
    SystemMouseCursors.grabbing,
    SystemMouseCursors.resizeDownLeft,
    SystemMouseCursors.resizeDownRight,
    SystemMouseCursors.resizeLeft,
    SystemMouseCursors.resizeLeftRight,
    SystemMouseCursors.resizeRight,
    SystemMouseCursors.resizeUpLeft,
    SystemMouseCursors.resizeUpRight,
    SystemMouseCursors.resizeUp,
    SystemMouseCursors.resizeUpDown,
  ];
  @override
  Widget build(BuildContext context) {
    return GridView.builder(
      gridDelegate: const SliverGridDelegateWithFixedCrossAxisCount(
        crossAxisCount: 4,
        mainAxisSpacing: 2,
        crossAxisSpacing: 2,
      ),
      itemCount: _cursorStatus.length,
      itemBuilder: (context, index) {
        return MouseRegion(
          cursor: _cursorStatus[index],
          child: Container(
            decoration: BoxDecoration(
              color: Colors.green[50],
            ),
            child: Center(
              child: Text(
                _cursorStatus[index].kind,
                style: Theme.of(context).textTheme.bodyLarge,
              ),
            ),
          ),
        );
      },
    );
  }
}
