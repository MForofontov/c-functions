#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/string_utils.h"

/**
 * @brief Find the longest common substring between two strings.
 * 
 * @param str1 The first string.
 * @param str2 The second string.
 * @return A new string containing the longest common substring, or NULL if memory allocation fails.
 */
char *str_longest_common_substring(const char *str1, const char *str2) {
    if (str1 == NULL || str2 == NULL) {
        return NULL;
    }
    
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    
    // Create DP table
    int **dp = malloc((len1 + 1) * sizeof(int*));
    for (size_t i = 0; i <= len1; i++) {
        dp[i] = calloc(len2 + 1, sizeof(int));
    }
    
    size_t max_len = 0;
    size_t end_pos = 0;
    
    // Fill DP table
    for (size_t i = 1; i <= len1; i++) {
        for (size_t j = 1; j <= len2; j++) {
            if (str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                if (dp[i][j] > (int)max_len) {
                    max_len = dp[i][j];
                    end_pos = i;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }
    
    // Free DP table
    for (size_t i = 0; i <= len1; i++) free(dp[i]);
    free(dp);
    
    if (max_len == 0) {
        char *empty = malloc(1);
        if (empty) empty[0] = '\0';
        return empty;
    }
    
    // Extract substring
    char *result = malloc(max_len + 1);
    if (!result) return NULL;
    
    strncpy(result, str1 + end_pos - max_len, max_len);
    result[max_len] = '\0';
    
    return result;
}
