async function sleep (ms) {
  await new Promise((resolve) => {
    setTimeout(resolve, ms)
  })
}

async function longWork (value) {
  await sleep(500)
  console.log(value)
}

await longWork('hello world')

// after finish long work
console.log('something')
