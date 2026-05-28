import 'package:flutter/material.dart';
import 'package:flutter_test/flutter_test.dart';
import 'package:flutterdemo/hello_world.dart';
import 'package:integration_test/integration_test.dart';

void main() {
  IntegrationTestWidgetsFlutterBinding.ensureInitialized();

  group('end to end test', () {
    testWidgets('hello world widget test', (widgetTester) async {
      await widgetTester.pumpWidget(const HelloWorldApp());

      var widget = find.text('Hello Flutter World!');
      expect(widget, findsOneWidget);

      await widgetTester.tap(widget);
      await widgetTester.pump();
      expect(find.byType(SnackBar), findsOneWidget);
    });
  });
}
