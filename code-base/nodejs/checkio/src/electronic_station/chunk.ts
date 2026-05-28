import assert from "assert";

function chunkingBy(items: number[], size: number): number[][] {
	const result: number[][] = [];
	for (let i = 0; i < items.length; i += size) {
		result.push(items.slice(i, i + size));
	}
	return result;
}

console.log("Example:");
console.log(JSON.stringify(chunkingBy([5, 4, 7, 3, 4, 5, 4], 3)));

// These "asserts" are used for self-checking
assert.deepStrictEqual(chunkingBy([5, 4, 7, 3, 4, 5, 4], 3), [
	[5, 4, 7],
	[3, 4, 5],
	[4],
]);
assert.deepStrictEqual(chunkingBy([3, 4, 5], 1), [[3], [4], [5]]);
assert.deepStrictEqual(chunkingBy([5, 4], 7), [[5, 4]]);
assert.deepStrictEqual(chunkingBy([], 3), []);
assert.deepStrictEqual(chunkingBy([4, 4, 4, 4], 4), [[4, 4, 4, 4]]);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
