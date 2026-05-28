import assert from "assert";

function longestWord(sentence: string): string {
	return sentence.split(" ").reduce((longest, current) => {
		return current.length > longest.length ? current : longest;
	}, "");
}

console.log("Example:");
console.log(longestWord("hello world"));

// These "asserts" are used for self-checking
assert.strictEqual(longestWord("hello world"), "hello");
assert.strictEqual(longestWord("openai gpt-4"), "openai");
assert.strictEqual(longestWord("this is a sentence"), "sentence");
assert.strictEqual(longestWord("the quick brown fox"), "quick");
assert.strictEqual(longestWord("jumped over the lazy dog"), "jumped");
assert.strictEqual(longestWord("typescript is great"), "typescript");
assert.strictEqual(longestWord("the answer is 42"), "answer");
assert.strictEqual(longestWord("to be or not to be"), "not");
assert.strictEqual(longestWord("that is the question"), "question");
assert.strictEqual(longestWord(""), "");
assert.strictEqual(longestWord(" "), "");

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
