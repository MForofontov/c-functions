#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <stddef.h>

// Advanced string algorithms
int str_levenshtein_distance(const char *str1, const char *str2);
char *str_longest_common_subsequence(const char *str1, const char *str2);
char *str_longest_common_substring(const char *str1, const char *str2);

// String pattern matching
int str_kmp_search(const char *text, const char *pattern, int **positions);
int str_boyer_moore_search(const char *text, const char *pattern, int **positions);
int str_fuzzy_match(const char *str1, const char *str2, int max_distance);

// String validation and analysis
int str_is_palindrome(const char *str);
int str_is_numeric(const char *str);
int str_is_email(const char *str);
int str_is_url(const char *str);
int str_is_ipv4(const char *str);
int str_is_ipv6(const char *str);
double str_entropy(const char *str);

// String transformation
char *str_reverse(const char *str);
char *str_trim(const char *str);
char *str_capitalize_words(const char *str);
char *str_snake_to_camel(const char *str);
char *str_camel_to_snake(const char *str);
char *str_base64_encode(const char *data, size_t input_length);
char *str_base64_decode(const char *encoded_data, size_t *output_length);
char *str_url_encode(const char *str);
char *str_url_decode(const char *str);
char *str_html_escape(const char *str);
char *str_html_unescape(const char *str);

// String counting and statistics
size_t str_count_char(const char *str, char ch);
size_t str_count_substring(const char *str, const char *sub);
size_t str_count_words(const char *str);
size_t str_count_lines(const char *str);
double str_similarity(const char *str1, const char *str2);

// String manipulation
char *str_replace_all(const char *str, const char *old_sub, const char *new_sub);
char *str_insert_at(const char *str, const char *insert_str, size_t position);
char *str_remove_range(const char *str, size_t start, size_t length);
char *str_remove_char(const char *str, char ch);
char *str_remove_duplicates(const char *str);
char *str_shuffle(const char *str);

// String formatting
char *str_pad_left(const char *str, size_t total_length, char pad_char);
char *str_pad_right(const char *str, size_t total_length, char pad_char);
char *str_pad_center(const char *str, size_t total_length, char pad_char);
char *str_wrap(const char *str, size_t width);
char *str_format_bytes(size_t bytes);
char *str_format_duration(int seconds);

// String searching and matching
int str_starts_with(const char *str, const char *prefix);
int str_ends_with(const char *str, const char *suffix);
char *str_substring(const char *str, size_t start, size_t length);
char **str_split(const char *str, const char *delim, size_t *num_tokens);
char *str_join(char **strings, size_t count, const char *delim);
void str_split_free(char **tokens, size_t count);

// Advanced string utilities
char *str_generate_random(size_t length, const char *charset);
char *str_compress_whitespace(const char *str);
char *str_extract_numbers(const char *str);
char *str_extract_words(const char *str);
char *str_phonetic_key(const char *str); // Soundex algorithm
char *str_caesar_cipher(const char *str, int shift);

#endif // STRING_UTILS_H
