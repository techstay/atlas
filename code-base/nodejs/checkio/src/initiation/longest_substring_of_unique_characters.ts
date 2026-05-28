import assert from "assert";

function longestSubstr(s: string): number {
	let longest = 0;
	for (let i = 0; i < s.length; i++) {
		const set = new Set<string>(s[i]);
		for (let j = i + 1; j < s.length; j++) {
			if (!set.has(s[j])) {
				set.add(s[j]);
			} else {
				longest = Math.max(longest, set.size);
				break;
			}
		}
		longest = Math.max(longest, set.size);
	}
	return longest;
}

console.log("Example:");
console.log(longestSubstr("abcabcbb"));

// These "asserts" are used for self-checking
assert.strictEqual(longestSubstr("abcabcbb"), 3);
assert.strictEqual(longestSubstr("bbbbb"), 1);
assert.strictEqual(longestSubstr("pwwkew"), 3);
assert.strictEqual(longestSubstr("abcdef"), 6);
assert.strictEqual(longestSubstr(""), 0);
assert.strictEqual(longestSubstr("au"), 2);
assert.strictEqual(longestSubstr("dvdf"), 3);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
