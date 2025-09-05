#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/string_utils.h"

/**
 * @brief Unescape HTML entities.
 * 
 * @param str The HTML escaped string to unescape.
 * @return A new unescaped string, or NULL if memory allocation fails.
 */
char *str_html_unescape(const char *str) {
    if (str == NULL) {
        return NULL;
    }
    
    size_t len = strlen(str);
    char *result = malloc(len + 1);
    if (!result) return NULL;
    
    size_t j = 0;
    
    for (size_t i = 0; i < len; i++) {
        if (str[i] == '&') {
            if (strncmp(&str[i], "&lt;", 4) == 0) {
                result[j++] = '<';
                i += 3;
            } else if (strncmp(&str[i], "&gt;", 4) == 0) {
                result[j++] = '>';
                i += 3;
            } else if (strncmp(&str[i], "&amp;", 5) == 0) {
                result[j++] = '&';
                i += 4;
            } else if (strncmp(&str[i], "&quot;", 6) == 0) {
                result[j++] = '"';
                i += 5;
            } else if (strncmp(&str[i], "&#39;", 5) == 0) {
                result[j++] = '\'';
                i += 4;
            } else {
                result[j++] = str[i];
            }
        } else {
            result[j++] = str[i];
        }
    }
    
    result[j] = '\0';
    
    // Resize to actual length
    char *final_result = realloc(result, j + 1);
    return final_result ? final_result : result;
}
