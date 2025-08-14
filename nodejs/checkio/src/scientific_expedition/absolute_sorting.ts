import assert from "assert";

function absoluteSorting(values: number[]): number[] {
	return values.sort((a, b) => Math.abs(a) - Math.abs(b));
}

console.log("Example:");
console.log(JSON.stringify(absoluteSorting([-20, -5, 10, 15])));

// These "asserts" are used for self-checking
assert.deepStrictEqual(absoluteSorting([-20, -5, 10, 15]), [-5, 10, 15, -20]);
assert.deepStrictEqual(absoluteSorting([1, 2, 3, 0]), [0, 1, 2, 3]);
assert.deepStrictEqual(absoluteSorting([-1, -2, -3, 0]), [0, -1, -2, -3]);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
