
#include "converter.h"

uint8 choice = 0;
ret_status ret_val = RET_OK; // 0

char input_str[150] = {'\0'};
char bin_str[150] = {'\0'};
char dec_str[150] = {'\0'};
char oct_str[150] = {'\0'};
char hex_str[150] = {'\0'};

void print_results(const char *const bin, const char *const oct, const char *const dec, const char *const hex);
ret_status take_input_number(uint8 base, const char *const str);
void print_main_menu(void);

int main()
{
    while (1) // Main application
    {
        print_main_menu();
        scanf("%i", &choice);
        while (getchar() != '\n'); // clear the buffer

        switch (choice)
        {
            case 1:
                if (RET_NOK == take_input_number(BINARY_BASE, "Binary"))
                    break;
                ret_val |= convert_base_to_decimal(BINARY_BASE, input_str, dec_str, sizeof(dec_str));
                ret_val |= convert_decimal_to_base(OCTAL_BASE, dec_str, oct_str, sizeof(oct_str));
                ret_val |= convert_decimal_to_base(HEXADECIMAL_BASE, dec_str, hex_str, sizeof(hex_str)); 
                print_results(input_str, oct_str, dec_str, hex_str);
                break;

            case 2:
                if (RET_NOK == take_input_number(OCTAL_BASE, "Octal"))
                    break;
                ret_val |= convert_base_to_decimal(OCTAL_BASE, input_str, dec_str, sizeof(dec_str));
                ret_val |= convert_decimal_to_base(BINARY_BASE, dec_str, bin_str, sizeof(bin_str));
                ret_val |= convert_decimal_to_base(HEXADECIMAL_BASE, dec_str, hex_str, sizeof(hex_str));
                print_results(bin_str, input_str, dec_str, hex_str);
                break;

            case 3:
                if (RET_NOK == take_input_number(DECIMAL_BASE, "Decimal"))
                    break;
                ret_val |= convert_decimal_to_base(BINARY_BASE, input_str, bin_str, sizeof(bin_str));
                ret_val |= convert_decimal_to_base(OCTAL_BASE, input_str, oct_str, sizeof(oct_str));
                ret_val |= convert_decimal_to_base(HEXADECIMAL_BASE, input_str, hex_str, sizeof(hex_str));
                print_results(bin_str, oct_str, input_str, hex_str);
                break;

            case 4:
                if (RET_NOK == take_input_number(HEXADECIMAL_BASE, "Hexadecimal"))
                    break;
                ret_val |= convert_base_to_decimal(HEXADECIMAL_BASE, input_str, dec_str, sizeof(dec_str));
                ret_val |= convert_decimal_to_base(BINARY_BASE, dec_str, bin_str, sizeof(bin_str));
                ret_val |= convert_decimal_to_base(OCTAL_BASE, dec_str, oct_str, sizeof(oct_str));
                print_results(bin_str, oct_str, dec_str, input_str);
                break;

            case 5:
                exit(0);
                break;

            default:
                break;
        }
    }

    return 0;
}


void print_main_menu(void)
{
    system("cls");
    // printf("[previous error status] > %i \n", ret_val); // to verify the operations
    printf("=======================================\n");
    printf("       [Number System Converter]       \n");
    printf("   Choose the system to convert from   \n");
    printf("=======================================\n");
    printf("[1] Binary\n");
    printf("[2] Octal\n");
    printf("[3] Decimal\n");
    printf("[4] HexaDecimal\n");
    printf("[5] Quit\n");
    printf("---------------------------------------\n");
    printf("Enter your choice... ");
}
ret_status take_input_number(uint8 base, const char *const str)
{
    system("cls");
    printf("Please enter a %s value...\n", str);
    scanf("%s", input_str);
    if (RET_NOK == validate_number_system(base, input_str))
    {
        printf("eror: Please enter a valid %s number!\n", str);
        printf("\npress Enter to continue...");
        getchar(); getchar();
        return RET_NOK;
    }
    return RET_OK;
}

void print_results(const char *const bin, const char *const oct, const char *const dec, const char *const hex)
{
    printf("--------------------------------\n");
    printf("          Results are           \n");
    printf("--------------------------------\n");
    printf("Binary: \t0b%s\n", bin);
    printf("Octal:  \t0o%s\n", oct);
    printf("Decimal: \t%s\n", dec);
    printf("Hexadecimal: \t0x%s\n", hex);
    printf("\npress Enter to continue...");
    getchar(); getchar();
}