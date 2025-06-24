#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* head = NULL;

struct Node*  create(int value){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    //sizeof(struct Node) calculate krse ke Node ne store ketli jagya joi che ane malloc heap mem. mathi allocate krse bytes 
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertatfirst(int value){
    struct Node* newNode = create(value);
    newNode->next = head;
    head = newNode;
    printf("inserted %d at begining" , value);
}

void insertatend(int value){
    struct Node* newNode = create(value);
    if(head == NULL){
        head = newNode;
        return;
    }else{
        struct Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("%d inserted at last" , value);
}

void deleteatfirst(){
    if(head == NULL){
        printf("List is empty");
        return;
    }else{
        struct Node* temp = head;
        head = head->next;
        printf("%d is deleted from beginning" , temp->data);
        free(temp);
    }
}

void deleteatend(){
    if(head == NULL){
        printf("List is empty");
        return;
    } 
    if(head->next == NULL){
        printf("Deleted %d from end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    printf("Deleted %d from end.\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

void display(){
    if(head == NULL){
        printf("List is empty");
        return;
    }
    struct Node * temp = head;
    printf("LINKED LIST: ");
    while(temp != NULL){
        printf("%d -> " , temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void main(){
     int n , choice;
    
    while(1){
        printf("\n1.INSERT AT FIRST\n2.INSERT AT LAST\n3.DELETE AT FIRST\n4.DELETE AT LAST.\n5.DISPLAY LIST\n6.EXIT\n");
        printf("Enter the choice for linked list operation: ");
        scanf("%d" , &choice);

        switch(choice){
            case 1:
                printf("Enter the value: ");
                scanf("%d" , &n);
                insertatfirst(n);
                break;
            case 2:
                printf("Enter the value: ");
                scanf("%d" , &n);
                insertatend(n);
                break;
            case 3:
                deleteatfirst();
                break;
            case 4:
                deleteatend();
                break;
            case 5:
                display();
                break;
            default:
                printf("Invalid choice!!");
                return;
        }
    }
    

}

