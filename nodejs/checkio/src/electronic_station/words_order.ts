import assert from "assert";

function wordsOrder(text: string, words: string[]): boolean {
	const textWords = text.split(" ");
	const indices: number[] = [];

	for (const word of words) {
		let index = textWords.indexOf(word);
		if (index === -1) {
			for (let i = 0; i < textWords.length; i++) {
				if (textWords[i].includes(word)) {
					index = i;
					break;
				}
			}
			if (index === -1) {
				return false;
			}
		}
		if (indices.includes(index)) {
			return false;
		}
		indices.push(index);
	}

	for (let i = 1; i < indices.length; i++) {
		if (indices[i] <= indices[i - 1]) {
			return false;
		}
	}

	return true;
}

console.log("Example:");
console.log(wordsOrder("hi world im here", ["world", "here"]));

// These "asserts" are used for self-checking
assert.strictEqual(wordsOrder("hi world im here", ["world", "here"]), true);
assert.strictEqual(wordsOrder("hi world im here", ["here", "world"]), false);
assert.strictEqual(wordsOrder("hi world im here", ["world"]), true);
assert.strictEqual(
	wordsOrder("hi world im here", ["world", "here", "hi"]),
	false,
);
assert.strictEqual(
	wordsOrder("hi world im here", ["world", "im", "here"]),
	true,
);
assert.strictEqual(
	wordsOrder("hi world im here", ["world", "hi", "here"]),
	false,
);
assert.strictEqual(wordsOrder("hi world im here", ["world", "world"]), false);
assert.strictEqual(wordsOrder("hi world im here", ["country", "world"]), false);
assert.strictEqual(wordsOrder("hi world im here", ["wo", "rld"]), false);
assert.strictEqual(wordsOrder("", ["world", "here"]), false);
assert.strictEqual(
	wordsOrder("hi world world im here", ["world", "world"]),
	false,
);
assert.strictEqual(
	wordsOrder("hi world world im here hi world world im here", [
		"world",
		"here",
	]),
	true,
);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
