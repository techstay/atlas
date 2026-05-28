void main(List<String> args) {
  var uri = 'http://localhost:8080/api?name=techstay?msg=hello world';
  var encoded = Uri.encodeFull(uri);
  print(encoded);
  print(Uri.decodeFull(encoded));

  encoded = Uri.encodeComponent(uri);
  print(encoded);
  print(Uri.decodeComponent(encoded));

  // parsing uris
  var uriObject = Uri.parse(uri);
  print(uriObject.scheme);
  print(uriObject.host);
  print(uriObject.port);
  print(uriObject.path);
  print(uriObject.origin);

  // building uris
  print(Uri.http('localhost', '/api', {
    'name': 'techstay',
    'msg': 'hello world',
  }));
}
