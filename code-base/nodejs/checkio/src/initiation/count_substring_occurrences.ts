import assert from "assert";

function countOccurrences(mainStr: string, subStr: string): number {
	let count = 0;
	mainStr = mainStr.toLowerCase();
	subStr = subStr.toLowerCase();
	for (let i = 0; i < mainStr.length; i++) {
		if (mainStr.slice(i, i + subStr.length) === subStr) {
			count++;
		}
	}
	return count;
}

console.log("Example:");
console.log(countOccurrences("hello world hello", "hello"));

// These "asserts" are used for self-checking
assert.strictEqual(countOccurrences("hello world hello", "hello"), 2);
assert.strictEqual(countOccurrences("Hello World hello", "hello"), 2);
assert.strictEqual(countOccurrences("hello", "world"), 0);
assert.strictEqual(
	countOccurrences("hello world hello world hello", "world"),
	2,
);
assert.strictEqual(countOccurrences("HELLO", "hello"), 1);
assert.strictEqual(countOccurrences("appleappleapple", "appleapple"), 2);
assert.strictEqual(countOccurrences("HELLO WORLD", "WORLD"), 1);
assert.strictEqual(countOccurrences("hello world hello", "o w"), 1);
assert.strictEqual(countOccurrences("apple apple apple", "apple"), 3);
assert.strictEqual(countOccurrences("apple Apple apple", "apple"), 3);
assert.strictEqual(countOccurrences("apple", "APPLE"), 1);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
