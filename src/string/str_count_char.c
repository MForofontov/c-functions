#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/string_utils.h"

/**
 * @brief Count occurrences of a character in a string.
 * 
 * @param str The string to search in.
 * @param ch The character to count.
 * @return The number of occurrences of the character.
 */
size_t str_count_char(const char *str, char ch) {
    if (str == NULL) {
        return 0;
    }
    
    size_t count = 0;
    while (*str) {
        if (*str == ch) {
            count++;
        }
        str++;
    }
    return count;
}
