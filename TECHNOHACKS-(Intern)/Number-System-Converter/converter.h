
#ifndef CONVERTER_H
#define CONVERTER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BINARY_BASE      2
#define OCTAL_BASE       8
#define DECIMAL_BASE     10
#define HEXADECIMAL_BASE 16

#define IS_HEX_CHAR(ch)        (((ch) >= 'a' && (ch) <= 'f') || ((ch) >= 'A' && (ch) <= 'F'))
#define IS_DIGIT(ch)           ((ch) >= '0' && (ch) <= '9')
#define GET_HEX_CHAR(num)      ((rem) - 10 + 'A') // Convert remainder to hex character
#define GET_HEX_VALUE(ch, val) ((val) = ((ch) >= 'a') ? ((ch) - 'a' + 10) : ((ch) - 'A' + 10))

typedef unsigned char uint8;
typedef unsigned int uint32;

typedef enum
{
    RET_OK,
    RET_NOK,
    NULL_POINTER_PASSED
}ret_status;

/**
 * @brief Validates if a string is a valid number in a given base.
 * 
 * @param base The base of the number system.
 * @param input The string to validate.
 * @return `ret_status` Returns `RET_OK` if valid, otherwise `RET_NOK`.
 */
ret_status validate_number_system(const uint8 base, const char *input);

/**
 * @brief Converts a decimal string to a specified base string.
 * 
 * @param base The target base for conversion (e.g., 2 for binary, 16 for hexadecimal).
 * @param dec_input The input decimal number as a string.
 * @param result The output string buffer for the converted result.
 * @param result_size The size of the output string buffer.
 * @return `ret_status` Returns `RET_OK` on success, `RET_NOK` on failure, and `NULL_POINTER_PASSED` if input pointers are null.
 */
ret_status convert_decimal_to_base(const uint8 base, const char *dec_input, char *const result, const uint8 result_size); // -> string

/**
 * @brief Converts a number from a given base to a decimal (base 10) number.
 * 
 * @param base The base of the input number (e.g., 2 for binary, 16 for hexadecimal).
 * @param base_input The input number as a string.
 * @param decimal The output decimal value.
 * @return ret_status Returns `RET_OK` on success, `RET_NOK` on failure, and `NULL_POINTER_PASSED` if input pointers are null.
 */
ret_status convert_base_to_decimal(const uint8 base, const char *base_input, char *const result, const uint8 result_size); // -> decimal

#endif