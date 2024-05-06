import 'dart:async';

import 'package:flex_color_picker/flex_color_picker.dart';
import 'package:flutter/material.dart';
import 'package:flutterdemo/shared_component.dart';

class ShowDialogApp extends StatelessWidget {
  const ShowDialogApp({super.key});
  static const name = 'Show Dialogs';

  @override
  Widget build(BuildContext context) {
    return const MyScaffoldApp(navName: name, view: ShowDialogView());
  }
}

class ShowDialogView extends StatefulWidget {
  const ShowDialogView({super.key});

  @override
  State<ShowDialogView> createState() => _ShowDialogViewState();
}

class _ShowDialogViewState extends State<ShowDialogView>
    with TickerProviderStateMixin {
  var _checkboxValue = false;
  late Color _dialogPickerColor = Theme.of(context).colorScheme.primary;

  // Define custom colors. The 'guide' color values are from
  // https://material.io/design/color/the-color-system.html#color-theme-creation
  static const Color guidePrimary = Color(0xFF6200EE);
  static const Color guidePrimaryVariant = Color(0xFF3700B3);
  static const Color guideSecondary = Color(0xFF03DAC6);
  static const Color guideSecondaryVariant = Color(0xFF018786);
  static const Color guideError = Color(0xFFB00020);
  static const Color guideErrorDark = Color(0xFFCF6679);
  static const Color blueBlues = Color(0xFF174378);

  // Make a custom ColorSwatch to name map from the above custom colors.
  final Map<ColorSwatch<Object>, String> colorsNameMap =
      <ColorSwatch<Object>, String>{
    ColorTools.createPrimarySwatch(guidePrimary): 'Guide Purple',
    ColorTools.createPrimarySwatch(guidePrimaryVariant): 'Guide Purple Variant',
    ColorTools.createAccentSwatch(guideSecondary): 'Guide Teal',
    ColorTools.createAccentSwatch(guideSecondaryVariant): 'Guide Teal Variant',
    ColorTools.createPrimarySwatch(guideError): 'Guide Error',
    ColorTools.createPrimarySwatch(guideErrorDark): 'Guide Error Dark',
    ColorTools.createPrimarySwatch(blueBlues): 'Blue blues',
  };

  @override
  Widget build(BuildContext context) {
    return Center(
      child: Padding(
        padding: const EdgeInsets.all(12.0),
        child: Wrap(
          spacing: 20,
          runSpacing: 20,
          children: [
            _buildButton(context, 'Show Alert Dialog', _showAlertDialog),
            _buildButton(context, 'Show Simple Dialog', _showSimpleDialog),
            _buildButton(context, 'Show General Dialog', _showGeneralDialog),
            _buildButton(
                context, 'Show Modal Bottom Sheet', _showModalBottomSheet),
            _buildButton(context, 'Show Loading Dialog', _showLoadingDialog),
            _buildButton(context, 'Show Date Picker', _showDatePickerDialog),
            _buildButton(context, 'Show Timer Picker', _showTimePickerDialog),
            _buildButton(context, 'Show Color Picker', _showColorPickerDialog),
          ],
        ),
      ),
    );
  }

  void _showAlertDialog() async {
    var result = await showDialog<String>(
      context: context,
      builder: (context) => AlertDialog(
        title: const Text('Alert Dialog'),
        content: Wrap(
          spacing: 10,
          runSpacing: 10,
          direction: Axis.vertical,
          children: [
            const Text('This is an alert dialog'),
            StatefulBuilder(
              builder: (context, setState) => CheckBoxWithLabel(
                label: 'Checkbox',
                value: _checkboxValue,
                callback: () {
                  setState(() {
                    _checkboxValue = !_checkboxValue;
                  });
                  debugPrint('Checkbox tapped: currentValue = $_checkboxValue');
                },
              ),
            ),
          ],
        ),
        actions: [
          TextButton(
            onPressed: () {
              Navigator.pop(context, 'OK');
            },
            child: const Text('OK'),
          ),
          TextButton(
            onPressed: () {
              Navigator.pop(context);
            },
            child: const Text('Cancel'),
          ),
        ],
      ),
    );
    debugPrint('Alert Dialog result: $result');
  }

  Future<void> _showGeneralDialog() async {
    var result = await showGeneralDialog(
      context: context,
      barrierDismissible: true,
      barrierLabel: 'General Dialog',
      barrierColor: Colors.black87,
      pageBuilder: (context, animation, secondaryAnimation) => Dialog(
        child: ListView.builder(
          shrinkWrap: true,
          itemCount: 6,
          itemBuilder: (context, index) => ListTile(
            title: Text('Item ${index + 1}'),
            onTap: () => Navigator.pop(context, index + 1),
          ),
        ),
      ),
      transitionDuration: const Duration(milliseconds: 300),
      transitionBuilder: (context, animation, secondaryAnimation, child) =>
          ScaleTransition(
        scale: CurvedAnimation(
          parent: animation,
          curve: Curves.easeInOut,
        ),
        child: child,
      ),
    );
    debugPrint('General Dialog result: $result');
  }

  void _showSimpleDialog() {
    showDialog(
      context: context,
      builder: (context) => SimpleDialog(
        title: const Text('Simple Dialog'),
        children: List.generate(
          4,
          (index) => SimpleDialogOption(
            child: Text('Item ${index + 1}'),
            onPressed: () {
              Navigator.pop(context, index + 1);
            },
          ),
        ),
      ),
    ).then((result) {
      debugPrint('Simple Dialog: item $result clicked');
    });
  }

  void _showModalBottomSheet() {
    showModalBottomSheet(
      context: context,
      builder: (context) => ListView.builder(
        itemCount: 10,
        itemBuilder: (context, index) => ListTile(
          title: Text('Item ${index + 1}'),
          onTap: () {
            Navigator.pop(context);
            debugPrint('Item ${index + 1} clicked');
          },
        ),
      ),
    );
  }

  void _showLoadingDialog() {
    showDialog(
      context: context,
      barrierDismissible: false,
      builder: (context) => AlertDialog(
        content: Padding(
          padding: const EdgeInsets.all(14.0),
          child: Wrap(
            spacing: 14,
            runSpacing: 14,
            runAlignment: WrapAlignment.center,
            crossAxisAlignment: WrapCrossAlignment.center,
            direction: Axis.vertical,
            children: [
              StatefulBuilder(builder: (context, setState) {
                var controller = AnimationController(
                  vsync: this,
                  duration: const Duration(milliseconds: 1500),
                )..addStatusListener((status) {
                    if (status == AnimationStatus.completed) {
                      Navigator.pop(context);
                      debugPrint('animation completed');
                    }
                  });
                var animation = CurvedAnimation(
                  curve: Curves.easeInOutCubic,
                  parent: controller,
                );
                controller.forward();

                return AnimatedBuilder(
                  animation: animation,
                  builder: (context, child) =>
                      CircularProgressIndicator(value: animation.value),
                );
              }),
              Text(
                'Loading...',
                style: Theme.of(context).textTheme.titleMedium,
              ),
            ],
          ),
        ),
      ),
    );
  }

  void _showDatePickerDialog() {
    showDatePicker(
      context: context,
      firstDate: DateTime(1990),
      lastDate: DateTime(2077),
      initialDate: DateTime.now(),
    ).then((value) => debugPrint('selected date: $value'));
  }

  void _showTimePickerDialog() {
    showGeneralDialog(
      context: context,
      barrierDismissible: true,
      barrierLabel: 'Time Picker',
      pageBuilder: (context, animation, secondaryAnimation) => TimePickerDialog(
        initialTime: TimeOfDay.now(),
      ),
      transitionBuilder: _veryCoolTransition,
      transitionDuration: const Duration(milliseconds: 350),
    ).then((value) => debugPrint('selected time: $value'));
  }

  void _showColorPickerDialog() async {
    var oldColor = _dialogPickerColor;
    ColorPicker(
      // Use the dialogPickerColor as start color.
      color: _dialogPickerColor,
      // Update the dialogPickerColor using the callback.
      onColorChanged: (value) {},
      onColorChangeEnd: (Color color) {
        setState(() {
          _dialogPickerColor = color;
        });
        globalTheme.value = ThemeData(colorSchemeSeed: _dialogPickerColor);
        debugPrint('selected color: $color');
      },
      width: 40,
      height: 40,
      borderRadius: 4,
      spacing: 5,
      runSpacing: 5,
      wheelDiameter: 155,
      heading: Text(
        'Select color',
        style: Theme.of(context).textTheme.titleSmall,
      ),
      subheading: Text(
        'Select color shade',
        style: Theme.of(context).textTheme.titleSmall,
      ),
      wheelSubheading: Text(
        'Selected color and its shades',
        style: Theme.of(context).textTheme.titleSmall,
      ),
      showMaterialName: true,
      showColorName: true,
      showColorCode: true,
      copyPasteBehavior: const ColorPickerCopyPasteBehavior(
        longPressMenu: true,
      ),
      materialNameTextStyle: Theme.of(context).textTheme.bodySmall,
      colorNameTextStyle: Theme.of(context).textTheme.bodySmall,
      colorCodeTextStyle: Theme.of(context).textTheme.bodySmall,
      pickersEnabled: const <ColorPickerType, bool>{
        ColorPickerType.both: false,
        ColorPickerType.primary: true,
        ColorPickerType.accent: true,
        ColorPickerType.bw: false,
        ColorPickerType.custom: true,
        ColorPickerType.wheel: true,
      },
      customColorSwatchesAndNames: colorsNameMap,
    )
        .showPickerDialog(
      context,
      // New in version 3.0.0 custom transitions support.
      transitionBuilder: _veryCoolTransition,
      backgroundColor: globalTheme.value.colorScheme.background,
      transitionDuration: const Duration(milliseconds: 400),
      constraints:
          const BoxConstraints(minHeight: 460, minWidth: 300, maxWidth: 320),
    )
        .then((value) {
      if (!value) {
        _dialogPickerColor = oldColor;
        globalTheme.value = ThemeData(colorSchemeSeed: oldColor);
      }
    });
  }
}

Widget _veryCoolTransition(
  BuildContext context,
  Animation<double> a1,
  Animation<double> a2,
  Widget child,
) {
  final double curvedValue = Curves.easeInOutBack.transform(a1.value) - 1.0;
  return Transform(
    transform: Matrix4.translationValues(0.0, curvedValue * 200, 0.0),
    child: Opacity(
      opacity: a1.value,
      child: child,
    ),
  );
}

Widget _buildButton(BuildContext context, String text, VoidCallback onPressed) {
  return ElevatedButton(
    onPressed: onPressed,
    child: Text(text),
  );
}

class CheckBoxWithLabel extends StatelessWidget {
  final bool value;
  final String label;
  final VoidCallback? callback;

  const CheckBoxWithLabel({
    super.key,
    required this.value,
    required this.label,
    this.callback,
  });

  @override
  Widget build(BuildContext context) {
    return InkWell(
      onTap: callback,
      child: Row(
        children: [
          AbsorbPointer(
              child: Checkbox(
            value: value,
            onChanged: (value) {},
          )),
          const SizedBox(width: 10),
          const Text('Label'),
        ],
      ),
    );
  }
}
