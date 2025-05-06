#include <stdio.h>
int process[20]; // size of processes
int memory[20];  // size of available memory blocks
int result[20][3]; // resultant matrix

void main() {
    int n, m, i, j; // n = no. of processes, m = no. of memory blocks

    printf("Enter the no of processes-");
    scanf("%d", &n);

    // sizes of processes
    printf("Enter the sizes of processes-");
    for(i = 0; i < n; i++) {
        scanf("%d", &process[i]);
    }

    printf("Enter the no of memory blocks-");
    scanf("%d", &m);

    // sizes of memory blocks
    printf("Enter the sizes of memory blocks-");
    for(i = 0; i < m; i++) {
        scanf("%d", &memory[i]);
    }

    // First Fit Allocation
    for(i = 0; i < n; i++) {
        int allocated = 0;
        for(j = 0; j < m; j++) {
            if(process[i] <= memory[j]) {
                result[i][0] = process[i];
                result[i][1] = memory[j];
                result[i][2] = memory[j] - process[i];
                memory[j] = 0;
                allocated = 1;
                break;
            }
        }
        if(!allocated) {
            result[i][0] = process[i];
            result[i][1] = -1; // indicates not allocated
        }
    }

    printf("Process \t Memory Block \t Holes\n");
    for(i = 0; i < n; i++) {
        if(result[i][1] != -1)
            printf("%d \t\t %d \t\t %d\n", result[i][0], result[i][1], result[i][2]);
        else
            printf("%d \t\t Not Allocated\n", result[i][0]);
    }
}