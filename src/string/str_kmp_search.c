#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/string_utils.h"

/**
 * @brief Search for pattern in text using KMP algorithm.
 * 
 * @param text The text to search in.
 * @param pattern The pattern to search for.
 * @param positions Pointer to array that will store match positions.
 * @return Number of matches found.
 */
int str_kmp_search(const char *text, const char *pattern, int **positions) {
    if (text == NULL || pattern == NULL || positions == NULL) {
        return 0;
    }
    
    size_t text_len = strlen(text);
    size_t pattern_len = strlen(pattern);
    
    if (pattern_len == 0) {
        return 0;
    }
    
    // Build failure function
    int *failure = malloc(pattern_len * sizeof(int));
    if (!failure) return 0;
    
    failure[0] = 0;
    int j = 0;
    for (size_t i = 1; i < pattern_len; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = failure[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            j++;
        }
        failure[i] = j;
    }
    
    // Search for pattern
    int *matches = malloc(text_len * sizeof(int));
    if (!matches) {
        free(failure);
        return 0;
    }
    
    int match_count = 0;
    j = 0;
    
    for (size_t i = 0; i < text_len; i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = failure[j - 1];
        }
        if (text[i] == pattern[j]) {
            j++;
        }
        if (j == (int)pattern_len) {
            matches[match_count++] = i - pattern_len + 1;
            j = failure[j - 1];
        }
    }
    
    free(failure);
    
    if (match_count == 0) {
        free(matches);
        *positions = NULL;
        return 0;
    }
    
    *positions = realloc(matches, match_count * sizeof(int));
    return match_count;
}
