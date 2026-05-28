import assert from "assert";

function isMajority(items: boolean[]): boolean {
	const trueCount = items.filter(Boolean).length;
	return trueCount > items.length / 2;
}

console.log("Example:");
console.log(isMajority([true, true, false, true, false]));

// These "asserts" are used for self-checking
assert.strictEqual(isMajority([true, true, false, true, false]), true);
assert.strictEqual(isMajority([true, true, false]), true);
assert.strictEqual(isMajority([true, true, false, false]), false);
assert.strictEqual(isMajority([true, true, false, false, false]), false);
assert.strictEqual(isMajority([false]), false);
assert.strictEqual(isMajority([true]), true);
assert.strictEqual(isMajority([]), false);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
