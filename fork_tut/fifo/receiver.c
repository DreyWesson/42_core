#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

int	send_sum(int fd, int sum)
{
	fd = open("sum", O_WRONLY);
	if (fd == -1)
		return (1);
	if (write(fd, &sum, sizeof(int)) == -1)
		return (2);
	printf("Sum sent is %d\n", sum);
	close(fd);
	return (0);
}

int	main(void)
{
	int	fd;
	int	arr[5];
	int	i = 0;
	int	sum = 0;


	printf("Opening...\n");
	fd = open("sum", O_RDONLY);
	if (fd == -1)
		return (1);
	while (i < 5)
	{
		if (read(fd, &arr[i], sizeof(int)) == -1)
			return (2);
		printf("Received %d from fifo\n", arr[i]);
		sum += arr[i];
		i++;
	}
	printf("Sum is %d\n", sum);
	send_sum(fd, sum);
	close(fd);
	return (0);
}