async function sleep (ms) {
  await new Promise((resolve) => {
    setTimeout(resolve, ms)
  })
}

async function longWork (value) {
  console.log('start')
  await sleep(1000)
  console.log(value)
}

await longWork('hello world')

// after finish long work
console.log('fished')
