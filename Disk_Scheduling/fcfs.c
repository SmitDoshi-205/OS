#include<stdio.h>
#include<stdlib.h>
int queue[100]; //destination queue
int head; //initial header position
int seek_time = 0; //total seek-time

void main(){
    int n; //no of elements in destination queue
    int len; //length of disk(0 - len-1)
    int i,j;
    
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
    
    //FCFS
    for(i=0; i<n; i++){
        printf("Moving from %d to %d\n", head, queue[i]);
        seek_time += abs(queue[i] - head);
        head = queue[i];
    }
    
    printf("\nTotal Seek Time = %d", seek_time);
}