#include<stdio.h>
#define size 5
int front=-1,rear=-1,a[size];
void enqueue(int value);
void dequeue();
void show();
int main(){
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);
	enqueue(6);
	printf("Queue After enqueueing numbers\n");
	show();
	dequeue();
	printf("Queue after dequeueing numbers\n");
	show();
}
void enqueue(int value){
	if(rear==size-1){
		printf("\nQueue is full\n");
	}
	else{
		if(front==-1)
		front=0;
		rear++;
		a[rear]=value;
		printf("\nInserted->%d",value);
	}
}
void dequeue(){
	if(front==-1){
		printf("\nQueue is empty");
	}
	else
	{
		printf("\nDeleted->%d\n",a[front]);
		front++;
		if(front>rear)
		front=rear=-1;
	}
}
void show()
{
	if(rear==-1)
	printf("Queue is empty");
	else
	{
		printf("\nQueue elements are:\n");
		for(int i=front;i<=rear;i++)
		printf("%d",a[i]);
	}
	printf("\n");
}
