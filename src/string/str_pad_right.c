#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/string_utils.h"

/**
 * @brief Pad a string on the right with a character to reach total length.
 * 
 * @param str The string to pad.
 * @param total_length The desired total length.
 * @param pad_char The character to pad with.
 * @return A new padded string, or NULL if memory allocation fails.
 */
char *str_pad_right(const char *str, size_t total_length, char pad_char) {
    if (str == NULL) {
        return NULL;
    }
    
    size_t str_len = strlen(str);
    
    if (str_len >= total_length) {
        return strdup(str);
    }
    
    char *result = malloc(total_length + 1);
    if (!result) return NULL;
    
    // Copy original string
    strcpy(result, str);
    
    // Fill with padding character
    for (size_t i = str_len; i < total_length; i++) {
        result[i] = pad_char;
    }
    
    result[total_length] = '\0';
    return result;
}
