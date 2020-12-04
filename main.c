#include "myBank.h"
#include <stdbool.h>
#include <stdio.h>


int main(){
    bool flag = true;
    char input;
    float rate;
    float account_number;

    while (flag == true)
    {

        printf("Please choose transaction type:\n");
        printf("\n\nO - Open Account.\nB - Balance Inquiry.\nD - Deposit.\nW - Withdrawal.\nC - Close Account.\nI - Interest.\nP - Print.\nE - Exit.\n\n");
        scanf("%c%*c",&input);
        //input check.
        if(input != 'O' && input != 'B' && input != 'D' && input != 'W' && input != 'C' && input != 'I' && input != 'P'&& input != 'E')
            printf("Invalid transaction type\n\n");
     
        switch (input)
        {
        case 'O':
            newAccount();
            break;
        case 'B':
            printf("Please enter account number:\n");
            scanf("%f%*c",&account_number);
            accountStatus(account_number);
            break;
        case 'D':
            printf("Please enter account number:\n");
            scanf("%f%*c",&account_number);
            deposit(account_number);
            break;
        case 'W':
            printf("Please enter account number:\n");
            scanf("%f%*c",&account_number);
            withdraw(account_number);
            break;
        case 'C':
            printf("Please enter account number:\n");
            scanf("%f%*c",&account_number);
            closeAccount(account_number);
            break;
        case 'I':
            printf("Please enter the interest rate :\n");
            scanf("%f%*c",&rate);
            interestRate(rate);
            break;
        case 'P':
            printAccounts();
            break;
        case 'E':
            closeAll();
            flag = false;
            break;
        default:
            break;

        }

    }
    
    
    
    return 0;
}