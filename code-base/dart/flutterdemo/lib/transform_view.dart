import 'dart:math';

import 'package:flutter/material.dart';
import 'package:flutterdemo/shared_component.dart';

class TransformApp extends StatelessWidget {
  static const name = 'Transform';

  const TransformApp({super.key});

  @override
  Widget build(BuildContext context) {
    return const MyScaffoldApp(navName: name, view: TransformView());
  }
}

class TransformView extends StatefulWidget {
  const TransformView({super.key});

  @override
  State<TransformView> createState() => _TransformViewState();
}

class _TransformViewState extends State<TransformView> {
  final _rotateNotifier = ValueNotifier(0.0);
  final _scaleNotifier = ValueNotifier(1.0);
  final _translateXNotifier = ValueNotifier(0.0);
  final _translateYNotifier = ValueNotifier(0.0);
  final _skewXNotifier = ValueNotifier(0.0);
  final _skewYNotifier = ValueNotifier(0.0);

  @override
  Widget build(BuildContext context) {
    return SingleChildScrollView(
      child: Center(
        child: Padding(
          padding: const EdgeInsets.symmetric(
            horizontal: 30,
            vertical: 30,
          ),
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            crossAxisAlignment: CrossAxisAlignment.center,
            children: [
              RepaintBoundary(
                child: Transform(
                  alignment: Alignment.center,
                  transform:
                      Matrix4.skew(_skewXNotifier.value, _skewYNotifier.value)
                        ..rotateZ(_rotateNotifier.value)
                        ..scale(_scaleNotifier.value)
                        ..translate(
                          _translateXNotifier.value,
                          _translateYNotifier.value,
                        ),
                  child: SizedBox(
                    width: 300,
                    height: 300,
                    child: Container(
                      decoration: const BoxDecoration(
                        gradient: LinearGradient(
                          begin: Alignment.topRight,
                          end: Alignment.bottomLeft,
                          stops: [
                            0.1,
                            0.4,
                            0.6,
                            0.9,
                          ],
                          colors: [
                            Colors.orange,
                            Colors.red,
                            Colors.indigo,
                            Colors.teal,
                          ],
                        ),
                      ),
                    ),
                  ),
                ),
              ),
              _buildSlider('Rotate', _rotateNotifier, 0, 2 * pi),
              _buildSlider('Scale', _scaleNotifier, 0.2, 1.5),
              _buildSlider('TranslateX', _translateXNotifier, -200, 200),
              _buildSlider('TranslateY', _translateYNotifier, -100, 100),
              _buildSlider('SkewX', _skewXNotifier, -0.5, 0.5),
              _buildSlider('SkewY', _skewYNotifier, -0.5, 0.5),
              ElevatedButton(
                onPressed: () {
                  setState(() {
                    _rotateNotifier.value = 0;
                    _scaleNotifier.value = 1;
                    _translateXNotifier.value = 0;
                    _translateYNotifier.value = 0;
                    _skewXNotifier.value = 0;
                    _skewYNotifier.value = 0;
                  });
                },
                child: const Text('Reset'),
              )
            ],
          ),
        ),
      ),
    );
  }

  Widget _buildSlider(String sliderText, ValueNotifier<double> notifier,
      double min, double max) {
    return Padding(
      padding: const EdgeInsets.symmetric(horizontal: 10),
      child: Row(
        children: [
          Text(sliderText),
          ValueListenableBuilder(
            valueListenable: notifier,
            builder: (context, value, child) => Expanded(
              child: Slider(
                min: min,
                max: max,
                value: value,
                onChanged: (value) {
                  setState(() {
                    notifier.value = value;
                  });
                },
              ),
            ),
          ),
        ],
      ),
    );
  }
}
