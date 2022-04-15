#include <stdio.h>

int main()
{
    int n;
    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    int Burst_Time[n], Arrival_Time[n], Waiting_Time[n];
    float Average_Waiting_Time = 0;

    printf("\nEnter Burst Time & Arrival Time :\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nBurst Time For P%d: ", i);
        scanf("%d", &Burst_Time[i]);
        printf("Arrival Time For P%d: ", i);
        scanf("%d", &Arrival_Time[i]);
    }

    Waiting_Time[0] = 0;
    for (int i = 1; i < n; i++)
    {
        Waiting_Time[i] = Burst_Time[i - 1] + Waiting_Time[i - 1];
    }

    printf("Process     Burst_Time      Waiting_Time\n");
    for (int i = 0; i < n; i++)
    {
        Waiting_Time[i] = Waiting_Time[i] - Arrival_Time[i];
        Average_Waiting_Time = Average_Waiting_Time + Waiting_Time[i];
        printf(" P%d             %d              %d\n", i, Burst_Time[i], Waiting_Time[i]);
    }

    printf("Average Waiting Time= %.2f\n", Average_Waiting_Time / n);

    return 0;
}