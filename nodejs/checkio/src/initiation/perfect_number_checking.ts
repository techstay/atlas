import assert from "assert";

function isPerfect(n: number): boolean {
	let sum = 0;
	for (let i = 1; i <= n / 2; i++) {
		if (n % i === 0) {
			sum += i;
		}
	}
	return sum === n;
}

console.log("Example:");
console.log(isPerfect(3));

// These "asserts" are used for self-checking
assert.strictEqual(isPerfect(6), true);
assert.strictEqual(isPerfect(2), false);
assert.strictEqual(isPerfect(28), true);
assert.strictEqual(isPerfect(20), false);
assert.strictEqual(isPerfect(496), true);
assert.strictEqual(isPerfect(30), false);
assert.strictEqual(isPerfect(8128), true);
assert.strictEqual(isPerfect(100), false);
assert.strictEqual(isPerfect(500), false);
assert.strictEqual(isPerfect(1000), false);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
