
#include "atm.h"

ret_status ret_val = RET_OK; // 0
float64 money = 0;
uint8 choice = 0;

int main() 
{
    system("cls");
    printf("==================================\n");
    printf("           ATM Login              \n");
    printf("==================================\n");
    if(authenticate_password()) // failed
    {
        exit(0); // exit from the program
    }
    while (1) // Main application
    {
        system("cls");
        printf("[previous error status] > %i \n", ret_val); // to verify the operations
        printf("==================================\n");
        printf("         Welcome to ATM           \n");
        printf("==================================\n");
        printf("[1] Check Balance\n");
        printf("[2] Withdraw Cash\n");
        printf("[3] Deposit Cash\n");
        printf("[4] Quit\n");
        printf("==================================\n");
        printf("Enter your choice... ");
        scanf("%i", &choice);
        while (getchar() != '\n'); // clear the buffer

        switch (choice)
        {
            case 1:
                ret_val |= check_balance(&money);
                printf("Your balance is: [%.2lf L.E.] \n", money);
                WAIT();
                break;

            case 2:
                printf("Enter the amount to withdraw ...\n");
                scanf("%lf", &money); getchar();
                ret_val |= withdraw(money);
                WAIT();
                break;

            case 3:
                printf("Enter the amount to deposit ...\n");
                scanf("%lf", &money); getchar();
                ret_val |= deposit(money);
                WAIT();
                break;

            case 4:
                exit(0);
                break;

            default:
                break;
        }
    }

    return 0;
}