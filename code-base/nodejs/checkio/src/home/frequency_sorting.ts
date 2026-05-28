import assert from "assert";

function frequencySorting(numbers: number[]): number[] {
	const frequencyMap: Map<number, number> = new Map();

	for (const num of numbers) {
		frequencyMap.set(num, (frequencyMap.get(num) || 0) + 1);
	}

	const sorted = Array.from(frequencyMap.entries()).sort((a, b) => {
		if (b[1] === a[1]) {
			return a[0] - b[0];
		}
		return b[1] - a[1];
	});

	return sorted.flatMap(([num, freq]) => Array(freq).fill(num));
}

console.log("Example:");
console.log(JSON.stringify(frequencySorting([1, 2, 3, 4, 5])));

// These "asserts" are used for self-checking
assert.deepStrictEqual(frequencySorting([1, 2, 3, 4, 5]), [1, 2, 3, 4, 5]);
assert.deepStrictEqual(
	frequencySorting([3, 4, 11, 13, 11, 4, 4, 7, 3]),
	[4, 4, 4, 3, 3, 11, 11, 7, 13],
);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
