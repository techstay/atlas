import assert from "assert";

function frequencySort<T extends number | string>(items: T[]): T[] {
	const frequencyMap: Map<T, number> = new Map();

	for (const item of items) {
		frequencyMap.set(item, (frequencyMap.get(item) || 0) + 1);
	}

	const sorted = Array.from(frequencyMap.entries()).sort((a, b) => {
		return b[1] - a[1];
	});

	return sorted.flatMap(([item, freq]) => Array(freq).fill(item));
}

console.log("Example:");
console.log(JSON.stringify(frequencySort([4, 6, 2, 2, 6, 4, 4, 4])));

// These "asserts" are used for self-checking
assert.deepStrictEqual(
	frequencySort([4, 6, 2, 2, 6, 4, 4, 4]),
	[4, 4, 4, 4, 6, 6, 2, 2],
);
assert.deepStrictEqual(
	frequencySort([4, 6, 2, 2, 2, 6, 4, 4, 4]),
	[4, 4, 4, 4, 2, 2, 2, 6, 6],
);
assert.deepStrictEqual(frequencySort(["bob", "bob", "carl", "alex", "bob"]), [
	"bob",
	"bob",
	"bob",
	"carl",
	"alex",
]);
assert.deepStrictEqual(frequencySort([17, 99, 42]), [17, 99, 42]);
assert.deepStrictEqual(frequencySort([]), []);
assert.deepStrictEqual(frequencySort([1]), [1]);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
