void main(List<String> args) async {
  print('start fetching data...');
  var data = await fetchData();
  print(data);
}

Future<String> fetchData() async {
  return Future.delayed(Duration(seconds: 2), () => 'data');
}
