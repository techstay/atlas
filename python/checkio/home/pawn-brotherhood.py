def safe_pawns(pawns: set) -> int:
    def is_safe(pawn: str) -> bool:
        pos1 = chr(ord(pawn[0]) - 1) + str(int(pawn[1]) - 1)
        pos2 = chr(ord(pawn[0]) + 1) + str(int(pawn[1]) - 1)
        return pos1 in pawns or pos2 in pawns

    return sum(is_safe(pawn) for pawn in pawns)


print("Example:")
print(safe_pawns({"b4", "d4", "f4", "c3", "e3", "g5", "d2"}))

assert safe_pawns({"f4", "g5", "c3", "d2", "b4", "e3", "d4"}) == 6
assert safe_pawns({"f4", "e5", "g4", "e4", "b4", "d4", "c4"}) == 1

print("The mission is done! Click 'Check Solution' to earn rewards!")
