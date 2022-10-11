#include <stdio.h>
#include <stdlib.h>
int main()
{
    int at[10], bt[10], ct[10], tat[10], wt[10], n;
    printf("enter number of processes");
    scanf("%d", &n);
    printf("enter arrival time and burst time of each process");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &at[i]);
        scanf("%d", &bt[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (at[j] > at[j + 1])
            {
                int temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
            }
        }
    }
    ct[0] = at[0] + bt[0];
    for (int i = 1; i < n; i++)
    {
        if (at[i] > ct[i - 1])
        {
            ct[i] = at[i] + bt[i];
        }
        else
        {
            ct[i] = ct[i - 1] + bt[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
    }
    for (int i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];
    }

    printf("process_id\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t", i + 1);
        printf("%d\t", at[i]);
        printf("%d\t", bt[i]);
        printf("%d\t", ct[i]);
        printf("%d\t", tat[i]);
        printf("%d\t", wt[i]);
        printf(" \n");
    }

    return 0;
}
