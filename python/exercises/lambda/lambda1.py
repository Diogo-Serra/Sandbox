#!/usr/bin/env python3

def artifact_sorter(artifacts: list[dict]) -> list[dict]:
    return sorted(artifacts, key=lambda x: x['power'], reverse=True)


if __name__ == "__main__":

    artifacts: list[dict] = [
        {"name": "art1", "power": 3, "type": "Type1"},
        {"name": "art2", "power": 1, "type": "Type2"},
        {"name": "art3", "power": 2, "type": "Type3"},
        {"name": "art4", "power": 5, "type": "Type4"},
        {"name": "art5", "power": 4, "type": "Type5"},]
    for artifac in artifact_sorter(artifacts):
        print(artifac)
