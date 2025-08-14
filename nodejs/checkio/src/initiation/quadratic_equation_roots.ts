import assert from "assert";

function quadraticRoots(
	a: number,
	b: number,
	c: number,
): [number, number] | [string] {
	const discriminant = b * b - 4 * a * c;
	if (discriminant > 0) {
		const root1 = (-b + Math.sqrt(discriminant)) / (2 * a);
		const root2 = (-b - Math.sqrt(discriminant)) / (2 * a);
		return [root1, root2];
	} else if (discriminant === 0) {
		const root = -b / (2 * a);
		return [root, root];
	} else {
		return ["No real roots"];
	}
}

console.log("Example:");
console.log(quadraticRoots(1, 2, 3));

// These "asserts" are used for self-checking
assert.deepStrictEqual(quadraticRoots(1, -3, 2), [2, 1]);
assert.deepStrictEqual(quadraticRoots(1, 0, -1), [1, -1]);
assert.deepStrictEqual(quadraticRoots(1, 2, 1), [-1, -1]);
assert.deepStrictEqual(quadraticRoots(1, 0, 1), ["No real roots"]);
assert.deepStrictEqual(quadraticRoots(1, 4, 4), [-2, -2]);
assert.deepStrictEqual(quadraticRoots(1, -5, 6), [3, 2]);
assert.deepStrictEqual(quadraticRoots(1, -6, 9), [3, 3]);
assert.deepStrictEqual(quadraticRoots(2, 2, 1), ["No real roots"]);
assert.deepStrictEqual(quadraticRoots(2, -7, 6), [2, 1.5]);
assert.deepStrictEqual(quadraticRoots(2, -3, 1), [1, 0.5]);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
