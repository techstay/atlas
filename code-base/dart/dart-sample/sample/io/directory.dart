import 'package:path/path.dart' as path;
import 'dart:io';

void main(List<String> args) async {
  // getting project directory path
  var dir = path.current;
  while (path.basename(dir) != 'dart-sample') {
    dir = Directory(dir).parent.path;
  }

  // iterating file trees and counting all dart files
  var fileList = Directory(dir).listSync(recursive: true);
  var dartFiles =
      fileList.where((f) => f is File && path.extension(f.path) == '.dart');
  print('Found ${dartFiles.length} dart files:');
  for (var file in dartFiles) {
    print('  ${path.relative(file.path, from: dir)}');
  }
}
