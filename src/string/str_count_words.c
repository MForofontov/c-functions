#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/string_utils.h"

/**
 * @brief Count the number of words in a string.
 * 
 * @param str The string to count words in.
 * @return The number of words.
 */
size_t str_count_words(const char *str) {
    if (str == NULL) {
        return 0;
    }
    
    size_t count = 0;
    int in_word = 0;
    
    while (*str) {
        if (isspace((unsigned char)*str)) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            count++;
        }
        str++;
    }
    
    return count;
}
