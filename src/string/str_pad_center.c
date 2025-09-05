#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/string_utils.h"

/**
 * @brief Pad a string on both sides with a character to reach total length.
 * 
 * @param str The string to pad.
 * @param total_length The desired total length.
 * @param pad_char The character to pad with.
 * @return A new centered string, or NULL if memory allocation fails.
 */
char *str_pad_center(const char *str, size_t total_length, char pad_char) {
    if (str == NULL) {
        return NULL;
    }
    
    size_t str_len = strlen(str);
    
    if (str_len >= total_length) {
        return strdup(str);
    }
    
    char *result = malloc(total_length + 1);
    if (!result) return NULL;
    
    size_t total_pad = total_length - str_len;
    size_t left_pad = total_pad / 2;
    size_t right_pad = total_pad - left_pad;
    
    // Left padding
    for (size_t i = 0; i < left_pad; i++) {
        result[i] = pad_char;
    }
    
    // Copy original string
    strcpy(result + left_pad, str);
    
    // Right padding
    for (size_t i = left_pad + str_len; i < total_length; i++) {
        result[i] = pad_char;
    }
    
    result[total_length] = '\0';
    return result;
}
