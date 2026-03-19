#!/usr/bin/env python3

class Book:

    def __init__(self, title: str, author: str, year: int, pages: int):
        self.title = title
        self.author = author
        self.year = year
        self.pages = pages

    def __str__(self):
        return (f"{self.title} by {self.author} ({self.year}),"
                f" {self.pages} pages")

    def __repr__(self):
        return (f"Book(title='{self.title}', author='{self.author}',"
                f" year={self.year})")


def tester():
    book1 = Book("LOTR", "JRRT", 1990, 400)
    print(book1)
    book1.__repr__()


tester()
