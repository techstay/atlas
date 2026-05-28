import assert from "assert";

function nearestValue(values: number[], s: number): number {
	const sorted = values.toSorted(
		(a, b) => Math.abs(a - s) - Math.abs(b - s) || a - b,
	);
	return sorted[0];
}

console.log("Example:");
console.log(nearestValue([4, 7, 10, 11, 12, 17], 9));

// These "asserts" are used for self-checking
assert.strictEqual(nearestValue([4, 7, 10, 11, 12, 17], 9), 10);
assert.strictEqual(nearestValue([4, 7, 10, 11, 12, 17], 8), 7);
assert.strictEqual(nearestValue([4, 8, 10, 11, 12, 17], 9), 8);
assert.strictEqual(nearestValue([4, 9, 10, 11, 12, 17], 9), 9);
assert.strictEqual(nearestValue([4, 7, 10, 11, 12, 17], 0), 4);
assert.strictEqual(nearestValue([4, 7, 10, 11, 12, 17], 100), 17);
assert.strictEqual(nearestValue([5, 10, 8, 12, 89, 100], 7), 8);
assert.strictEqual(nearestValue([-1, 2, 3], 0), -1);
assert.strictEqual(nearestValue([5], 5), 5);
assert.strictEqual(nearestValue([5], 7), 5);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
