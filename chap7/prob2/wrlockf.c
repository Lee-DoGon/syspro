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

	if (argc < 2)
		exit(1);

	if ((fd = open(argv[1], O_RDWR)) == -1)
	{
		perror(argv[1]);
		exit(2);
	}

	printf("\nEnter StudID to modify : ");

	while (scanf("%d", &id) == 1)
	{
		lseek(fd, (long)(id-START_ID)*sizeof(rec), SEEK_SET);

		if (lockf(fd, F_LOCK, sizeof(rec)) == -1)
		{
			perror(argv[1]);
			exit(3);
		}

		if ((read(fd, (char*)&rec, sizeof(rec)) > 0) && (rec.id != 0))
		{
			printf("Name:%s\t StuID:%d\t Score:%d\n", rec.name, rec.id, rec.score);

		printf("Enter new Score : ");
		scanf("%d", &rec.score);
		lseek(fd, (long) -sizeof(rec), SEEK_CUR);
		write(fd, (char*)&rec, sizeof(rec));

		lseek(fd, (long) (id-START_ID)*sizeof(rec), SEEK_SET);
		lockf(fd, F_ULOCK, sizeof(rec));
		}

		else
			printf("no rec %d\n", id);
	
		printf("\nEnter StuID to modify : ");
	}

	close(fd);
	
	exit(0);
}
