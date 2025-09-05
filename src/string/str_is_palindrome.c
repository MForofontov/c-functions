#include <string.h>
#include "../include/string_utils.h"

/**
 * @brief Check if a string is a palindrome.
 * 
 * @param str The string to check.
 * @return 1 if the string is a palindrome, 0 otherwise.
 */
int str_is_palindrome(const char *str) {
    if (str == NULL) {
        return 0;
    }
    
    size_t len = strlen(str);
    for (size_t i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Is a palindrome
}
