let dice = new Map()

const N = 100000

for (let i = 0; i < N; i++) {
  let key = Math.floor(Math.random() * 6 + 1)
  let value = dice.get(key) || 1
  dice.set(key, value + 1)
}

console.log(dice)
