#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int main(void)
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int i;
	int res;
	int fd[2];
	int	tmp;

	if (pipe(fd) == -1)
	{
		printf("Pipe failed to open");
		return (1);
	}
	res = 0;
	if (fork() == 0)
	{
		close(fd[0]);
		i = 5;
		while (i < 10)
			res += arr[i++];
		write(fd[1], &res, sizeof(int));
		close(fd[1]);
	}
	else
	{
		tmp = 0;
		close(fd[1]);
		i = 0;
		while (i < 5)
			res += arr[i++];
		read(fd[0], &tmp, sizeof(int));
		res += tmp;
		close(fd[0]);
		printf("Total -> %d\n", res);
	}
	while (wait(NULL) != -1 || errno != ECHILD)
	{
	}
	return (0);
}