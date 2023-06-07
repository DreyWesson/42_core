#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    int id1 = fork();
    int id2 = fork();
    int id3 = fork();
    int id4 = fork();

	if (id1 > 0 && id2 > 0 && id3 > 0 && id4 > 0)
	{
		printf("\033[32m""Parent:\n""\033[0m");
    	printf("  id1: %d, id2: %d, id3: %d, id4: %d, pid: %d, ppid: %d\n", id1, id2, id3, id4, getpid(), getppid());
	}

	if (id1 == 0 && id2 > 0 && id3 > 0 && id4 > 0)
	{
		printf("\033[34m""Child:\n""\033[0m");
    	printf("  id1: %d, id2: %d, id3: %d, id4: %d, pid: %d, ppid: %d\n", id1, id2, id3, id4, getpid(), getppid());	
	}
	if (id1 > 0 && id2 > 0 && id3 == 0 && id4 > 0)
	{
		printf("\033[34m""Child:\n""\033[0m");
    	printf("  id1: %d, id2: %d, id3: %d, id4: %d, pid: %d, ppid: %d\n", id1, id2, id3, id4, getpid(), getppid());
	}
	if (id1 > 0 && id2 == 0 && id3 > 0 && id4 > 0)
	{
		printf("\033[34m""Child:\n""\033[0m");
    	printf("  id1: %d, id2: %d, id3: %d, id4: %d, pid: %d, ppid: %d\n", id1, id2, id3, id4, getpid(), getppid());
	}
	if (id1 > 0 && id2 > 0 && id3 > 0 && id4 == 0)
	{
		printf("\033[34m""Child:\n""\033[0m");
    	printf("  id1: %d, id2: %d, id3: %d, id4: %d, pid: %d, ppid: %d\n", id1, id2, id3, id4, getpid(), getppid());
	}


	if (id1 == 0 && id2 == 0 && id3 > 0 && id4 > 0)
	{
		printf("\033[0;33m""Grand Child:\n""\033[0m");
    	printf("  id1: %d, id2: %d, id3: %d, id4: %d, pid: %d, ppid: %d\n", id1, id2, id3, id4, getpid(), getppid());
	}
	if (id1 == 0 && id2 > 0 && id3 > 0 && id4 == 0)
	{
		printf("\033[0;33m""Grand Child:\n""\033[0m");
    	printf("  id1: %d, id2: %d, id3: %d, id4: %d, pid: %d, ppid: %d\n", id1, id2, id3, id4, getpid(), getppid());
	}
	if (id1 == 0 && id2 > 0 && id3 == 0 && id4 > 0)
	{
		printf("\033[0;33m""Grand Child:\n""\033[0m");
    	printf("  id1: %d, id2: %d, id3: %d, id4: %d, pid: %d, ppid: %d\n", id1, id2, id3, id4, getpid(), getppid());
	}
	if (id1 > 0 && id2 > 0 && id3 == 0 && id4 == 0)
	{
		printf("\033[0;33m""Grand Child:\n""\033[0m");
    	printf("  id1: %d, id2: %d, id3: %d, id4: %d, pid: %d, ppid: %d\n", id1, id2, id3, id4, getpid(), getppid());
	}
	if (id1 > 0 && id2 == 0 && id3 > 0 && id4 == 0)
	{
		printf("\033[0;33m""Grand Child:\n""\033[0m");
    	printf("  id1: %d, id2: %d, id3: %d, id4: %d, pid: %d, ppid: %d\n", id1, id2, id3, id4, getpid(), getppid());
	}
	if (id1 > 0 && id2 == 0 && id3 == 0 && id4 > 0)
	{
		printf("\033[0;33m""Grand Child:\n""\033[0m");
    	printf("  id1: %d, id2: %d, id3: %d, id4: %d, pid: %d, ppid: %d\n", id1, id2, id3, id4, getpid(), getppid());
	}


	if (id1 == 0 && id2 > 0 && id3 == 0 && id4 == 0)
	{
		printf("\033[0;31m""Great Grand Child:\n""\033[0m");
    	printf("  id1: %d, id2: %d, id3: %d, id4: %d, pid: %d, ppid: %d\n", id1, id2, id3, id4, getpid(), getppid());
	}
	if (id1 == 0 && id2 == 0 && id3 == 0 && id4 > 0)
	{
		printf("\033[0;31m""Great Grand Child:\n""\033[0m");
    	printf("  id1: %d, id2: %d, id3: %d, id4: %d, pid: %d, ppid: %d\n", id1, id2, id3, id4, getpid(), getppid());
	}
	if (id1 == 0 && id2 == 0 && id3 > 0 && id4 == 0)
	{
		printf("\033[0;31m""Great Grand Child:\n""\033[0m");
    	printf("  id1: %d, id2: %d, id3: %d, id4: %d, pid: %d, ppid: %d\n", id1, id2, id3, id4, getpid(), getppid());
	}
	if (id1 > 0 && id2 == 0 && id3 == 0 && id4 == 0)
	{
		printf("\033[0;31m""Great Grand Child:\n""\033[0m");
    	printf("  id1: %d, id2: %d, id3: %d, id4: %d, pid: %d, ppid: %d\n", id1, id2, id3, id4, getpid(), getppid());
	}

	if (id1 == 0 && id2 == 0 && id3 == 0 && id4 == 0)
	{
		printf("\033[2;37m""Great Great Grand Child:\n""\033[0m");
    	printf("  id1: %d, id2: %d, id3: %d, id4: %d, pid: %d, ppid: %d\n", id1, id2, id3, id4, getpid(), getppid());
	}

    return 0;
}