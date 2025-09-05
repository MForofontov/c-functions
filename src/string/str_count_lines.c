#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/string_utils.h"

/**
 * @brief Count the number of lines in a string.
 * 
 * @param str The string to count lines in.
 * @return The number of lines.
 */
size_t str_count_lines(const char *str) {
    if (str == NULL || strlen(str) == 0) {
        return 0;
    }
    
    size_t count = 1; // At least one line if string is not empty
    
    for (size_t i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            count++;
        }
    }
    
    return count;
}
