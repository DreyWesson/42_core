#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <sys/wait.h>

int main(void)
{
	int	p1[2];
	int	p2[2];
	int	x;
	int	pid;
	
	if (pipe(p1) == -1)
		return (-1);
	if (pipe(p2) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
		return (2);
	if (pid == 0)
	{
		close(p2[1]);
		close(p1[0]);
		if (read(p2[0], &x, sizeof(x)) == -1) return (3);
		printf("Child Received %d\n", x);
		x *= 4;
		if (write(p1[1], &x, sizeof(x)) == -1) return (4);
		printf("Child modified X and wrote %d\n", x);
	}
	else
	{
		close(p2[0]);
		close(p1[1]);
		x = 10;
		if (write(p2[1], &x, sizeof(x)) == -1) return (5);
		printf("Parent Wrote %d\n", x);
		if (read(p1[0], &x, sizeof(x)) == -1) return (6);
		printf("Parent Received %d\n", x);
		close(p2[1]);
		close(p1[0]);
	}
	return (0);
}
