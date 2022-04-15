#include <math.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	pid_t pid = fork();
	if (pid < 0)
	{
		printf("Process ID= %d Fork Faild\n", getpid());
	}
	else if (pid > 0)
	{
		printf("Process ID=%d Parent Process\n", getpid());
	}
	else
	{

		printf("Process ID=%d Child Process\n", getpid());
		pid_t pid2 = fork();
		if (pid2 < 0)
		{
			printf("Process2 ID= %d Fork Faild\n", getpid());
		}
		else if (pid2 == 0)
		{
			printf("Process2 ID=%d Child Process\n={", getpid());
			double A[5] = {4, 5, 8, 9, 3};
			for (int i = 0; i < 4; i++)
			{
				printf("-%.0f,", pow(A[i], 2));
			}
			printf("-%.0f}", pow(A[4], 2));
		}
	}

	return 0;
}