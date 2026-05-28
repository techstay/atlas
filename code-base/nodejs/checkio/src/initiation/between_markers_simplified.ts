import assert from "assert";

function betweenMarkers(text: string, start: string, end: string): string {
	let startIndex = 0;
	let endIndex = 0;
	for (let i = 0; i < text.length; i++) {
		if (text[i] === start) {
			startIndex = i + 1;
		}
		if (text[i] === end) {
			endIndex = i;
			break;
		}
	}
	return text.slice(startIndex, endIndex);
}

console.log("Example:");
console.log(betweenMarkers("What is >apple<", ">", "<"));

// These "asserts" are used for self-checking
assert.strictEqual(betweenMarkers("What is >apple<", ">", "<"), "apple");
assert.strictEqual(betweenMarkers("What is [apple]", "[", "]"), "apple");
assert.strictEqual(betweenMarkers("What is ><", ">", "<"), "");
assert.strictEqual(betweenMarkers("[an apple]", "[", "]"), "an apple");

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
