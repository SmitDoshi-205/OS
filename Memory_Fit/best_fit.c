#include <stdio.h>

int process[20]; // sizes of processes
int memory[20];  // sizes of memory blocks
int result[20][3]; // result matrix

void main() {
    int n, m, i, j;

    printf("Enter the no of processes-");
    scanf("%d", &n);

    printf("Enter the sizes of processes-");
    for(i = 0; i < n; i++) {
        scanf("%d", &process[i]);
    }

    printf("Enter the no of memory blocks-");
    scanf("%d", &m);

    printf("Enter the sizes of memory blocks-");
    for(i = 0; i < m; i++) {
        scanf("%d", &memory[i]);
    }

    for(i = 0; i < n; i++) {
        int bestIdx = -1;

        for(j = 0; j < m; j++) {
            if(memory[j] >= process[i]) {
                if(bestIdx == -1 || memory[j] < memory[bestIdx]) {
                    bestIdx = j;
                }
            }
        }

        if(bestIdx != -1) {
            result[i][0] = process[i];
            result[i][1] = memory[bestIdx];
            result[i][2] = memory[bestIdx] - process[i];
            memory[bestIdx] = 0; // mark block as used
        } else {
            result[i][0] = process[i];
            result[i][1] = -1; // not allocated
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