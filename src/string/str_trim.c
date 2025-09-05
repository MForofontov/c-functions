#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/string_utils.h"

/**
 * @brief Trim leading and trailing whitespace from a string.
 * 
 * @param str The string to trim.
 * @return A new string with leading and trailing whitespace removed, or NULL if memory allocation fails.
 */
char *str_trim(const char *str) {
    if (str == NULL) {
        return NULL;
    }
    
    const char *start = str;
    while (isspace((unsigned char)*start)) start++;
    
    if (*start == '\0') {
        char *empty = malloc(1);
        if (empty) empty[0] = '\0';
        return empty;
    }

    const char *end = str + strlen(str) - 1;
    while (end > start && isspace((unsigned char)*end)) end--;

    size_t len = end - start + 1;
    char *trimmed = (char *)malloc((len + 1) * sizeof(char));
    if (trimmed) {
        strncpy(trimmed, start, len);
        trimmed[len] = '\0';
    }
    return trimmed;
}
