function doIt (work: () => void) {
  work()
}

doIt(() => {
  console.log('do something')
})

function doWork (work: (param: string) => string, param: string) {
  console.log(work(param))
}

doWork(e => e.toUpperCase(), 'jack')
