#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5 

int stack1[MAX_SIZE]; 
int stack2[MAX_SIZE];
int top1 = -1;
int top2 = -1;

void push1(int data)
{
    stack1[++top1] = data;
}

int pop1() 
{
    return stack1[top1--];
}

void push2(int data) 
{
    stack2[++top2] = data;
}

int pop2() 
{
    return stack2[top2--];
}

void enqueue(int data) 
{
    if ((top1 + 1) + (top2 + 1) >= MAX_SIZE) 
	{
        printf("\nQueue is full (Max Size: %d). Cannot Enqueue %d.\n", MAX_SIZE, data);
        return; 
    }
    push1(data);
    printf("Enqueued: %d\n", data);
}

void transfer_stacks() 
{
    if (top2 == -1) 
	{
        while (top1 != -1) 
		{
            push2(pop1());
        }
    }
}

void dequeue() 
{
    if (top1 == -1 && top2 == -1) 
	{
        printf("Queue is empty. Cannot Dequeue.\n");
        return;
    }
    transfer_stacks();
    int dequeued_data = pop2();
    printf("Dequeued: %d\n", dequeued_data);
}

void peek() 
{
    if (top1 == -1 && top2 == -1) 
	{
        printf("Queue is empty. No element to Peek.\n");
        return;
    }
    transfer_stacks();
    printf("Peek (Front Element): %d\n", stack2[top2]);
}

void display() {
	
    if (top1 == -1 && top2 == -1) 
	{
        printf("Queue is empty.\n");
        return;
    }
    transfer_stacks(); 
    printf("Queue Elements (Front -> Rear): ");
    int i;
    for ( i = top2; i >= 0; i--) 
	{
        printf("%d ", stack2[i]);
    }
    printf("\n");
}

int main() 
{
    int choice, data;
    printf("Queue Implementation using Stacks \n");
    do 
	{
        printf("\n--- Menu ---\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) 
		{
        	
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
                printf("Exiting program....\n");
                break;                
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);
    return 0;
}
