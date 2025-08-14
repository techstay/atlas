import assert from "assert";

function maxOfThree(a: number, b: number, c: number): number {
	return Math.max(a, b, c);
}

console.log("Example:");
console.log(maxOfThree(1, 2, 3));

// These "asserts" are used for self-checking
assert.strictEqual(maxOfThree(1, 2, 3), 3);
assert.strictEqual(maxOfThree(3, 2, 1), 3);
assert.strictEqual(maxOfThree(1, 3, 2), 3);
assert.strictEqual(maxOfThree(0, 0, 0), 0);
assert.strictEqual(maxOfThree(-1, -2, -3), -1);
assert.strictEqual(maxOfThree(5, 5, 4), 5);
assert.strictEqual(maxOfThree(-5, -5, -6), -5);
assert.strictEqual(maxOfThree(10, 9, 10), 10);
assert.strictEqual(maxOfThree(123, 456, 789), 789);
assert.strictEqual(maxOfThree(789, 123, 456), 789);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
