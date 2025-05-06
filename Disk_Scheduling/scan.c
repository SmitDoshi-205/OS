#include<stdio.h>
#include<stdlib.h>
int queue[100]; //destination queue
int head; //initial header position
int seek_time = 0; //total seek-time

void main(){
    int n; //no of elements in destination queue
    int len; //length of disk(0 - len-1)
    int i,j,ch,temp,pos;
    
    printf("Enter the length of the disk-");
    scanf("%d", &len);
    
    printf("Enter the initial position of head-");
    scanf("%d", &head);
    
    printf("Enter the no of elements in the destination queue-");
    scanf("%d", &n);
    
    int sort[n+1]; //contains the sorted list of all requests
    
    printf("Enter the elements in queue-");
    for(i=0; i<n; i++){
        scanf("%d", &queue[i]);
    }
    
    for(i=0; i<n+1; i++){
        sort[i] = queue[i];
    }
    sort[n] = head; //adding head to sort array
    
    printf("Enter your choice(0 for Left / 1 for Right)-");
    scanf("%d", &ch);
    
    n += 1; //sort array includes head now, so size is n+1
 
    //bubble sort
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(sort[j] > sort[j+1]){
                temp = sort[j];
                sort[j] = sort[j+1];
                sort[j+1] = temp;
            }
        }
    }
    
    //find position of head in sorted list
    for(i=0; i<n; i++){
        if(sort[i] == head){
            pos = i;
            break;
        }
    }
    
    //moving right or up
    if(ch == 1){
        
        //head to last request
        for(i = pos+1; i<n; i++){
            printf("Moving from %d to %d\n", head, sort[i]);
            seek_time += abs(sort[i] - head);
            head = sort[i];
        }
        
        //last request to end of disk
        if(head != len-1){
            printf("Moving from %d to %d\n", head, (len-1));
            seek_time += abs((len-1) - head);
            head = len - 1;
        }
        
        //end of disk to requests on left
        for(i = pos-1; i>=0; i--){
            printf("Moving from %d to %d\n", head, sort[i]);
            seek_time += abs(head - sort[i]);
            head = sort[i];
        }
    }
    
    //moving left or down
    if(ch == 0){
        
        //head to first request
        for(i = pos-1; i>=0; i--){
            printf("Moving from %d to %d\n", head, sort[i]);
            seek_time += abs(head - sort[i]);
            head = sort[i];
        }
        
        //first request to start of disk
        if(head != 0){
            printf("Moving from %d to %d\n", head, 0);
            seek_time += abs(head - 0);
            head = 0;
        }
        
        //start of disk to requests on right
        for(i = pos+1; i<n; i++){
            printf("Moving from %d to %d\n", head, sort[i]);
            seek_time += abs(sort[i] - head);
            head = sort[i];
        }
    }
    
    printf("\nTotal Seek Time = %d", seek_time);
}