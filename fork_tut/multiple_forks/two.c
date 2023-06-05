#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <sys/wait.h>

typedef struct details {
	int		id1;
	int		id2;
	int		pid;
	int		ppid;
	char	*str;
}	t_args;

void	print_ids(t_args ids, char *str)
{
	printf("\033[32m""%s\n""\033[0m", str);
	printf("  PID: %d, Parent_ID: %d \n", ids.pid, ids.ppid);
	printf("  fork_id1: %d, fork_id2: %d \n\n", ids.id1, ids.id2);
}

int	main(void)
{
	t_args	ids;

	ids.id1 = fork();
	ids.id2 = fork();
	ids.pid = getpid();
	ids.ppid = getppid();

	if (ids.id1 == 0)
	{
		if (ids.id2 == 0) 
			print_ids(ids, "Grand_Child_Of_X:");
		else
			print_ids(ids, "First_Child:");
	}
	else
	{
		if (ids.id2 == 0)
			print_ids(ids, "Second_Child - Here id1 takes fork_id1 of parent");
		else
			print_ids(ids, "Parent");
	}
	while (wait(NULL) != -1 || errno != ECHILD);
	return (0);
}
