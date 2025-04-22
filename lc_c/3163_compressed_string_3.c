// 3163_compressed_string_3.c

#include <stdio.h>
#include <string.h>

#define MAX_FREQ 9
#define MAX_WORD_SIZE 40000

char* compressedString(const char* word) {
    static char new_string[MAX_WORD_SIZE];  // Adjust this size based on your requirements
    int current_freq = 0;
    char current_letter = '\0';
    int new_str_index = 0;  // Index for new_string

    for (int i = 0; word[i] != '\0'; i++) {
        char letter = word[i];

        if (letter != current_letter) {
            if (current_letter != '\0') {  // Append the previous character and its count
                new_str_index += snprintf(new_string + new_str_index, sizeof(new_string) - new_str_index, "%d%c", current_freq, current_letter);
            }
            current_letter = letter;
            current_freq = 1;
        } else {
            if (current_freq >= MAX_FREQ) {
                new_str_index += snprintf(new_string + new_str_index, sizeof(new_string) - new_str_index, "%d%c", current_freq, current_letter);
                current_freq = 0;
            }
            current_freq++;
        }
    }

    // Append the last character and its count
    if (current_letter != '\0') {
        snprintf(new_string + new_str_index, sizeof(new_string) - new_str_index, "%d%c", current_freq, current_letter);
    }

    return new_string;
}

int main() {
    printf("This is compressed string:\n");
    const char* word1 = "abcde";
    const char* word2 = "aaabbbbccccc";
    const char* word3 = "aaaaaaaaaaaaaaaabbcc"; 

    printf("New word1: %s\n", compressedString(word1));
    printf("New word2: %s\n", compressedString(word2));
    printf("New word3: %s\n", compressedString(word3));

    return 0;
}
