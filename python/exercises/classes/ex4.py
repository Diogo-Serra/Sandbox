#!/usr/bin/env python3

class Book:

    def __init__(self, title: str, author: str, year: int, pages: int):
        self.title = title
        self.author = author
        self.year = year
        self.pages = pages

    def __str__(self):
        return (f"Title: \"{self.title}\" "
                f"(author={self.author}, year={self.year}"
                f" pages={self.pages}")

    def __repr__(self):
        print(self)


def tester():
    book1 = Book("LOTR", "JRRT", 1990, 400)
    print(book1)
    book1.__repr__()


tester()
