import assert from "assert";

function sortByExt(files: string[]): string[] {
	//TODO: implement
	return files.sort((a, b) => {
		const extA = a.split(".").pop();
		const extB = b.split(".").pop();
		if (extA === extB) {
			return a.localeCompare(b);
		}
		return extA!.localeCompare(extB!);
	});
}

console.log("Example:");
console.log(JSON.stringify(sortByExt(["1.cad", "1.bat", "1.aa"])));

// These "asserts" are used for self-checking
assert.deepStrictEqual(sortByExt(["1.cad", "1.bat", "1.aa"]), [
	"1.aa",
	"1.bat",
	"1.cad",
]);
assert.deepStrictEqual(sortByExt(["1.cad", "1.bat", "1.aa", "2.bat"]), [
	"1.aa",
	"1.bat",
	"2.bat",
	"1.cad",
]);
assert.deepStrictEqual(sortByExt(["1.cad", "1.bat", "1.aa", ".bat"]), [
	".bat",
	"1.aa",
	"1.bat",
	"1.cad",
]);
assert.deepStrictEqual(sortByExt(["1.cad", "1.bat", ".aa", ".bat"]), [
	".aa",
	".bat",
	"1.bat",
	"1.cad",
]);
assert.deepStrictEqual(sortByExt(["1.cad", "1.", "1.aa"]), [
	"1.",
	"1.aa",
	"1.cad",
]);
assert.deepStrictEqual(sortByExt(["1.cad", "1.bat", "1.aa", "1.aa.doc"]), [
	"1.aa",
	"1.bat",
	"1.cad",
	"1.aa.doc",
]);
assert.deepStrictEqual(sortByExt(["1.cad", "1.bat", "1.aa", ".aa.doc"]), [
	"1.aa",
	"1.bat",
	"1.cad",
	".aa.doc",
]);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
