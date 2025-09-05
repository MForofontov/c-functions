#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/string_utils.h"

/**
 * @brief Insert a string at a specific position.
 * 
 * @param str The original string.
 * @param insert_str The string to insert.
 * @param position The position to insert at (0-based).
 * @return A new string with the insertion, or NULL if memory allocation fails.
 */
char *str_insert_at(const char *str, const char *insert_str, size_t position) {
    if (str == NULL || insert_str == NULL) {
        return NULL;
    }
    
    size_t str_len = strlen(str);
    size_t insert_len = strlen(insert_str);
    
    // Clamp position to string length
    if (position > str_len) {
        position = str_len;
    }
    
    char *result = malloc(str_len + insert_len + 1);
    if (!result) return NULL;
    
    // Copy part before insertion point
    strncpy(result, str, position);
    
    // Copy insertion string
    strcpy(result + position, insert_str);
    
    // Copy part after insertion point
    strcpy(result + position + insert_len, str + position);
    
    return result;
}
