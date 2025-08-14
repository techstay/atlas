import assert from "assert";

function replaceFirst(values: number[]): number[] {
	return values.length > 0 ? [...values.slice(1), values[0]] : [];
}

console.log("Example:");
console.log(JSON.stringify(replaceFirst([1, 2, 3, 4])));

// These "asserts" are used for self-checking
assert.deepStrictEqual(replaceFirst([1, 2, 3, 4]), [2, 3, 4, 1]);
assert.deepStrictEqual(replaceFirst([1]), [1]);
assert.deepStrictEqual(replaceFirst([]), []);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
