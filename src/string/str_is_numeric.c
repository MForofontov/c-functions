#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/string_utils.h"

/**
 * @brief Check if a string contains only numeric characters.
 * 
 * @param str The string to check.
 * @return 1 if the string is numeric, 0 otherwise.
 */
int str_is_numeric(const char *str) {
    if (str == NULL || *str == '\0') {
        return 0;
    }
    
    // Allow for optional leading sign
    if (*str == '+' || *str == '-') {
        str++;
    }
    
    // Check if empty after sign
    if (*str == '\0') {
        return 0;
    }
    
    int has_decimal = 0;
    while (*str) {
        if (*str == '.') {
            if (has_decimal) {
                return 0; // Multiple decimal points
            }
            has_decimal = 1;
        } else if (!isdigit((unsigned char)*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}
