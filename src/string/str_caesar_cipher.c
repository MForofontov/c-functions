#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/string_utils.h"

/**
 * @brief Apply Caesar cipher encryption/decryption to a string.
 * 
 * @param str The string to encrypt/decrypt.
 * @param shift The shift value (positive for encryption, negative for decryption).
 * @return A new encrypted/decrypted string, or NULL if memory allocation fails.
 */
char *str_caesar_cipher(const char *str, int shift) {
    if (str == NULL) {
        return NULL;
    }
    
    size_t len = strlen(str);
    char *result = malloc(len + 1);
    if (!result) return NULL;
    
    // Normalize shift to 0-25 range
    shift = ((shift % 26) + 26) % 26;
    
    for (size_t i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            char base = isupper(str[i]) ? 'A' : 'a';
            result[i] = (str[i] - base + shift) % 26 + base;
        } else {
            result[i] = str[i];
        }
    }
    
    result[len] = '\0';
    return result;
}
