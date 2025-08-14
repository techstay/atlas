import assert from "assert";

function threeWords(text: string): boolean {
  let count = 0;
  for (const str of text.split(" ")) {
    if (/\d/.test(str)) {
      count = 0;
    } else {
      count++;
    }
    if (count === 3) {
      return true;
    }
  }
  return false;
}

console.log("Example:");
console.log(threeWords("Hello World hello"));

// These "asserts" are used for self-checking
assert.strictEqual(threeWords("Hello World hello"), true);
assert.strictEqual(threeWords("He is 123 man"), false);
assert.strictEqual(threeWords("1 2 3 4"), false);
assert.strictEqual(threeWords("bla bla bla bla"), true);
assert.strictEqual(threeWords("Hi"), false);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
