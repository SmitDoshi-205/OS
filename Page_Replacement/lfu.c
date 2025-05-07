#include <stdio.h>

int pages[100];
int frame[100];
int freq[100]; // frequency of each page in frame
int time[100]; // time of insertion for FIFO

void main() {
    int n, size;
    int i, j, k, clk = 0; // clk tracks time for FIFO
    int pf = 0, ph = 0;

    // Input: number of pages
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    printf("Enter the pages: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    // Input: frame size
    printf("Enter the frame size: ");
    scanf("%d", &size);

    // Initialize frame, frequency and time arrays
    for(i = 0; i < size; i++) {
        frame[i] = -1;
        freq[i] = 0;
        time[i] = 0;
    }

    for(i = 0; i < n; i++) {
        clk++; // increase time for FIFO tracking
        int flag = 0;

        // Page hit check
        for(j = 0; j < size; j++) {
            if(frame[j] == pages[i]) {
                ph++;
                freq[j]++;
                flag = 1;
                break;
            }
        }

        // Page fault
        if(!flag) {
            pf++;

            // Check for empty space in frame
            int emptyIndex = -1;
            for(j = 0; j < size; j++) {
                if(frame[j] == -1) {
                    emptyIndex = j;
                    break;
                }
            }

            if(emptyIndex != -1) {
                frame[emptyIndex] = pages[i];
                freq[emptyIndex] = 1;
                time[emptyIndex] = clk;
            } else {
                // Find LFU index with FIFO tie-breaking
                int minFreq = freq[0];
                int minTime = time[0];
                int index = 0;
                for(j = 1; j < size; j++) {
                    if(freq[j] < minFreq || (freq[j] == minFreq && time[j] < minTime)) {
                        minFreq = freq[j];
                        minTime = time[j];
                        index = j;
                    }
                }

                frame[index] = pages[i];
                freq[index] = 1;
                time[index] = clk;
            }
        }

        // Display frame status
        for(k = 0; k < size; k++) {
            if(frame[k] != -1) {
                printf("%d \t", frame[k]);
            } else {
                printf("- \t");
            }
        }
        printf("\n");
    }

    // Final output
    printf("\nNo of Page Faults = %d", pf);
    printf("\nNo of Page Hits = %d", ph);
    printf("\nMiss Ratio = %.2f", (float)pf / n);
    printf("\nHit Ratio = %.2f", (float)ph / n);
}