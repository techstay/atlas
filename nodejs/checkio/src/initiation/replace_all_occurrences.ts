import assert from "assert";

function replaceAll(mainText: string, target: string, repl: string): string {
	return mainText.split(target).join(repl);
}

console.log("Example:");
console.log(replaceAll("hello world", "world", "TypeScript"));

// These "asserts" are used for self-checking
assert.strictEqual(
	replaceAll("hello world", "world", "TypeScript"),
	"hello TypeScript",
);
assert.strictEqual(
	replaceAll("hello world world", "world", "TypeScript"),
	"hello TypeScript TypeScript",
);
assert.strictEqual(
	replaceAll("TypeScript is fun", "fun", "awesome"),
	"TypeScript is awesome",
);
assert.strictEqual(replaceAll("aaa", "a", "b"), "bbb");
assert.strictEqual(
	replaceAll("replace all the all", "all", "some"),
	"replace some the some",
);
assert.strictEqual(
	replaceAll("nothing to replace", "something", "nothing"),
	"nothing to replace",
);
assert.strictEqual(
	replaceAll("same same same", "same", "same"),
	"same same same",
);
assert.strictEqual(replaceAll("123 123", "123", "321"), "321 321");
assert.strictEqual(replaceAll("OpenAI", "AI", "Source"), "OpenSource");
assert.strictEqual(replaceAll("", "anything", "nothing"), "");

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
