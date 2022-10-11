#include <stdio.h>
#include <conio.h>

void main()
{
    int i, sum = 0, at[10], bt[10], temp[10], tat = 0, wt = 0, y, n, quant, count = 0;
    float avg_wt = 0, avg_tat = 0;
    printf("Enter the number process :");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time :");
        scanf("%d", &at[i]);
        printf("Enter the burst time :");
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
    }
    printf("Enter the quant : ");
    scanf("%d", &quant);
    y = n;
    printf("\nPid     AT   BT    CT  WT  TAT \n");
    for (sum = 0, i = 0; y != 0;)
    {
        if (temp[i] <= quant && temp[i] > 0)
        {
            sum = sum + temp[i];
            temp[i] = 0;
            count = 1;
        }
        else if (temp[i] > 0)
        {
            temp[i] = temp[i] - quant;
            sum = sum + quant;
        }
        if (temp[i] == 0 && count == 1)
        {
            printf("p%d     %d     %d     %d    %d     %d\n", i + 1, at[i], bt[i], sum, sum - at[i] - bt[i], sum - at[i]);
            wt += sum - at[i] - bt[i];
            tat += sum - at[i];
            y--;
            count = 0;
        }
        if (i == n - 1)
            i = 0;
        else if (at[i + 1] <= sum)
            i++;
        else
            i = 0;
    }
}