import 'dart:convert';
import 'dart:io';

void main(List<String> args) async {
  var url = Uri.parse('https://httpbin.org/get?name=techstay&msg=hello+world');
  var httpClient = HttpClient();
  var request = await httpClient.getUrl(url);
  var response = await request.close();
  var data = await utf8.decoder.bind(response).toList();
  print('status code: ${response.statusCode}');
  print(data.join());
  httpClient.close();
}
