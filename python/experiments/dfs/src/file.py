
def write_to_file(filepath: str, data: list[str]) -> None:
    with open(filepath, 'w') as f:
        for row in data:
            f.write(''.join(format(cell, 'X') for cell in row) + '\n')
