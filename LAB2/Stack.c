#include<stdio.h>
#include<stdlib.h>

#define SIZE 50

int top = -1;
int stack[SIZE];

void push(int value){
    if(top >= SIZE - 1){
        printf("Stack Overflow");
    }else{
        stack[++top] = value;
        printf("%d is pushed in the stack" , value);
    }
}

void pop(){
    if(top <= -1){
        printf("Stack underflow");
    }else{
        printf("%d Element popped" , stack[top--]);
    }
}

void peep(){
    if(top <= -1){
        printf("Stack underflow");
    }else{
        printf("%d is the top element of Stack" , stack[top]);
    }
}

void change(int position , int value){
    if(top - position + 1 <= -1 || position <= 0){
        printf("Invalid position");
    }else{
        stack[top - position + 1] = value;
        printf("New element is %d at the position %d" , value , position);
    }
}

void display(){
    if(top == -1){
        printf("Stack is empty");
    }else{
        for(int i = top ; i >= 0 ; i--){
            printf("%d\n" , stack[i]);
        }
    }
}

void main(){
     int choice;
     int n;
     int i , x;
    
    while(1){
        printf("\n1.PUSH\n2.POP\n3.PEEP\n4.CHANGE.\n5.DISPLAY\n6.EXIT\n");
        printf("Enter the choice for stack operation: ");
        scanf("%d" , &choice);

        switch(choice){
            case 1:
                printf("Enter the value: ");
                scanf("%d" , &n);
                push(n);
                break;
            case 2:
                pop();
                break;
            case 3:
                peep();
                break;
            case 4:
                printf("Enter the position: ");
                scanf("%d" , &i);
                printf("Enter the new element: ");
                scanf("%d" , &x);
                change(i , x);
                break;
            case 5:
                display();
                break;
            case 6:
                return;
            default:
                printf("Invalid choice!!");
                break;
        }
    }
    

}




