import assert from "assert";

function backwardString(value: string): string {
	return value.split("").reverse().join("");
}

console.log("Example:");
console.log(backwardString("val"));

// These "asserts" are used for self-checking
assert.strictEqual(backwardString("val"), "lav");
assert.strictEqual(backwardString(""), "");
assert.strictEqual(backwardString("ohho"), "ohho");
assert.strictEqual(backwardString("123456789"), "987654321");

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
