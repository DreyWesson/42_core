#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv, char **envp)
{
	char *arr[] = {"/sbin/ping", "google.com", "-c", "1", NULL};
	int pid;
	(void)argc;
	(void)argv;
	(void)envp;
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		int file = open("output_file.txt", O_CREAT|O_WRONLY, 0);
		if (file == -1)
		{
			printf("Couldn't open file\n");
			return (2);
		}
		
		if( dup2(file, STDOUT_FILENO) == -1 )
		{
			perror( "dup2 failed" );
			exit( EXIT_FAILURE );
		}

		printf("STDOUT Hijacked\n");
		close(file);
		int err = execve("/sbin/ping", arr, envp);
		if (err == -1)
		{
			printf("Could not find the program to execute\n");
			return (2);
		}
	}
	else
	{
		int wstatus;
		wait(&wstatus);
		if (WIFEXITED(wstatus))
		{
			int status_code = WEXITSTATUS(wstatus);
			if (status_code == 0)
				printf("Success\n");
			else
				printf("Failed\n");
		}
		printf("Exec didn't hijack\n");
	}
	return (0);
}
