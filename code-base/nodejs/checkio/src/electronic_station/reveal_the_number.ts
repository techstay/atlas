import assert from "assert";

function revealNum(line: string): number | null {
	// TODO: Implement this function
	return null;
}

console.log("Example:");
console.log(revealNum("+A%+-1-0..."));

// These "asserts" are used for self-checking
assert.strictEqual(revealNum("F0(t}"), 0);
assert.strictEqual(revealNum("Utc&g"), null);
assert.strictEqual(revealNum("-aB%|_-+2ADS.12+3.ADS1.2"), 2.12312);
assert.strictEqual(revealNum("-aB%|_+-2ADS.12+3.ADS1.2"), -2.12312);
assert.strictEqual(revealNum("zV\u21161}3;o.vEf``C.WqTY0"), 13.0);
assert.strictEqual(
	revealNum("!3B'j=(}89JQ6aWvN*%5@uy.r)B<?pZ.!545ZD^KF9Sx@gqfa*"),
	38965.5459,
);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
