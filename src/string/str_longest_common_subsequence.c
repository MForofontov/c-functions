#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/string_utils.h"

/**
 * @brief Find the longest common subsequence between two strings.
 * 
 * @param str1 The first string.
 * @param str2 The second string.
 * @return A new string containing the LCS, or NULL if memory allocation fails.
 */
char *str_longest_common_subsequence(const char *str1, const char *str2) {
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
    
    // Fill DP table
    for (size_t i = 1; i <= len1; i++) {
        for (size_t j = 1; j <= len2; j++) {
            if (str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = (dp[i-1][j] > dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1];
            }
        }
    }
    
    // Reconstruct LCS
    size_t lcs_len = dp[len1][len2];
    char *result = malloc(lcs_len + 1);
    if (!result) {
        for (size_t i = 0; i <= len1; i++) free(dp[i]);
        free(dp);
        return NULL;
    }
    
    result[lcs_len] = '\0';
    size_t i = len1, j = len2, k = lcs_len;
    
    while (i > 0 && j > 0) {
        if (str1[i-1] == str2[j-1]) {
            result[--k] = str1[i-1];
            i--; j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    
    // Free DP table
    for (size_t i = 0; i <= len1; i++) free(dp[i]);
    free(dp);
    
    return result;
}
