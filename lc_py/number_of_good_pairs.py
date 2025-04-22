#!/usr/bin/env python3
# lc 3162
# number_of_good_pairs.py

class Solution:
    def numberOfPairs(self, nums1: List[int], nums2: List[int], k: int) -> int:
        pairs = 0
        for n1 in nums1:
            for n2 in nums2:
                den = n2 * k
                if den == 0:
                    continue
                if n1 % den == 0:
                    pairs += 1
        return pairs

