import assert from "assert";

function longPressed(text: string, typed: string): boolean {
	if (text.length >= typed.length) {
		return false;
	}

	let i = 0; // index for text
	let j = 0; // index for typed

	while (j < typed.length) {
		if (i < text.length && text[i] === typed[j]) {
			// Characters match; move both pointers.
			i += 1;
			j += 1;
		} else if (j > 0 && typed[j] === typed[j - 1]) {
			// Current typed character is a long-press of the previous one.
			j += 1;
		} else {
			// Mismatch that can't be explained by a long-press.
			return false;
		}
	}

	// All original characters must be matched.
	return i === text.length;
}

assert.strictEqual(longPressed("alex", "aaleex"), true);
assert.strictEqual(
	longPressed("welcome to checkio", "weeeelcome to cccheckio"),
	true,
);
assert.strictEqual(
	longPressed("there is an error here", "there is an errorrr hereaa"),
	false,
);
assert.strictEqual(
	longPressed("hi, my name is...", "hi, my name is..."),
	false,
);

console.log("Coding complete? Click 'Check Solution' to earn rewards!");
