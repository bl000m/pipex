#include<stdlib.h>
#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<time.h>

int	main(int argc, char *argv[])
{
	int	fd[2];
	int	pid;
	int	n;
	int	i;
	int	arr[10];
	int sum;

	sum = 0;
	i = 0;
	if (pipe(fd) == -1)
		return (2);
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		close(fd[0]);
		//generate n random numbers
		srand(time(NULL));
		n = rand() % 10 + 1;
		printf("Generated: ");
		while (i < n)
		{
			arr[i] = rand() % 11;
			printf("%d ", arr[i]);
			i++;
		}
		//send n to parent
		if (write(fd[1], &n, sizeof(int)) < 0)
			return (4);
		printf("Sent %d numbers\n", n);
		//send numbers
		if (write(fd[1], arr, sizeof(int) * n) < 0)
			return
		printf("Array sent from child to parent\n");
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		//read n from child
		if (read(fd[0], &n, sizeof(int)) < 0)
			return (6);
		printf("Received in array %d numbers\n", n);
		if (read(fd[0], arr, sizeof(int) * n) < 0)
			return 7;
		close(fd[0]);
		while (i < n)
			sum += arr[i++];
		printf("Result is: %d \n", sum);
		//read numbers
	}
	wait(NULL);
	return (0);
}
