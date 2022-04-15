#include <stdio.h>

int main()
{
    int n;
    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    int Burst_Time[n], Arrival_Time[n], Waiting_Time[n], Sum, Time_Slice, i, Cnt, y;
    float Average_Waiting_Time = 0;
    y = n;
    printf("\nEnter Burst Time & Arrival Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("Burst Time For P%d: ", i);
        scanf("%d", &Burst_Time[i]);
        printf("Arrival Time For P%d: ", i);
        scanf("%d", &Arrival_Time[i]);
        Waiting_Time[i] = Burst_Time[i];
    }

    printf("Enter the Time Slice for the process: ");
    scanf("%d", &Time_Slice);

    printf("Process No    Burst Time      Arrival Time        Waiting Time\n");
    for (Sum = 0, i = 0; y != 0;)
    {
        if (Waiting_Time[i] <= Time_Slice && Waiting_Time[i] > 0)
        {
            Sum = Sum + Waiting_Time[i];
            Waiting_Time[i] = 0;
            Cnt = 1;
        }
        else if (Waiting_Time[i] > 0)
        {
            Waiting_Time[i] = Waiting_Time[i] - Time_Slice;
            Sum = Sum + Time_Slice;
        }
        if (Waiting_Time[i] == 0 && Cnt == 1)
        {
            y--;
            printf("%d             %d               %d                   %d\n", i, Burst_Time[i], Arrival_Time[i], Sum - Arrival_Time[i] - Burst_Time[i]);
            Average_Waiting_Time = Average_Waiting_Time + Sum - Arrival_Time[i];
            Cnt = 0;
        }
        if (i == n - 1)
        {
            i = 0;
        }
        else if (Arrival_Time[i + 1] <= Sum)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }
    printf("\nAverage Waiting Time= %.2f\n", Average_Waiting_Time / n);

    return 0;
}