#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int	x = 0;

void	handle_sigusr1(int sig)
{
	printf("remember to answer!\n");
}

//getppid() => to get parent pid
//sa_flags => just with scanf
int	main(int argc, char *argv[])
{
	int	pid;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		sleep(5);
		kill(getppid(), SIGUSR1);
	}
	else
	{
		struct sigaction sa = { 0 };
		sa.sa_flags = SA_RESTART;
		sa.sa_handler = &handle_sigusr1;
		sigaction(SIGUSR1, &sa, NULL);

		printf("What's the result of 6 x 7? \n");
		scanf("%d", &x);
		if (x == 42)
			printf("right\n");
		else
			printf("wrong\n");
	}
	return (0);
}
