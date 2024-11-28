#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void alarmHandler(int signo);
void sigint_handler(int signo);
void signal_my(int signo, void (*handler)(int));

int main()
{
    signal_my(SIGALRM, alarmHandler);
    alarm(5);

    short i = 0;

    while (1)
    {
        sleep(1);
        i++;
        printf("%d second\n", i);
    }

    printf("end\n");
}

void signal_my(int signo, void (*handler)(int))
{
    struct sigaction newact;
    
    newact.sa_handler = handler;
    sigemptyset(&newact.sa_mask);
    newact.sa_flags = 0;

    if (sigaction(signo, &newact, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }
}

void alarmHandler(int signo)
{
    printf("Wake up\n");
    exit(0);
}
