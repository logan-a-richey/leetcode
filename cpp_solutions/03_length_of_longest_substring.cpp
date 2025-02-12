// 03.cpp

/*
Given a string s, find the length of the longest substring without repeating characters.
Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <iostream>
#include <set>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::set<char> chars_set;  
        int left = 0;  
        int max_length = 0;  
        for (int right = 0; right < s.length(); right++) {
            while (chars_set.find(s[right]) != chars_set.end()) {
                chars_set.erase(s[left]);  
                left++;  
            }
            chars_set.insert(s[right]);
            max_length = std::max(max_length, right - left + 1);
        }
        return max_length;
    }
};

int main() {
    Solution solution;
    
    std::cout << solution.lengthOfLongestSubstring("abcabcbb") << std::endl;  // Output: 3 ("abc")
    std::cout << solution.lengthOfLongestSubstring("bbbbb") << std::endl;  // Output: 1 ("b")
    std::cout << solution.lengthOfLongestSubstring("pwwkew") << std::endl;  // Output: 3 ("wke")

    return 0;
}

