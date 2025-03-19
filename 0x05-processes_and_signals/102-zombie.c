#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * infinit_while - infinite while loop.
 *
 * Return: Always 0.
 */
int	infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 * main - Entry point of the program.  
 *
 * Return: Always 0.
 */
int main(void)
{
	int i;

	i = 0;
	while (i < 5)
	{
		int pid = fork(); 

		if (pid < 0)
		{
			write(2, "Forking has failed\n", 20);
			exit(1);
		}
	
		if (pid == 0)
			exit(0);
		else
		{
			printf("Zombie process created, PID: %d\n", pid);
			i++;
		}

	} 
	infinite_while();
	return (0);
}
