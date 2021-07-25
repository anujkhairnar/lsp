#include <stdio.h>
#include <signal.h>
#include <stdbool.h>

bool is_run = true;

void sig_handler(int signum)
{
	printf("Signal received is: %d\n", signum);
	is_run = false;
}

int main()
{
	signal(SIGINT, sig_handler);

	while(is_run)
	{
		
	}
	printf("Out of while loop\n");

	return 0;
}
