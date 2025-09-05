#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/string_utils.h"

/**
 * @brief Wrap text to specified width by inserting line breaks.
 * 
 * @param str The string to wrap.
 * @param width The maximum line width.
 * @return A new wrapped string, or NULL if memory allocation fails.
 */
char *str_wrap(const char *str, size_t width) {
    if (str == NULL || width == 0) {
        return NULL;
    }
    
    size_t len = strlen(str);
    // Worst case: every character becomes two (char + newline)
    char *result = malloc(len * 2 + 1);
    if (!result) return NULL;
    
    size_t line_pos = 0;
    size_t result_pos = 0;
    
    for (size_t i = 0; i < len; i++) {
        if (str[i] == '\n') {
            result[result_pos++] = str[i];
            line_pos = 0;
        } else if (line_pos >= width) {
            // Find last space in current line to break at word boundary
            size_t break_pos = result_pos;
            while (break_pos > 0 && !isspace(result[break_pos - 1])) {
                break_pos--;
            }
            
            if (break_pos > 0 && result_pos - break_pos < width / 2) {
                // Insert newline at word boundary
                result_pos = break_pos;
                result[result_pos++] = '\n';
                line_pos = result_pos - break_pos;
            } else {
                // Force break
                result[result_pos++] = '\n';
                line_pos = 0;
            }
            
            result[result_pos++] = str[i];
            line_pos++;
        } else {
            result[result_pos++] = str[i];
            line_pos++;
        }
    }
    
    result[result_pos] = '\0';
    
    // Resize to actual length
    char *final_result = realloc(result, result_pos + 1);
    return final_result ? final_result : result;
}
