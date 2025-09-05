#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/string_utils.h"

/**
 * @brief Extract all alphabetic words from a string.
 * 
 * @param str The string to extract words from.
 * @return A new string containing only alphabetic characters and spaces, or NULL if memory allocation fails.
 */
char *str_extract_words(const char *str) {
    if (str == NULL) {
        return NULL;
    }
    
    size_t len = strlen(str);
    char *result = malloc(len + 1);
    if (!result) return NULL;
    
    size_t j = 0;
    int last_was_alpha = 0;
    
    for (size_t i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            result[j++] = str[i];
            last_was_alpha = 1;
        } else if (last_was_alpha && j > 0) {
            result[j++] = ' ';
            last_was_alpha = 0;
        }
    }
    
    // Remove trailing space
    if (j > 0 && result[j-1] == ' ') {
        j--;
    }
    
    result[j] = '\0';
    
    // Resize to actual length
    char *final_result = realloc(result, j + 1);
    return final_result ? final_result : result;
}
