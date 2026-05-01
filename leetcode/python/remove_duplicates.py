from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        k = 1

        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1]:
                nums[k] = nums[i]
                k += 1
        return k


if __name__ == "__main__":

    nums_list = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]

    solution = Solution()
    r = solution.removeDuplicates(nums_list)
    print(r)
