#!/usr/bin/python3
# leetcode 7: reverse an i32

class Solution:
    def reverse(self, x: int) -> int:
        # Handling negative numbers and storing the sign
        sign = -1 if x < 0 else 1
        x = abs(x)
        
        reversed_x = 0
        while x != 0:
            # Extract the last digit of x
            digit = x % 10
            x //= 10
            
            # Check for overflow before updating reversed_x
            if reversed_x > (2**31 - 1) // 10 or (reversed_x == (2**31 - 1) // 10 and digit > 7):
                return 0
            
            # Build the reversed number
            reversed_x = reversed_x * 10 + digit
        
        return reversed_x * sign

def main():
    sol = Solution()
    x = 1234
    rx = sol.reverse(x)
    print(x, rx)

if __name__ == "__main__":
    main()

