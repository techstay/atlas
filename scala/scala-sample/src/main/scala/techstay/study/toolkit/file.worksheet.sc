// constructing a path
val root = os.root
val hostsPath = os.root / "windows" / "system32" / "drivers" / "etc" / "hosts"

// listing files
val systemPath = os.root / "windows"
os.list(systemPath).filter(os.isFile).filter(_.ext == "exe")

// reading files
val hostsContent = os.read(hostsPath)
// reading by lines
val hostsContentLines = os.read.lines(hostsPath)
println(hostsContentLines(0))

// writing files
val tempFile = os.temp.dir() / "temp.txt"
val content = """abc
def
ghi
"""

os.write.over(tempFile, content)
