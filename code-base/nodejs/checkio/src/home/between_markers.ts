import assert from "assert";

function betweenMarkers(text: string, begin: string, end: string): string {
	const start =
		text.indexOf(begin) !== -1 ? text.indexOf(begin) + begin.length : 0;
	const finish = text.indexOf(end) === -1 ? text.length : text.indexOf(end);
	return text.slice(start, finish);
}

console.log("Example:");
console.log(betweenMarkers("What is >apple<", ">", "<"));

// These "asserts" are used for self-checking
assert.strictEqual(betweenMarkers("What is >apple<", ">", "<"), "apple");
assert.strictEqual(
	betweenMarkers(
		"<head><title>My new site</title></head>",
		"<title>",
		"</title>",
	),
	"My new site",
);
assert.strictEqual(betweenMarkers("No[/b] hi", "[b]", "[/b]"), "No");
assert.strictEqual(betweenMarkers("No [b]hi", "[b]", "[/b]"), "hi");
assert.strictEqual(betweenMarkers("No hi", "[b]", "[/b]"), "No hi");
assert.strictEqual(betweenMarkers("No <hi>", ">", "<"), "");

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
