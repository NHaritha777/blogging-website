#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // MAX SIZE SET TO 5

// --- Global Stacks and Pointers ---
int stack1[MAX_SIZE]; 
int stack2[MAX_SIZE];
int top1 = -1;
int top2 = -1;

// --- Stack Operations (Simplified to return status) ---

// Push element onto stack1
void push1(int data) {
    stack1[++top1] = data;
}

// Pop element from stack1
int pop1() {
    return stack1[top1--];
}

// Push element onto stack2
void push2(int data) {
    stack2[++top2] = data;
}

// Pop element from stack2
int pop2() {
    return stack2[top2--];
}

// --- Queue Operations ---

// 1. ENQUEUE (Checks total queue capacity correctly)
void enqueue(int data) {
    // Check total queue size: (top1 + 1) is size of stack1, (top2 + 1) is size of stack2
    if ((top1 + 1) + (top2 + 1) >= MAX_SIZE) {
        printf("\nQueue is full (Max Size: %d). Cannot Enqueue %d.\n", MAX_SIZE, data);
        return; // Exit if full
    }
    
    // If there's capacity, push to stack1
    push1(data);
    printf("Enqueued: %d\n", data);
}

// Helper function to transfer elements from stack1 to stack2
void transfer_stacks() {
    if (top2 == -1) {
        while (top1 != -1) {
            push2(pop1());
        }
    }
}

// 2. DEQUEUE 
void dequeue() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty. Cannot Dequeue.\n");
        return;
    }

    transfer_stacks();
    int dequeued_data = pop2();

    printf("Dequeued: %d\n", dequeued_data);
}

// 3. PEEK
void peek() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty. No element to Peek.\n");
        return;
    }
    
    transfer_stacks();
    
    printf("Peek (Front Element): %d\n", stack2[top2]);
}

// 4. DISPLAY
void display() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty.\n");
        return;
    }

    transfer_stacks(); // Ensure stack2 holds the elements in FIFO order

    printf("Queue Elements (Front -> Rear): ");
    int i;
    // Display elements from stack2
    for ( i = top2; i >= 0; i--) {
        printf("%d ", stack2[i]);
    }
    
    printf("\n");
}

// --- Main Program ---
int main() {
    int choice, data;
    
    printf("Queue Implementation using Two Stacks (Max Size: %d)\n", MAX_SIZE);
    
    do {
        printf("\n--- Menu ---\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            choice = 0;
        }

        switch (choice) {
            case 1:
                printf("Enter data to Enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
                
            case 2:
                dequeue();
                break;
                
            case 3:
                peek();
                break;
                
            case 4:
                display();
                break;
                
            case 5:
                printf("Exiting program. Goodbye!\n");
                break;
                
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}
