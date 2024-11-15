#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAXARG 100

void trim_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    char input[1024];
    char *args[MAXARG];
    char *token;
    pid_t pid, child;
    int background, status;

    while (1) {
        printf("[Shell] ");
        fflush(stdout);

        if (!fgets(input, sizeof(input), stdin)) {
            break;
        }
        
        trim_newline(input);
        
        background = 0;
        if (input[strlen(input) - 1] == '&') {
            background = 1;
            input[strlen(input) - 1] = '\0';
        }

        token = strtok(input, " ");
        int i = 0;
        while (token != NULL) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        if (args[0] != NULL && strcmp(args[0], "exit") == 0) {
            break;
        }

        printf("[%d] Parent process start\n", getpid());
        
        pid = fork();
        
        if (pid < 0) {
            perror("Fork failed");
            exit(1);
        }

        if (pid == 0) {
            if (execvp(args[0], args) == -1) {
                perror("execvp failed");
                exit(1);
            }
        } else {
            if (!background) {
                child = wait(&status);
                if (child == -1) {
                    perror("Wait failed");
                } else {
                    printf("[%d] Child process %d finished with status %d\n", getpid(), child, WEXITSTATUS(status));
                }
            }
        }
    }

    return 0;
}
