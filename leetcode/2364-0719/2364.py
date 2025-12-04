from typing import List
from collections import defaultdict


class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        n = len(nums)
        res = n * (n - 1) // 2

        # j - i != nums[j] - nums[i] -> i - nums[i] != j - nums[j]
        freq = defaultdict(int)
        for i in range(n):
            freq[i - nums[i]] += 1

        good_pairs = 0
        for count in freq.values():
            if count > 1:
                good_pairs += count * (count - 1) // 2
        
        res -= good_pairs

        # for i in range(0, len(nums)):
        #     for j in range(i, len(nums)):
        #         if j - i != nums[j] - nums[i]:
        #             res += 1

        return res