#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/string_utils.h"

/**
 * @brief Validate if a string is a valid IPv4 address.
 * 
 * @param str The string to validate.
 * @return 1 if valid IPv4, 0 otherwise.
 */
int str_is_ipv4(const char *str) {
    if (str == NULL) {
        return 0;
    }
    
    char *str_copy = strdup(str);
    if (!str_copy) return 0;
    
    char *token = strtok(str_copy, ".");
    int count = 0;
    
    while (token != NULL) {
        count++;
        
        // Check if token is a valid number
        if (strlen(token) == 0 || strlen(token) > 3) {
            free(str_copy);
            return 0;
        }
        
        // Check if all characters are digits
        for (size_t i = 0; i < strlen(token); i++) {
            if (!isdigit(token[i])) {
                free(str_copy);
                return 0;
            }
        }
        
        // Check if number is in range 0-255
        int num = atoi(token);
        if (num < 0 || num > 255) {
            free(str_copy);
            return 0;
        }
        
        // Check for leading zeros (except for "0")
        if (strlen(token) > 1 && token[0] == '0') {
            free(str_copy);
            return 0;
        }
        
        token = strtok(NULL, ".");
    }
    
    free(str_copy);
    return count == 4;
}
