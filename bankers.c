#include <stdio.h>
int alloc[20][20]; //allocated resources
int max[20][20]; //max need of processes
int need[20][20]; //current need of processes
int avail[20]; //available resources
int ans[20]; //final safe state sequence
int flag[20]; //to check if process is executed or not
int n,m; //no of processes, no of resources

void main(){
    int i,j,f,k,count = 0,index = 0;
    
    //no of processes
    printf("Enter no of processes-");
    scanf("%d", &n);
    
    //no of resources
    printf("Enter no of resources-");
    scanf("%d", &m);
    
    //allocation matrix
    printf("Enter allocation matrix:\n");
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            scanf("%d", &alloc[i][j]);
        }
    }
    
    //maximum need or request matrix
    printf("Enter maximum need matrix:\n");
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            scanf("%d", &max[i][j]);
        }
    }
    
    //calculate need matrix
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    printf("Need matrix:\n");
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }
    
    //current available resources
    printf("Enter the amount of available resources:\n");
    for(i=0; i<m; i++){
        scanf("%d", &avail[i]);
    }
    
    //none of the processes are executed yet 
    for(i=0; i<n; i++){
        flag[i] = 0;
    }
    
    while(count < n){
        for(i=0; i<n; i++){
            if(flag[i] == 0){ //if process not executed
                f = 0;
                for(j=0; j<m; j++){
                    if(need[i][j] > avail[j]){
                        f = 1;
                        break;
                    }
                }
                if(f == 0){
                    for(k=0; k<m; k++){
                        avail[k] = avail[k] + alloc[i][k]; //update available
                    }
                    ans[index++] = i; //store the order of process
                    flag[i] = 1; //current process executed
                    count++;
                }
            }
        }
    }
    if(count == n){
        printf("Safe State\n");
        for(i=0; i<n-1; i++){
            printf("P%d --> ", ans[i]);
        }
        printf("P%d", n-1);
    }
    else{
        printf("Unsafe State\n");
    }
    
}