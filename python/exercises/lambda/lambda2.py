from collections.abc import Callable


def mage_counter() -> Callable:
    global_counter: int = 0

    def counter():
        nonlocal global_counter
        global_counter += 1
        return global_counter
    return counter


def spell_accumulator(initial_power: int) -> Callable:
    spell_power: int = initial_power

    def accumulator():
        nonlocal spell_power
        spell_power += 10
        return spell_power
    return accumulator


def enchantment_factory(enchantment_type: str) -> Callable:
    enchantment_type: str = enchantment_type + " "

    def enchant(item: str):
        nonlocal enchantment_type
        return enchantment_type + item
    return enchant


def memory_vault() -> dict[str, Callable]:
    vault: dict[str, object] = {}

    def store(key: str, value: object) -> None:
        vault[key] = value

    def recall(key: str) -> str | object:
        if key in vault:
            return vault[key]
        return "memory not found"

    return {"store": store, "recall": recall}


if __name__ == "__main__":

    print("\nCounter")
    counter = mage_counter()
    print(counter())
    print(counter())
    print(counter())

    print("\nAccumulator")
    accumulator = spell_accumulator(20)
    print(accumulator())
    print(accumulator())
    print(accumulator())

    print("\nEnchantment")
    enchantment_factory = enchantment_factory("Flamming")
    print(enchantment_factory("Sword"))
    print(enchantment_factory("Shield"))

    print("\nMemory")
    vault = memory_vault()
    vault["store"]("secret", 42)
    print(vault['recall']('secret'))
