// C program to illustrate factorial calculation
// using fork() in C for Linux
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
  
int main(int argc , char *argv[] )
{
    pid_t pid;
	int nbr;

	if (argc != 2)
	{
		printf("arg missing or exceeding\n");
		exit(0);
	}

    // atoi converts string to integer
	nbr = atoi(argv[1]);
	if (nbr < 0)
	{
		printf("negative number entered %d", nbr);
		exit(0);
	}

	pid = fork();

	if (pid < 0)
	{
		printf("failed to create child\n");
		exit(0);
	}
    else if ( pid==0 )
    {
		//Child Process
		int ans = 0, i, j, k = 2, n;
  
		// atoi converts string to integer
		int arr[nbr], sum[nbr];
		arr[0] = 1;
		// generating factorial series
		for (i = 1 ; i < nbr; i++)
		{
            arr[i] = arr[i - 1] * k;
            k++;
		}
  
		// printing and sum of each sub-series
		for (j = 0; j < nbr; j++)
		{
			sum[j] = 0;
			for (i = 0; i <= j; i++)
			{
				printf(" %d ",arr[i]);
				sum[j] += arr[i];
			}
			printf("\n");
		}

		for (i = 0; i < n; i++)
		{
			if ((sum[i] % 2) == 0)
				sum[i] = -1;
		}

		printf("After deletion sum\n");
		for (i = 0; i < nbr; i++)
		{
            if (sum[i] > 0)
                printf(" %d ", sum[i]);
		}
		exit(0);
    }
    // parent process
    else
    {
        wait(NULL);
  
        // waiting for child process to end
        printf("Done\n");
    }
}