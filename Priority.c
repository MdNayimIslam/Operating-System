#include <stdio.h>
int main()
{
    int Process[4] = {1, 2, 3, 4}, Priority[4] = {2, 1, 3, 4}, Burst_Time[4] = {10, 8, 2, 5}, Waiting_Time[4], key, Proces;
    float Average_Waiting_Time = 0;

    for (int i = 0; i < 4; i++)
    {
        Proces = i;
        for (int j = i + 1; j < 4; j++)
        {
            if (Priority[j] < Priority[Proces])
                Proces = j;
        }
        key = Priority[i];
        Priority[i] = Priority[Proces];
        Priority[Proces] = key;

        key = Burst_Time[i];
        Burst_Time[i] = Burst_Time[Proces];
        Burst_Time[Proces] = key;

        key = Process[i];
        Process[i] = Process[Proces];
        Process[Proces] = key;
    }

    Waiting_Time[0] = 0;
    for (int i = 1; i < 4; i++)
    {
        Waiting_Time[i] = Burst_Time[i - 1] + Waiting_Time[i - 1];
    }

    printf("Process     Burst_Time      Waiting_Time\n");
    for (int i = 0; i < 4; i++)
    {
        Average_Waiting_Time = Average_Waiting_Time + Waiting_Time[i];
        printf(" P%d             %d              %d\n", Process[i], Burst_Time[i], Waiting_Time[i]);
    }

    printf("Average Waiting Time= %.2f\n", Average_Waiting_Time / 4);

    return 0;
}