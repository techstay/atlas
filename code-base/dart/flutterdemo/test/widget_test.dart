import 'package:flutter/material.dart';
import 'package:flutter_test/flutter_test.dart';
import 'package:flutterdemo/hello_world.dart';
import 'package:flutterdemo/long_list_view.dart';

void main() {
  testWidgets('Hello world widget test', (WidgetTester tester) async {
    await tester.pumpWidget(const HelloWorldApp());
    var widget = find.text('Hello Flutter World!');

    expect(widget, findsOneWidget);

    await tester.tap(widget);
    await tester.pump();
    expect(find.byType(SnackBar), findsOneWidget);
  });

  testWidgets('Long list view widget test', (widgetTester) async {
    await widgetTester.pumpWidget(const MyLongListApp());
    final listFinder = find.byType(Scrollable);
    final itemFinder = find.byKey(const ValueKey('item_300_text'));

    await widgetTester.scrollUntilVisible(
      itemFinder,
      500,
      scrollable: listFinder,
      maxScrolls:
          1000, // default to 50, not enough in long lists, so specify to 1000
    );

    expect(itemFinder, findsOneWidget);
  });
}
