let proxy = new Proxy({},
  {
    get: (target, propKey, receiver) => {
      console.log(`getting prop: ${propKey}`)
      return Reflect.get(target, propKey, receiver)
    },
    set: (target, propKey, propValue, receiver) => {
      console.log(`set prop: ${propKey}=${propValue}`)
      return Reflect.set(target, propKey, propValue, receiver)
    }
  })

proxy.name = 'john3'
console.log(proxy.name)

// upper case proxy
let person = { name: 'john3' }
let upperProxy = new Proxy(person, {
  get: (target, propKey, receiver) => Reflect.get(target, propKey, receiver).toUpperCase()
})

console.log(upperProxy.name)
