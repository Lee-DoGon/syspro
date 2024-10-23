// create_account.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "account.h"

int main(int argc, char *argv[]) {
    int fd;
    struct account acc;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        exit(1);
    }

    if ((fd = open(argv[1], O_WRONLY | O_CREAT, 0640)) == -1) {
        perror(argv[1]);
        exit(2);
    }

    printf("Enter Account Number, Name, Initial Balance: ");
    while (scanf("%d %s %f", &acc.acc_num, acc.name, &acc.balance) == 3) {
        lseek(fd, (acc.acc_num - START_ACC_NUM) * sizeof(acc), SEEK_SET);
        write(fd, &acc, sizeof(acc));
        printf("Enter Account Number, Name, Initial Balance: ");
    }

    close(fd);
    exit(0);
}
