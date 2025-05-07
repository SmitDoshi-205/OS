#include <stdio.h>

int burst_time[20];      // Burst time
int arr_time[20];        // Arrival time
int comp_time[20];       // Completion time
int remain_time[20];     // Remaining time
int tat[20];             // Turnaround time
int wt[20];              // Waiting time
float avg_tat = 0.0;
float avg_wt = 0.0;
int total_tat = 0;
int total_wt = 0;

int main() {
    int n, i, quantum;
    int currentTime = 0, done = 0;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst times:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &burst_time[i]);
        remain_time[i] = burst_time[i];
    }

    printf("Enter arrival times:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr_time[i]);
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    while(done < n) {
        int allIdle = 1;
        for(i = 0; i < n; i++) {
            if(remain_time[i] > 0 && arr_time[i] <= currentTime) {
                allIdle = 0;
                if(remain_time[i] <= quantum) {
                    currentTime += remain_time[i];
                    remain_time[i] = 0;
                    comp_time[i] = currentTime;
                    tat[i] = comp_time[i] - arr_time[i];
                    wt[i] = tat[i] - burst_time[i];
                    total_tat += tat[i];
                    total_wt += wt[i];
                    done++;
                } else {
                    currentTime += quantum;
                    remain_time[i] -= quantum;
                }
            }
        }

        if(allIdle) currentTime++; // If no process was ready, move time forward
    }

    avg_tat = (float)total_tat / n;
    avg_wt = (float)total_wt / n;

    printf("\nProcess\tBT\tAT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, burst_time[i], arr_time[i], comp_time[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", avg_tat);
    printf("\nAverage Waiting Time = %.2f\n", avg_wt);

    return 0;
}