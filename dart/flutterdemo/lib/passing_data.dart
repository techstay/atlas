// ignore_for_file: constant_identifier_names

import 'package:flutter/material.dart';
import 'package:flutterdemo/shared_component.dart';

class PassingDataApp extends StatelessWidget {
  static const name = 'Passing Data';

  const PassingDataApp({super.key});

  @override
  Widget build(BuildContext context) {
    return const MyApp(scaffold: FirstScreen());
  }
}

enum RadioValue { ONE, TWO, THREE }

class FirstScreen extends StatefulWidget {
  const FirstScreen({super.key});

  @override
  State<StatefulWidget> createState() => _FirstScreenState();
}

class _FirstScreenState extends State<FirstScreen> {
  RadioValue? _radioValue = RadioValue.ONE;
  int? _receivedData;

  Widget _buildRadioItem(RadioValue value) {
    return RadioListTile<RadioValue>(
      groupValue: _radioValue,
      value: value,
      title: Text(value.name),
      onChanged: (RadioValue? newValue) {
        setState(() {
          _radioValue = newValue;
        });
      },
    );
  }

  Future<int> _navigateToSecondScreen(
      BuildContext context, RadioValue? data) async {
    final result = await Navigator.push(
      context,
      MaterialPageRoute(
          builder: (context) => const SecondScreen(),
          settings: RouteSettings(arguments: data)),
    );
    return result;
  }

  @override
  Widget build(BuildContext context) {
    return MyScaffold(
      navName: PassingDataApp.name,
      view: Center(
        child: Column(
          children: [
            _buildRadioItem(RadioValue.ONE),
            _buildRadioItem(RadioValue.TWO),
            _buildRadioItem(RadioValue.THREE),
            Text('Selected Item: $_radioValue, received data: $_receivedData'),
            const SizedBox(height: 20),
            ElevatedButton(
              onPressed: () {
                var result = _navigateToSecondScreen(context, _radioValue);
                result.then(
                  (value) => setState(() {
                    _receivedData = value;
                  }),
                );
              },
              child: const Text('Go to next Page'),
            )
          ],
        ),
      ),
    );
  }
}

class SecondScreen extends StatefulWidget {
  const SecondScreen({super.key});

  @override
  State<StatefulWidget> createState() => _SecondScreenState();
}

class _SecondScreenState extends State<SecondScreen> {
  var _sliderValue = 0;

  @override
  Widget build(BuildContext context) {
    var data = ModalRoute.of(context)!.settings.arguments as RadioValue;
    return MyScaffold(
      navName: PassingDataApp.name,
      view: Center(
        child: Column(
          children: [
            Padding(
              padding: const EdgeInsets.only(top: 14.0),
              child: Text(
                  'Received Value: ${data.name}, slider data: $_sliderValue'),
            ),
            Slider(
              min: 0,
              max: 100,
              value: _sliderValue.toDouble(),
              onChanged: (value) {
                setState(() {
                  _sliderValue = value.toInt();
                });
              },
            ),
            ElevatedButton(
              onPressed: () {
                Navigator.pop(
                  context,
                  // Returned value of this widget
                  _sliderValue,
                );
              },
              child: const Text('Go back'),
            ),
          ],
        ),
      ),
    );
  }
}
