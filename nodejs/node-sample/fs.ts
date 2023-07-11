// file systems

import { error } from 'console'
import { readFile } from 'fs/promises'

// reading hosts file
const hostsPath = String.raw`C:\Windows\System32\drivers\etc\hosts`

try {
  const content = await readFile(hostsPath, { encoding: 'utf-8' })
  console.log(content)
} catch (err) {
  error(err)
}
