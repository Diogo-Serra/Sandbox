from collections.abc import Callable


def attack(target: str, power: int) -> str:
    return f"{target} attacks with {power} power"


def heal(target: str, power: int) -> str:
    return f"{target} heals {power} hp"


def spell_combiner(
    spell1: Callable[[str, int], str], spell2: Callable[[str, int], str]
) -> Callable[[str, int], tuple[str, str]]:
    return lambda target, power: (spell1(target, power), spell2(target, power))


def power_amplifier(
    base_spell: Callable[[str, int], str], multiplier: int
) -> Callable[[str, int], str]:
    return lambda target, power: base_spell(target, power * multiplier)


def condition(target: str, power: int) -> bool:
    return power > 70


def conditional_caster(condition: Callable, spell: Callable) -> Callable:
    return lambda target, power: (
        spell(target, power)
        if condition(target, power) is True
        else "Spell fizzled"
    )


def spell_sequence(spells: list[Callable]) -> Callable:
    return lambda spells: [x for x in spells]


if __name__ == "__main__":

    print("\nSpell combiner")
    combined = spell_combiner(attack, heal)
    print(combined("Wizard", 85))

    print("\nPower amplifier")
    amplified = power_amplifier(attack, 10)
    print(amplified("Wizard", 85))

    print("\nConditional caster")
    amplified = power_amplifier(attack, 10)
    print(amplified("Wizard", 85))

    print("\nSpell sequence")
    spell_list = [
        "water",
        "fire",
        "earth"]
    sequence = spell_sequence(spell_list)
    for spell in sequence(spell_list):
        print(spell)
