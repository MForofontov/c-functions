#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/string_utils.h"

/**
 * @brief URL encode a string (percent encoding).
 * 
 * @param str The string to encode.
 * @return A new URL encoded string, or NULL if memory allocation fails.
 */
char *str_url_encode(const char *str) {
    if (str == NULL) {
        return NULL;
    }
    
    size_t len = strlen(str);
    // Worst case: every character becomes %XX (3 characters)
    char *result = malloc(len * 3 + 1);
    if (!result) return NULL;
    
    size_t j = 0;
    
    for (size_t i = 0; i < len; i++) {
        unsigned char c = (unsigned char)str[i];
        
        // Characters that don't need encoding
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            result[j++] = c;
        } else {
            // Percent encode
            sprintf(&result[j], "%%%02X", c);
            j += 3;
        }
    }
    
    result[j] = '\0';
    
    // Resize to actual length
    char *final_result = realloc(result, j + 1);
    return final_result ? final_result : result;
}
