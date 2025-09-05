#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/string_utils.h"

/**
 * @brief Randomly shuffle the characters in a string.
 * 
 * @param str The string to shuffle.
 * @return A new shuffled string, or NULL if memory allocation fails.
 */
char *str_shuffle(const char *str) {
    if (str == NULL) {
        return NULL;
    }
    
    size_t len = strlen(str);
    char *result = malloc(len + 1);
    if (!result) return NULL;
    
    strcpy(result, str);
    
    // Initialize random seed if not already done
    static int seeded = 0;
    if (!seeded) {
        srand((unsigned int)time(NULL));
        seeded = 1;
    }
    
    // Fisher-Yates shuffle algorithm
    for (size_t i = len - 1; i > 0; i--) {
        size_t j = rand() % (i + 1);
        
        // Swap characters
        char temp = result[i];
        result[i] = result[j];
        result[j] = temp;
    }
    
    return result;
}
