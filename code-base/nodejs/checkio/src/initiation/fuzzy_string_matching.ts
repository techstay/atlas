import assert from "assert";

function fuzzyStringMatch(
	str1: string,
	str2: string,
	threshold: number,
): boolean {
	const n = Math.max(str1.length, str2.length);
	let differences = 0;

	for (let i = 0; i < n; i++) {
		if (str1[i] !== str2[i]) {
			differences++;
			if (differences > threshold) {
				return false;
			}
		}
	}
	return true;
}

console.log("Example:");
console.log(fuzzyStringMatch("apple", "appel", 2));

// These "asserts" are used for self-checking
assert.strictEqual(fuzzyStringMatch("apple", "appel", 2), true);
assert.strictEqual(fuzzyStringMatch("apple", "bpple", 1), true);
assert.strictEqual(fuzzyStringMatch("apple", "bpple", 0), false);
assert.strictEqual(fuzzyStringMatch("apple", "apples", 1), true);
assert.strictEqual(fuzzyStringMatch("apple", "bpples", 2), true);
assert.strictEqual(fuzzyStringMatch("apple", "apxle", 1), true);
assert.strictEqual(fuzzyStringMatch("apple", "pxxli", 3), false);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
