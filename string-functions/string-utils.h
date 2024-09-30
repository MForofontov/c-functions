#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <stddef.h>

// Function to get the length of a string
size_t str_length(const char *str);

// Function to copy a string
char *str_copy(char *dest, const char *source);

// Function to concatenate two strings
char *str_concat(const char *str1, const char *str2);

// Function to compare two strings
int str_compare(const char *str1, const char *str2);

// Function to find a substring in a string
char *str_find(const char *haystack, const char *needle);

// Function to convert a string to uppercase
void str_to_upper(char *str);

// Function to convert a string to lowercase
void str_to_lower(char *str);

// Function to reverse a string
char *str_reverse(const char *str);

// Function to trim leading and trailing whitespace
char *str_trim(const char *str);

// Function to check if a string is a palindrome
int str_is_palindrome(const char *str);

// Function to count the number of words in a string
size_t str_word_count(const char *str);

// Function to replace a substring with another substring
char *str_replace(const char *str, const char *old_sub, const char *new_sub);

// Function to split a string by a delimiter
char **str_split(const char *str, const char *delim, size_t *num_tokens);


#endif // STRING_UTILS_H