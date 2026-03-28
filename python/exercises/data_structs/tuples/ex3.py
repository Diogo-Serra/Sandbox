#!/usr/bin/env python3


def main():
    students: list[tuple] = [
        ("Daniel", 16, 7.5),
        ("Sara", 15, 9.5),
        ("Tiago", 15, 10)]
    students.sort()
    print(students)


main()
