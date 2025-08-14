import assert from "assert";

function sumUptoN(N: number): number {
	let sum = 0;
	for (let i = 1; i <= N; i++) {
		sum += i;
	}
	return sum;
}

console.log("Example:");
console.log(sumUptoN(11));

// These "asserts" are used for self-checking
assert.strictEqual(sumUptoN(1), 1);
assert.strictEqual(sumUptoN(2), 3);
assert.strictEqual(sumUptoN(3), 6);
assert.strictEqual(sumUptoN(4), 10);
assert.strictEqual(sumUptoN(5), 15);
assert.strictEqual(sumUptoN(10), 55);
assert.strictEqual(sumUptoN(20), 210);
assert.strictEqual(sumUptoN(100), 5050);
assert.strictEqual(sumUptoN(200), 20100);
assert.strictEqual(sumUptoN(500), 125250);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
