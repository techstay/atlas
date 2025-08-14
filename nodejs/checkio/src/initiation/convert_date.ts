import assert from "assert";

function convertDate(date: string): string {
	const parts = date.split("/").map(Number);
	const errorMessage = "Error: Invalid date.";
	if (parts.length !== 3) {
		return errorMessage;
	}
	const [day, month, year] = parts;
	const dateObj = new Date(Date.UTC(year, month - 1, day));
	if (
		dateObj.getFullYear() === year &&
		dateObj.getMonth() === month - 1 &&
		dateObj.getDate() === day
	) {
		return dateObj.toISOString().split("T")[0];
	}
	return errorMessage;
}

console.log("Example:");
console.log(convertDate("01/01/2023"));

// These "asserts" are used for self-checking
assert.strictEqual(convertDate("25/12/2021"), "2021-12-25");
assert.strictEqual(convertDate("01/01/2000"), "2000-01-01");
assert.strictEqual(convertDate("15/06/1995"), "1995-06-15");
assert.strictEqual(convertDate("29/02/2020"), "2020-02-29");
assert.strictEqual(convertDate("10/10/2010"), "2010-10-10");
assert.strictEqual(convertDate("31/05/1985"), "1985-05-31");
assert.strictEqual(convertDate("07/08/1960"), "1960-08-07");
assert.strictEqual(convertDate("02/09/1999"), "1999-09-02");
assert.strictEqual(convertDate("30/04/1975"), "1975-04-30");
assert.strictEqual(convertDate("29/02/2019"), "Error: Invalid date.");
assert.strictEqual(convertDate("30/04/1975/1"), "Error: Invalid date.");

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
