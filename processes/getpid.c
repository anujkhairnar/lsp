#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("My pid is = %d\nMy parent pid is = %d\n", getpid(), getppid());
}
