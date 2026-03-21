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
        encrypted = ""
        for ch in value:
            ch = chr(ord(ch) + 3)
            encrypted += ch
        return encrypted

    def __decrypt(self, value):
        decrypted = ""
        for ch in value:
            ch = chr(ord(ch) - 3)
            decrypted += ch
        return decrypted


def tester():
    secured_data = SecureData()
    secured_data.set_data(["Test", "TestTest"])
    print(secured_data.get_data())


tester()
