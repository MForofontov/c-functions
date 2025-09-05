#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/string_utils.h"

/**
 * @brief Calculate Levenshtein distance between two strings (edit distance).
 * This measures the minimum number of single-character edits required to change one string into another.
 * 
 * @param str1 The first string.
 * @param str2 The second string.
 * @return The Levenshtein distance between the strings.
 */
int str_levenshtein_distance(const char *str1, const char *str2) {
    if (str1 == NULL || str2 == NULL) {
        return -1;
    }
    
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    
    // Create a matrix to store distances
    int **matrix = malloc((len1 + 1) * sizeof(int*));
    for (size_t i = 0; i <= len1; i++) {
        matrix[i] = malloc((len2 + 1) * sizeof(int));
    }
    
    // Initialize first row and column
    for (size_t i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (size_t j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }
    
    // Fill the matrix
    for (size_t i = 1; i <= len1; i++) {
        for (size_t j = 1; j <= len2; j++) {
            int cost = (str1[i-1] == str2[j-1]) ? 0 : 1;
            
            int deletion = matrix[i-1][j] + 1;
            int insertion = matrix[i][j-1] + 1;
            int substitution = matrix[i-1][j-1] + cost;
            
            matrix[i][j] = deletion < insertion ? deletion : insertion;
            matrix[i][j] = matrix[i][j] < substitution ? matrix[i][j] : substitution;
        }
    }
    
    int result = matrix[len1][len2];
    
    // Free memory
    for (size_t i = 0; i <= len1; i++) {
        free(matrix[i]);
    }
    free(matrix);
    
    return result;
}
