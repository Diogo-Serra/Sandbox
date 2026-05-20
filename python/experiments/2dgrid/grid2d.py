#!/usr/bin/python3
from sys import argv, exit


if len(argv) == 1:
    user = input("Insert Width and Height: \n").strip().split()
    if len(user) == 2:
        width = user[0]
        height = user[1]
    else:
        print("Exiting")
        exit(1)
