#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <sys/wait.h>

int main()
{
	int i = 0;
	int sum = 0;

	int id = fork();
	if (id != 0)
		wait(0);
	while (++i <= 5)
	{
		if (id != 0 && i % 2 == 0)
			sum += i;
		if (id == 0 && i % 2 != 0)
			sum += i;
	}
	if (id == 0)
		printf("Odd numbers -> Child: %d\n", sum);
	else
		printf("Even numbers -> Parent: %d\n", sum);
	return (0);
}
