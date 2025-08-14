import assert from "assert";

function longestPrefix(arr: string[]): string {
	const shortestStringLength = arr
		.map((str) => str.length)
		.reduce((min, len) => Math.min(min, len), Infinity);
	let prefix = "";

	for (let i = 0; i < shortestStringLength; i++) {
		const currentChar = arr[0][i];
		if (arr.every((str) => str[i] === currentChar)) {
			prefix += currentChar;
		} else {
			break;
		}
	}

	return prefix;
}

console.log("Example:");
console.log(JSON.stringify(longestPrefix(["flower", "flow", "flight"])));

// These "asserts" are used for self-checking
assert.strictEqual(longestPrefix(["flower", "flow", "flight"]), "fl");
assert.strictEqual(longestPrefix(["dog", "racecar", "car"]), "");
assert.strictEqual(longestPrefix(["apple", "application", "appetizer"]), "app");
assert.strictEqual(longestPrefix(["a"]), "a");
assert.strictEqual(longestPrefix(["", "b"]), "");
assert.strictEqual(longestPrefix(["same", "same", "same"]), "same");
assert.strictEqual(longestPrefix(["mismatch", "mister", "miss"]), "mis");
assert.strictEqual(longestPrefix(["alphabet", "alpha", "alphadog"]), "alpha");
assert.strictEqual(longestPrefix(["book", "boot", "booster"]), "boo");
assert.strictEqual(longestPrefix(["short", "shore", "shot"]), "sho");

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
