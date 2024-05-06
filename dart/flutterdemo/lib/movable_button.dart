import 'package:flutter/material.dart';
import 'package:flutterdemo/shared_component.dart';

class MovableButtonApp extends StatelessWidget {
  static const name = 'Movable Button';

  const MovableButtonApp({super.key});

  @override
  Widget build(BuildContext context) {
    return const MyScaffoldApp(
      navName: name,
      view: MovableButtonView(),
    );
  }
}

class MovableButtonView extends StatefulWidget {
  const MovableButtonView({super.key});

  @override
  State<StatefulWidget> createState() => _MovableButtonViewState();
}

class _MovableButtonViewState extends State<MovableButtonView> {
  var _offset = const Offset(20, 20);
  var _initialPosition = Offset.zero;

  @override
  Widget build(BuildContext context) {
    return Stack(
      children: [
        _buildText(),
        _buildDraggableButton(),
      ],
    );
  }

  Widget _buildText() {
    return const Center(
      child: Padding(
        padding: EdgeInsets.all(30.0),
        child: SizedBox(
          width: 400,
          child: Text(
            'This button is movable, drag it to somewhere to see the effect.',
            style: TextStyle(
              fontSize: 20,
            ),
          ),
        ),
      ),
    );
  }

  // Here we make the button movable
  // Wrapping the button with Draggable is another approach but we don't use it here
  // because Draggable will make the origin position visible which is not what we want
  Widget _buildDraggableButton() {
    return Positioned(
      left: _offset.dx,
      top: _offset.dy,
      child: GestureDetector(
        child: const FloatingActionButton(
          onPressed: null,
          child: Icon(Icons.drag_indicator),
        ),
        onPanStart: (details) {
          _initialPosition = details.globalPosition - _offset;
        },
        onPanUpdate: (details) {
          setState(() {
            _offset = details.globalPosition - _initialPosition;
          });
        },
        onPanEnd: (details) {
          debugPrint(
              'Button moved from $_initialPosition to ${_initialPosition + _offset}');
        },
      ),
    );
  }
}
