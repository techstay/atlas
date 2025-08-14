import assert from "assert";

function isArmstrong(num: number): boolean {
	const digits = String(num).split("").map(Number);
	const power = digits.length;
	const sum = digits.reduce((acc, digit) => acc + digit ** power, 0);
	return sum === num;
}

console.log("Example:");
console.log(isArmstrong(11));

// These "asserts" are used for self-checking
assert.strictEqual(isArmstrong(153), true);
assert.strictEqual(isArmstrong(370), true);
assert.strictEqual(isArmstrong(947), false);
assert.strictEqual(isArmstrong(371), true);
assert.strictEqual(isArmstrong(407), true);
assert.strictEqual(isArmstrong(163), false);
assert.strictEqual(isArmstrong(100), false);
assert.strictEqual(isArmstrong(8208), true);
assert.strictEqual(isArmstrong(930), false);
assert.strictEqual(isArmstrong(4), true);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
