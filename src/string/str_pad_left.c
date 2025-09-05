#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/string_utils.h"

/**
 * @brief Pad a string on the left with a character to reach total length.
 * 
 * @param str The string to pad.
 * @param total_length The desired total length.
 * @param pad_char The character to pad with.
 * @return A new padded string, or NULL if memory allocation fails.
 */
char *str_pad_left(const char *str, size_t total_length, char pad_char) {
    if (str == NULL) {
        return NULL;
    }
    
    size_t str_len = strlen(str);
    
    if (str_len >= total_length) {
        return strdup(str);
    }
    
    char *result = malloc(total_length + 1);
    if (!result) return NULL;
    
    size_t pad_count = total_length - str_len;
    
    // Fill with padding character
    for (size_t i = 0; i < pad_count; i++) {
        result[i] = pad_char;
    }
    
    // Copy original string
    strcpy(result + pad_count, str);
    
    return result;
}
