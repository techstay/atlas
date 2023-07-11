import os from 'node:os'

console.log(`System uptime: ${os.uptime()}s`)
console.log(`${os.version()} ${os.arch()}`)
console.log(`${os.platform()} ${os.release()} ${os.machine()}`)
console.log(os.networkInterfaces())
