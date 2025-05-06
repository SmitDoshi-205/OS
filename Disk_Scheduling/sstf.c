#include<stdio.h>
#include<stdlib.h>
int queue[100]; //destination queue
int head; //initial header position
int seek_time = 0; //total seek-time

void main(){
    int n; //no of elements in destination queue
    int len; //length of disk(0 - len-1)
    int i,j,idx,min;
    int done[100]; //visited disk requests
    
    printf("Enter the length of the disk-");
    scanf("%d", &len);
    
    printf("Enter the initial position of head-");
    scanf("%d", &head);
    
    printf("Enter the no of elements in the destination queue-");
    scanf("%d", &n);
    printf("Enter the elements in queue-");
    for(i=0; i<n; i++){
        scanf("%d", &queue[i]);
    }
    
    //SSTF      
    for(i=0; i<n; i++){
        min = 10000;
        idx = -1;
        //finding minimum distance
        for(j=0; j<n; j++){
            if(!done[j]){
                if(abs(head - queue[j]) < min){
                    min = abs(head - queue[j]);
                    idx = j;
                }
            }
        }
        
        printf("Moving from %d to %d\n", head, queue[idx]);
        seek_time += abs(head - queue[idx]);
        head = queue[idx];
        done[idx] = 1;
    }
    
    printf("\nTotal Seek Time = %d", seek_time);
}