import assert from "assert";

function isAllUpper(text: string): boolean {
	if (!/[a-zA-Z]/.test(text)) {
		return false;
	}
	return text === text.toUpperCase();
}

console.log("Example:");
console.log(isAllUpper("ALL UPPER"));

// These "asserts" are used for self-checking
assert.strictEqual(isAllUpper("ALL UPPER"), true);
assert.strictEqual(isAllUpper("all lower"), false);
assert.strictEqual(isAllUpper("mixed UPPER and lower"), false);
assert.strictEqual(isAllUpper(""), false);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
