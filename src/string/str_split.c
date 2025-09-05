#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/string_utils.h"

/**
 * @brief Split a string by a delimiter.
 * 
 * @param str The string to split.
 * @param delim The delimiter string.
 * @param num_tokens Pointer to a size_t to store the number of tokens.
 * @return An array of strings (tokens), or NULL if memory allocation fails.
 */
char **str_split(const char *str, const char *delim, size_t *num_tokens) {
    if (str == NULL || delim == NULL) {
        if (num_tokens) *num_tokens = 0;
        return NULL;
    }
    
    char *str_copy = strdup(str);
    if (!str_copy) return NULL;

    size_t count = 0;
    char *token = strtok(str_copy, delim);
    while (token) {
        count++;
        token = strtok(NULL, delim);
    }

    char **tokens = (char **)malloc((count + 1) * sizeof(char *));
    if (!tokens) {
        free(str_copy);
        return NULL;
    }

    strcpy(str_copy, str);
    count = 0;
    token = strtok(str_copy, delim);
    while (token) {
        tokens[count] = strdup(token);
        if (!tokens[count]) {
            // Free previously allocated memory in case of failure
            for (size_t i = 0; i < count; i++) {
                free(tokens[i]);
            }
            free(tokens);
            free(str_copy);
            return NULL;
        }
        count++;
        token = strtok(NULL, delim);
    }
    tokens[count] = NULL;

    if (num_tokens) *num_tokens = count;
    free(str_copy);
    return tokens;
}
