#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/string_utils.h"

/**
 * @brief Check if two strings match within a maximum edit distance (fuzzy matching).
 * 
 * @param str1 The first string.
 * @param str2 The second string.
 * @param max_distance Maximum allowed Levenshtein distance.
 * @return 1 if strings match within max_distance, 0 otherwise.
 */
int str_fuzzy_match(const char *str1, const char *str2, int max_distance) {
    if (str1 == NULL || str2 == NULL || max_distance < 0) {
        return 0;
    }
    
    int distance = str_levenshtein_distance(str1, str2);
    return distance <= max_distance;
}
