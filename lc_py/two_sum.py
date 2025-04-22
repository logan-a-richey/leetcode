#!/usr/bin/env python3
# lc 0
# two_sum.py

class Solution:
    def twoSum(self, nums, target):
        m = {}
        for i, n in enumerate(nums):
            if target - n in m:
                return [m[target - n], i]
            m[n] = i
        return [-1, -1]

