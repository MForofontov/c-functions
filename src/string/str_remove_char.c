#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/string_utils.h"

/**
 * @brief Remove all occurrences of a character from a string.
 * 
 * @param str The string to remove characters from.
 * @param ch The character to remove.
 * @return A new string with the character removed, or NULL if memory allocation fails.
 */
char *str_remove_char(const char *str, char ch) {
    if (str == NULL) {
        return NULL;
    }
    
    size_t len = strlen(str);
    char *result = malloc(len + 1);
    if (!result) return NULL;
    
    size_t j = 0;
    
    for (size_t i = 0; i < len; i++) {
        if (str[i] != ch) {
            result[j++] = str[i];
        }
    }
    
    result[j] = '\0';
    
    // Resize to actual length
    char *final_result = realloc(result, j + 1);
    return final_result ? final_result : result;
}
