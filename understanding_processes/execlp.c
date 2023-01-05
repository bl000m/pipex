#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int	main(int argc, char *argv[])
{
	execlp("ping", "ping", "-c", "3", "42.fr", NULL);
	return(0);
}
