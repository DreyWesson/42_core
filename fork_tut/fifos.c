#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	int val = 65;
	if (mkfifo("myfifo1", 0777) == -1)
	{
		if (errno != EEXIST)
		{
			printf("Could not create fifo");
			return (1);
		}
	}
	printf("Opening...\n");
	fd = open("myfifo1", O_WRONLY);
	printf("Opened\n");
	if (write(fd, &val, sizeof(val)) == -1)
		return (2);
	printf("Written\n");
	close(fd);
	printf("Closed\n");
	return (0);
}