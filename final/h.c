#include <stdio.h>
#include <stdlib.h>

// void exit(int status);
// void _exit(int status);
// void atexit(void (*func)(void));
// returns: 0 if OK, nonzero on error

static void exit_handler1(void), exit_handler2(void);

int main(void)
{
	if (atexit(exit_handler1) != 0)
		perror("exit_handler1 can't regist");
	if (atexit(exit_handler2) != 0)
		perror("exit_handler1 can't regist");

	printf("main end\n");

	exit(0);
}

static void exit_handler1(void)
{
	printf("first exit handler1\n");
}

static void exit_handler2(void)
{
	printf("second exit handler2\n");
}
