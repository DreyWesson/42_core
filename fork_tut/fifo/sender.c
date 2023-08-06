#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

int receive_sum()
{
	int	sum;
	int fd;

	sum = 0;
	printf("Re-opening...\n");
	fd = open("sum", O_RDONLY);
	if (fd == -1)
		return (1);
	if (read(fd, &sum, sizeof(int)) == -1)
		return (2);
	printf("Sum received is %d\n", sum);
	close(fd);
	return (0);
}

int main(void)
{
	int fd;
	int i = 0;
	int arr[] = {21, 42, 63, 84, 105};

	if (mkfifo("sum", 0777) == -1 && errno != EEXIST)
	{
			printf("Could not create fifo");
			return (1);
	}
	printf("Opening...\n");
	fd = open("sum", O_WRONLY);
	if (fd == -1)
		return (1);
	// while (i < 5)
	// {
		if (write(fd, arr, sizeof(int)) == -1)
			return (2);
	// 	printf("Writing %d into fifo\n", arr[i]);
	// 	i++;
	// }
	receive_sum();
	close(fd);
	return (0);
}