import assert from "assert";

function firstWord(text: string): string {
	return text.split(" ")[0];
}

console.log("Example:");
console.log(firstWord("Hello world"));

// These "asserts" are used for self-checking
assert.strictEqual(firstWord("Hello world"), "Hello");
assert.strictEqual(firstWord("a word"), "a");
assert.strictEqual(firstWord("greeting from CheckiO Planet"), "greeting");
assert.strictEqual(firstWord("hi"), "hi");

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
