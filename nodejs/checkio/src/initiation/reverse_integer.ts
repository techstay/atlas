import assert from "assert";

function reverseDigits(num: number): number {
	const reversed = parseInt(num.toString().split("").reverse().join(""), 10);
	return num < 0 ? -reversed : reversed;
}

console.log("Example:");
console.log(reverseDigits(32));

// These "asserts" are used for self-checking
assert.strictEqual(reverseDigits(1234), 4321);
assert.strictEqual(reverseDigits(0), 0);
assert.strictEqual(reverseDigits(-123), -321);
assert.strictEqual(reverseDigits(5), 5);
assert.strictEqual(reverseDigits(-9), -9);
assert.strictEqual(reverseDigits(100), 1);
assert.strictEqual(reverseDigits(-100), -1);
assert.strictEqual(reverseDigits(54321), 12345);
assert.strictEqual(reverseDigits(1111), 1111);
assert.strictEqual(reverseDigits(987654321), 123456789);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
