#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "store.h"

int main(int argc, char *argv[])
{
	int fd;
	struct store rec;

	//fd = open(argv[1], O_WRONLY);

	fd = open(argv[1], O_WRONLY|O_CREAT, 0640);

	printf("%s \t%s \t%s \t%s \t%s\n", "id", "name", "category", "expire date", "stock");

/*
  .h
struct store
{
	int id;
	char name[MAX];
	char category[MAX];
	int exp_date;
	int stock;
};
*/

	while (scanf("%d %s %s %d %d", &rec.id, rec.name, rec.category, &rec.exp_date, &rec.stock) == 5)
	{
		lseek(fd, (rec.id - START_ID) * sizeof(rec), SEEK_SET);

		write(fd, &rec, sizeof(rec));
	}

	close(fd);

	exit(0);
}
