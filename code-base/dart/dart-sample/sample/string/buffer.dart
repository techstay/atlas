void main(List<String> args) {
  var sb = StringBuffer();
  sb.write('XXX');
  sb.write('YYY');
  sb.writeAll('a,b,c,d,e'.split(','));
  print(sb.toString());
}
