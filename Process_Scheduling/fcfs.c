#include<stdio.h>

int burst_time[20]; //burst time
int arr_time[20]; //arrival time
int comp_time[20] = {0}; //completion time
int tat[20]; //turn-arnd-time
int wt[20]; //waiting time
float avg_tat = 0.0;
float avg_wt = 0.0;
int total_tat = 0;
int total_wt = 0;

void main(){
    int n; //no of processes
    int i;
    int total = 0;
    
    printf("Enter the no of processes-");
    scanf("%d", &n);
    
    //burst-time
    printf("Enter the burst time of processes-");
    for(i=0; i<n; i++){
        scanf("%d", &burst_time[i]);
    }
    
    //arrival-time
    printf("Enter the arrival time of processes-");
    for(i=0; i<n; i++){
        scanf("%d", &arr_time[i]);
    }
    
    //completion-time
    for(i=0; i<n; i++){
        total += burst_time[i];
        comp_time[i] = total;
    }
    
    //turn-around-time
    for(i=0; i<n; i++){
        tat[i] = comp_time[i] - arr_time[i];
        total_tat += tat[i];
    }
    
    //waiting-time
    for(i=0; i<n; i++){
        wt[i] = tat[i] - burst_time[i];
        total_wt += wt[i];
    }
    
    avg_tat = (float)total_tat/n;
    avg_wt = (float)total_wt/n;
    
    printf("Process\tBurst Time\tArrival Time\tCompletion Time\t\tTAT\t\tWT\n");
    for(i=0; i<n; i++){
        printf("P%d \t\t\t %d \t\t\t %d \t\t\t\t %d \t\t\t\t %d \t\t %d", i,burst_time[i],arr_time[i],comp_time[i],tat[i],wt[i]);
        printf("\n");
    }
    printf("\nAvg TAT = %.2f", avg_tat);
    printf("\nAvg WT = %.2f", avg_wt);
}