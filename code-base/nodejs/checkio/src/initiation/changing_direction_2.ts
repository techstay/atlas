import assert from "assert";

function changingDirection(elements: number[]): number {
	if (elements.length < 3) {
		return 0;
	}
	let direction = elements[1] - elements[0];
	let directionChanged = 0;
	for (let i = 2; i < elements.length; i++) {
		if (direction === 0) {
			direction = elements[i] - elements[i - 1];
		} else if ((elements[i] - elements[i - 1]) * direction < 0) {
			directionChanged++;
			direction = elements[i] - elements[i - 1];
		}
	}
	return directionChanged;
}

console.log("Example:");
console.log(changingDirection([1, 2, 3, 4, 5]));

// These "asserts" are used for self-checking
assert.strictEqual(changingDirection([1, 2, 3, 4, 5]), 0);
assert.strictEqual(changingDirection([1, 2, 3, 2, 1]), 1);
assert.strictEqual(changingDirection([1, 2, 2, 1, 2, 2]), 2);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
