#include <stdio.h>

int pages[100];
int frame[100];

void main() {
    int n, size;
    int i, j, k, pf = 0, ph = 0;

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

    // Initialize frames
    for(i = 0; i < size; i++) {
        frame[i] = -1;
    }

    for(i = 0; i < n; i++) {
        int flag = 0;

        // Check for page hit
        for(j = 0; j < size; j++) {
            if(frame[j] == pages[i]) {
                ph++;
                flag = 1;
                break;
            }
        }

        // Page fault
        if(!flag) {
            pf++;

            // If space is available
            int emptyIndex = -1;
            for(j = 0; j < size; j++) {
                if(frame[j] == -1) {
                    emptyIndex = j;
                    break;
                }
            }

            if(emptyIndex != -1) {
                frame[emptyIndex] = pages[i];
            } else {
                // OPT replacement
                int farthest = -1, index = -1;
                for(j = 0; j < size; j++) {
                    int found = 0;
                    for(k = i + 1; k < n; k++) {
                        if(frame[j] == pages[k]) {
                            found = 1;
                            if(k > farthest) {
                                farthest = k;
                                index = j;
                            }
                            break;
                        }
                    }

                    // If the page is never used again
                    if(!found) {
                        index = j;
                        break;
                    }
                }

                frame[index] = pages[i];
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