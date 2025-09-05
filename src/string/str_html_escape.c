#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/string_utils.h"

/**
 * @brief Escape HTML special characters.
 * 
 * @param str The string to escape.
 * @return A new HTML escaped string, or NULL if memory allocation fails.
 */
char *str_html_escape(const char *str) {
    if (str == NULL) {
        return NULL;
    }
    
    size_t len = strlen(str);
    // Worst case: every character becomes &entity; (max 6 chars)
    char *result = malloc(len * 6 + 1);
    if (!result) return NULL;
    
    size_t j = 0;
    
    for (size_t i = 0; i < len; i++) {
        switch (str[i]) {
            case '<':
                strcpy(&result[j], "&lt;");
                j += 4;
                break;
            case '>':
                strcpy(&result[j], "&gt;");
                j += 4;
                break;
            case '&':
                strcpy(&result[j], "&amp;");
                j += 5;
                break;
            case '"':
                strcpy(&result[j], "&quot;");
                j += 6;
                break;
            case '\'':
                strcpy(&result[j], "&#39;");
                j += 5;
                break;
            default:
                result[j++] = str[i];
                break;
        }
    }
    
    result[j] = '\0';
    
    // Resize to actual length
    char *final_result = realloc(result, j + 1);
    return final_result ? final_result : result;
}
