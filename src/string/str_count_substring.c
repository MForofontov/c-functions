#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/string_utils.h"

/**
 * @brief Count occurrences of a substring in a string.
 * 
 * @param str The string to search in.
 * @param sub The substring to count.
 * @return The number of occurrences.
 */
size_t str_count_substring(const char *str, const char *sub) {
    if (str == NULL || sub == NULL || strlen(sub) == 0) {
        return 0;
    }
    
    size_t count = 0;
    size_t sub_len = strlen(sub);
    const char *pos = str;
    
    while ((pos = strstr(pos, sub)) != NULL) {
        count++;
        pos += sub_len;
    }
    
    return count;
}
