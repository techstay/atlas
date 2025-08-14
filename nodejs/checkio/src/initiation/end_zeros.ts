import assert from "assert";

function endZeros(a: number): number {
	let count = 0;
	while (a % 10 === 0) {
		count++;
		a = a / 10;
		if (a === 0) {
			break;
		}
	}
	return count;
}

console.log("Example:");
console.log(endZeros(10));

// These "asserts" are used for self-checking
assert.strictEqual(endZeros(0), 1);
assert.strictEqual(endZeros(1), 0);
assert.strictEqual(endZeros(10), 1);
assert.strictEqual(endZeros(101), 0);
assert.strictEqual(endZeros(245), 0);
assert.strictEqual(endZeros(100100), 2);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
