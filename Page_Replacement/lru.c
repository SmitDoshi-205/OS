#include <stdio.h>

int pages[100];
int frame[100];
int recent[100]; // stores last used time for LRU

void main(){
    int n, size;
    int i, j, k, l, time = 0;
    int pf = 0, ph = 0;
    int least, index;

    // pages input
    printf("Enter the no of pages- ");
    scanf("%d", &n);
    printf("Enter the pages- ");
    for(i = 0; i < n; i++){
        scanf("%d", &pages[i]);
    }

    // page frame size
    printf("Enter the frame size- ");
    scanf("%d", &size);

    // initialize frame and recent arrays
    for(i = 0; i < size; i++){
        frame[i] = -1;
        recent[i] = -1;
    }

    for(i = 0; i < n; i++){
        int flag = 0;
        time++; // increment time with each page request

        // check if page is already in frame
        for(j = 0; j < size; j++){
            if(frame[j] == pages[i]){
                ph++;
                recent[j] = time; // update recent time
                flag = 1;
                break;
            }
        }

        // if not found, it's a page fault
        if(!flag){
            pf++;

            // if there's space in frame
            for(j = 0; j < size; j++){
                if(frame[j] == -1){
                    frame[j] = pages[i];
                    recent[j] = time;
                    flag = 1;
                    break;
                }
            }

            // if frame is full, apply LRU
            if(!flag){
                least = recent[0];
                index = 0;
                for(k = 1; k < size; k++){
                    if(recent[k] < least){
                        least = recent[k];
                        index = k;
                    }
                }
                frame[index] = pages[i];
                recent[index] = time;
            }
        }

        // display current state of frame
        for(k = 0; k < size; k++){
            if(frame[k] != -1){
                printf("%d \t", frame[k]);
            } else {
                printf("- \t");
            }
        }
        printf("\n");
    }

    // display final results
    printf("\nNo of Page Faults = %d", pf);
    printf("\nNo of Page Hits = %d", ph);
    printf("\nMiss Ratio = %.2f", (float)pf / n);
    printf("\nHit Ratio = %.2f", (float)ph / n);
}