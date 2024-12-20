#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "student.h"

int main(int argc, char *argv[])
{
	int fd, id;
	struct student rec;
	struct flock lock;

	if (argc < 2)
		exit(1);

	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		perror(argv[1]);
		exit(2);
	}

	printf("\nEnter StudentId to search : ");

	while (scanf("%d", &id) == 1)
	{
		lock.l_type = F_RDLCK;
		lock.l_whence = SEEK_SET;
		lock.l_start = (id-START_ID)*sizeof(rec);
		lock.l_len = sizeof(rec);

		if (fcntl(fd, F_SETLKW, &lock) == -1)
		{
			perror(argv[1]);
			exit(3);
		}

		lseek(fd, (id-START_ID)*sizeof(rec), SEEK_SET);

		if ((read(fd, (char*)&rec, sizeof(rec)) > 0) && (rec.id != 0))
			printf("Name:%s\t StuID:%d\t Score:%d\n", rec.name, rec.id, rec.score);
		else
			printf("No rec %d\n", id);

		lock.l_type = F_UNLCK;
		fcntl(fd, F_SETLK, &lock);
		printf("\nEnter StuID to search : ");
	}

	close(fd);

	exit(0);
}
