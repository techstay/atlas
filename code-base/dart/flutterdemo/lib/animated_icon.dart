import 'package:flutter/material.dart';
import 'package:flutter_animate/flutter_animate.dart';
import 'package:flutterdemo/shared_component.dart';

class AnimatedIconApp extends StatefulWidget {
  const AnimatedIconApp({super.key});
  static const name = 'Animated Icon';

  @override
  State<AnimatedIconApp> createState() => _AnimatedIconAppState();
}

class _AnimatedIconAppState extends State<AnimatedIconApp>
    with TickerProviderStateMixin {
  late AnimationController _controller;
  var iconData = [
    AnimatedIcons.play_pause,
    AnimatedIcons.pause_play,
    AnimatedIcons.add_event,
    AnimatedIcons.event_add,
    AnimatedIcons.arrow_menu,
    AnimatedIcons.menu_arrow,
    AnimatedIcons.close_menu,
    AnimatedIcons.menu_close,
    AnimatedIcons.home_menu,
    AnimatedIcons.menu_home,
    AnimatedIcons.ellipsis_search,
    AnimatedIcons.search_ellipsis,
    AnimatedIcons.list_view,
    AnimatedIcons.view_list,
  ];
  @override
  void initState() {
    super.initState();
    _controller = AnimationController(
      vsync: this,
      duration: 1.5.seconds,
    )
      ..addListener(() {
        setState(() {});
      })
      ..addStatusListener((status) {
        if (status == AnimationStatus.completed) {
          _controller.reverse();
        } else if (status == AnimationStatus.dismissed) {
          _controller.forward();
        }
      })
      ..forward();
  }

  @override
  void dispose() {
    super.dispose();
    _controller.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return MyScaffoldApp(
      navName: AnimatedIconApp.name,
      view: LayoutBuilder(
        builder: (context, constraints) {
          var columns = (constraints.maxWidth / 110).floor();
          return GridView.builder(
            gridDelegate: SliverGridDelegateWithFixedCrossAxisCount(
              crossAxisCount: columns,
            ),
            itemCount: iconData.length,
            itemBuilder: (context, index) {
              return Center(
                child: Padding(
                  padding: const EdgeInsets.all(8.0),
                  child: Column(
                    children: [
                      AnimatedIcon(
                        icon: iconData[index],
                        progress: CurvedAnimation(
                          parent: _controller,
                          curve: Curves.easeInOutQuad,
                        ),
                        size: 100,
                        color: Colors.accents[index % Colors.accents.length],
                      ),
                    ],
                  ),
                ),
              );
            },
          );
        },
      ),
    );
  }
}
