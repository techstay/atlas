import assert from "assert";

function nonUniqueElements(data: number[]): number[] {
	const frequency: Record<number, number> = {};
	data.forEach((num) => {
		frequency[num] = (frequency[num] || 0) + 1;
	});

	return data.filter((num) => frequency[num] > 1);
}

console.log("Example:");
console.log(JSON.stringify(nonUniqueElements([1, 2, 3, 1, 3])));

// These "asserts" are used for self-checking
assert.deepStrictEqual(nonUniqueElements([1, 2, 3, 1, 3]), [1, 3, 1, 3]);
assert.deepStrictEqual(nonUniqueElements([1, 2, 3, 4, 5]), []);
assert.deepStrictEqual(nonUniqueElements([5, 5, 5, 5, 5]), [5, 5, 5, 5, 5]);
assert.deepStrictEqual(
	nonUniqueElements([10, 9, 10, 10, 9, 8]),
	[10, 9, 10, 10, 9],
);
assert.deepStrictEqual(nonUniqueElements([2, 2, 3, 2, 2]), [2, 2, 2, 2]);
assert.deepStrictEqual(nonUniqueElements([10, 20, 30, 10]), [10, 10]);
assert.deepStrictEqual(nonUniqueElements([7]), []);
assert.deepStrictEqual(
	nonUniqueElements([0, 1, 2, 3, 4, 0, 1, 2, 4]),
	[0, 1, 2, 4, 0, 1, 2, 4],
);
assert.deepStrictEqual(nonUniqueElements([99, 98, 99]), [99, 99]);
assert.deepStrictEqual(
	nonUniqueElements([0, 0, 0, 1, 1, 100]),
	[0, 0, 0, 1, 1],
);
assert.deepStrictEqual(
	nonUniqueElements([0, 0, 0, -1, -1, 100]),
	[0, 0, 0, -1, -1],
);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
