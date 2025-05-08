// Producer Consumer
#include <stdio.h>

int mutex = 1;
int full = 0;
int empty = 3;
int x = 0;

void produce(){
    --mutex;
    ++full;
    --empty;
    x++;
    printf("Producer produced %d\n", x);
    ++mutex;
}

void consume(){
    --mutex;
    --full;
    ++empty;
    printf("Consumer consumed %d\n", x);
    x--;
    ++mutex;
}

int main() {
    
    int choice = -1;
    
    printf("1) Produce\n2) Consume\n3) Exit\n\n");
    while (choice != 3){
        printf("Enter Choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1: 
                if(mutex == 1 && empty != 0)
                    produce();
                else
                    printf("Wait\n");
                break;
                
            case 2: 
                if(mutex == 1 && full != 0)
                    consume();
                else
                    printf("Wait\n");
                break;
            case 3: 
                printf("Exitting...\n");
                break;
            default: 
                printf("Enter proper choice\n");
                break;
        }
    }
    
    

    return 0;
}