#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

void linearsearch(int arr[] , int n , int a){
    bool isFound = false;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] == a){
            printf("Element %d Found at: %d\n" , arr[i] , i);
            isFound = true;
            break;
        }
    }
    if(!isFound){
        printf("Element not found\n");
    }
}

void main(){
    // int arr[100] , size , element;
    // printf("Enter the size of array: ");
    // scanf("%d" , &size);
    // for(int i = 0 ; i < size ; i++){
    //     printf("Enter element %d: " , i + 1);
    //     scanf("%d" , &arr[i]);
    // }
    
    // printf("Enter element to search: ");
    // scanf("%d" , &element);
    // linearsearch(arr , size , element);

    FILE *file;
    clock_t start , end;
    double cpu_time;
    int n = 100000;
    int element;
    int arr1[n];
    int arr2[n];
    int arr3[n];

    //worst case scenario
    file = fopen("Worst.txt", "r");
    if(file == NULL){
        printf("Failed to open file\n");
        return;
    }
    for(int i = 0 ; i < n ; i++){
        fscanf(file,"%d" , &arr1[i]);
    }
    fclose(file);
    printf("Enter element to search: ");
    scanf("%d" , &element);
    printf(":::WORST CASE SCENARIO:::\n");
    start = clock();
    linearsearch(arr1 , n , element);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to the linear search array in worst case: %f seconds\n" , cpu_time);


    //best case scenario
    file = fopen("Best.txt", "r");
    if(file == NULL){
        printf("Failed to open file\n");
        return;
    }
    for(int i = 0 ; i < n ; i++){
        fscanf(file,"%d" , &arr2[i]);
    }
    fclose(file);
    printf(":::BEST CASE SCENARIO:::\n");
    start = clock();
    linearsearch(arr2 , n , element);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to the linear search array in Best case: %f seconds\n" , cpu_time);

    //average case scenario
    file = fopen("Average.txt", "r");
    if(file == NULL){
        printf("Failed to open file\n");
        return;
    }
    for(int i = 0 ; i < n ; i++){
        fscanf(file,"%d" , &arr3[i]);
    }
    fclose(file);
    printf(":::AVERAGE CASE SCENARIO:::\n");
    start = clock();
    linearsearch(arr3 , n , element);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to the linear search array in worst case: %f seconds\n" , cpu_time);
}