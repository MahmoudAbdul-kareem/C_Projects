#ifndef ATM_H
#define ATM_H

#include <stdio.h>
#include <stdlib.h>

#define PASS_VALID_TRY 3 // maximum trying for error password

#define WAIT()  do {printf("\n\npress any key to continue...");\
                getchar(); }while(0)

typedef unsigned char uint8;
typedef unsigned int uint32;
typedef double float64;

typedef struct user_info
{
    float64 balance;
    const uint32 password;
}user_info_t;


typedef enum
{
    RET_OK,
    RET_NOK,
}ret_status;

ret_status authenticate_password(void); // three-times -> exit
ret_status check_balance(float64 *const bal);
ret_status withdraw(const float64 money);
ret_status deposit(const float64 money);


#endif