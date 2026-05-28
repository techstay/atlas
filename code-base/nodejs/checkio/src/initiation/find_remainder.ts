import assert from "assert";

function findRemainder(dividend: number, divisor: number): number {
	return dividend % divisor;
}

console.log("Example:");
console.log(findRemainder(3, 2));

// These "asserts" are used for self-checking
assert.strictEqual(findRemainder(10, 3), 1);
assert.strictEqual(findRemainder(14, 4), 2);
assert.strictEqual(findRemainder(27, 4), 3);
assert.strictEqual(findRemainder(10, 5), 0);
assert.strictEqual(findRemainder(10, 1), 0);
assert.strictEqual(findRemainder(5, 7), 5);
assert.strictEqual(findRemainder(7, 5), 2);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
