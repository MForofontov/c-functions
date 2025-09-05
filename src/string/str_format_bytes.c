#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/string_utils.h"

/**
 * @brief Format byte count as human-readable string (B, KB, MB, GB, TB).
 * 
 * @param bytes The number of bytes.
 * @return A new formatted string, or NULL if memory allocation fails.
 */
char *str_format_bytes(size_t bytes) {
    const char *units[] = {"B", "KB", "MB", "GB", "TB"};
    const size_t num_units = sizeof(units) / sizeof(units[0]);
    
    double size = (double)bytes;
    size_t unit_index = 0;
    
    while (size >= 1024.0 && unit_index < num_units - 1) {
        size /= 1024.0;
        unit_index++;
    }
    
    char *result = malloc(32); // Should be enough for any reasonable size
    if (!result) return NULL;
    
    if (unit_index == 0) {
        snprintf(result, 32, "%.0f %s", size, units[unit_index]);
    } else {
        snprintf(result, 32, "%.1f %s", size, units[unit_index]);
    }
    
    return result;
}
