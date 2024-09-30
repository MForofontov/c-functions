#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "string-utils.h"

/**
 * @brief Get the length of a string.
 * 
 * @param str The input string.
 * @return The length of the string.
 */
size_t str_length(const char *str) {
    return strlen(str);
}

/**
 * @brief Copy a string to a destination buffer.
 * 
 * @param dest The destination buffer. If NULL, memory will be allocated.
 * @param source The source string.
 * @return The destination buffer containing the copied string, or NULL if memory allocation fails.
 */
char *str_copy(char *dest, const char *source) {
    if (dest == NULL) {
        dest = (char *)malloc((strlen(source) + 1) * sizeof(char));
        if (dest == NULL) {
            return NULL; // Memory allocation failed
        }
    }
    strcpy(dest, source);
    return dest;
}

/**
 * @brief Concatenate two strings.
 * 
 * @param str1 The first string.
 * @param str2 The second string.
 * @return A new string containing the concatenation of str1 and str2, or NULL if memory allocation fails.
 */
char *str_concat(const char *str1, const char *str2) {
    size_t len1 = str_length(str1);
    size_t len2 = str_length(str2);
    char *result = (char *)malloc((len1 + len2 + 1) * sizeof(char));
    if (result) {
        strcpy(result, str1);
        strcat(result, str2);
    }
    return result;
}

/**
 * @brief Compare two strings.
 * 
 * @param str1 The first string.
 * @param str2 The second string.
 * @return An integer less than, equal to, or greater than zero if str1 is found, respectively, to be less than, to match, or be greater than str2.
 */
int str_compare(const char *str1, const char *str2) {
    return strcmp(str1, str2);
}

/**
 * @brief Find a substring in a string.
 * 
 * @param haystack The string to search in.
 * @param needle The substring to search for.
 * @return A pointer to the first occurrence of needle in haystack, or NULL if needle is not found.
 */
char *str_find(const char *haystack, const char *needle) {
    return strstr(haystack, needle);
}

/**
 * @brief Convert a string to uppercase.
 * 
 * @param str The string to convert.
 */
void str_to_upper(char *str) {
    for (size_t i = 0; i < str_length(str); i++) {
        str[i] = (char)toupper((unsigned char)str[i]);
    }
}

/**
 * @brief Convert a string to lowercase.
 * 
 * @param str The string to convert.
 */
void str_to_lower(char *str) {
    for (size_t i = 0; i < str_length(str); i++) {
        str[i] = (char)tolower((unsigned char)str[i]);
    }
}

/**
 * @brief Reverse a string.
 * 
 * @param str The string to reverse.
 * @return A new string containing the reversed input string, or NULL if memory allocation fails.
 */
char *str_reverse(const char *str) {
    size_t len = strlen(str);
    char *reversed = (char *)malloc((len + 1) * sizeof(char));
    if (reversed) {
        for (size_t i = 0; i < len; i++) {
            reversed[i] = str[len - 1 - i];
        }
        reversed[len] = '\0';
    }
    return reversed;
}

/**
 * @brief Trim leading and trailing whitespace from a string.
 * 
 * @param str The string to trim.
 * @return A new string with leading and trailing whitespace removed, or NULL if memory allocation fails.
 */
char *str_trim(const char *str) {
    const char *start = str;
    while (isspace((unsigned char)*start)) start++;
    
    if (*start == '\0') return strdup(""); // All spaces

    const char *end = str + strlen(str) - 1;
    while (end > start && isspace((unsigned char)*end)) end--;

    size_t len = end - start + 1;
    char *trimmed = (char *)malloc((len + 1) * sizeof(char));
    if (trimmed) {
        strncpy(trimmed, start, len);
        trimmed[len] = '\0';
    }
    return trimmed;
}

/**
 * @brief Check if a string is a palindrome.
 * 
 * @param str The string to check.
 * @return 1 if the string is a palindrome, 0 otherwise.
 */
int str_is_palindrome(const char *str) {
    size_t len = strlen(str);
    for (size_t i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Is a palindrome
}

/**
 * @brief Count the number of words in a string.
 * 
 * @param str The string to count words in.
 * @return The number of words in the string.
 */
size_t str_word_count(const char *str) {
    size_t count = 0;
    int in_word = 0;
    while (*str) {
        if (isspace((unsigned char)*str)) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            count++;
        }
        str++;
    }
    return count;
}

/**
 * @brief Replace a substring with another substring in a string.
 * 
 * @param str The original string.
 * @param old_sub The substring to be replaced.
 * @param new_sub The substring to replace with.
 * @return A new string with the replacements, or NULL if memory allocation fails.
 */
char *str_replace(const char *str, const char *old_sub, const char *new_sub) {
    char *result;
    size_t i, count = 0;
    size_t new_len = strlen(new_sub);
    size_t old_len = strlen(old_sub);

    // Counting the number of times old substring occurs in the string
    for (i = 0; str[i] != '\0'; i++) {
        if (strstr(&str[i], old_sub) == &str[i]) {
            count++;
            i += old_len - 1;
        }
    }

    // Allocating memory for the new string
    result = (char *)malloc(i + count * (new_len - old_len) + 1);
    if (!result) return NULL;

    i = 0;
    while (*str) {
        if (strstr(str, old_sub) == str) {
            strcpy(&result[i], new_sub);
            i += new_len;
            str += old_len;
        } else {
            result[i++] = *str++;
        }
    }
    result[i] = '\0';
    return result;
}

/**
 * @brief Split a string by a delimiter.
 * 
 * @param str The string to split.
 * @param delim The delimiter string.
 * @param num_tokens Pointer to a size_t to store the number of tokens.
 * @return An array of strings (tokens), or NULL if memory allocation fails.
 */
char **str_split(const char *str, const char *delim, size_t *num_tokens) {
    char *str_copy = strdup(str); // Use strdup to copy the string
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

    strcpy(str_copy, str); // Copy the original string again
    count = 0;
    token = strtok(str_copy, delim);
    while (token) {
        tokens[count] = strdup(token); // Allocate memory and copy the token
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