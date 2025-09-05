#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/string_utils.h"

/**
 * @brief Validate if a string is a valid URL.
 * 
 * @param str The string to validate.
 * @return 1 if valid URL, 0 otherwise.
 */
int str_is_url(const char *str) {
    if (str == NULL || strlen(str) == 0) {
        return 0;
    }
    
    // Check for basic URL schemes
    const char *schemes[] = {"http://", "https://", "ftp://", "ftps://", "file://", NULL};
    int has_scheme = 0;
    
    for (int i = 0; schemes[i] != NULL; i++) {
        if (strncmp(str, schemes[i], strlen(schemes[i])) == 0) {
            has_scheme = 1;
            str += strlen(schemes[i]);
            break;
        }
    }
    
    if (!has_scheme) {
        return 0;
    }
    
    // Check if there's a domain part
    if (strlen(str) == 0) {
        return 0;
    }
    
    // Find end of domain (before path, query, or fragment)
    const char *domain_end = str;
    while (*domain_end && *domain_end != '/' && *domain_end != '?' && *domain_end != '#') {
        domain_end++;
    }
    
    if (domain_end == str) {
        return 0; // No domain
    }
    
    // Basic domain validation (simplified)
    const char *p = str;
    int has_dot = 0;
    
    while (p < domain_end) {
        if (*p == '.') {
            has_dot = 1;
        } else if (!isalnum(*p) && *p != '-' && *p != ':') {
            return 0; // Invalid character in domain
        }
        p++;
    }
    
    return has_dot; // Must have at least one dot in domain
}
