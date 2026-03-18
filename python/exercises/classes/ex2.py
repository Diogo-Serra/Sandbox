#!/usr/bin/env python3


class Bank:
    interest_rate: float = 0.02

    def __init__(self, account_holder: str, balance: float):
        self.account_holder = account_holder
        self.balance = balance

    @classmethod
    def change_interest_rate(cls, new_rate):
        cls.interest_rate = new_rate

    def apply_interest(self):
        self.interest_rate += 1

    def deposit(self, amount):
        self.balance += amount

    def withdraw(self, amount):
        self.withdraw -= amount

    def __str__(self):
        return (f"{self.account_holder}: {self.balance} | "
                f"Interest: {self.interest_rate}")


def main():
    client1 = Bank("test1", 0)
    client2 = Bank("test2", 0)
    print(client1)
    print(client2)
    client1.deposit(100)
    client2.deposit(400)
    print(client1)
    print(client2)
    Bank.change_interest_rate(0.05)
    print(client1)
    print(client2)


main()
