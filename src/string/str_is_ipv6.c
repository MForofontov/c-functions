#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/string_utils.h"

/**
 * @brief Validate if a string is a valid IPv6 address.
 * 
 * @param str The string to validate.
 * @return 1 if valid IPv6, 0 otherwise.
 */
int str_is_ipv6(const char *str) {
    if (str == NULL || strlen(str) == 0) {
        return 0;
    }
    
    char *str_copy = strdup(str);
    if (!str_copy) return 0;
    
    int group_count = 0;
    int double_colon_found = 0;
    char *token = strtok(str_copy, ":");
    
    // Handle leading ::
    if (str[0] == ':' && str[1] == ':') {
        double_colon_found = 1;
    }
    
    while (token != NULL) {
        group_count++;
        
        // Check if token is empty (indicates ::)
        if (strlen(token) == 0) {
            if (double_colon_found) {
                free(str_copy);
                return 0; // Multiple :: not allowed
            }
            double_colon_found = 1;
        } else {
            // Validate hex group (1-4 hex digits)
            if (strlen(token) > 4) {
                free(str_copy);
                return 0;
            }
            
            for (size_t i = 0; i < strlen(token); i++) {
                if (!isxdigit(token[i])) {
                    free(str_copy);
                    return 0;
                }
            }
        }
        
        token = strtok(NULL, ":");
    }
    
    free(str_copy);
    
    // IPv6 should have 8 groups, but :: can compress consecutive zeros
    if (double_colon_found) {
        return group_count <= 8;
    } else {
        return group_count == 8;
    }
}
