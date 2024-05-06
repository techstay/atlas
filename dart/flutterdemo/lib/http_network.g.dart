// GENERATED CODE - DO NOT MODIFY BY HAND

part of 'http_network.dart';

// **************************************************************************
// JsonSerializableGenerator
// **************************************************************************

Hitokoto _$HitokotoFromJson(Map<String, dynamic> json) => Hitokoto(
      id: (json['id'] as num).toInt(),
      hitokoto: json['hitokoto'] as String,
      type: json['type'] as String,
      from: json['from'] as String,
      fromWho: json['from_who'] as String?,
    );

Map<String, dynamic> _$HitokotoToJson(Hitokoto instance) => <String, dynamic>{
      'id': instance.id,
      'hitokoto': instance.hitokoto,
      'type': instance.type,
      'from': instance.from,
      'from_who': instance.fromWho,
    };
