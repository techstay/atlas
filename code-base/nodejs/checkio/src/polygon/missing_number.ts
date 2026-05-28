import assert from "assert";

function missingNumber(items: number[]): number {
	const sorted = items.toSorted((a, b) => a - b);
	const min = sorted[0];
	const max = sorted[sorted.length - 1];
	const d = (max - min) / sorted.length;
	let expected = 0;
	for (let i = 0; i < sorted.length - 1; i++) {
		expected = min + i * d;
		if (sorted[i] !== expected) return expected;
	}
	return expected;
}

console.log("Example:");
console.log(missingNumber([1, 4, 2, 5]));

// These "asserts" are used for self-checking
assert.strictEqual(missingNumber([1, 4, 2, 5]), 3);
assert.strictEqual(missingNumber([2, 6, 8]), 4);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
