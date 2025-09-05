#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/string_utils.h"

#define ALPHABET_SIZE 256

/**
 * @brief Search for pattern in text using Boyer-Moore algorithm.
 * 
 * @param text The text to search in.
 * @param pattern The pattern to search for.
 * @param positions Pointer to array that will store match positions.
 * @return Number of matches found.
 */
int str_boyer_moore_search(const char *text, const char *pattern, int **positions) {
    if (text == NULL || pattern == NULL || positions == NULL) {
        return 0;
    }
    
    size_t text_len = strlen(text);
    size_t pattern_len = strlen(pattern);
    
    if (pattern_len == 0) {
        return 0;
    }
    
    // Build bad character table
    int bad_char[ALPHABET_SIZE];
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        bad_char[i] = -1;
    }
    for (size_t i = 0; i < pattern_len; i++) {
        bad_char[(unsigned char)pattern[i]] = i;
    }
    
    int *matches = malloc(text_len * sizeof(int));
    if (!matches) return 0;
    
    int match_count = 0;
    size_t shift = 0;
    
    while (shift <= text_len - pattern_len) {
        int j = pattern_len - 1;
        
        while (j >= 0 && pattern[j] == text[shift + j]) {
            j--;
        }
        
        if (j < 0) {
            matches[match_count++] = shift;
            shift += (shift + pattern_len < text_len) ? 
                     pattern_len - bad_char[(unsigned char)text[shift + pattern_len]] : 1;
        } else {
            shift += (j - bad_char[(unsigned char)text[shift + j]] > 1) ?
                     j - bad_char[(unsigned char)text[shift + j]] : 1;
        }
    }
    
    if (match_count == 0) {
        free(matches);
        *positions = NULL;
        return 0;
    }
    
    *positions = realloc(matches, match_count * sizeof(int));
    return match_count;
}
