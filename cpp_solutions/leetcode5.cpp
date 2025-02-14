// leetcode 5
// find longest palindrome substring
// a palindrome is a word that is spelled the same forwards and backwards

#include <iostream>
#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        // lambda function to expand about a center index
        // return the longest palindrome
        auto expandAroundCenter = [&](int left, int right) -> std::string {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                left--; right++;  
            }
            // return longest palindrome
            return s.substr(left + 1, right - left - 1);
        };
        
        std::string res = "";  // temp string to store the answer
        for (int i = 0; i < s.length(); i++) {
            // check for odd-length palindrome centered at i
            std::string odd = expandAroundCenter(i, i);
            
            // check for even-length palindrome centered between i and i+1
            std::string even = expandAroundCenter(i, i + 1);
            
            // Update result if a longer palindrome is found
            if (odd.length() > res.length()) res = odd;
            if (even.length() > res.length()) res = even;
        }
        // return the longest palindrome
        return res;
    }
};

int main() {
    Solution sol;
    std::string msg = "abcRADARxyzz";
    // Output the longest palindrome
    std::cout << sol.longestPalindrome(msg) << std::endl;  // Should print "RADAR"
    return 0;
}

