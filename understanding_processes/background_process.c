#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void	handle_sigcont(int sig)
{
	printf("Input number: \n");
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;
	int					x;

	sa.sa_handler = &handle_sigcont;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGCONT, &sa, NULL);
	printf("write a number: \n");
	scanf("%d", &x);
	printf("result = %d\n", x * 5);
	return (0);
}
