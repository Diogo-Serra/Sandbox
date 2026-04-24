from collections.abc import Callable


def mage_counter() -> Callable:
    global_counter: int = 0

    def counter():
        nonlocal global_counter
        global_counter += 1
        return global_counter
    return counter


def spell_accumulator(initial_power: int) -> Callable:
    spell_power: int = 0

    def accumulator():
        nonlocal spell_power
        spell_power += 10
        return spell_power
    return accumulator


if __name__ == "__main__":

    counter = mage_counter()
    print(counter())
    print(counter())
    print(counter())

    accumulator = spell_accumulator(10)
    print(accumulator())
    print(accumulator())
    print(accumulator())
