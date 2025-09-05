#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/string_utils.h"

/**
 * @brief Validate if a string is a valid email address.
 * 
 * @param str The string to validate.
 * @return 1 if valid email, 0 otherwise.
 */
int str_is_email(const char *str) {
    if (str == NULL || strlen(str) == 0) {
        return 0;
    }
    
    const char *at_pos = strchr(str, '@');
    if (at_pos == NULL || at_pos == str) {
        return 0; // No @ or @ at the beginning
    }
    
    // Check if there's only one @
    if (strchr(at_pos + 1, '@') != NULL) {
        return 0;
    }
    
    // Check if there's a dot after @
    const char *dot_pos = strchr(at_pos + 1, '.');
    if (dot_pos == NULL || dot_pos == at_pos + 1) {
        return 0; // No dot after @ or dot immediately after @
    }
    
    // Check if there's at least one character after the last dot
    if (strlen(dot_pos) <= 1) {
        return 0;
    }
    
    // Basic character validation (simplified)
    for (const char *p = str; *p; p++) {
        if (!isalnum(*p) && *p != '@' && *p != '.' && *p != '_' && *p != '-' && *p != '+') {
            return 0;
        }
    }
    
    return 1;
}
