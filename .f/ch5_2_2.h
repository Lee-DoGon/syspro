// account.h
#ifndef ACCOUNT_H
#define ACCOUNT_H

#define START_ACC_NUM 1000 // Starting account number

struct account {
    int acc_num;      // Account number
    char name[30];    // Account holder's name
    float balance;    // Account balance
};

#endif
