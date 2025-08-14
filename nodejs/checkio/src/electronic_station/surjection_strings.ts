import assert from "assert";

function isometricStrings(line1: string, line2: string): boolean {
	if (line1.length !== line2.length) {
		return false;
	}
	const map = new Map<string, string>();
	for (let i = 0; i < line1.length; i++) {
		if (map.has(line1[i])) {
			if (map.get(line1[i]) !== line2[i]) {
				return false;
			}
		} else {
			map.set(line1[i], line2[i]);
		}
	}
	return true;
}

console.log("Example:");
console.log(isometricStrings("add", "egg"));

// These "asserts" are used for self-checking
assert.strictEqual(isometricStrings("add", "egg"), true);
assert.strictEqual(isometricStrings("foo", "bar"), false);
assert.strictEqual(isometricStrings("bar", "foo"), true);
assert.strictEqual(isometricStrings("", ""), true);
assert.strictEqual(isometricStrings("all", "all"), true);
assert.strictEqual(isometricStrings("gogopy", "doodle"), false);
assert.strictEqual(isometricStrings("abba", "cccc"), true);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
