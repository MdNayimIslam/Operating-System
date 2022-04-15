#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	pid_t pid=fork();
	
	if(pid<0)
	{
		printf("Process ID= %d Fork Faild\n", getpid());
	}
	else if(pid==0)
	{
		printf("Process ID=%d Child Process\n", getpid());
	}
	else
	{
		printf("Process ID=%d Parent Process\n", getpid());
	}
	return 0;
}