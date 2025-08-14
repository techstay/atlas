import assert from "assert";

function createZigzag(
	rows: number,
	cols: number,
	start: number = 1,
): number[][] {
	const result: number[][] = [];
	let current = start;
	for (let r = 0; r < rows; r++) {
		const row: number[] = [];
		for (let c = 0; c < cols; c++) {
			row.push(current++);
		}
		if (r % 2 === 1) {
			row.reverse();
		}
		result.push(row);
	}
	return result;
}

console.log("Example:");
console.log(JSON.stringify(createZigzag(3, 5)));

// These "asserts" are used for self-checking
assert.deepStrictEqual(createZigzag(3, 5), [
	[1, 2, 3, 4, 5],
	[10, 9, 8, 7, 6],
	[11, 12, 13, 14, 15],
]);
assert.deepStrictEqual(createZigzag(5, 1), [[1], [2], [3], [4], [5]]);
assert.deepStrictEqual(createZigzag(3, 3, 5), [
	[5, 6, 7],
	[10, 9, 8],
	[11, 12, 13],
]);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
