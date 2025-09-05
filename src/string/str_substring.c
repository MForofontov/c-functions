#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/string_utils.h"

/**
 * @brief Generate a substring from a string.
 * 
 * @param str The source string.
 * @param start Starting position (0-based index).
 * @param length Length of the substring.
 * @return A new string containing the substring, or NULL if memory allocation fails.
 */
char *str_substring(const char *str, size_t start, size_t length) {
    if (str == NULL) {
        return NULL;
    }
    
    size_t str_len = strlen(str);
    if (start >= str_len) {
        char *empty = malloc(1);
        if (empty) empty[0] = '\0';
        return empty;
    }
    
    if (start + length > str_len) {
        length = str_len - start;
    }
    
    char *result = (char *)malloc((length + 1) * sizeof(char));
    if (result) {
        strncpy(result, str + start, length);
        result[length] = '\0';
    }
    
    return result;
}
