#include<stdio.h>
#define size 5
void enqueue(int);
void dequeue();
void display();
int items[size],front=-1,rear=-1;
int main(){
dequeue();
enqueue(1);
enqueue(2);
enqueue(3);
enqueue(4);
enqueue(5);
enqueue(6);
display();
dequeue();
display();
return 0;
}
void enqueue(int value){
    if(rear==size-1)
    printf("\nqueue is full!!");
    else{
        if(front==-1)
        front=0;
        rear++;
        items[rear]=value;
        printf("\ninserted->%d",value);
    }
}
void dequeue(){
    if(front==-1)
    printf("\nqueue is empty!!");
    else{
        printf("\ndeleted:%d",items[front]);
        front++;
        if(front>rear)
        front=rear=-1;
    }
}
void display(){
    if(rear==-1)
    printf("\nqueue is empty!!!");
    else{
        int i;
        printf("\nqueue elements are:\n");
        for(i=front;i<=rear;i++)
        printf("%d",items[i]);
    }
    printf("\n");
}