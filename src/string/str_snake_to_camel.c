#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/string_utils.h"

/**
 * @brief Convert snake_case to camelCase.
 * 
 * @param str The snake_case string to convert.
 * @return A new camelCase string, or NULL if memory allocation fails.
 */
char *str_snake_to_camel(const char *str) {
    if (str == NULL) {
        return NULL;
    }
    
    size_t len = strlen(str);
    char *result = malloc(len + 1);
    if (!result) return NULL;
    
    size_t j = 0;
    int capitalize_next = 0;
    
    for (size_t i = 0; i < len; i++) {
        if (str[i] == '_') {
            capitalize_next = 1;
        } else {
            if (capitalize_next && j > 0) {
                result[j++] = toupper(str[i]);
                capitalize_next = 0;
            } else {
                result[j++] = tolower(str[i]);
            }
        }
    }
    
    result[j] = '\0';
    return result;
}
