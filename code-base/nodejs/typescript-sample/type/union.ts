// union types

function numberOrString (param: number | string) {
  if (typeof param === 'number') {
    console.log(`number: ${param}`)
  } else {
    console.log(`string: ${param}`)
  }
}

numberOrString(42)
numberOrString('Hello')
// invalid parameters
// numberOrString(true)
