#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/string_utils.h"

/**
 * @brief Compress multiple consecutive whitespace characters into single spaces.
 * 
 * @param str The string to compress.
 * @return A new string with compressed whitespace, or NULL if memory allocation fails.
 */
char *str_compress_whitespace(const char *str) {
    if (str == NULL) {
        return NULL;
    }
    
    size_t len = strlen(str);
    char *result = malloc(len + 1);
    if (!result) return NULL;
    
    size_t j = 0;
    int in_whitespace = 0;
    
    for (size_t i = 0; i < len; i++) {
        if (isspace(str[i])) {
            if (!in_whitespace) {
                result[j++] = ' ';
                in_whitespace = 1;
            }
        } else {
            result[j++] = str[i];
            in_whitespace = 0;
        }
    }
    
    result[j] = '\0';
    
    // Resize to actual length
    char *final_result = realloc(result, j + 1);
    return final_result ? final_result : result;
}
