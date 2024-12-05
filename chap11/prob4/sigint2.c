#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

struct sigaction newact;
struct sigaction oldact;

void sigint_handler(int signo)
{
	printf("signal number %d\n", signo);
	printf("press it again, Exit\n");
	sigaction(SIGINT, &oldact, NULL);
}


int main()
{
	newact.sa_handler = sigint_handler;
	sigfillset(&newact.sa_mask);
	sigaction(SIGINT, &newact, &oldact);

	while (1)
	{
		printf("Type Ctrl-C\n");
		sleep(1);
	}
}