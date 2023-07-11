import { error } from 'node:console'
import dns from 'node:dns'

dns.lookup('www.baidu.com', (err, address, family) => {
  if (err) {
    error(err)
  } else {
    console.log(`address: ${address}, family: IPv${family}`)
  }
})

dns.resolve6('www.google.com', (err, addresses) => {
  if (err) {
    error(err)
  } else {
    console.log(`address: ${addresses.join(', ')}`)
  }
})
