import assert from "assert";

function countDivisible(n: number, k: number): number {
	let count = 0;
	for (let i = 1; i * k <= n; i++) {
		count++;
	}
	return count;
}

console.log("Example:");
console.log(countDivisible(2, 1));

// These "asserts" are used for self-checking
assert.strictEqual(countDivisible(10, 2), 5);
assert.strictEqual(countDivisible(10, 3), 3);
assert.strictEqual(countDivisible(10, 5), 2);
assert.strictEqual(countDivisible(15, 4), 3);
assert.strictEqual(countDivisible(20, 6), 3);
assert.strictEqual(countDivisible(100, 10), 10);
assert.strictEqual(countDivisible(200, 25), 8);
assert.strictEqual(countDivisible(50, 7), 7);
assert.strictEqual(countDivisible(60, 8), 7);
assert.strictEqual(countDivisible(70, 9), 7);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
