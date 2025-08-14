import assert from "assert";

function removeAfterKth<T>(items: T[], k: number): T[] {
	const frequencyMap: Map<T, number> = new Map();
	const result: T[] = [];

	for (const item of items) {
		let currentCount = frequencyMap.get(item) || 0;
		currentCount++;
		frequencyMap.set(item, currentCount);
		if (currentCount <= k) {
			result.push(item);
		}
	}

	return result;
}

console.log("Example:");
console.log(JSON.stringify(removeAfterKth([42, 42, 42, 42, 42, 42, 42], 3)));

// These "asserts" are used for self-checking
assert.deepStrictEqual(
	removeAfterKth([42, 42, 42, 42, 42, 42, 42], 3),
	[42, 42, 42],
);
assert.deepStrictEqual(removeAfterKth([42, 42, 42, 99, 99, 17], 0), []);
assert.deepStrictEqual(
	removeAfterKth([1, 1, 1, 2, 2, 2], 5),
	[1, 1, 1, 2, 2, 2],
);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
