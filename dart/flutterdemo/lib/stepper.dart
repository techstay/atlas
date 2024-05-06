import 'package:flutter/material.dart';
import 'package:flutterdemo/shared_component.dart';

class StepperApp extends StatefulWidget {
  const StepperApp({super.key});
  static const name = 'Stepper';
  @override
  State<StepperApp> createState() => _StepperAppState();
}

class _StepperAppState extends State<StepperApp> {
  var _currentStep = 0;
  final _maxStep = 4;
  var _isVertical = true;

  @override
  Widget build(BuildContext context) {
    return MyScaffoldApp(
      navName: StepperApp.name,
      view: Stepper(
        currentStep: _currentStep,
        type: _isVertical ? StepperType.vertical : StepperType.horizontal,
        steps: List.generate(
          _maxStep,
          (index) => Step(
            title: Text('Step ${index + 1}'),
            content: Text('Step ${index + 1} details'),
            isActive: _currentStep == index,
          ),
        ),
        onStepTapped: (value) {
          setState(() {
            _currentStep = value;
          });
        },
        onStepContinue: () {
          if (_currentStep < _maxStep - 1) {
            setState(() {
              _currentStep++;
            });
          }
        },
        onStepCancel: () {
          if (_currentStep > 0) {
            setState(() {
              _currentStep--;
            });
          }
        },
      ),
      actions: [
        MouseRegion(
          onHover: (event) {},
          child: IconButton(
            onPressed: () {
              setState(() {
                _isVertical = !_isVertical;
              });
            },
            icon: const Icon(
              Icons.swap_vert,
            ),
          ),
        )
      ],
    );
  }
}
