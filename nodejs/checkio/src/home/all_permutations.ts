import assert from "assert";

function stringPermutations(s: string): string[] {
	if (s.length < 2) return [s];
	const results: string[] = [];
	for (let i = 0; i < s.length; i++) {
		const char = s[i];
		const remainingChars = s.slice(0, i) + s.slice(i + 1);
		for (const perm of stringPermutations(remainingChars)) {
			results.push(char + perm);
		}
	}
	return results.sort();
}

console.log("Example:");
console.log(stringPermutations("ab"));

// These "asserts" are used for self-checking
assert.deepStrictEqual(stringPermutations("ab"), ["ab", "ba"]);
assert.deepStrictEqual(stringPermutations("abc"), [
	"abc",
	"acb",
	"bac",
	"bca",
	"cab",
	"cba",
]);
assert.deepStrictEqual(stringPermutations("a"), ["a"]);
assert.deepStrictEqual(stringPermutations("abcd"), [
	"abcd",
	"abdc",
	"acbd",
	"acdb",
	"adbc",
	"adcb",
	"bacd",
	"badc",
	"bcad",
	"bcda",
	"bdac",
	"bdca",
	"cabd",
	"cadb",
	"cbad",
	"cbda",
	"cdab",
	"cdba",
	"dabc",
	"dacb",
	"dbac",
	"dbca",
	"dcab",
	"dcba",
]);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
