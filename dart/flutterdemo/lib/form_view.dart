// ignore_for_file: constant_identifier_names

import 'dart:developer';

import 'package:flutter/material.dart';
import 'package:flutterdemo/shared_component.dart';

class MyFormApp extends StatelessWidget {
  static const name = 'Form View';

  const MyFormApp({super.key});

  @override
  Widget build(BuildContext context) {
    return const MyScaffoldApp(
      navName: name,
      view: MyFormView(),
    );
  }
}

class MyFormView extends StatefulWidget {
  const MyFormView({super.key});

  @override
  State<StatefulWidget> createState() => _MyFormViewState();
}

enum ColorValue { RED, BLUE, GREEN }

class _MyFormViewState extends State<MyFormView> {
  final _textController = TextEditingController();
  final _textFormController = TextEditingController();
  final _formKey = GlobalKey<FormState>();
  var _radioValue = ColorValue.RED;
  final Set<ColorValue> _checkBoxValue = {};

  @override
  Widget build(BuildContext context) {
    return Container(
      padding: const EdgeInsets.symmetric(vertical: 20, horizontal: 40),
      child: Form(
        key: _formKey,
        autovalidateMode: AutovalidateMode.always,
        child: Column(
          children: [
            TextField(
              decoration: const InputDecoration(
                label: Text('Text Field'),
                helperText: 'This is a text field',
              ),
              controller: _textController,
              enabled: false,
              autofocus: true,
            ),
            TextFormField(
              decoration: const InputDecoration(
                label: Text('Text Form Field'),
                helperText: 'This is a text form field',
                border: UnderlineInputBorder(),
              ),
              controller: _textFormController,
              validator: (value) {
                if (value == null || value.isEmpty) {
                  return 'Please enter some text';
                }
                return null;
              },
            ),
            Autocomplete(
              initialValue: null,
              optionsBuilder: (textEditingValue) {
                var options = ['apple', 'banana', 'orange', 'watermelon'];
                return options.where(
                  (element) =>
                      element.contains(textEditingValue.text.toLowerCase()),
                );
              },
            ),
            ElevatedButton(
              onPressed: () {
                log(_textFormController.text);
                if (_formKey.currentState!.validate()) {
                  ScaffoldMessenger.of(context).showSnackBar(
                    const SnackBar(
                      behavior: SnackBarBehavior.floating,
                      content: Text('Form validated'),
                      duration: Duration(milliseconds: 500),
                    ),
                  );
                }
              },
              child: const Text('validate'),
            ),
            Row(
              children:
                  ColorValue.values.map((e) => _buildRadioButton(e)).toList(),
            ),
            Text(_radioValue.name),
            Row(
              children:
                  ColorValue.values.map((e) => _buildCheckBox(e)).toList(),
            ),
            Text('${_checkBoxValue.map((e) => e.name)}'),
          ],
        ),
      ),
    );
  }

  Widget _buildRadioButton(ColorValue colorValue) {
    onChanged(ColorValue? value) {
      setState(() {
        _radioValue = value!;
      });
    }

    return InkWell(
      child: Row(
        children: [
          AbsorbPointer(
            child: Radio<ColorValue>(
              value: colorValue,
              groupValue: _radioValue,
              onChanged: (value) => onChanged(value),
            ),
          ),
          Text(colorValue.name),
        ],
      ),
      onTap: () => onChanged(colorValue),
    );
  }

  Widget _buildCheckBox(ColorValue colorValue) {
    var isChecked = _checkBoxValue.contains(colorValue);
    onChanged(bool? value) {
      setState(() {
        if (value ?? false) {
          _checkBoxValue.add(colorValue);
        } else {
          _checkBoxValue.remove(colorValue);
        }
      });
    }

    return InkWell(
      child: Row(
        children: [
          AbsorbPointer(
            child: Checkbox(
              value: isChecked,
              onChanged: (value) => onChanged(value),
            ),
          ),
          Text(colorValue.name),
        ],
      ),
      onTap: () => onChanged(!isChecked),
    );
  }

  @override
  void initState() {
    super.initState();
    // Start listening to changes.
    _textFormController.addListener(
      () {
        _textController.text = _textFormController.text;
      },
    );
  }

  @override
  void dispose() {
    _textController.dispose();
    _textFormController.dispose();
    super.dispose();
  }
}
