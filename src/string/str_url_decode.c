#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/string_utils.h"

static int hex_to_int(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    return -1;
}

/**
 * @brief URL decode a string (percent decoding).
 * 
 * @param str The URL encoded string to decode.
 * @return A new decoded string, or NULL if memory allocation fails.
 */
char *str_url_decode(const char *str) {
    if (str == NULL) {
        return NULL;
    }
    
    size_t len = strlen(str);
    char *result = malloc(len + 1);
    if (!result) return NULL;
    
    size_t j = 0;
    
    for (size_t i = 0; i < len; i++) {
        if (str[i] == '%' && i + 2 < len) {
            int high = hex_to_int(str[i + 1]);
            int low = hex_to_int(str[i + 2]);
            
            if (high >= 0 && low >= 0) {
                result[j++] = (char)(high * 16 + low);
                i += 2; // Skip the two hex digits
            } else {
                result[j++] = str[i]; // Invalid encoding, keep as is
            }
        } else if (str[i] == '+') {
            result[j++] = ' '; // + represents space in URL encoding
        } else {
            result[j++] = str[i];
        }
    }
    
    result[j] = '\0';
    
    // Resize to actual length
    char *final_result = realloc(result, j + 1);
    return final_result ? final_result : result;
}
