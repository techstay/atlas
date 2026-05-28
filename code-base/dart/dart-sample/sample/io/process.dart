import 'dart:io';

void main(List<String> args) async {
  var result = await Process.run('cmd.exe', ['/c', 'dir']);
  print(result.stdout);

  result = await Process.run('powershell.exe',
      ['-Command', '& {Get-Process | Select-Object ProcessName -First 5}']);
  print(result.stdout);
}
