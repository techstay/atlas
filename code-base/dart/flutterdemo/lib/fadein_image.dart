import 'package:flutter/material.dart';
import 'package:flutterdemo/shared_component.dart';
import 'package:transparent_image/transparent_image.dart';

class FadeInImageApp extends StatelessWidget {
  static const name = 'Fade In Image';

  const FadeInImageApp({super.key});

  @override
  Widget build(BuildContext context) {
    return const MyScaffoldApp(
      navName: name,
      view: FadeInImageView(),
    );
  }
}

class FadeInImageView extends StatelessWidget {
  const FadeInImageView({super.key});
  @override
  Widget build(BuildContext context) {
    return Stack(
      children: [
        const Center(
          child: CircularProgressIndicator(),
        ),
        Center(
          child: FadeInImage.memoryNetwork(
            placeholder: kTransparentImage,
            image: 'https://pixiv.cat/116776192.jpg',
          ),
        ),
      ],
    );
  }
}
