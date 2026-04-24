#!/usr/bin/env python3

def artifact_sorter(artifacts: list[dict]) -> list[dict]:
    return sorted(artifacts, key=lambda x: x['power'], reverse=True)


def power_filter(mages: list[dict], min_power: int) -> list[dict]:
    return filter(lambda x: x['power'] > min_power, mages)


def spell_transformer(spells: list[str]) -> list[str]:
    return map(lambda x: '* ' + x + ' *', spells)


def mage_stats(mages: list[dict]) -> dict:
    stats: dict = {'max_power': int, 'min_power': int, 'avg_power': float}
    stats['max_power'] = max(mages, key=lambda x: x['power'])['power']
    stats['min_power'] = min(mages, key=lambda x: x['power'])['power']
    total_power = [x['power'] for x in mages]
    stats['avg_power'] = round(sum(total_power) / len(mages), 2)
    return stats


if __name__ == "__main__":

    print("\nSorted per power")
    artifacts: list[dict] = [
        {"name": "art1", "power": 3, "type": "Type1"},
        {"name": "art2", "power": 1, "type": "Type2"},
        {"name": "art3", "power": 2, "type": "Type3"},
        {"name": "art4", "power": 5, "type": "Type4"},
        {"name": "art5", "power": 4, "type": "Type5"},]
    for artifac in artifact_sorter(artifacts):
        print(artifac)

    print("\nFilter per power")
    mages: list[dict] = [
        {"name": "mage1", "power": 3, "element": "element1"},
        {"name": "mage2", "power": 1, "element": "element2"},
        {"name": "mage3", "power": 2, "element": "element3"},
        {"name": "mage4", "power": 5, "element": "element4"},
        {"name": "mage5", "power": 4, "element": "element5"},]
    for mage in power_filter(mages, 3):
        print(mage)

    print("\nTransform spell")
    spells: list[dict] = [
        "Spell1",
        "Spell2",
        "Spell3"]
    for spell in spell_transformer(spells):
        print(spell)

    print("\nStats")
    print(mage_stats(mages))
