import assert from "assert";

const VOWELS = ["a", "e", "i", "o", "u"];

function countVowels(text: string): number {
	return text.split("").filter((char) => VOWELS.includes(char.toLowerCase()))
		.length;
}

console.log("Example:");
console.log(countVowels("Hello"));

// These "asserts" are used for self-checking
assert.strictEqual(countVowels("hello"), 2);
assert.strictEqual(countVowels("openai"), 4);
assert.strictEqual(countVowels("typescript"), 2);
assert.strictEqual(countVowels("a"), 1);
assert.strictEqual(countVowels("b"), 0);
assert.strictEqual(countVowels("aeiou"), 5);
assert.strictEqual(countVowels("AEIOU"), 5);
assert.strictEqual(countVowels("The quick brown fox"), 5);
assert.strictEqual(countVowels("Jumps over the lazy dog"), 6);
assert.strictEqual(countVowels(""), 0);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
