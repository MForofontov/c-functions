#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/string_utils.h"

/**
 * @brief Convert camelCase to snake_case.
 * 
 * @param str The camelCase string to convert.
 * @return A new snake_case string, or NULL if memory allocation fails.
 */
char *str_camel_to_snake(const char *str) {
    if (str == NULL) {
        return NULL;
    }
    
    size_t len = strlen(str);
    // Worst case: every character becomes two characters (letter + underscore)
    char *result = malloc(len * 2 + 1);
    if (!result) return NULL;
    
    size_t j = 0;
    
    for (size_t i = 0; i < len; i++) {
        if (isupper(str[i]) && i > 0) {
            result[j++] = '_';
        }
        result[j++] = tolower(str[i]);
    }
    
    result[j] = '\0';
    
    // Resize to actual length
    char *final_result = realloc(result, j + 1);
    return final_result ? final_result : result;
}
