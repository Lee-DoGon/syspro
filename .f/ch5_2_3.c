// manage_account.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "account.h"

void deposit(int fd, int acc_num, float amount);
void withdraw(int fd, int acc_num, float amount);
void check_balance(int fd, int acc_num);

int main(int argc, char *argv[]) {
    int fd, acc_num;
    char c;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        exit(1);
    }

    if ((fd = open(argv[1], O_RDWR)) == -1) {
        perror(argv[1]);
        exit(2);
    }

    do {
        printf("Enter Account Number: ");
        scanf("%d", &acc_num);
        printf("Options: D - Deposit, W - Withdraw, C - Check Balance: ");
        scanf(" %c", &c);

        switch (c) {
            case 'D':
                {
                    float amount;
                    printf("Enter Deposit Amount: ");
                    scanf("%f", &amount);
                    deposit(fd, acc_num, amount);
                }
                break;
            case 'W':
                {
                    float amount;
                    printf("Enter Withdraw Amount: ");
                    scanf("%f", &amount);
                    withdraw(fd, acc_num, amount);
                }
                break;
            case 'C':
                check_balance(fd, acc_num);
                break;
            default:
                printf("Invalid option\n");
        }

        printf("Continue? (Y/N): ");
        scanf(" %c", &c);
    } while (c == 'Y');

    close(fd);
    exit(0);
}

void deposit(int fd, int acc_num, float amount) {
    struct account acc;

    lseek(fd, (acc_num - START_ACC_NUM) * sizeof(acc), SEEK_SET);
    read(fd, &acc, sizeof(acc));

    if (acc.acc_num != 0) {
        acc.balance += amount;
        lseek(fd, (acc_num - START_ACC_NUM) * sizeof(acc), SEEK_SET);
        write(fd, &acc, sizeof(acc));
        printf("New Balance: %.2f\n", acc.balance);
    } else {
        printf("Account not found.\n");
    }
}

void withdraw(int fd, int acc_num, float amount) {
    struct account acc;

    lseek(fd, (acc_num - START_ACC_NUM) * sizeof(acc), SEEK_SET);
    read(fd, &acc, sizeof(acc));

    if (acc.acc_num != 0) {
        if (acc.balance >= amount) {
            acc.balance -= amount;
            lseek(fd, (acc_num - START_ACC_NUM) * sizeof(acc), SEEK_SET);
            write(fd, &acc, sizeof(acc));
            printf("New Balance: %.2f\n", acc.balance);
        } else {
            printf("Insufficient funds.\n");
        }
    } else {
        printf("Account not found.\n");
    }
}

void check_balance(int fd, int acc_num) {
    struct account acc;

    lseek(fd, (acc_num - START_ACC_NUM) * sizeof(acc), SEEK_SET);
    read(fd, &acc, sizeof(acc));

    if (acc.acc_num != 0) {
        printf("Account Number: %d, Name: %s, Balance: %.2f\n", acc.acc_num, acc.name, acc.balance);
    } else {
        printf("Account not found.\n");
    }
}
