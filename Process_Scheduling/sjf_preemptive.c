#include<stdio.h>

int burst_time[20]; //burst time
int arr_time[20]; //arrival time
int comp_time[20] = {0}; //completion time
int remain_time[20]; //remaining time for process
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
    int min_rt,idx;
    
    printf("Enter the no of processes-");
    scanf("%d", &n);
    
    //burst-time
    printf("Enter the burst time of processes-");
    for(i=0; i<n; i++){
        scanf("%d", &burst_time[i]);
        remain_time[i] = burst_time[i]; //copy burst-time to remaining-time
    }
    
    //arrival-time
    printf("Enter the arrival time of processes-");
    for(i=0; i<n; i++){
        scanf("%d", &arr_time[i]);
    }
    
    while(count < n){
        idx = -1;
        min_rt = 9999;
        
        //find mininum process
        for(i=0; i<n; i++){
            if(arr_time[i] <= t && complete[i] == 0 && remain_time[i] < min_rt && remain_time > 0){
                min_rt = remain_time[i];
                idx = i;
            }
        }
        
        if(idx != -1){
            remain_time[idx]--;
            t ++;
            
            //if no time remains, process is complete
            if(remain_time[idx] == 0){
                comp_time[idx] = t;
                tat[idx] = comp_time[idx] - arr_time[idx];
                wt[idx] = tat[idx] - burst_time[idx];
                total_tat += tat[idx];
                total_wt += wt[idx];
                complete[idx] = 1;
                count++;
            }
        }
        else{
            t++;
        }
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