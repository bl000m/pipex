#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <errno .h>

int	main(int argc, char *argv[])
{
	int id = fork();
	if (id == 0)
	{
		printf("Child Fork ID: %d\n", id);
		printf("Current ID: %d, parent ID: %d\n", getpid(), getppid());
	}
	else
	{
		sleep(1);
		printf("Parent Fork ID: %d\n", id);
		printf("Current ID: %d, parent ID: %d\n", getpid(), getppid());
	}
	return (0);
}
