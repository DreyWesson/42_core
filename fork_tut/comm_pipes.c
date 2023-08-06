#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <sys/wait.h>
// #include <sys/types.h>

// Using just a single pipe sample

int main(void)
{
	int fd[2];
	if (pipe(fd) == -1)
	{
		printf("Failed to open pipe");
		return (1);
	}

	if (fork() == 0)
	{
		char x[6] = "";
		close(fd[0]);
		printf("Write data\n");
		scanf("%s", x);
		write(fd[1], x, sizeof(char *));
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		char	y[6] = "";
		read(fd[0], y, sizeof(char *));
		close(fd[0]);
		printf("Child process sent -> %s", y);
	}
	wait(NULL);
	return (0);
}