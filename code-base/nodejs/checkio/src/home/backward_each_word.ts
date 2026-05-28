import assert from "assert";

function backwardStringByWord(text: string): string {
	return text
		.split(" ")
		.map((word) => word.split("").reverse().join(""))
		.join(" ");
}

console.log("Example:");
console.log(backwardStringByWord("welcome to a game"));

// These "asserts" are used for self-checking
assert.strictEqual(backwardStringByWord(""), "");
assert.strictEqual(backwardStringByWord("world"), "dlrow");
assert.strictEqual(backwardStringByWord("hello world"), "olleh dlrow");
assert.strictEqual(backwardStringByWord("hello   world"), "olleh   dlrow");
assert.strictEqual(
	backwardStringByWord("welcome to a game"),
	"emoclew ot a emag",
);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
