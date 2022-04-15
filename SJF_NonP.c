#include <stdio.h>
int main()
{
    int n;
    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    int Process[n], Burst_Time[n], Waiting_Time[n], key, Proces;
    float Average_Waiting_Time = 0;

    printf("Enter Burst Time:\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d: ", i);
        scanf("%d", &Burst_Time[i]);
        Process[i] = i;
    }

    for (int i = 0; i < n; i++)
    {
        Proces = i;
        for (int j = i + 1; j < n; j++)
        {
            if (Burst_Time[j] < Burst_Time[Proces])
                Proces = j;
        }
        key = Burst_Time[i];
        Burst_Time[i] = Burst_Time[Proces];
        Burst_Time[Proces] = key;
        key = Process[i];
        Process[i] = Process[Proces];
        Process[Proces] = key;
    }

    Waiting_Time[0] = 0;
    for (int i = 1; i < n; i++)
    {
        Waiting_Time[i] = Burst_Time[i - 1] + Waiting_Time[i - 1];
    }

    printf("Process     Burst_Time      Waiting_Time\n");
    for (int i = 0; i < n; i++)
    {
        Average_Waiting_Time = Average_Waiting_Time + Waiting_Time[i];
        printf(" P%d             %d              %d\n", Process[i], Burst_Time[i], Waiting_Time[i]);
    }

    printf("Average Waiting Time= %.2f\n", Average_Waiting_Time / n);

    return 0;
}