// regular expressions
let pattern1 = /abc/g
let result = 'abc abc'.matchAll(pattern1)
for (let r of result) {
  console.log(r)
}

// named groups
let pattern2 = /(?<year>\d{4})-(?<month>\d{2})-(?<day>\d{2})/
result = pattern2.exec('2002-12-24')
console.log(result.groups)
