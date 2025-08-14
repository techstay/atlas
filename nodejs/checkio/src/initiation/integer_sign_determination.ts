import assert from "assert";

function determineSign(num: number): string {
	if (num > 0) {
		return "positive";
	} else if (num < 0) {
		return "negative";
	} else {
		return "zero";
	}
}

console.log("Example:");
console.log(determineSign(11));

// These "asserts" are used for self-checking
assert.strictEqual(determineSign(5), "positive");
assert.strictEqual(determineSign(0), "zero");
assert.strictEqual(determineSign(-10), "negative");
assert.strictEqual(determineSign(1), "positive");
assert.strictEqual(determineSign(-1), "negative");
assert.strictEqual(determineSign(999), "positive");
assert.strictEqual(determineSign(-1000), "negative");
assert.strictEqual(determineSign(123456789), "positive");
assert.strictEqual(determineSign(-987654321), "negative");
assert.strictEqual(determineSign(2), "positive");

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
