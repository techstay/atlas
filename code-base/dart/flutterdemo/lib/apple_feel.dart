import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:flutterdemo/hello_world.dart';
import 'package:flutterdemo/shared_component.dart';

class AppleFeelApp extends StatelessWidget {
  static const name = 'Apple Feel';

  const AppleFeelApp({super.key});

  @override
  Widget build(BuildContext context) {
    return const MyAppleApp(
      navName: name,
      view: FirstPage(),
    );
  }
}

class FirstPage extends StatelessWidget {
  const FirstPage({super.key});

  @override
  Widget build(BuildContext context) {
    return MyAppleScaffold(
      navName: AppleFeelApp.name,
      view: Container(
        color: Colors.red,
        child: Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              CupertinoButton.filled(
                child: const Text('Go to second'),
                onPressed: () {
                  Navigator.push(
                    context,
                    CupertinoPageRoute(
                      builder: (context) => const SecondPage(),
                    ),
                  );
                },
              ),
              const SizedBox(height: 20),
              CupertinoButton.filled(
                child: const Text('Go to Index Page'),
                onPressed: () {
                  Navigator.push(
                    context,
                    CupertinoPageRoute(
                      builder: (context) => const HelloWorldApp(),
                    ),
                  );
                  selectedIndexOfMyDrawer = 0;
                },
              ),
            ],
          ),
        ),
      ),
    );
  }
}

class SecondPage extends StatelessWidget {
  const SecondPage({super.key});

  @override
  Widget build(BuildContext context) {
    return MyAppleScaffold(
      navName: AppleFeelApp.name,
      view: Container(
        color: Colors.blue,
        child: Center(
          child: CupertinoButton.filled(
            child: const Text('Go back'),
            onPressed: () {
              Navigator.pop(context);
            },
          ),
        ),
      ),
    );
  }
}
