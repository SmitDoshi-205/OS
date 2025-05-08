#include <stdio.h>

#define SIZE 3  // Size of the buffer

int mutex = 1;
int full = 0;
int empty = SIZE;
int buffer[SIZE];
int in = 0;   // Index for producer
int out = 0;  // Index for consumer
int item = 0; // Item number to produce

void produce() {
    --mutex;
    ++full;
    --empty;

    item++;
    buffer[in] = item;
    printf("Producer produced item %d at index %d\n", buffer[in], in);
    in = (in + 1) % SIZE;

    ++mutex;
}

void consume() {
    --mutex;
    --full;
    ++empty;

    printf("Consumer consumed item %d from index %d\n", buffer[out], out);
    buffer[out] = 0; // Optional: Clear the consumed spot
    out = (out + 1) % SIZE;

    ++mutex;
}

int main() {
    int choice = -1;

    printf("1) Produce\n2) Consume\n3) Exit\n\n");

    while (choice != 3) {
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(mutex == 1 && empty != 0)
                    produce();
                else
                    printf("Buffer full or busy. Wait.\n");
                break;

            case 2:
                if(mutex == 1 && full != 0)
                    consume();
                else
                    printf("Buffer empty or busy. Wait.\n");
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Enter proper choice.\n");
                break;
        }
    }

    return 0;
}