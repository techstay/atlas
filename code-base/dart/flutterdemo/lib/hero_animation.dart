import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:flutterdemo/shared_component.dart';

class HeroAnimationApp extends StatelessWidget {
  const HeroAnimationApp({super.key});
  static const name = 'Hero Animation';

  @override
  Widget build(BuildContext context) {
    return const MyApp(
      scaffold: FirstPage(),
    );
  }
}

class FirstPage extends StatelessWidget {
  const FirstPage({super.key});

  @override
  Widget build(BuildContext context) {
    return MyScaffold(
      navName: HeroAnimationApp.name,
      view: Center(
        child: Hero(
          tag: 'unique',
          child: GestureDetector(
            onTap: () {
              Navigator.push(
                context,
                CupertinoPageRoute(
                  builder: (context) => const SecondPage(),
                ),
              );
            },
            child: SizedBox.square(
              dimension: 200,
              child: Tooltip(
                message: 'Click me to see the hero animation',
                textStyle: Theme.of(context).textTheme.bodyMedium,
                child: const FlutterLogo(),
              ),
            ),
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
    var gridCount = 30;
    return Scaffold(
      appBar: AppBar(
        title: const Text('Second Page'),
      ),
      body: GridView.builder(
        gridDelegate: const SliverGridDelegateWithFixedCrossAxisCount(
          crossAxisCount: 6,
          childAspectRatio: 1,
        ),
        itemCount: gridCount,
        itemBuilder: (context, index) {
          return Container(
            width: 200,
            height: 200,
            color: Color.fromRGBO(
              255 - 255 ~/ gridCount * index,
              255 - 255 ~/ gridCount * index,
              255 - 255 ~/ gridCount * index,
              1,
            ),
          );
        },
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: () => Navigator.pop(context),
        heroTag: 'unique', // floating action button is also a hero widget
        child: const FlutterLogo(),
      ),
    );
  }
}
