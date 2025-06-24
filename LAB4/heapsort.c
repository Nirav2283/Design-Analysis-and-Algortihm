#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void heapify(int arr[] , int n , int i){
    int maxIndex = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if(leftChild <  n && arr[leftChild] > arr[maxIndex]){
        maxIndex = leftChild;
    }
    if(rightChild < n && arr[rightChild] > arr[maxIndex]){
        maxIndex = rightChild;
    }

    if(i != maxIndex){
        int temp = arr[i];
        arr[i] = arr[maxIndex];
        arr[maxIndex] = temp;

        heapify(arr , n , maxIndex);
    }
    
}

void heapsort(int arr[] , int n){
    for(int i = n / 2 - 1 ; i >= 0 ; i--){
        heapify(arr , n , i);
    }
    for(int j = n - 1 ; j >= 1 ; j--){
        int temp = arr[0];
        arr[0] = arr[j];
        arr[j] = temp;

        heapify(arr, j , 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main(){
    //testing the code 

    // int arr[100] , size;
    // printf("Enter the size of array: ");
    // scanf("%d" , &size);
    // for(int i = 0 ; i < size ; i++){
    //     printf("Enter element %d: " , i + 1);
    //     scanf("%d" , &arr[i]);
    // }
    // printf("original array: ");
    // printArray(arr , size);
    // printf("sorted array: ");
    // heapsort(arr , size);
    // printArray(arr , size);


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
        fscanf(file,"%d" , arr1[i]);
    }
    fclose(file);
    printf(":::WORST CASE SCENARIO:::\n");
    start = clock();
    heapsort(arr1 , n);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to the heap sort array in worst case: %f seconds\n" , cpu_time);

    //best case scenario
    file = fopen("Best.txt" , "r");
    for(int i = 0 ; i < n ; i++){
        fscanf(file,"%d" , arr2[i]);
    }
    fclose(file);
    printf(":::BEST CASE SCENARIO:::\n");
    start = clock();
    heapsort(arr1 , n);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to the heap sort array in  best case: %f seconds\n" , cpu_time);

    //average case scenario

    file = fopen("Average.txt" , "r");
    for(int i = 0 ; i < n ; i++){
        fscanf(file,"%d" , arr3[i]);
    }
    fclose(file);
    printf(":::AVERAGE CASE SCENARIO:::\n");
    start = clock();
    heapsort(arr1 , n);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to the heap sort array in average case: %f seconds\n" , cpu_time);

}