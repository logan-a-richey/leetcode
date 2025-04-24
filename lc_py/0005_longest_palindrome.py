#!/usr/bin/env python3
# leetcode 5 - longest palindrome

class Solution:    
    def longestPalindrome(self, s: str) -> str:
        def expand_from_center(left: int, right: int) -> str:
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            return s[left + 1:right]

        longest = ""
        for i in range(len(s)):
            # Odd length palindromes
            word1 = expand_from_center(i, i)
            # Even length palindromes
            word2 = expand_from_center(i, i + 1)

            for word in [word1, word2]:
                drow = word[::-1]  # for fun/logging/debugging
                if len(word) > len(longest):
                    longest = word

        return longest

if __name__ == "__main__":
    s = Solution()
    tests = ["babad", "cbbd", "madam"]
    for t in tests:
        print(s.longestPalindrome(t))

