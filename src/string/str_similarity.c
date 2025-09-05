#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/string_utils.h"

/**
 * @brief Calculate similarity between two strings using Levenshtein distance.
 * 
 * @param str1 The first string.
 * @param str2 The second string.
 * @return Similarity ratio (0.0 = completely different, 1.0 = identical).
 */
double str_similarity(const char *str1, const char *str2) {
    if (str1 == NULL || str2 == NULL) {
        return 0.0;
    }
    
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    
    if (len1 == 0 && len2 == 0) {
        return 1.0;
    }
    
    if (len1 == 0 || len2 == 0) {
        return 0.0;
    }
    
    int distance = str_levenshtein_distance(str1, str2);
    size_t max_len = (len1 > len2) ? len1 : len2;
    
    return 1.0 - ((double)distance / max_len);
}
