// use promises for concurrency work

console.log('start doing...')

let work = new Promise((resolve, reject) => {
  console.log('doing something')
  resolve('good result')
  reject('bad result')
})

work.then((value) => {
  console.log('finish work successfully')
  console.log(value)
}).catch((error) => {
  console.log('finish work with errors:')
  console.log(error)
}).finally(() => {
  console.log('finally do something')
})
