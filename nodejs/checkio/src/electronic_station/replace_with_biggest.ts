import assert from "assert";

function replaceBiggest(data: number[]): number[] {
	return data.map((_, i) => {
		const subArray = data.slice(i + 1);
		const max = Math.max(...subArray);
		return subArray.length ? max : -1;
	});
}

console.log("Example:");
console.log(JSON.stringify(replaceBiggest([17, 18, 5, 4, 6, 1])));

// These "asserts" are used for self-checking
assert.deepStrictEqual(
	replaceBiggest([17, 18, 5, 4, 6, 1]),
	[18, 6, 6, 6, 1, -1],
);
assert.deepStrictEqual(replaceBiggest([1, 2, 3, 4, 5, 6]), [6, 6, 6, 6, 6, -1]);
assert.deepStrictEqual(replaceBiggest([1, 1, 1]), [1, 1, -1]);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
