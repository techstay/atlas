import assert from "assert";

function isLeapYear(year: number): boolean {
	return (year % 4 === 0 && year % 100 !== 0) || year % 400 === 0;
}

console.log("Example:");
console.log(isLeapYear(1891));

// These "asserts" are used for self-checking
assert.strictEqual(isLeapYear(2000), true);
assert.strictEqual(isLeapYear(1900), false);
assert.strictEqual(isLeapYear(2004), true);
assert.strictEqual(isLeapYear(2100), false);
assert.strictEqual(isLeapYear(2020), true);
assert.strictEqual(isLeapYear(2021), false);
assert.strictEqual(isLeapYear(1600), true);
assert.strictEqual(isLeapYear(1700), false);
assert.strictEqual(isLeapYear(1800), false);
assert.strictEqual(isLeapYear(2400), true);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
