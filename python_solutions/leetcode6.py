#!/usr/bin/python3
# leetcode 6: zigzag pattern

class Solution:
    def __init__(self):
        pass
    
    def convert(self, s: str, numRows: int) -> str:
        # if there's only one row, return the original string
        if numRows == 1:
            return s
        
        # list of empty strings for each row
        rows = ['' for _ in range(numRows)]
        i, vdir = 0, 1  # row index, vertical direction
        
        # Traverse the string and append characters to appropriate rows
        for c in s:
            # Append character to the current row
            rows[i] += c  
            # Change direction when we reach the first or last row
            if i == 0:
                # set vertical direction to down
                vdir = 1  
            elif i == numRows - 1:
                # # set vertical direction to up
                vdir = -1  
            # toggle vertical direction
            i += vdir  
        
        # Join all rows together to form the final result
        return ''.join(rows)

def main():
    """ Test case """
    sol = Solution()
    s = "PAYPALISHIRING"
    rows = 4
    res = sol.convert(s, rows)
    print(res)  # Output: "PINALSIGYAHRPI"

if __name__ == "__main__":
    main()

