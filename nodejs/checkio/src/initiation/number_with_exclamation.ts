import assert from "assert";

function factorial(n: number): number {
	return n === 0 ? 1 : n * factorial(n - 1);
}

console.log("Example:");
console.log(factorial(4));

// These "asserts" are used for self-checking
assert.strictEqual(factorial(0), 1);
assert.strictEqual(factorial(1), 1);
assert.strictEqual(factorial(5), 120);
assert.strictEqual(factorial(10), 3628800);
assert.strictEqual(factorial(15), 1307674368000);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
