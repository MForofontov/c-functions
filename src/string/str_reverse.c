#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/string_utils.h"

/**
 * @brief Reverse a string.
 * 
 * @param str The string to reverse.
 * @return A new string containing the reversed input string, or NULL if memory allocation fails.
 */
char *str_reverse(const char *str) {
    if (str == NULL) {
        return NULL;
    }
    
    size_t len = strlen(str);
    char *reversed = (char *)malloc((len + 1) * sizeof(char));
    if (reversed) {
        for (size_t i = 0; i < len; i++) {
            reversed[i] = str[len - 1 - i];
        }
        reversed[len] = '\0';
    }
    return reversed;
}
