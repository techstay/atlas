// generator functions
function* integers () {
  for (let i = 1; i <= 5; i++) {
    yield i
  }
}

for (let i of integers()) {
  console.log(i)
}
