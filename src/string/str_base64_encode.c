#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/string_utils.h"

static const char base64_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

/**
 * @brief Encode data to Base64.
 * 
 * @param data The data to encode.
 * @param input_length The length of input data.
 * @return A new Base64 encoded string, or NULL if memory allocation fails.
 */
char *str_base64_encode(const char *data, size_t input_length) {
    if (data == NULL) {
        return NULL;
    }
    
    size_t output_length = 4 * ((input_length + 2) / 3);
    char *encoded = malloc(output_length + 1);
    if (!encoded) return NULL;
    
    for (size_t i = 0, j = 0; i < input_length;) {
        uint32_t octet_a = i < input_length ? (unsigned char)data[i++] : 0;
        uint32_t octet_b = i < input_length ? (unsigned char)data[i++] : 0;
        uint32_t octet_c = i < input_length ? (unsigned char)data[i++] : 0;
        
        uint32_t triple = (octet_a << 0x10) + (octet_b << 0x08) + octet_c;
        
        encoded[j++] = base64_chars[(triple >> 3 * 6) & 0x3F];
        encoded[j++] = base64_chars[(triple >> 2 * 6) & 0x3F];
        encoded[j++] = base64_chars[(triple >> 1 * 6) & 0x3F];
        encoded[j++] = base64_chars[(triple >> 0 * 6) & 0x3F];
    }
    
    // Add padding
    size_t mod = input_length % 3;
    if (mod == 1) {
        encoded[output_length - 2] = '=';
        encoded[output_length - 1] = '=';
    } else if (mod == 2) {
        encoded[output_length - 1] = '=';
    }
    
    encoded[output_length] = '\0';
    return encoded;
}
