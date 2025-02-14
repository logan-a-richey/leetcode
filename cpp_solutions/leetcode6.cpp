/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);



Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I

Example 3:

Input: s = "A", numRows = 1
Output: "A"
*/

// leetcode 6: zigzag pattern

#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        // edge case: if there is only one row, return original string
        if (numRows == 1) {
            return s;
        }

        // vector of empty strings for each row
        std::vector<std::string> rows(numRows);
        int i = 0, vdir = 1; // row index, vertical direction

        // loop through char in s, append to correct row
        for (char c : s) {
            rows[i] += c;

            // Change direction when we reach the first or last row
            if (i == 0) {
                // moving down
                vdir = 1; 
            } else if (i == numRows - 1) {
                // moving up
                vdir = -1;
            }
            // toggle vertical direction
            i += vdir; 
        }

        // concat final result
        std::string result = "";
        for (const std::string& row : rows) {
            result += row;
        }
        return result;
    }
};

int main() {
    Solution sol;
    std::string s = "PAYPALISHIRING";
    int rows = 4;
    std::string result = sol.convert(s, rows); 

    // should return "PINALSIGYAHRPI"
    std::cout << "Input : " << s << std::endl;
    std::cout << "Result: " << result << std::endl; 
    return 0;
}


