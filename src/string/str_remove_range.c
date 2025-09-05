#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/string_utils.h"

/**
 * @brief Remove a range of characters from a string.
 * 
 * @param str The original string.
 * @param start The starting position (0-based).
 * @param length The number of characters to remove.
 * @return A new string with the range removed, or NULL if memory allocation fails.
 */
char *str_remove_range(const char *str, size_t start, size_t length) {
    if (str == NULL) {
        return NULL;
    }
    
    size_t str_len = strlen(str);
    
    if (start >= str_len) {
        return strdup(str);
    }
    
    // Adjust length if it goes beyond string end
    if (start + length > str_len) {
        length = str_len - start;
    }
    
    size_t new_len = str_len - length;
    char *result = malloc(new_len + 1);
    if (!result) return NULL;
    
    // Copy part before removal
    strncpy(result, str, start);
    
    // Copy part after removal
    strcpy(result + start, str + start + length);
    
    return result;
}
