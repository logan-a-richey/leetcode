// 0005_longest_palindrome

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*****************************************************************************/
// declare

char* slice_string(const char* str, int start, int end);
char* expand_from_center(const char* s, int left, int right);
char* longestPalindrome(char* s);

/*****************************************************************************/
// define

char* slice_string(const char* str, int start, int end) {
    if (str == NULL || start < 0 || end < start) {
        return NULL;
    }

    int length = end - start;
    char* sliced_str = (char*)malloc((length + 1) * sizeof(char));
    if (sliced_str == NULL) {
        return NULL;
    }

    strncpy(sliced_str, str + start, length);
    sliced_str[length] = '\0';

    return sliced_str;
}

char* expand_from_center(const char* s, int left, int right) {
    int len = strlen(s);
    while (left >= 0 && right < len && s[left] == s[right]) {
        left--;
        right++;
    }
    return slice_string(s, left + 1, right);
}

char* longestPalindrome(char* s) {
    if (s == NULL || strlen(s) == 0) return "";

    char* longest = NULL;
    int max_len = 0;

    for (int i = 0; i < strlen(s); i++) {
        char* w1 = expand_from_center(s, i, i);
        char* w2 = expand_from_center(s, i, i + 1);

        if (strlen(w1) > max_len) {
            // free previous string if needed
            free(longest);  
            longest = w1;
            max_len = strlen(w1);
        } else {
            free(w1);
        }

        if (strlen(w2) > max_len) {
            free(longest);
            longest = w2;
            max_len = strlen(w2);
        } else {
            free(w2);
        }
    }

    return longest;
}

int main() {
    char word[] = "my madam";
    char* result = longestPalindrome(word);
    printf("Longest palindrome: %s\n", result);
    free(result);
    return 0;
}

