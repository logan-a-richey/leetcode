#!/usr/bin/env python3
# lc 3163
# compressed_string_3

class Solution:
    def compressedString(self, word: str) -> str:
        # Examples:
        # abcde -> 1a1b1c1d1e
        # aaabbbbccccc -> 3a4b5c
        # assume that length of word is between 1 and 2e5
        # allow max freq to be 9
        
        new_string = ""
        current_letter = ""
        current_freq = 0
        
        for letter in word:
            if letter != current_letter:
                if current_letter:
                    new_string += "{}{}".format(current_freq, current_letter)
                current_letter = letter
                current_freq = 1
            else:
                if current_freq >= 9:
                    new_string += "{}{}".format(current_freq, current_letter)
                    current_freq = 0
                current_freq += 1
        
        new_string += "{}{}".format(current_freq, current_letter)
        return new_string
