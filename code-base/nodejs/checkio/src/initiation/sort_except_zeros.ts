import assert from "assert";

function exceptZero(items: number[]): number[] {
	const nonZeroItems = items.filter((item) => item !== 0);
	nonZeroItems.sort((a, b) => a - b);
	return items.map((item) => (item === 0 ? 0 : nonZeroItems.shift()!));
}

console.log("Example:");
console.log(JSON.stringify(exceptZero([5, 3, 0, 0, 4, 1, 4, 0, 7])));

// These "asserts" are used for self-checking
assert.deepStrictEqual(
	exceptZero([5, 3, 0, 0, 4, 1, 4, 0, 7]),
	[1, 3, 0, 0, 4, 4, 5, 0, 7],
);
assert.deepStrictEqual(
	exceptZero([0, 2, 3, 1, 0, 4, 5]),
	[0, 1, 2, 3, 0, 4, 5],
);
assert.deepStrictEqual(exceptZero([0, 0, 0, 1, 0]), [0, 0, 0, 1, 0]);
assert.deepStrictEqual(exceptZero([4, 5, 3, 1, 1]), [1, 1, 3, 4, 5]);
assert.deepStrictEqual(exceptZero([0, 0]), [0, 0]);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
