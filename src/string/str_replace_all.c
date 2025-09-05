#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/string_utils.h"

/**
 * @brief Replace all occurrences of a substring with another substring.
 * 
 * @param str The original string.
 * @param old_sub The substring to replace.
 * @param new_sub The replacement substring.
 * @return A new string with all replacements, or NULL if memory allocation fails.
 */
char *str_replace_all(const char *str, const char *old_sub, const char *new_sub) {
    if (str == NULL || old_sub == NULL || new_sub == NULL) {
        return NULL;
    }
    
    size_t old_len = strlen(old_sub);
    size_t new_len = strlen(new_sub);
    
    if (old_len == 0) {
        return strdup(str);
    }
    
    // Count occurrences
    size_t count = str_count_substring(str, old_sub);
    if (count == 0) {
        return strdup(str);
    }
    
    // Calculate new length
    size_t str_len = strlen(str);
    size_t new_str_len = str_len + count * (new_len - old_len);
    
    char *result = malloc(new_str_len + 1);
    if (!result) return NULL;
    
    const char *src = str;
    char *dst = result;
    
    while (*src) {
        const char *match = strstr(src, old_sub);
        if (match == src) {
            // Found match at current position
            strcpy(dst, new_sub);
            dst += new_len;
            src += old_len;
        } else {
            // Copy character
            *dst++ = *src++;
        }
    }
    
    *dst = '\0';
    return result;
}
