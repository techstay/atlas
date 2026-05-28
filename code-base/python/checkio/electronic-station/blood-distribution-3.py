def distribute_blood(
    blood_avail: dict[str, int], blood_needs: dict[str, int]
) -> dict[str, dict[str, int]]:
    compatibility = {
        "O": ("O"),
        "A": ("A", "O"),
        "B": ("B", "O"),
        "AB": ("AB", "A", "B", "O"),
    }

    def check(donor_type: str, recipient_type: str, blood=0):
        for compatible_type in compatibility[recipient_type]:
            if compatible_type == donor_type:
                blood = min(blood_avail[compatible_type], blood_needs[recipient_type])
                blood_needs[recipient_type] -= blood
                blood_avail[compatible_type] -= blood
        return blood

    return {
        donor_type: {
            recipient_type: check(donor_type, recipient_type)
            for recipient_type in blood_avail
        }
        for donor_type in blood_avail
    }


if __name__ == "__main__":
    assert distribute_blood(
        {"A": 150, "B": 100, "AB": 0, "O": 0}, {"A": 100, "B": 100, "AB": 50, "O": 0}
    ) == {
        "A": {"A": 100, "B": 0, "AB": 50, "O": 0},
        "B": {"A": 0, "B": 100, "AB": 0, "O": 0},
        "AB": {"A": 0, "B": 0, "AB": 0, "O": 0},
        "O": {"A": 0, "B": 0, "AB": 0, "O": 0},
    }
    assert distribute_blood(
        {"A": 10, "B": 10, "AB": 20, "O": 20}, {"A": 20, "B": 10, "AB": 30, "O": 0}
    ) == {
        "A": {"A": 10, "B": 0, "AB": 0, "O": 0},
        "B": {"A": 0, "B": 10, "AB": 0, "O": 0},
        "AB": {"A": 0, "B": 0, "AB": 20, "O": 0},
        "O": {"A": 10, "B": 0, "AB": 10, "O": 0},
    }

    print("Coding complete? Click 'Check' to earn cool rewards!")
