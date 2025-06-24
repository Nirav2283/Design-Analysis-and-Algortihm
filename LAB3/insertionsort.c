#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertionsort(int arr[] , int n){
    int key , j ;
    for(int i = 1 ; i < n ;i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void main(){
    // int arr[100] , size;
    // printf("Enter the size of array: ");
    // scanf("%d" , &size);
    // for(int i = 0 ; i < size ; i++){
    //     printf("Enter array element %d: " , i + 1);
    //     scanf("%d" , &arr[i]);
    // }
    // printf("Original array: ");
    // printArray(arr,size);
    // insertionsort(arr,size);
    // printf("Sorted array: ");
    // printArray(arr,size);

    FILE *file;
    clock_t start , end;
    double cpu_time;
    int n = 100000;
    int arr1[n];
    int arr2[n];
    int arr3[n];

    //worst case scenario
    file = fopen("Worst.txt" , "r");
    for(int i = 0 ; i < n ; i++){
        fscanf(file , "%d" , &arr1[i]);
    }
    fclose(file);
    printf(":::WORST CASE SCENARIO:::\n");
    start = clock();
    insertionsort(arr1 , n);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to the insertion sort array in worst case: %f seconds\n" , cpu_time);

    // best case scenario
    file = fopen("Best.txt" , "r");
    for(int i = 0 ; i < n ; i++){
        fscanf(file , "%d" , &arr2[i]);
    }
    fclose(file);
    printf(":::BEST CASE SCENARIO:::\n");
    start = clock();
    insertionsort(arr1 , n);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to the insertion sort array in best case: %f seconds\n" , cpu_time);

    //average case scenario
    file = fopen("Average.txt" , "r");
    for(int i = 0 ; i < n ; i++){
        fscanf(file , "%d" , &arr3[i]);
    }
    fclose(file);
    printf(":::AVERAGE CASE SCENARIO:::\n");
    start = clock();
    insertionsort(arr1 , n);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to the insertion sort array in Average case: %f seconds\n" , cpu_time);
}