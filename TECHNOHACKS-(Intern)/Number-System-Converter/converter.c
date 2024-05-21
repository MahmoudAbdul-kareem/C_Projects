
#include "converter.h"

/******** Implementing some helper functions ********/
static ret_status validate_binary(const char *input) 
{
    if (NULL == input)
        return NULL_POINTER_PASSED;
    while (*input) 
    {
        if (*input != '0' && *input != '1') 
        {
            return RET_NOK;
        }
        input++;
    }
    return RET_OK;
}

static ret_status validate_octal(const char *input) 
{
    if (NULL == input)
        return NULL_POINTER_PASSED;
    while (*input) 
    {
        if (*input < '0' || *input > '7') 
        {
            return RET_NOK;
        }
        input++;
    }
    return RET_OK;
}

static ret_status validate_decimal(const char *input) 
{
    if (NULL == input)
        return NULL_POINTER_PASSED;
    while (*input) 
    {
        if (!IS_DIGIT(*input)) 
        {
            return RET_NOK;
        }
        input++;
    }
    return RET_OK;
}

static ret_status validate_hexadecimal(const char *input) 
{
    if (NULL == input)
        return NULL_POINTER_PASSED;
    while (*input) 
    {
        if (!(IS_DIGIT(*input) || IS_HEX_CHAR(*input))) 
        {
            return RET_NOK;
        }
        input++;
    }
    return RET_OK;
}

static void reverse_string(char *const str) 
{
    if(NULL == str)
        printf("NULL pointer passed ! \n");
    
    int left = 0;
    int right = strlen(str) - 1;
    char temp;

    while (left < right) {
        // Swap characters
        temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        // Move towards the center
        left++;
        right--;
    }
}

/********* Implementing the basic functions *********/

/**
 * @brief Validates if a string is a valid number in a given base.
 * 
 * @param base The base of the number system.
 * @param input The string to validate.
 * @return `ret_status` Returns `RET_OK` if valid, otherwise `RET_NOK`.
 */
ret_status validate_number_system(const uint8 base, const char *input)
{
    if (NULL == input)
        return NULL_POINTER_PASSED;
    if (base < 2 || base > 16)
        return RET_NOK;
    switch (base)
    {
        case BINARY_BASE:
            return validate_binary(input);
        case OCTAL_BASE:
            return validate_octal(input);
        case DECIMAL_BASE:
            return validate_decimal(input);
        case HEXADECIMAL_BASE:
            return validate_hexadecimal(input);
        default:
            printf("Invalid base! - it must be one of these values [2, 8, 10, 16]\n");
            return RET_NOK;
    }
}

/**
 * @brief Converts a decimal string to a specified base string.
 * 
 * @param base The target base for conversion (e.g., 2 for binary, 16 for hexadecimal).
 * @param dec_input The input decimal number as a string.
 * @param result The output string buffer for the converted result.
 * @param result_size The size of the output string buffer.
 * @return `ret_status` Returns `RET_OK` on success, `RET_NOK` on failure, and `NULL_POINTER_PASSED` if input pointers are null.
 */
ret_status convert_decimal_to_base(const uint8 base,const char *dec_input, char *const result, const uint8 result_size)
{
    if (NULL == dec_input || NULL == result)
    {
        return NULL_POINTER_PASSED;
    }
    else if (RET_OK != validate_number_system(DECIMAL_BASE, dec_input))
    {
        return RET_NOK;
    }
    else
    {
        uint32 int_val = atoi(dec_input);
        uint8 iterator = 0;

        do
        {
            if (iterator >= result_size - 1) 
            {  // Ensure there is enough space for the base string and null terminator
                return RET_NOK;
            }
            uint8 rem = (int_val % base);
            int_val /= base;
            if (rem < 10)
            {
                result[iterator] = (rem + '0'); // convert rem to char and append it to result
            }
            else
            {
                result[iterator] = GET_HEX_CHAR(rem); // 10 + 55
            }
            iterator++;
        }while (int_val);

        result[iterator] = '\0'; // add null termination to the end of the string
        reverse_string(result);

        return RET_OK;
    }
}

/**
 * @brief Converts a number from a given base to a decimal (base 10) number.
 * 
 * @param base The base of the input number (e.g., 2 for binary, 16 for hexadecimal).
 * @param base_input The input number as a string.
 * @param decimal The output decimal value.
 * @return ret_status Returns `RET_OK` on success, `RET_NOK` on failure, and `NULL_POINTER_PASSED` if input pointers are null.
 */
ret_status convert_base_to_decimal(const uint8 base, const char *base_input, char *const result, const uint8 result_size) 
{
    if (base_input == NULL || result == NULL) 
    {
        return NULL_POINTER_PASSED;
    }

    if (RET_OK != validate_number_system(base, base_input)) 
    {
        return RET_NOK;
    }

    uint32 decimal = 0;
    uint8 int_val = 0;
    uint8 iterator = 0;
    uint8 length = strlen(base_input);

    for (iterator = 0; iterator < length; ++iterator) 
    {
        if (iterator >= result_size - 1) 
        {  // Ensure there is enough space for the base string and null terminator
            return RET_NOK;
        }
        char ch = base_input[iterator];
        if (IS_DIGIT(ch)) 
        {
            int_val = ch - '0';
        }
        else
        {
            GET_HEX_VALUE(ch, int_val);
        }
        decimal = (decimal * base) + int_val; /*** Important ***/
    }
    // Convert the decimal number to a string
    if (NULL == itoa(decimal, result, DECIMAL_BASE)) 
    {
        return RET_NOK;
    }
    // Ensure the result fits in the provided buffer
    if (strlen(result) >= result_size) 
    {
        return RET_NOK;
    }

    return RET_OK;
}

