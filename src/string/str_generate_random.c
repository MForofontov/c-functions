#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/string_utils.h"

/**
 * @brief Generate a random string of specified length using given character set.
 * 
 * @param length The length of the string to generate.
 * @param charset The character set to use (if NULL, uses alphanumeric).
 * @return A new random string, or NULL if memory allocation fails.
 */
char *str_generate_random(size_t length, const char *charset) {
    if (length == 0) {
        char *empty = malloc(1);
        if (empty) empty[0] = '\0';
        return empty;
    }
    
    const char *default_charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    const char *chars = charset ? charset : default_charset;
    size_t charset_len = strlen(chars);
    
    if (charset_len == 0) {
        return NULL;
    }
    
    char *result = malloc(length + 1);
    if (!result) return NULL;
    
    // Initialize random seed if not already done
    static int seeded = 0;
    if (!seeded) {
        srand((unsigned int)time(NULL));
        seeded = 1;
    }
    
    for (size_t i = 0; i < length; i++) {
        result[i] = chars[rand() % charset_len];
    }
    
    result[length] = '\0';
    return result;
}
