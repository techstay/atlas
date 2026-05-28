import 'package:chinese_font_library/chinese_font_library.dart';
import 'package:dio/dio.dart';
import 'package:flutter/material.dart';
import 'package:flutterdemo/shared_component.dart';
import 'package:json_annotation/json_annotation.dart';
import 'package:worker_manager/worker_manager.dart';

part 'http_network.g.dart';

class HttpNetworkApp extends StatefulWidget {
  const HttpNetworkApp({super.key});
  static const name = 'Fetching Data';

  @override
  State<HttpNetworkApp> createState() => _HttpNetworkAppState();
}

final dio = Dio();

class _HttpNetworkAppState extends State<HttpNetworkApp> {
  static String hitokotoUrl = 'https://international.v1.hitokoto.cn';
  final List<Hitokoto> _hitokotos = [];
  final GlobalKey<AnimatedListState> _listKey = GlobalKey<AnimatedListState>();
  final ScrollController _scrollController = ScrollController();

  @override
  Widget build(BuildContext context) {
    return MyScaffoldApp(
      navName: HttpNetworkApp.name,
      view: AnimatedList(
        key: _listKey,
        initialItemCount: _hitokotos.length,
        controller: _scrollController,
        itemBuilder: (context, index, animation) {
          return _buildHitokoto(context, index, animation);
        },
      ),
      actions: [
        IconButton(
          onPressed: fetchData,
          icon: const Icon(Icons.add),
        )
      ],
    );
  }

  void fetchData() async {
    Cancelable<Hitokoto> task = workerManager.execute<Hitokoto>(
      () async {
        var response = await dio.get('$hitokotoUrl/?encode=json&charset=utf-8');
        return Hitokoto.fromJson(response.data);
      },
      priority: WorkPriority.immediately,
    );

    task.then((hitokoto) {
      setState(() {
        _hitokotos.add(hitokoto);
        _listKey.currentState!.insertItem(_hitokotos.length - 1);
      });

      WidgetsBinding.instance.addPostFrameCallback((_) {
        _scrollController.animateTo(
          _scrollController.position.maxScrollExtent,
          duration: const Duration(milliseconds: 300),
          curve: Curves.easeOut,
        );
      });
    }).onError((error, stackTrace) {
      debugPrint(error.toString());
    });
  }

  Widget _buildHitokoto(
      BuildContext context, int index, Animation<double> animation) {
    return ScaleTransition(
      scale: animation,
      child: Card(
        child: DefaultTextStyle(
          style: Theme.of(context).textTheme.bodyLarge!.useSystemChineseFont(),
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              Padding(
                padding:
                    const EdgeInsets.symmetric(vertical: 8, horizontal: 14),
                child: Text(_hitokotos[index].hitokoto),
              ),
              if (_hitokotos[index].fromWho != null)
                Padding(
                  padding:
                      const EdgeInsets.symmetric(vertical: 8, horizontal: 14),
                  child: Row(
                    mainAxisAlignment: MainAxisAlignment.end,
                    children: [
                      Text(
                        '-- ${_hitokotos[index].from}',
                        textAlign: TextAlign.right,
                      ),
                    ],
                  ),
                ),
            ],
          ),
        ),
      ),
    );
  }
}

@JsonSerializable()
class Hitokoto {
  int id;
  String hitokoto;
  String type;
  String from;
  @JsonKey(name: 'from_who')
  String? fromWho;

  Hitokoto({
    required this.id,
    required this.hitokoto,
    required this.type,
    required this.from,
    this.fromWho,
  });

  factory Hitokoto.fromJson(Map<String, dynamic> json) =>
      _$HitokotoFromJson(json);
  Map<String, dynamic> toJson() => _$HitokotoToJson(this);
}
