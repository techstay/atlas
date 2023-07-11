import path from 'node:path'

const filePath = path.parse(String.raw`C:\Windows\System32\drivers\etc\hosts`)

console.log(filePath.dir)
console.log(filePath.base)
console.log(filePath.root)

