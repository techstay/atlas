import assert from "assert";

function convAggr(data: [string, number][]): Record<string, number> {
	const result: Record<string, number> = {};

	for (const [key, value] of data) {
		if (key) {
			result[key] = (result[key] || 0) + value;
		}
	}

	// Remove keys with zero values
	for (const key in result) {
		if (result[key] === 0) {
			delete result[key];
		}
	}

	return result;
}

console.log("Example:");
console.log(
	JSON.stringify(
		convAggr([
			["a", 7],
			["b", 8],
			["a", 10],
		]),
	),
);

// These "asserts" are used for self-checking
assert.deepStrictEqual(
	convAggr([
		["a", 7],
		["b", 8],
		["a", 10],
	]),
	{ a: 17, b: 8 },
);
assert.deepStrictEqual(convAggr([]), {});
assert.deepStrictEqual(
	convAggr([
		["a", 5],
		["a", -5],
	]),
	{},
);
assert.deepStrictEqual(
	convAggr([
		["a", 5],
		["a", 5],
		["a", 0],
	]),
	{ a: 10 },
);
assert.deepStrictEqual(
	convAggr([
		["a", 5],
		["", 15],
	]),
	{ a: 5 },
);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
