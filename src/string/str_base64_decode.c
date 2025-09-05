#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/string_utils.h"

static int base64_decode_char(char c) {
    if (c >= 'A' && c <= 'Z') return c - 'A';
    if (c >= 'a' && c <= 'z') return c - 'a' + 26;
    if (c >= '0' && c <= '9') return c - '0' + 52;
    if (c == '+') return 62;
    if (c == '/') return 63;
    return -1;
}

/**
 * @brief Decode Base64 data.
 * 
 * @param encoded_data The Base64 encoded string.
 * @param output_length Pointer to store the length of decoded data.
 * @return A new decoded string, or NULL if memory allocation fails or invalid input.
 */
char *str_base64_decode(const char *encoded_data, size_t *output_length) {
    if (encoded_data == NULL) {
        if (output_length) *output_length = 0;
        return NULL;
    }
    
    size_t input_length = strlen(encoded_data);
    if (input_length % 4 != 0) {
        if (output_length) *output_length = 0;
        return NULL;
    }
    
    size_t decoded_length = input_length / 4 * 3;
    if (encoded_data[input_length - 1] == '=') decoded_length--;
    if (encoded_data[input_length - 2] == '=') decoded_length--;
    
    char *decoded = malloc(decoded_length + 1);
    if (!decoded) {
        if (output_length) *output_length = 0;
        return NULL;
    }
    
    for (size_t i = 0, j = 0; i < input_length;) {
        uint32_t sextet_a = encoded_data[i] == '=' ? 0 & i++ : base64_decode_char(encoded_data[i++]);
        uint32_t sextet_b = encoded_data[i] == '=' ? 0 & i++ : base64_decode_char(encoded_data[i++]);
        uint32_t sextet_c = encoded_data[i] == '=' ? 0 & i++ : base64_decode_char(encoded_data[i++]);
        uint32_t sextet_d = encoded_data[i] == '=' ? 0 & i++ : base64_decode_char(encoded_data[i++]);
        
        if (sextet_a == (uint32_t)-1 || sextet_b == (uint32_t)-1 || 
            sextet_c == (uint32_t)-1 || sextet_d == (uint32_t)-1) {
            free(decoded);
            if (output_length) *output_length = 0;
            return NULL;
        }
        
        uint32_t triple = (sextet_a << 3 * 6) + (sextet_b << 2 * 6) + 
                         (sextet_c << 1 * 6) + (sextet_d << 0 * 6);
        
        if (j < decoded_length) decoded[j++] = (triple >> 2 * 8) & 0xFF;
        if (j < decoded_length) decoded[j++] = (triple >> 1 * 8) & 0xFF;
        if (j < decoded_length) decoded[j++] = (triple >> 0 * 8) & 0xFF;
    }
    
    decoded[decoded_length] = '\0';
    if (output_length) *output_length = decoded_length;
    return decoded;
}
