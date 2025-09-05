#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/string_utils.h"

/**
 * @brief Format duration in seconds as human-readable string (e.g., "1h 30m 45s").
 * 
 * @param seconds The duration in seconds.
 * @return A new formatted string, or NULL if memory allocation fails.
 */
char *str_format_duration(int seconds) {
    if (seconds < 0) {
        return NULL;
    }
    
    char *result = malloc(64); // Should be enough for any reasonable duration
    if (!result) return NULL;
    
    if (seconds == 0) {
        strcpy(result, "0s");
        return result;
    }
    
    int hours = seconds / 3600;
    int minutes = (seconds % 3600) / 60;
    int secs = seconds % 60;
    
    result[0] = '\0'; // Start with empty string
    
    if (hours > 0) {
        char temp[16];
        snprintf(temp, sizeof(temp), "%dh", hours);
        strcat(result, temp);
    }
    
    if (minutes > 0) {
        char temp[16];
        if (strlen(result) > 0) strcat(result, " ");
        snprintf(temp, sizeof(temp), "%dm", minutes);
        strcat(result, temp);
    }
    
    if (secs > 0) {
        char temp[16];
        if (strlen(result) > 0) strcat(result, " ");
        snprintf(temp, sizeof(temp), "%ds", secs);
        strcat(result, temp);
    }
    
    return result;
}
