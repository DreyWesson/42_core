#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>


int	sum(int start, int end, int *arr)
{
	int	res;

	res = 0;
	while (start < end)
		res += arr[start++];
	return (res);
}

void	writer(int *fd, int start, int end, int *arr, char *str)
{
	int	res;

	close(fd[0]);
	res = sum(start, end, arr);
	write(fd[1], &res, sizeof(int));
	close(fd[1]);
	printf("%s %d\n", str, res);
}

void read_and_write(int *fd, int start, int end, int *arr, char *str)
{
	int total = 0;
	int tmp = 0;

	total = sum(start, end,arr);
	read(fd[0], &tmp, sizeof(int));
	total += tmp;
	write(fd[1], &total, sizeof(int));
	if (strcmp(str, "Parent ->"))
		printf("%s %d\n", str, total);
	close(fd[0]);
	close(fd[1]);
	if (!strcmp(str, "Parent ->"))
		printf("%s Total = %d\n", str, total);
}

int	main(void)
{
	int	arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	int	fd[2];
	int	id1;
	int	id2;

	if (pipe(fd) == -1)
	{
		printf("Pipe failed to open");
		return (1);
	}

	id1 = fork();
	id2 = fork();
	if (id1 == 0)
	{
		if (id2 == 0)
			read_and_write(fd, 0, 5, arr, "Grand Child ->");
		else
			read_and_write(fd, 5, 10, arr, "2nd Child ->");
	}
	else
	{
		if (id2 == 0)
			writer(fd, 10, 15, arr, "1st Child ->");
		else
		{
			while (wait(NULL) != -1 || errno != ECHILD);
			read_and_write(fd, 15, 20, arr, "Parent ->");
		}
	}
	return (0);
}