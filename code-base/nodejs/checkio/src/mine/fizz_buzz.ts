import assert from "assert";

function fizzBuzz(a: number): string {
	// your code here
	if (a % 3 === 0 && a % 5 === 0) {
		return "Fizz Buzz";
	} else if (a % 3 === 0) {
		return "Fizz";
	} else if (a % 5 === 0) {
		return "Buzz";
	} else {
		return a.toString();
	}
}

console.log("Example:");
console.log(fizzBuzz(15));

// These "asserts" are used for self-checking
assert.strictEqual(fizzBuzz(15), "Fizz Buzz");
assert.strictEqual(fizzBuzz(6), "Fizz");
assert.strictEqual(fizzBuzz(10), "Buzz");
assert.strictEqual(fizzBuzz(7), "7");

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
