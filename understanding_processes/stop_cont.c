#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>

int	main(int argc, char *argv[])
{
	int	pid = fork();
	int	t = 1;
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		//this loop is a placeholder for something more high level
		while (1)
		{
			printf("something\n");
			usleep(50000);
		}
		//
	}
	else
	{
		kill(pid, SIGSTOP);
		while (t > 0)
		{
			printf("time in seconds: ");
			scanf("%d", &t);
			if (t > 0)
			{
				kill(pid, SIGCONT);
				sleep(t);
				kill(pid, SIGSTOP);
			}
		}
		kill(pid, SIGKILL);
		wait(NULL);
	}
	return (0);
}
