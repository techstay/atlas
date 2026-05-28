import 'dart:developer';

import 'package:flutter/material.dart';
import 'package:flutterdemo/shared_component.dart';

class MyLongListApp extends StatelessWidget {
  static const name = 'Long List View';

  const MyLongListApp({super.key});

  @override
  Widget build(BuildContext context) {
    return const MyScaffoldApp(
      navName: name,
      view: MyLongListView(),
    );
  }
}

class MyLongListView extends StatelessWidget {
  const MyLongListView({super.key});

  @override
  Widget build(BuildContext context) {
    var items = List.generate(300, (index) => 'item ${index + 1}');
    return ListView.builder(
      key: const Key('long list'),
      addAutomaticKeepAlives: true,
      itemCount: items.length,
      prototypeItem: LongListItem(items.first),
      itemBuilder: (context, index) {
        debugPrint('Building item ${index + 1}');
        return LongListItem(items[index]);
      },
    );
  }
}

class LongListItem extends StatefulWidget {
  const LongListItem(this.item, {super.key});

  final String item;

  @override
  State<LongListItem> createState() => _LongListItemState();
}

class _LongListItemState extends State<LongListItem>
    with AutomaticKeepAliveClientMixin {
  @override
  Widget build(BuildContext context) {
    // must call the super build method
    super.build(context);

    return ListTile(
      title: Text(
        widget.item,
        key: Key(
          '${widget.item}_text'.replaceAll(' ', '_'),
        ),
      ),
      onTap: () {
        log('Tapped: ${widget.item}');
      },
    );
  }

  @override
  bool get wantKeepAlive => true;
}
