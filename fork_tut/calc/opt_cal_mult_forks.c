#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

void writer(int *fd, int start, int end, int *arr, char *str)
{
	int res = 0;
	close(fd[0]);
	while (start < end)
		res += arr[start++];
	write(fd[1], &res, sizeof(int));
	close(fd[1]);
	printf("%s %d\n", str, res);
	return (res);
}

void read_and_write(int *fd, int start, int end, int *arr, char *str)
{
	// int res = 0;
	// close(fd[0]);
	// while (start < end)
	// 	res += arr[start++];
	// write(fd[1], &res, sizeof(int));
	// close(fd[1]);
	// printf("%s %d\n", str, res);
	// return (res);
	int total = 0;
	int tmp = 0;

	while (start < end)
		total += arr[start++];
	read(fd[0], &tmp, sizeof(int));
	
	total += tmp;
	write(fd[1], &total, sizeof(int));
	printf("%s %d\n", str, total);
	// printf("2nd Total -> %d\n", total);
	close(fd[0]);
	close(fd[1]);
	if (!strcmp(str, "Parent ->"))
		printf("Total -> %d\n", total);
}

int main(void)
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	int i;
	int total;
	int fd[2];
	int	tmp;

	if (pipe(fd) == -1)
	{
		printf("Pipe failed to open");
		return (1);
	}
	int id1 = fork();
	int id2 = fork();
	// ANS should be 90 + 65 + 40 + 15 = 210

	total = 0;
	if (id1 == 0)
	{
		if (id2 == 0)
		{
			tmp = 0;
			i = 0;
			while (i < 5)
				total += arr[i++];
			read(fd[0], &tmp, sizeof(int));
			printf("Second -> %d %d\n", tmp, total);
			total += tmp;
			write(fd[1], &total, sizeof(int));
			printf("2nd Total -> %d\n", total);
			close(fd[0]);
			close(fd[1]);
		}
			// writer(fd, 0, 5, arr, "Grand Child ->");
		else
		{
			tmp = 0;
			// close(fd[1]);
			i = 5;
			while (i < 10)
				total += arr[i++];
			read(fd[0], &tmp, sizeof(int));
			printf("Second -> %d %d\n", tmp, total);
			total += tmp;
			write(fd[1], &total, sizeof(int));
			printf("2nd Total -> %d\n", total);
			close(fd[0]);
			close(fd[1]);
		}
			// writer(fd, 5, 10, arr, "2nd Child ->");
	}
	else
	{
		if (id2 == 0)
		// {
		// 	tmp = 0;
		// 	// close(fd[1]);
		// 	i = 5;
		// 	while (i < 10)
		// 		total += arr[i++];
		// 	read(fd[0], &tmp, sizeof(int));
		// 	printf("First -> %d %d\n", tmp, total);
		// 	total += tmp;
		// 	write(fd[1], &total, sizeof(int));
		// 	printf("1st Total -> %d\n", total);
		// 	close(fd[0]);
		// 	close(fd[1]);
		// }
			writer(fd, 10, 15, arr, "1st Child ->");
		else
		{
			while (wait(NULL) != -1 || errno != ECHILD)
			{
			}
			tmp = 0;
			close(fd[1]);
			i = 15;
			while (i < 20)
				total += arr[i++];
			read(fd[0], &tmp, sizeof(int));
			total += tmp;
			printf("Parent -> %d %d\n", tmp, total);
			close(fd[0]);
			printf("Total -> %d\n", total);
		}
	}
	return (0);
}