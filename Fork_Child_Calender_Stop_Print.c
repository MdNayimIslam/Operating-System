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
		execlp("cal","cal",NULL);
		pid_t pid2=fork();
		if(pid2<0)
		{
			printf("Process2 ID= %d Fork Faild\n", getpid());
		}
		else if(pid2==0)
		{
			printf("Process2 ID=%d Child Process\n", getpid());
		}
		else if(pid2>0)
		{
			printf("Process2 ID=%d Parent Process\n", getpid());
		}
	}
	else
	{
		printf("Process ID=%d Parent Process\n", getpid());
	}
	
	return 0;
}