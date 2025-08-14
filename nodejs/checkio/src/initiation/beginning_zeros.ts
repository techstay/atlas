import assert from "assert";

function beginningZeros(a: string): number {
	return RegExp(/^0+/).exec(a)?.[0]?.length ?? 0;
}

console.log("Example:");
console.log(beginningZeros("10"));

// These "asserts" are used for self-checking
assert.strictEqual(beginningZeros("100"), 0);
assert.strictEqual(beginningZeros("001"), 2);
assert.strictEqual(beginningZeros("100100"), 0);
assert.strictEqual(beginningZeros("001001"), 2);
assert.strictEqual(beginningZeros("012345679"), 1);
assert.strictEqual(beginningZeros("0000"), 4);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
