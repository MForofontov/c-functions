#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/string_utils.h"

/**
 * @brief Join an array of strings with a delimiter.
 * 
 * @param strings Array of strings to join.
 * @param count Number of strings in the array.
 * @param delim The delimiter string.
 * @return A new string containing the joined strings, or NULL if memory allocation fails.
 */
char *str_join(char **strings, size_t count, const char *delim) {
    if (strings == NULL || delim == NULL || count == 0) {
        return NULL;
    }
    
    size_t total_len = 0;
    size_t delim_len = strlen(delim);
    
    // Calculate total length needed
    for (size_t i = 0; i < count; i++) {
        if (strings[i] != NULL) {
            total_len += strlen(strings[i]);
        }
        if (i < count - 1) {
            total_len += delim_len;
        }
    }
    
    char *result = (char *)malloc((total_len + 1) * sizeof(char));
    if (!result) return NULL;
    
    result[0] = '\0';
    for (size_t i = 0; i < count; i++) {
        if (strings[i] != NULL) {
            strcat(result, strings[i]);
        }
        if (i < count - 1) {
            strcat(result, delim);
        }
    }
    
    return result;
}
