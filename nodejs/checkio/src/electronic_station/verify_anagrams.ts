import assert from "assert";

function verifyAnagrams(line1: string, line2: string): boolean {
	const sorted1 = line1
		.toLowerCase()
		.split("")
		.filter((char) => char !== " ")
		.sort()
		.join("");
	const sorted2 = line2
		.toLowerCase()
		.split("")
		.filter((char) => char !== " ")
		.sort()
		.join("");
	return sorted1 === sorted2;
}

console.log("Example:");
console.log(verifyAnagrams("Programming", "Gram Ring Mop"));

// These "asserts" are used for self-checking
assert.strictEqual(verifyAnagrams("Programming", "Gram Ring Mop"), true);
assert.strictEqual(verifyAnagrams("Hello", "Ole Oh"), false);
assert.strictEqual(verifyAnagrams("Kyoto", "Tokyo"), true);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
