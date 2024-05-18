
#include "atm.h"

// initialize the ATM (user_1) balance and password
static user_info_t user_1 = {.balance = 1000.00, .password = 1234};


ret_status authenticate_password() // three-times -> exit
{
    ret_status ret = RET_NOK; 
    uint8 try = PASS_VALID_TRY;
    uint32 pin = 0;

    while (try--)
    {
        printf("please enter your PIN number: \n");
        scanf("%i", &pin);
        if (pin == user_1.password)
        {
            ret = RET_OK;
            break;
        }
        else
        {
            printf("WRONG PASSWORD! [%i try available]\n", try);
        }
    }

    return ret;
}

ret_status check_balance(float64 *const bal)
{
    ret_status ret = RET_NOK;

    if(NULL == bal)
    {
        printf("NULL pointer passed!\n");
        ret = RET_NOK;
    }
    else
    {
        *bal = user_1.balance;
        ret = RET_OK;
    }

    return ret;
}

ret_status withdraw(const float64 money)
{
    ret_status ret = RET_NOK;

    if(money <= 0) // negative, not-zero check
    {
        printf("Can't withdraw: please enter valid value! \n");
        ret = RET_NOK;
    }
    else if(money > user_1.balance)
    {
        printf("Can't withdraw: your balance exceded! \n");
        ret = RET_NOK;
    }
    else
    {
        user_1.balance -= money;
        printf("[%.2lf L.E.] has been withdrawn \n", money);
        ret = RET_OK;
    }

    return ret;
}

ret_status deposit(const float64 money)
{
    ret_status ret = RET_NOK;
    
    if(money <= 0) // negative, not-zero check
    {
        printf("Can't deposit: please enter valid value! \n");
        ret = RET_NOK;
    }
    else
    {
        user_1.balance += money;
        printf("[%.2lf L.E.] has been deposited \n", money);
        ret = RET_OK;
    }
    
    return ret;
}
