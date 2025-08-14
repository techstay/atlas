import assert from "assert";

function isAcceptablePassword(password: string): boolean {
	const cond1 = password.length > 6;
	let cond2 = /\d/.test(password) && /\D/.test(password);
	if (password.length > 9) {
		cond2 = true;
	}
	const cond4 = !/password/i.test(password);
	return cond1 && cond2 && cond4;
}

console.log("Example:");
console.log(isAcceptablePassword("short"));

// These "asserts" are used for self-checking
assert.strictEqual(isAcceptablePassword("short"), false);
assert.strictEqual(isAcceptablePassword("short54"), true);
assert.strictEqual(isAcceptablePassword("muchlonger"), true);
assert.strictEqual(isAcceptablePassword("ashort"), false);
assert.strictEqual(isAcceptablePassword("muchlonger5"), true);
assert.strictEqual(isAcceptablePassword("sh5"), false);
assert.strictEqual(isAcceptablePassword("1234567"), false);
assert.strictEqual(isAcceptablePassword("12345678910"), true);
assert.strictEqual(isAcceptablePassword("password12345"), false);
assert.strictEqual(isAcceptablePassword("PASSWORD12345"), false);
assert.strictEqual(isAcceptablePassword("pass1234word"), true);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
