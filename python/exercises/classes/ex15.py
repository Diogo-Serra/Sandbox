#!/usr/bin/env python3

class SecureData:

    def __init__(self):
        self.__data = []

    def get_data(self):
        decrypted_data = []
        for word in self.__data:
            decrypted_data.append(self.__decrypt(word))
        return decrypted_data

    def set_data(self, data):
        for word in data:
            encrypted_word = self.__encrypt(word)
            self.__data.append(encrypted_word)

    def __encrypt(self, value):
        return "".join(chr(ord(ch) + 3) for ch in value)

    def __decrypt(self, value):
        return "".join(chr(ord(ch) - 3) for ch in value)


def tester():
    secured_data = SecureData()
    secured_data.set_data(["Test", "TestTest"])
    print(secured_data.get_data())


tester()
