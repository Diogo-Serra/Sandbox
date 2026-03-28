#!/usr/bin/env python3

class Solution:

    def isPalindrome(self, x: int) -> bool:
        num_str = str(x)
        j = 0
        for i in num_str:
            if num_str[j] == num_str[(len(num_str) - j - 1)]:
                j += 1
                continue
            else:
                return False
        return True


def main():
    solution = Solution()
    print(solution.isPalindrome(1000021))


main()
