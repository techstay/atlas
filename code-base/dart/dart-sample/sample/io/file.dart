import 'dart:io';

void main(List<String> args) async {
  // reading files
  var hosts = File(r'C:\Windows\system32\drivers\etc\hosts');
  var content = await hosts.readAsString();
  print(content);

  var lines = await hosts.readAsLines();
  print(lines.length);

  // writing files
  var file = File('output.txt');
  var sink = file.openWrite(mode: FileMode.write);
  sink.writeln('hello world!');
  sink.writeln('now is ${DateTime.now()}');
  await sink.flush();
  await sink.close();

  // deleting files
  file.delete();
}
