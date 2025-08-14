import assert from "assert";

function switchDict(data: Record<string, string>): Record<string, Set<string>> {
	const result: { [key: string]: Set<string> } = {};
	for (const [key, value] of Object.entries(data)) {
		if (!result[value]) {
			result[value] = new Set();
		}
		result[value].add(key);
	}
	return result;
}

console.log("Example:");
console.log(
	JSON.stringify(switchDict({ rouses: "red", car: "red", sky: "blue" })),
);

// These "asserts" are used for self-checking
assert.deepStrictEqual(switchDict({ rouses: "red", car: "red", sky: "blue" }), {
	red: new Set(["car", "rouses"]),
	blue: new Set(["sky"]),
});
assert.deepStrictEqual(
	switchDict({ "1": "one", "2": "two", "3": "one", "4": "two" }),
	{ one: new Set(["3", "1"]), two: new Set(["4", "2"]) },
);
assert.deepStrictEqual(switchDict({ a: "b", b: "c", c: "a" }), {
	b: new Set(["a"]),
	c: new Set(["b"]),
	a: new Set(["c"]),
});

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
