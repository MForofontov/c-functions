#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/string_utils.h"

/**
 * @brief Remove duplicate characters from a string (keeping first occurrence).
 * 
 * @param str The string to remove duplicates from.
 * @return A new string with duplicates removed, or NULL if memory allocation fails.
 */
char *str_remove_duplicates(const char *str) {
    if (str == NULL) {
        return NULL;
    }
    
    size_t len = strlen(str);
    char *result = malloc(len + 1);
    if (!result) return NULL;
    
    int seen[256] = {0}; // ASCII character tracker
    size_t j = 0;
    
    for (size_t i = 0; i < len; i++) {
        unsigned char c = (unsigned char)str[i];
        if (!seen[c]) {
            seen[c] = 1;
            result[j++] = str[i];
        }
    }
    
    result[j] = '\0';
    
    // Resize to actual length
    char *final_result = realloc(result, j + 1);
    return final_result ? final_result : result;
}
