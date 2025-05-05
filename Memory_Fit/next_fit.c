#include <stdio.h>

int process[20]; // sizes of processes
int memory[20];  // sizes of memory blocks
int result[20][2]; // result matrix

void main() {
    int n, m, i, j, lastPos = 0;

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
        int allocated = 0, count = 0;
        j = lastPos;

        // loop through memory blocks circularly
        while(count < m) {
            if(memory[j] >= process[i]) {
                result[i][0] = process[i];
                result[i][1] = memory[j];
                memory[j] = 0; // mark block as used
                lastPos = (j + 1) % m;
                allocated = 1;
                break;
            }
            j = (j + 1) % m;  //circular traversal
            count++;
        }

        if(!allocated) {
            result[i][0] = process[i];
            result[i][1] = -1; // not allocated
        }
    }

    printf("Process \t Memory Block\n");
    for(i = 0; i < n; i++) {
        if(result[i][1] != -1)
            printf("%d \t\t %d\n", result[i][0], result[i][1]);
        else
            printf("%d \t\t Not Allocated\n", result[i][0]);
    }
}