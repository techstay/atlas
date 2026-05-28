import assert from "assert";

function splitList<T>(values: T[]): [T[], T[]] {
	const splitAt = Math.ceil(values.length / 2);
	return [values.slice(0, splitAt), values.slice(splitAt)];
}

console.log("Example:");
console.log(JSON.stringify(splitList([1, 2, 3, 4, 5, 6])));

// These "asserts" are used for self-checking
assert.deepStrictEqual(splitList([1, 2, 3, 4, 5, 6]), [
	[1, 2, 3],
	[4, 5, 6],
]);
assert.deepStrictEqual(splitList([1, 2, 3]), [[1, 2], [3]]);
assert.deepStrictEqual(
	splitList(["banana", "apple", "orange", "cherry", "watermelon"]),
	[
		["banana", "apple", "orange"],
		["cherry", "watermelon"],
	],
);
assert.deepStrictEqual(splitList([1]), [[1], []]);
assert.deepStrictEqual(splitList([]), [[], []]);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
