#ifndef MY_BANK_H  
#define MY_BANK_H
#define NUM_OF_ACCOUNTS 50

//int accounts[NUM_OF_ACCOUNTS][3];

void newAccount();//if there is a room for a new account - open and ask for deposit
void accountStatus(float accountNumber);//if the account is open - print the amount of money
void deposit(float accountNumber);
void withdraw(float accountNumber);
void closeAccount(float accountNumber);//closing the acount only if the account was open before
void interestRate(float interest_rate);// adding interst rate
void printAccounts();//prints all the accounts in the bank
void closeAll();//close all the accounts in the bank and kill the program 




#endif