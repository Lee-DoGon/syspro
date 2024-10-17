#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int i;
    struct stat buf;

    for (i = 1; i < argc; i++)
    {
        printf("%s: ", argv[i]);

        if (lstat(argv[i], &buf) < 0)
        {
            perror("lstat()");
            continue;
        }

        if (S_ISREG(buf.st_mode))
            printf("Regular file\n");
        else if (S_ISDIR(buf.st_mode))
            printf("Directory\n");
        else if (S_ISCHR(buf.st_mode))
            printf("Character device\n");
        else if (S_ISFIFO(buf.st_mode))
            printf("FIFO (named pipe)\n");
        else if (S_ISLNK(buf.st_mode))
            printf("Symbolic link\n");
        else if (S_ISSOCK(buf.st_mode))
            printf("Socket\n");
        else
            printf("Other type\n");
    }

    exit(0);
}


/*
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int i;
	struct stat buf;

	for (i = 1; i < argc; i++)
	{
		printf("%s: ",argv[i]);

		if (lstat(argv[i], &buf) < 0)
		{
			perror("lstat()");
			continue;
		}

		if (S_ISREG(buf.st_mode))
			printf("%s \n", file);
		if (S_ISDIR(buf.st_mode))
			printf("%s \n", div);
		if (S_ISCHR(buf.st_mode))
			printf("%s \n", chdir);
		if (S_ISFIFO(buf.st_mode))
			printf("%s \n", mkfifo);
		if (S_ISLNK(buf.st_mode))
			printf("%s \n", link);
		if (S_ISSOCK(buf.st_mode))
			printf("%s \n", sock);
	}

	exit(0);
}
*/
