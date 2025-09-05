#include <string.h>
#include "../include/string_utils.h"

/**
 * @brief Check if a string starts with a prefix.
 * 
 * @param str The string to check.
 * @param prefix The prefix to look for.
 * @return 1 if the string starts with the prefix, 0 otherwise.
 */
int str_starts_with(const char *str, const char *prefix) {
    if (str == NULL || prefix == NULL) {
        return 0;
    }
    
    size_t str_len = strlen(str);
    size_t prefix_len = strlen(prefix);
    
    if (prefix_len > str_len) {
        return 0;
    }
    
    return strncmp(str, prefix, prefix_len) == 0;
}
