import 'dart:math';

import 'package:flutter/material.dart';
import 'package:flutterdemo/shared_component.dart';

class CustomPaintApp extends StatelessWidget {
  const CustomPaintApp({super.key});
  static const name = 'Custom Paint';

  @override
  Widget build(BuildContext context) {
    return const MyScaffoldApp(
      navName: name,
      view: CustomPaintView(),
    );
  }
}

class CustomPaintView extends StatefulWidget {
  const CustomPaintView({super.key});

  @override
  State<CustomPaintView> createState() => _CustomPaintViewState();
}

class _CustomPaintViewState extends State<CustomPaintView> {
  @override
  Widget build(BuildContext context) {
    return Center(
      child: Wrap(
        direction: Axis.vertical,
        crossAxisAlignment: WrapCrossAlignment.center,
        spacing: 20,
        children: [
          RepaintBoundary(
            child: CustomPaint(
              size: const Size(400, 400),
              painter: MyPainter(),
            ),
          ),
          ElevatedButton(
            onPressed: () => setState(() {}),
            child: const Text('Nothing'),
          ),
        ],
      ),
    );
  }
}

class MyPainter extends CustomPainter {
  final linesOfBoard = 9;

  @override
  void paint(Canvas canvas, Size size) {
    debugPrint('start painting...');
    var rect = Offset.zero & size;
    _drawChessBoard(canvas, rect);
    _drawPieces(canvas, rect);
  }

  void _drawChessBoard(Canvas canvas, Rect rect) {
    var paint = Paint()
      ..isAntiAlias = true
      ..style = PaintingStyle.fill
      ..color = const Color(0xFFDCC48C);
    canvas.drawRect(rect, paint);

    paint
      ..style = PaintingStyle.stroke
      ..color = Colors.black38
      ..strokeWidth = 1.0;

    for (int i = 0; i <= linesOfBoard; ++i) {
      double dy = rect.top + rect.height / linesOfBoard * i;
      canvas.drawLine(Offset(rect.left, dy), Offset(rect.right, dy), paint);
      double dx = rect.left + rect.width / linesOfBoard * i;
      canvas.drawLine(Offset(dx, rect.top), Offset(dx, rect.bottom), paint);
    }
  }

  void _drawPieces(Canvas canvas, Rect rect) {
    double eWidth = rect.width / linesOfBoard;
    double eHeight = rect.height / linesOfBoard;
    var paint = Paint()
      ..style = PaintingStyle.fill
      ..color = Colors.black;
    canvas.drawCircle(
      Offset(rect.center.dx - eWidth / 2, rect.center.dy - eHeight / 2),
      min(eWidth / 2, eHeight / 2) - 2,
      paint,
    );
    paint.color = Colors.white;
    canvas.drawCircle(
      Offset(rect.center.dx + eWidth / 2, rect.center.dy - eHeight / 2),
      min(eWidth / 2, eHeight / 2) - 2,
      paint,
    );
  }

  @override
  bool shouldRepaint(covariant CustomPainter oldDelegate) => false;
}
