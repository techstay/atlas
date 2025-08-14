import assert from "assert";

function secondIndex(text: string, symbol: string): number | null {
	const firstIndex = text.indexOf(symbol);
	if (firstIndex === -1) return null;
	const secondIndex = text.indexOf(symbol, firstIndex + 1);
	return secondIndex === -1 ? null : secondIndex;
}

console.log("Example:");
console.log(secondIndex("sims", "s"));

// These "asserts" are used for self-checking
assert.strictEqual(secondIndex("sims", "s"), 3);
assert.strictEqual(secondIndex("find the river", "e"), 12);
assert.strictEqual(secondIndex("hi", " "), null);
assert.strictEqual(secondIndex("hi mayor", " "), null);
assert.strictEqual(secondIndex("hi mr Mayor", " "), 5);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
