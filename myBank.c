#include "myBank.h"
#include <stdio.h>
#include <stdbool.h>

#define NUM_OF_ACCOUNTS 50

int current_accounts = 0;

float accounts[NUM_OF_ACCOUNTS][3] = {{901, 0, 0}, {902, 0, 0}, {903, 0, 0}, {904, 0, 0}, {905, 0, 0}, {906, 0, 0}, {907, 0, 0}, {908, 0, 0}, {909, 0, 0}, {910, 0, 0}, {911, 0, 0}, {912, 0, 0}, {913, 0, 0}, {914, 0, 0}, {915, 0, 0}, {916, 0, 0}, {917, 0, 0}, {918, 0, 0}, {919, 0, 0}, {920, 0, 0}, {921, 0, 0}, {922, 0, 0}, {923, 0, 0}, {924, 0, 0}, {925, 0, 0}, {926, 0, 0}, {927, 0, 0}, {928, 0, 0}, {929, 0, 0}, {930, 0, 0}, {931, 0, 0}, {932, 0, 0}, {933, 0, 0}, {934, 0, 0}, {935, 0, 0}, {936, 0, 0}, {937, 0, 0}, {938, 0, 0}, {939, 0, 0}, {940, 0, 0}, {941, 0, 0}, {942, 0, 0}, {943, 0, 0}, {944, 0, 0}, {945, 0, 0}, {946, 0, 0}, {947, 0, 0}, {948, 0, 0}, {949, 0, 0}, {950, 0, 0}};

void newAccount()
{   //Entering this function while current_accounts < NUM_OF_ACCOUNTS.
    if (current_accounts < NUM_OF_ACCOUNTS)
    {
        for (int i = 0; i < NUM_OF_ACCOUNTS; i++)
        {
            if (accounts[i][1] == 0 && accounts[i][2] == 0)//Double check
            {
                float deposit_amount = 0;
                printf("Please enter amount for deposit:\n");
                scanf("%f%*c", &deposit_amount);
                accounts[i][1] = 1;//making the account available 
                accounts[i][2] += deposit_amount;//adding the money to balance
                printf("New account number is: %.0f\n", accounts[i][0]);
                current_accounts++;
                break;
            }
            
        }
    }else printf("no room to insert more accounts\n");
}

void accountStatus(float accountNumber){
    bool flag1 = true;
    for (int i = 0; i < NUM_OF_ACCOUNTS; i++){
        if(accounts[i][0] == accountNumber){//Entering if the account number was found
            if(accounts[i][1] == 0){
                printf("The account is not Active\n");
                flag1 = false;
            }
            if(accounts[i][1] == 1){
                printf("The Balance of the account is : %.2f\n",accounts[i][2]);
                flag1 = false;
            }
            break;
        }
    
         
    }
    if(flag1)
        printf("THERE IS NO ACCOUNT WITH THIS NUMBER\n\n");
    

}

void deposit(float accountNumber){
    bool flag1 = true;
    float deposit;
    for (int i = 0; i < NUM_OF_ACCOUNTS; i++){
        if(accounts[i][0] == accountNumber){//looking for the account
            if(accounts[i][1] == 0){
                printf("The account is not Active\n");
                flag1 = false;
            }
            if(accounts[i][1] == 1){
                printf("Please enter how much to deposit :\n");
                scanf("%f%*c",&deposit);
                accounts[i][2] += deposit;
                flag1 = false;

            }
            break;//break when the account was found
        }
    }
    if (flag1)
        printf("THERE IS NO ACCOUNT WITH THIS NUMBER\n\n");

}

void withdraw(float accountNumber){
    bool flag1 = true;
    float withdraw;
    for (int i = 0; i < NUM_OF_ACCOUNTS; i++){
        if(accounts[i][0] == accountNumber){
            if(accounts[i][1] == 0){
                printf("The account is not Active\n");
                flag1 = false;
            }
            if(accounts[i][1] == 1){
                printf("Please enter how much to withdraw :\n");
                scanf("%f%*c",&withdraw);
                flag1 = false;
                accounts[i][2] -= withdraw;

            }
            break;//break when the account was found
        }
        
    }
    if (flag1)
        printf("THERE IS NO ACCOUNT WITH THIS NUMBER\n\n");
}

void closeAccount(float accountNumber){
    bool flag1 = true;
    for (int i = 0; i < NUM_OF_ACCOUNTS; i++){
        if(accounts[i][0] == accountNumber){
            if(accounts[i][1] == 0){
                printf("The account is not Active\n");
                flag1 = false;
            }
            if(accounts[i][1] == 1)
            {
                if(accounts[i][2] < 0){//case the account is in debt
                    printf("Your account number : %.0f is in debt! you cant close this account, please deposit tha money that you owe us !\n",accounts[i][0]);
                    break;
                }
                //case that every thing is fine
                accounts[i][1] = 0;
                accounts[i][2] = 0;
                printf("The account number : %.0f has been closed!\n",accounts[i][0]);
                flag1 = false;

            }
            break;
        }
        
    }
    if(flag1)
        printf("THERE IS NO ACCOUNT WITH THIS NUMBER\n\n");
         
}

void interestRate(float interest_rate){
    if(interest_rate >= 0){
    interest_rate /= 100;
    interest_rate += 1;
    for (int i = 0; i < NUM_OF_ACCOUNTS; i++){//adding the interst to each account
        if (accounts[i][1] == 1)
        {
            accounts[i][2] *= interest_rate;
            printf("%.0f - %.2f\n",accounts[i][0],accounts[i][2]);
        }
    
    }
        
    }else printf("Failed to read interest rate.\n");

}

void printAccounts(){//print all acounts
    for (int i = 0; i < NUM_OF_ACCOUNTS; i++){
        if(accounts[i][1] == 1){
            printf("%.0f - %.2f\n",accounts[i][0],accounts[i][2]);
        }
    }

}

void closeAll(){//closing all the accounts and kill the program
    for (int i = 0; i < NUM_OF_ACCOUNTS; i++){
        if(accounts[i][1] == 1){
            closeAccount(accounts[i][0]);
        }
    }
}
