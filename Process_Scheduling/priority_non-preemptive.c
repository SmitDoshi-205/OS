#include<stdio.h>

int burst_time[20]; //burst time
int arr_time[20]; //arrival time
int priority[20]; //priority of processes
int comp_time[20] = {0}; //completion time
int complete[20] = {0}; //completed process
int tat[20]; //turn-arnd-time
int wt[20]; //waiting time
float avg_tat = 0.0;
float avg_wt = 0.0;
int total_tat = 0;
int total_wt = 0;

void main(){
    int n; //no of processes
    int i;
    int t = 0, count = 0;
    int max,idx;
    
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
    
    //process priority
    printf("Enter the priority of processes(lower no = higher priority)-");
    for(i=0; i<n; i++){
        scanf("%d", &priority[i]);
    }
    
    while(count < n){
        idx = -1;
        max = 9999;
        
        //find mininum process
        for(i=0; i<n; i++){
            if(arr_time[i] <= t && complete[i] == 0 && priority[i] < max){
                max = priority[i];
                idx = i;
            }
        }
        
        if(idx != -1){
            t += burst_time[idx];
            comp_time[idx] = t;
            tat[idx] = comp_time[idx] - arr_time[idx];
            wt[idx] = tat[idx] - burst_time[idx];
            total_tat += tat[idx];
            total_wt += wt[idx];
            complete[idx] = 1;
            count++;
        }
        else{
            t++;
        }
    }
    
    avg_tat = (float)total_tat/n;
    avg_wt = (float)total_wt/n;
    
    printf("Process\tBurst Time\tArrival Time\tPriority\tCompletion Time\t\tTAT\t\tWT\n");
    for(i=0; i<n; i++){
        printf("P%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t\t\t%d\t\t\t%d", i,burst_time[i],arr_time[i],priority[i],comp_time[i],tat[i],wt[i]);
        printf("\n");
    }
    printf("\nAvg TAT = %.2f", avg_tat);
    printf("\nAvg WT = %.2f", avg_wt);
}