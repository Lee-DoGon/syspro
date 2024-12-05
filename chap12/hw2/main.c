#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 100

int main() {
    int fd1[2], fd2[2];
    pid_t pid1, pid2;
    char input[MAXLINE], modified[MAXLINE];

    pipe(fd1);
    pipe(fd2);

    printf("parent process start\n");

    if ((pid1 = fork()) == 0) {
        close(fd1[0]);
        close(fd2[0]);
        close(fd2[1]);

        // 사용자로부터 문자열 입력 받기
        printf("input string: ");
        fgets(input, MAXLINE, stdin);
        input[strcspn(input, "\n")] = 0;

        write(fd1[1], input, strlen(input) + 1);
        close(fd1[1]); // 쓰기 끝 닫기

        exit(0);
    }

    if ((pid2 = fork()) == 0) {
        // 두 번째 자식 프로세스
        close(fd1[1]);
        close(fd2[0]);

        read(fd1[0], input, MAXLINE);
        close(fd1[0]);

        for (int i = 0; input[i]; i++) {
            input[i] = toupper(input[i]);
        }

        printf("%s\n", input);
        close(fd2[1]); // 쓰기 끝 닫기
        exit(0);
    }

    close(fd1[0]);
    close(fd1[1]);
    close(fd2[0]);
    close(fd2[1]);

    wait(NULL);
    wait(NULL);

    return 0;
}
