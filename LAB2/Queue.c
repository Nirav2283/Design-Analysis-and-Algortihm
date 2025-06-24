#include<stdio.h>
#include<stdlib.h>

#define SIZE 50

int queue[SIZE];
int front = -1;
int rear = -1;

void insert(int value){
    if(rear == SIZE - 1){
        printf("Queue Overflow!!");
    }
    if(front == -1){
        front = 0;
    }
    rear++;
    queue[rear] = value;
    printf("%d is enqued in the queue" , value);
}

void delete(){
    if(front > rear || front == -1){
        printf("Queue underflow");
    }else{
        printf("%d is dequeud in the queue" , queue[front++]);
        
    }
}

void display(){
    if(front == -1){
        printf("queue is empty");
    }else{
        for(int i = front ; i <= rear ; i++){
            printf("%d " , queue[i]);
        }
    }
}

void main(){
     int n , choice;
    
    while(1){
        printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT.\n");
        printf("Enter the choice for queue operation: ");
        scanf("%d" , &choice);

        switch(choice){
            case 1:
                printf("Enter the value: ");
                scanf("%d" , &n);
                insert(n);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                return;
            default:
                printf("Invalid choice!!");
                break;
        }
    }
    

}