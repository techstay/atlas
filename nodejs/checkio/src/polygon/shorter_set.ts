import assert from "assert";

function removeMinMax(data: Set<number>, total: number): Set<number> {
	if (total === 0) return data;
	if (data.size <= total * 2) return new Set();

	const sorted = Array.from(data).sort((a, b) => a - b);
	return new Set(sorted.slice(total, sorted.length - total));
}

console.log("Example:");
console.log(removeMinMax(new Set([8, 9, 18, 7]), 1));

// These "asserts" are used for self-checking
assert.deepStrictEqual(
	removeMinMax(new Set([8, 9, 18, 7]), 1),
	new Set([8, 9]),
);
assert.deepStrictEqual(removeMinMax(new Set([8, 9, 7]), 0), new Set([8, 9, 7]));
assert.deepStrictEqual(removeMinMax(new Set([8, 9, 7]), 2), new Set([]));
assert.deepStrictEqual(removeMinMax(new Set([1, 2, 7, 8, 9]), 2), new Set([7]));
assert.deepStrictEqual(removeMinMax(new Set([]), 1), new Set([]));

console.log("Coding complete? Click 'Check' to earn cool rewards!");
