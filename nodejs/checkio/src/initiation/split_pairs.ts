import assert from "assert";

function splitPairs(text: string): string[] {
	return text.length >= 2
		? [text.slice(0, 2), ...splitPairs(text.slice(2))]
		: text.length === 1
			? [`${text}_`]
			: [];
}

console.log("Example:");
console.log(JSON.stringify(splitPairs("abcd")));

// These "asserts" are used for self-checking
assert.deepStrictEqual(splitPairs("abcd"), ["ab", "cd"]);
assert.deepStrictEqual(splitPairs("abc"), ["ab", "c_"]);
assert.deepStrictEqual(splitPairs("abcdf"), ["ab", "cd", "f_"]);
assert.deepStrictEqual(splitPairs("a"), ["a_"]);
assert.deepStrictEqual(splitPairs(""), []);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
