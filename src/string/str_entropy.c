#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../include/string_utils.h"

/**
 * @brief Calculate Shannon entropy of a string.
 * Entropy measures the randomness/information content of the string.
 * 
 * @param str The string to analyze.
 * @return The entropy value (0 = no randomness, higher = more random).
 */
double str_entropy(const char *str) {
    if (str == NULL || strlen(str) == 0) {
        return 0.0;
    }
    
    int frequency[256] = {0}; // ASCII character frequency
    size_t len = strlen(str);
    
    // Count character frequencies
    for (size_t i = 0; i < len; i++) {
        frequency[(unsigned char)str[i]]++;
    }
    
    // Calculate entropy
    double entropy = 0.0;
    for (int i = 0; i < 256; i++) {
        if (frequency[i] > 0) {
            double probability = (double)frequency[i] / len;
            entropy -= probability * log2(probability);
        }
    }
    
    return entropy;
}
