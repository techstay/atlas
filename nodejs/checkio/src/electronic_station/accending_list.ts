import assert from "assert";

function isAscending(values: number[]): boolean {
	for (let i = 1; i < values.length; i++) {
		if (values[i] <= values[i - 1]) {
			return false;
		}
	}
	return true;
}

console.log("Example:");
console.log(isAscending([-5, 10, 99, 123456]));

// These "asserts" are used for self-checking
assert.strictEqual(isAscending([-5, 10, 99, 123456]), true);
assert.strictEqual(isAscending([99]), true);
assert.strictEqual(isAscending([4, 5, 6, 7, 3, 7, 9]), false);
assert.strictEqual(isAscending([]), true);
assert.strictEqual(isAscending([1, 1, 1, 1]), false);
assert.strictEqual(isAscending([1, 3, 3, 5]), false);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
