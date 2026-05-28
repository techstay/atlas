import 'dart:developer';

import 'package:flutter/material.dart';
import 'package:flutterdemo/shared_component.dart';
import 'package:google_fonts/google_fonts.dart';

class HelloWorldApp extends StatelessWidget {
  static const name = 'Hello World';

  const HelloWorldApp({super.key});

  @override
  Widget build(BuildContext context) {
    return const MyScaffoldApp(
      navName: name,
      view: HelloWorldView(),
    );
  }
}

class HelloWorldView extends StatelessWidget {
  const HelloWorldView({super.key});

  @override
  Widget build(BuildContext context) {
    return Center(
      child: InkWell(
        onTap: () {
          log('Displaying a snackbar!');
          const stackBar = SnackBar(
            behavior: SnackBarBehavior.floating,
            showCloseIcon: true,
            content: Text('Hello Flutter World!'),
            duration: Duration(seconds: 1),
          );
          ScaffoldMessenger.of(context).showSnackBar(stackBar);
        },
        child: Tooltip(
          message: 'Click me to display a snackbar!',
          child: Text(
            'Hello Flutter World!',
            style: GoogleFonts.lato(fontSize: 24),
          ),
        ),
      ),
    );
  }
}
