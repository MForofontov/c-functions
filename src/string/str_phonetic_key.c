#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/string_utils.h"

/**
 * @brief Generate a Soundex phonetic key for a string.
 * Soundex is an algorithm that creates a phonetic representation of words.
 * 
 * @param str The string to generate Soundex for.
 * @return A new 4-character Soundex code, or NULL if memory allocation fails.
 */
char *str_phonetic_key(const char *str) {
    if (str == NULL || strlen(str) == 0) {
        return NULL;
    }
    
    char *result = malloc(5); // 4 characters + null terminator
    if (!result) return NULL;
    
    // Soundex mapping
    char soundex_map[26] = {
        '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', // A-J
        '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', // K-T
        '0', '1', '0', '2', '0', '2'  // U-Z
    };
    
    // Find first letter
    size_t i = 0;
    while (i < strlen(str) && !isalpha(str[i])) {
        i++;
    }
    
    if (i >= strlen(str)) {
        strcpy(result, "0000");
        return result;
    }
    
    result[0] = toupper(str[i]);
    int result_pos = 1;
    char last_code = soundex_map[toupper(str[i]) - 'A'];
    i++;
    
    // Process remaining characters
    while (i < strlen(str) && result_pos < 4) {
        if (isalpha(str[i])) {
            char code = soundex_map[toupper(str[i]) - 'A'];
            if (code != '0' && code != last_code) {
                result[result_pos++] = code;
            }
            last_code = code;
        }
        i++;
    }
    
    // Pad with zeros
    while (result_pos < 4) {
        result[result_pos++] = '0';
    }
    
    result[4] = '\0';
    return result;
}
