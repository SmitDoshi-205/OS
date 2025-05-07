#include<stdio.h>

int burst_time[20];    // burst time
int arr_time[20];      // arrival time
int priority[20];      // priority of processes
int comp_time[20];     // completion time
int remain_time[20];   // remaining time
int complete[20] = {0}; // process completed or not
int tat[20];           // turnaround time
int wt[20];            // waiting time
float avg_tat = 0.0, avg_wt = 0.0;
int total_tat = 0, total_wt = 0;

int main() {
    int n, i;
    int t = 0, count = 0;
    int idx, highest_priority;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst times:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &burst_time[i]);
        remain_time[i] = burst_time[i]; // Copy burst time
    }

    printf("Enter arrival times:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr_time[i]);
    }

    printf("Enter priorities (lower number = higher priority):\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &priority[i]);
    }

    while(count < n) {
        idx = -1;
        highest_priority = 9999;

        for(i = 0; i < n; i++) {
            if(arr_time[i] <= t && complete[i] == 0 && priority[i] < highest_priority && remain_time[i] > 0) {
                highest_priority = priority[i];
                idx = i;
            }
        }

        if(idx != -1) {
            remain_time[idx]--;
            t++;

            if(remain_time[idx] == 0) {
                comp_time[idx] = t;
                tat[idx] = comp_time[idx] - arr_time[idx];
                wt[idx] = tat[idx] - burst_time[idx];
                total_tat += tat[idx];
                total_wt += wt[idx];
                complete[idx] = 1;
                count++;
            }
        } else {
            t++; // No process is ready, so move time forward
        }
    }

    avg_tat = (float)total_tat / n;
    avg_wt = (float)total_wt / n;

    printf("\nProcess\tBT\tAT\tPrio\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i, burst_time[i], arr_time[i], priority[i], comp_time[i], tat[i], wt[i]);
    }

    printf("\nAvg TAT = %.2f", avg_tat);
    printf("\nAvg WT = %.2f\n", avg_wt);

    return 0;
}