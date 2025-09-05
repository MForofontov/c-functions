#include <stdlib.h>
#include "../include/string_utils.h"

/**
 * @brief Free memory allocated by str_split.
 * 
 * @param tokens Array of strings to free.
 * @param count Number of strings in the array.
 */
void str_split_free(char **tokens, size_t count) {
    if (tokens == NULL) {
        return;
    }
    
    for (size_t i = 0; i < count; i++) {
        if (tokens[i] != NULL) {
            free(tokens[i]);
        }
    }
    free(tokens);
}
