import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:flutterdemo/animated_icon.dart';
import 'package:flutterdemo/animated_list.dart';
import 'package:flutterdemo/animated_opacity.dart';
import 'package:flutterdemo/animated_switcher.dart';
import 'package:flutterdemo/animated_container.dart';
import 'package:flutterdemo/animation_controller.dart';
import 'package:flutterdemo/apple_feel.dart';
import 'package:flutterdemo/custom_paint.dart';
import 'package:flutterdemo/custom_scroll.dart';
import 'package:flutterdemo/data_table.dart';
import 'package:flutterdemo/dismissible_items.dart';
import 'package:flutterdemo/drag_and_drop.dart';
import 'package:flutterdemo/fadein_image.dart';
import 'package:flutterdemo/flutter_animate.dart';
import 'package:flutterdemo/http_network.dart';
import 'package:flutterdemo/form_view.dart';
import 'package:flutterdemo/future_builder.dart';
import 'package:flutterdemo/grid_view.dart';
import 'package:flutterdemo/hello_world.dart';
import 'package:flutterdemo/hero_animation.dart';
import 'package:flutterdemo/layout_demo.dart';
import 'package:flutterdemo/list_view.dart';
import 'package:flutterdemo/list_wheel_scroll_view.dart';
import 'package:flutterdemo/long_list_view.dart';
import 'package:flutterdemo/movable_button.dart';
import 'package:flutterdemo/navigation_bar.dart';
import 'package:flutterdemo/page_view.dart';
import 'package:flutterdemo/parallex_recipe.dart';
import 'package:flutterdemo/passing_data.dart';
import 'package:flutterdemo/physics_card_drag_demo.dart';
import 'package:flutterdemo/progress_indicator.dart';
import 'package:flutterdemo/refresh_indicator.dart';
import 'package:flutterdemo/shortcuts.dart';
import 'package:flutterdemo/show_dialog.dart';
import 'package:flutterdemo/sliver_appbar.dart';
import 'package:flutterdemo/spaced_elements_list.dart';
import 'package:flutterdemo/staggered_animation.dart';
import 'package:flutterdemo/state_management.dart';
import 'package:flutterdemo/stepper.dart';
import 'package:flutterdemo/stream_builder.dart';
import 'package:flutterdemo/system_mouse_cursors.dart';
import 'package:flutterdemo/tab_view.dart';
import 'package:flutterdemo/transform_view.dart';

// Unfortunately, Flutter doesn't support reflection,
// otherwise we wouldn't need to write so much code here.
var _examples = [
  (HelloWorldApp.name, () => const HelloWorldApp()),
  (SystemMouseCursorsApp.name, () => const SystemMouseCursorsApp()),
  (MovableButtonApp.name, () => const MovableButtonApp()),
  (PassingDataApp.name, () => const PassingDataApp()),
  (AppleFeelApp.name, () => const AppleFeelApp()),
  (CustomPaintApp.name, () => const CustomPaintApp()),
  (HttpNetworkApp.name, () => const HttpNetworkApp()),
];
var _layoutExamples = [
  (MyListApp.name, () => const MyListApp()),
  (SliverAppBarApp.name, () => const SliverAppBarApp()),
  (MyLongListApp.name, () => const MyLongListApp()),
  (MyGridApp.name, () => const MyGridApp()),
  (TabApp.name, () => const TabApp()),
  (PageViewApp.name, () => const PageViewApp()),
  (NavigationBarApp.name, () => const NavigationBarApp()),
  (ListWheelScrollViewApp.name, () => const ListWheelScrollViewApp()),
  (SpacedListApp.name, () => const SpacedListApp()),
  (TheLayoutApp.name, () => const TheLayoutApp()),
  (CustomScrollApp.name, () => const CustomScrollApp()),
];
var _widgetExamples = [
  (ProgressIndicatorApp.name, () => const ProgressIndicatorApp()),
  (DismissibleItemsApp.name, () => const DismissibleItemsApp()),
  (ShowDialogApp.name, () => const ShowDialogApp()),
  (StepperApp.name, () => const StepperApp()),
  (FadeInImageApp.name, () => const FadeInImageApp()),
  (RefreshIndicatorApp.name, () => const RefreshIndicatorApp()),
  (ShortcutsApp.name, () => const ShortcutsApp()),
  (FutureBuilderApp.name, () => const FutureBuilderApp()),
  (StreamBuilderApp.name, () => const StreamBuilderApp()),
  (MyFormApp.name, () => const MyFormApp()),
  (DataTableApp.name, () => const DataTableApp()),
];
var _advancedExamples = [
  (ExampleDragAndDropApp.name, () => const ExampleDragAndDropApp()),
  (ParallaxRecipeApp.name, () => const ParallaxRecipeApp()),
  (ShoppingApp.name, () => const ShoppingApp()),
];
var _animationExamples = [
  (AnimationControllerApp.name, () => const AnimationControllerApp()),
  (AnimatedContainerApp.name, () => const AnimatedContainerApp()),
  (AnimatedOpacityApp.name, () => const AnimatedOpacityApp()),
  (AnimatedSwitcherApp.name, () => const AnimatedSwitcherApp()),
  (HeroAnimationApp.name, () => const HeroAnimationApp()),
  (AnimatedIconApp.name, () => const AnimatedIconApp()),
  (StaggeredAnimationApp.name, () => const StaggeredAnimationApp()),
  (TransformApp.name, () => const TransformApp()),
  (AnimatedListApp.name, () => const AnimatedListApp()),
  (PhysicsCardDragDemoApp.name, () => const PhysicsCardDragDemoApp()),
  (FlutterAnimateApp.name, () => const FlutterAnimateApp()),
];
var _totalExamples = [
  ..._examples,
  ..._layoutExamples,
  ..._widgetExamples,
  ..._advancedExamples,
  ..._animationExamples
];

// Global theme
var globalTheme = ValueNotifier<ThemeData>(ThemeData.light());

// Here are some templates for creating new pages

// MaterialApp template, requiring a Scaffold
class MyApp extends StatelessWidget {
  const MyApp({super.key, required this.scaffold});
  final Widget scaffold;

  @override
  Widget build(BuildContext context) {
    return ValueListenableBuilder(
      valueListenable: globalTheme,
      builder: (context, theme, child) => MaterialApp(
        title: 'Flutter Demo',
        theme: theme,
        home: scaffold,
        debugShowCheckedModeBanner: false,
      ),
    );
  }
}

// Scaffold template, requiring a scaffold body, should put in a MaterialApp
class MyScaffold extends StatelessWidget {
  const MyScaffold({
    super.key,
    required this.navName,
    required this.view,
    this.actions,
    this.floatingActionButton,
    this.navigationBar,
  });

  final String navName;
  final Widget view;
  final List<Widget>? actions;
  final Widget? floatingActionButton;
  final Widget? navigationBar;
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(navName),
        elevation: 1,
        actions: actions,
      ),
      drawer: myDrawer,
      bottomNavigationBar: navigationBar,
      floatingActionButton: floatingActionButton,
      body: view,
    );
  }
}

// template for a MaterialApp with a Scaffold using the above templates
class MyScaffoldApp extends StatelessWidget {
  const MyScaffoldApp({
    super.key,
    required this.navName,
    required this.view,
    this.actions,
    this.floatingActionButton,
    this.navigationBar,
  });

  final String navName;
  final Widget view;
  final List<Widget>? actions;
  final Widget? floatingActionButton;
  final Widget? navigationBar;

  @override
  Widget build(BuildContext context) {
    return ValueListenableBuilder(
      valueListenable: globalTheme,
      builder: (context, theme, child) => MyApp(
        scaffold: MyScaffold(
          navName: navName,
          actions: actions,
          floatingActionButton: floatingActionButton,
          navigationBar: navigationBar,
          view: view,
        ),
      ),
    );
  }
}

class MyAppleApp extends StatelessWidget {
  const MyAppleApp({super.key, required this.navName, required this.view});
  final String navName;
  final Widget view;

  @override
  Widget build(BuildContext context) {
    return CupertinoApp(
      debugShowCheckedModeBanner: false,
      title: navName,
      home: view,
    );
  }
}

class MyAppleScaffold extends StatelessWidget {
  const MyAppleScaffold({super.key, required this.navName, required this.view});
  final String navName;
  final Widget view;

  @override
  Widget build(BuildContext context) {
    return CupertinoPageScaffold(
      navigationBar: CupertinoNavigationBar(
        middle: Text(navName),
      ),
      child: view,
    );
  }
}

// Setting a global drawer instance
const myDrawer = MyDrawer();

int selectedIndexOfMyDrawer = 0;

class MyDrawer extends StatefulWidget {
  const MyDrawer({super.key});

  @override
  State<MyDrawer> createState() => _MyDrawerState();
}

class _MyDrawerState extends State<MyDrawer> {
  final _colors = [...Colors.primaries, ...Colors.accents];
  int _colorIndex = 0;

  @override
  void initState() {
    super.initState();
    _colorIndex = 0;
  }

  List<Widget> _buildDrawerItems(List<(String, Widget Function())> list) {
    return list
        .map(
          (e) => NavigationDrawerDestination(
            icon: Icon(
              _totalExamples.indexOf(e) == selectedIndexOfMyDrawer
                  ? Icons.circle
                  : Icons.circle_outlined,
              color: _colors[_colorIndex++ % _colors.length],
            ),
            label: Text(e.$1),
          ),
        )
        .toList();
  }

  Widget _buildDrawerHeader(String headerName) {
    return ListTile(
      title: Text(
        headerName,
        style: Theme.of(context).textTheme.titleMedium,
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    return NavigationDrawer(
      selectedIndex: selectedIndexOfMyDrawer,
      onDestinationSelected: (int index) {
        _colorIndex = 0;
        debugPrint('Drawer item $index clicked');
        Navigator.push(
          context,
          MaterialPageRoute(
            builder: (context) => _totalExamples[index].$2(),
          ),
        );
        setState(() {
          selectedIndexOfMyDrawer = index;
        });
      },
      children: [
        _buildDrawerHeader('Examples'),
        ..._buildDrawerItems(_examples),
        _buildDrawerHeader('Layout'),
        ..._buildDrawerItems(_layoutExamples),
        _buildDrawerHeader('Widgets'),
        ..._buildDrawerItems(_widgetExamples),
        _buildDrawerHeader('Advanced'),
        ..._buildDrawerItems(_advancedExamples),
        _buildDrawerHeader('Animations'),
        ..._buildDrawerItems(_animationExamples),
      ],
    );
  }
}
