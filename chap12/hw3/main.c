#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define WRITE 1
#define READ 0

int main(int argc, char* argv[])
{
    char *command1, *command2;
    int fd[2];
    pid_t pid1, pid2;

    if (argc < 3) {
        printf("Usage: %s command1 | command2\n", argv[0]);
        return 1;
    }

    pipe(fd);

    if ((pid1 = fork()) == 0) {
        close(fd[READ]);
        dup2(fd[WRITE], STDOUT_FILENO);
        close(fd[WRITE]);
        execvp(argv[1], &argv[1]);
        perror("execvp command1 failed");
        exit(1);
    }

    if ((pid2 = fork()) == 0) {
        close(fd[WRITE]);
        dup2(fd[READ], STDIN_FILENO);
        close(fd[READ]);
        execvp(argv[2], &argv[2]);
        perror("execvp command2 failed");
        exit(1);
    }

    close(fd[READ]);
    close(fd[WRITE]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return 0;
}
