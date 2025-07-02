#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void binarysearch(int arr[], int n, int a) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == a) {
            printf("Element found at: %d\n", mid);
            return;
        } else if (arr[mid] > a) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    printf("Element not found\n");
}

void bubblesort(int arr[] , int n){
    int i , j , temp;
    for(i = 0 ; i < n - 1 ; i++){
        for(j = 0 ; j < n - i - 1 ; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
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
    // binarysearch(arr , size , element);


    FILE *file;
    clock_t start , end;
    double cpu_time;
    int n = 10000;
    int element;
    int arr1[n];
    int arr2[n];
    int arr3[n];

    // worst case scenario
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
    bubblesort(arr1 , n);
    start = clock();
    binarysearch(arr1 , n , element);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to the binary search array in worst case: %f seconds\n" , cpu_time);


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
    binarysearch(arr2 , n , element);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to the binary search array in Best case: %f seconds\n" , cpu_time);

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
    printf(":::AVERAGE CASE SCENARIO:::\n");\
    bubblesort(arr3 , n);
    start = clock();
    binarysearch(arr3 , n , element);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to the binary search array in worst case: %f seconds\n" , cpu_time);
}
