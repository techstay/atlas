import assert from "assert";

function rectanglePerimeter(length: number, width: number): number {
	return 2 * (length + width);
}

console.log("Example:");
console.log(rectanglePerimeter(3, 2));

// These "asserts" are used for self-checking
assert.strictEqual(rectanglePerimeter(2, 4), 12);
assert.strictEqual(rectanglePerimeter(3, 5), 16);
assert.strictEqual(rectanglePerimeter(10, 20), 60);
assert.strictEqual(rectanglePerimeter(7, 2), 18);
assert.strictEqual(rectanglePerimeter(1, 1), 4);
assert.strictEqual(rectanglePerimeter(1, 5), 12);
assert.strictEqual(rectanglePerimeter(4, 1), 10);
assert.strictEqual(rectanglePerimeter(100, 100), 400);
assert.strictEqual(rectanglePerimeter(0.5, 2), 5);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
