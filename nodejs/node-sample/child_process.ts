import { spawn } from 'node:child_process'

const ls = spawn('ls', ['-la'])

console.log(`child process pid is ${ls.pid}`)

ls.stdout.on('data', (data) => {
  console.log(data.toString())
})

ls.on('close', (code) => {
  console.log(`child process exited with code ${code}`)
})
