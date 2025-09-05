#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/string_utils.h"

/**
 * @brief Capitalize the first letter of each word in a string.
 * 
 * @param str The string to capitalize.
 * @return A new string with capitalized words, or NULL if memory allocation fails.
 */
char *str_capitalize_words(const char *str) {
    if (str == NULL) {
        return NULL;
    }
    
    size_t len = strlen(str);
    char *result = malloc(len + 1);
    if (!result) return NULL;
    
    int capitalize_next = 1;
    
    for (size_t i = 0; i < len; i++) {
        if (isspace(str[i])) {
            result[i] = str[i];
            capitalize_next = 1;
        } else if (capitalize_next && isalpha(str[i])) {
            result[i] = toupper(str[i]);
            capitalize_next = 0;
        } else {
            result[i] = tolower(str[i]);
        }
    }
    
    result[len] = '\0';
    return result;
}
