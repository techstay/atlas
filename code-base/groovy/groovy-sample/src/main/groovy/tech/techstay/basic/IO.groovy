package tech.techstay.basic

import groovy.io.FileType

// reading files
def hostsPath = /C:\Windows\System32\drivers\etc\hosts/
def file = new File(hostsPath)
file.eachLine { line, nb ->
  println("$nb: $line")
}

// writing files
def path = "test.txt"
new File(path).withWriter {
  it.writeLine("hello")
  it.writeLine("nice")
}

// deleting files
new File(path).delete()

// traversing file tree
def dir = new File(/C:\Windows/)
dir.eachFile {}
dir.eachFileMatch(~/.+\.exe$/) {
  println(it)
}
dir.traverse(
  maxDepth: 0,
  filter: ~/.+\.exe$/,
  type: FileType.FILES
) {
  println(it.path.toUpperCase())
}
