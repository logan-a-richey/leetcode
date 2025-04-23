# lc 0003
# longest substring

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        '''Find the length of the longest substring without repeating characters'''
        char_idx = {}
        start_idx = 0
        best_len = 0
        for i, char in enumerate(s):
            if char in char_idx and char_idx[char] >= start_idx:
                start_idx = char_idx[char] + 1
            char_idx[char] = i
            best_len = max(best_len, i - start_idx + 1)
        return best_len

def main():
    s = Solution()
    strings = ['abcabcbb', 'bbbbb', 'pwwkew']
    for string in strings:
        print("{} : {}".format(
            string.ljust(10), 
            s.lengthOfLongestSubstring(string)
        ))

if __name__ == "__main__":
    main()

