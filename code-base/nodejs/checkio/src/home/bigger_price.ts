import assert from "assert";

type Stock = {
	name: string;
	price: number;
};

function biggerPrice(limit: number, data: Stock[]): Stock[] {
	data.sort((a, b) => b.price - a.price);
	return data.slice(0, limit);
}

console.log("Example:");
console.log(
	JSON.stringify(
		biggerPrice(2, [
			{ name: "bread", price: 100 },
			{ name: "wine", price: 138 },
			{ name: "meat", price: 15 },
			{ name: "water", price: 1 },
		]),
	),
);

// These "asserts" are used for self-checking
assert.deepStrictEqual(
	biggerPrice(2, [
		{ name: "bread", price: 100 },
		{ name: "wine", price: 138 },
		{ name: "meat", price: 15 },
		{ name: "water", price: 1 },
	]),
	[
		{ name: "wine", price: 138 },
		{ name: "bread", price: 100 },
	],
);
assert.deepStrictEqual(
	biggerPrice(1, [
		{ name: "pen", price: 5 },
		{ name: "whiteboard", price: 170 },
	]),
	[{ name: "whiteboard", price: 170 }],
);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
