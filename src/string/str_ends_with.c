#include <string.h>
#include "../include/string_utils.h"

/**
 * @brief Check if a string ends with a suffix.
 * 
 * @param str The string to check.
 * @param suffix The suffix to look for.
 * @return 1 if the string ends with the suffix, 0 otherwise.
 */
int str_ends_with(const char *str, const char *suffix) {
    if (str == NULL || suffix == NULL) {
        return 0;
    }
    
    size_t str_len = strlen(str);
    size_t suffix_len = strlen(suffix);
    
    if (suffix_len > str_len) {
        return 0;
    }
    
    return strcmp(str + str_len - suffix_len, suffix) == 0;
}
