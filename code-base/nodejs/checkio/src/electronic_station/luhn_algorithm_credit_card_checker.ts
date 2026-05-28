import assert from "assert";

function checker(card: string): boolean {
	const digits = card.replaceAll(/\s+/g, "").split("").map(Number);
	const sum = digits
		.toReversed()
		.map((digit, index) => {
			if (index % 2 === 1) {
				const doubled = digit * 2;
				return doubled > 9 ? doubled - 9 : doubled;
			}
			return digit;
		})
		.reduce((sum, digit) => sum + digit, 0);
	return sum % 10 === 0;
}

console.log("Example:");
console.log(checker("4137 8947 1175 5904"));

// These "asserts" are used for self-checking
assert.strictEqual(checker("4137 8947 1175 5904"), true);
assert.strictEqual(checker("5468 1234 5678 9123"), false);
assert.strictEqual(checker("4539 1488 0343 6467"), true);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
