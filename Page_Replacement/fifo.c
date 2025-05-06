#include<stdio.h>
int pages[100];
int frame[100];

void main(){
    int n,size;
    int i,j,k;
    int front=0,count=0,flag;
    int pf = 0; //no of page faults
    int ph = 0; //no of page hits
    
    //pages input
    printf("Enter the no of pages-");
    scanf("%d", &n);
    printf("Enter the pages-");
    for(i=0; i<n; i++){
        scanf("%d", &pages[i]);
    }
    
    //page frame size
    printf("Enter the frame size-");
    scanf("%d", &size);
    
    //currently empty page frame
    for(i=0; i<size; i++){
        frame[i] = -1;
    }
    
    for(i=0; i<n; i++){
        flag = 0;
        
        //checking if page already exists in frame
        for(j=0; j<count; j++){
            if(frame[j] == pages[i]){
                ph++;
                flag = 1;
                break;
            }
        }
        if(!flag){
            pf++;
        }
        
        //if there is space in frame, add the page
        if(count < size){
            frame[count++] = pages[i];
        }
        
        //if frame is full, remove the oldest page
        else{
            frame[front] = pages[i];
            front = (front + 1) % size;
        }
        
        //showing each page frame
        for(k=0; k<size; k++){
            if(frame[k] != -1){
                printf("%d \t", frame[k]);
            }
            else{
                printf("-\t");
            }
        }
        printf("\n");
    }
    
    printf("\nNo of Page Faults = %d", pf);
    printf("\nNo of Page Hits = %d", ph);
    printf("\nMiss Ratio = %.2f", (float)pf/n);
    printf("\nHit Ratio = %.2f", (float)ph/n);
}