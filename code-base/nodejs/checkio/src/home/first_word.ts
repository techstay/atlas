import assert from "assert";

function firstWord(text: string): string {
  const words = text.split(/[\s,.]+/);
  let first = "";
  for (const str of words) {
    if (/\w/.test(str)) {
      first = str;
      break;
    }
  }
  return first;
}

console.log("Example:");
console.log(firstWord("Hello world"));

// These "asserts" are used for self-checking
assert.strictEqual(firstWord("Hello world"), "Hello");
assert.strictEqual(firstWord(" a word "), "a");
assert.strictEqual(firstWord("don't touch it"), "don't");
assert.strictEqual(firstWord("greetings, friends"), "greetings");
assert.strictEqual(firstWord("... and so on ..."), "and");
assert.strictEqual(firstWord("hi"), "hi");

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
