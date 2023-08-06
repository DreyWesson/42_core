
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
	int fd[2];
	int rand;
	int pid;

	if (pipe(fd) == -1)
	{
		printf("Some error occurred\n");
		return (2);
	}
	pid = fork();
	
	if (pid < 0)
	{
		printf("Couldn't fork\n");
	}
	if (pid == 0)
	{
		close(fd[0]);
		rand = 42;
		printf("Child -> %d\n", rand);
		if (write(fd[1], &rand, sizeof(int)) == -1)
		{
			printf("Some error occurred\n");
			return (1);
		}
	}
	else if (pid > 0)
	{
		close(fd[1]);
		wait(NULL);
		if (read(fd[0], &rand, sizeof(int)) == -1)
		{
			printf("Some error occurred\n");
			return (1);
		}
		printf("Child process sent -> %d\n", rand);
	}
	return (0);
}
