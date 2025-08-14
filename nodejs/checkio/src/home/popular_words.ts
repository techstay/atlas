import assert from "assert";

function popularWords(text: string, words: string[]) {
	const wordCount: Record<string, number> = {};
	const normalizedText = text.toLowerCase();

	words.forEach((word) => {
		const regex = new RegExp(`\\b${word}\\b`, "g");
		wordCount[word] = (normalizedText.match(regex) || []).length;
	});

	return wordCount;
}

console.log("Example:");
console.log(
	JSON.stringify(
		popularWords(
			`
When I was One
I had just begun
When I was Two
I was nearly new`,
			["i", "was", "three", "near"],
		),
	),
);

// These "asserts" are used for self-checking
assert.deepStrictEqual(
	popularWords(
		"\nWhen I was One\nI had just begun\nWhen I was Two\nI was nearly new\n",
		["i", "was", "three", "near"],
	),
	{ i: 4, was: 3, three: 0, near: 0 },
);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
