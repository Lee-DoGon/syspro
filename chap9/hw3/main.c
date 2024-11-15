#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_CMD_LENGTH 1024
#define MAX_ARGS 100

void execute_command(char *command);
void execute_multiple_commands(char *input);
void execute_redirect(char *command, int is_input_redirect, const char *file);

int main() {
    char input[MAX_CMD_LENGTH];

    while (1) {
        printf("[shell] ");
        if (fgets(input, MAX_CMD_LENGTH, stdin) == NULL) {
            break;
        }

        input[strcspn(input, "\n")] = 0;

        execute_multiple_commands(input);
    }

    return 0;
}

void execute_multiple_commands(char *input) {
    char *cmd;
    char *commands[MAX_ARGS];
    int cmd_count = 0;

    cmd = strtok(input, ";");
    while (cmd != NULL) {
        commands[cmd_count++] = cmd;
        cmd = strtok(NULL, ";");
    }

    for (int i = 0; i < cmd_count; i++) {
        execute_command(commands[i]);
    }
}

void execute_command(char *command) {
    pid_t pid;
    char *args[MAX_ARGS];
    char *token;
    int background = 0;
    int is_input_redirect = 0, is_output_redirect = 0;
    char input_file[MAX_CMD_LENGTH], output_file[MAX_CMD_LENGTH];

    if (strchr(command, '&')) {
        background = 1;
        command[strlen(command) - 1] = 0;
    }

    if ((token = strchr(command, '<')) != NULL) {
        *token = 0;
        is_input_redirect = 1;
        strcpy(input_file, token + 1);
        token = strtok(input_file, " \t\n");
    }

    if ((token = strchr(command, '>')) != NULL) {
        *token = 0;
        is_output_redirect = 1;
        strcpy(output_file, token + 1);
        token = strtok(output_file, " \t\n");
    }

    token = strtok(command, " \t\n");
    int arg_count = 0;
    while (token != NULL) {
        args[arg_count++] = token;
        token = strtok(NULL, " \t\n");
    }
    args[arg_count] = NULL;

    pid = fork();
    if (pid == 0) {
        if (is_input_redirect) {
            int fd_in = open(input_file, O_RDONLY);
            if (fd_in == -1) {
                perror("Input redirection failed");
                exit(1);
            }
            dup2(fd_in, STDIN_FILENO);
            close(fd_in);
        }

        if (is_output_redirect) {
            int fd_out = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fd_out == -1) {
                perror("Output redirection failed");
                exit(1);
            }
            dup2(fd_out, STDOUT_FILENO);
            close(fd_out);
        }

        if (execvp(args[0], args) == -1) {
            perror("Execution failed");
            exit(1);
        }
    } else if (pid > 0) {
        if (!background) {
            wait(NULL);
        }
    } else {
        perror("Fork failed");
    }
}
