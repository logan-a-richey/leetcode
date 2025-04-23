// 0003_longest_substring.c

#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int lengthOfLongestSubstring(char* s) {
    // Fixed size for ASCII
    int char_index[128];    
    for (int i = 0; i < 128; i++) {
        // Initialize all to -1
        char_index[i] = -1; 
    }

    int start_idx = 0;
    int best_len = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        char current = s[i];

        // If this character was seen in the current window, move start
        if (char_index[(int)current] >= start_idx) {
            start_idx = char_index[(int)current] + 1;
        }

        // Update last seen index
        char_index[(int)current] = i;

        // Update the best length
        best_len = max(best_len, i - start_idx + 1);
    }

    return best_len;
}

int main() {
    char* s1 = "abcabcbb";
    char* s2 = "bbbbb";
    char* s3 = "pwwkew";

    printf("'%s', %d\n", s1, lengthOfLongestSubstring(s1));
    printf("'%s', %d\n", s2, lengthOfLongestSubstring(s2));
    printf("'%s', %d\n", s3, lengthOfLongestSubstring(s3));

    return 0;
}

