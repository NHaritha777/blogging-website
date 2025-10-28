#include<stdio.h>
#define n 3
int stack[n],top=-1;
int isFull(){
	return top==n-1;
}
int isEmpty(){
	return top==-1;
}
void push(int x){
	if(isFull())
	printf("Stack Overflow\n");
	else{
		stack[++top]=x;
		printf("Pushed %d into stack\n",x);
	}
}
void pop(){
	if(isEmpty())
	printf("Stack Underflow\n");
	else {
	//stack[top--];
	printf("Popped : %d \n",stack[top--]);
	}	
}
void display(){
	int i;
	if(isEmpty())
	printf("Stack Underflow\n");
	else{
		for(i=0;i<=top;i++)
		printf("%4d",stack[i]);
	}
}
void peek(){
	if(isEmpty())
	printf("Stack Underflow\n");
	else{
		printf("Top element: %d \n",stack[top]);
	}
}
void main()
{
	int i,ch;
	do{
	printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
	printf("Enter your choice: ");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			printf("Enter ele to insert: ");
			scanf("%d",&i);
			push(i);
			break;
		case 2:
			pop();
			break;
		case 3:
			peek(); break;
		case 4:
			display(); break;
		case 5:
			printf("Exiting program......");
			break;
		default:
			printf("Invalid choice ! Try again\n");
		}	
	} while(ch!=5);
	
}
