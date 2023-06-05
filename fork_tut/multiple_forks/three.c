#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <sys/wait.h>

typedef struct args {
	int		id1;
	int		id2;
	int		id3;
	int		pid;
	int		ppid;
	char	*str;
}	t_args;

void print_ids(t_args ids, char *str)
{
	if (!strcmp(str, "gggc"))
		printf("\033[2;37m""Great Great Grand Child:\n""\033[0m");
	else if (!strcmp(str, "ggc"))
		printf("\033[0;31m""Great Grand Child:\n""\033[0m");
	else if (!strcmp(str, "gc"))
		printf("\033[0;33m""Grand Child:\n""\033[0m""\033[0m");
	else if (!strcmp(str, "c"))
		printf("\033[34m""Child:\n""\033[0m");
	else
		printf("\033[32m""Parent:\n""\033[0m");
    printf("  id1: %d, id2: %d, id3: %d, pid: %d, ppid: %d\n", ids.id1, ids.id2, ids.id3, ids.pid, ids.ppid);
}

int main()
{
	t_args	ids;

	ids.id1 = fork();
	ids.id2 = fork();
	ids.id3 = fork();
	ids.pid = getpid();
	ids.ppid = getppid();

	if (ids.id1 == 0)
	{
		if (ids.id2 == 0)
		{
			if (ids.id3 == 0)
			{
				print_ids(ids, "ggc");
			} else {
				print_ids(ids, "gc");
			}
		} else {
			if (ids.id3 == 0)
			{
				print_ids(ids, "gc");
			} else {
				print_ids(ids, "c");
			}
		}
	}
	else
	{
		if (ids.id2 == 0)
		{
			if (ids.id3 == 0)
			{
					print_ids(ids, "gc");
			} else {
				print_ids(ids, "c");
			}
		} else {
			if (ids.id3 == 0)
			{
				print_ids(ids, "c");
			}
			else
			{
				print_ids(ids, "");
			}	
		}
	}
	while (wait(NULL) != -1 || errno != ECHILD)
	{
	}
    return 0;
}