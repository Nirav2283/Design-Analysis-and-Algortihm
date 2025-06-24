#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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
void printarray(int arr[] , int n){
    for(int i = 0 ; i < n ; i++){
        printf("%d " , arr[i]);
    }

}

void main(){

    //checking the code whether it is working or not...

    // int arr[100] , size;
    // printf("Enter the size of array: ");
    // scanf("%d" , &size);
    // for(int i = 0 ; i < size ; i++){
    //     printf("Enter array element %d: " , i + 1);
    //     scanf("%d" , &arr[i]);
    // }
    // printf("Original array: ");
    // printarray(arr,size);
    // bubblesort(arr,size);
    // printf("Sorted array: ");
    // printarray(arr,size);


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
    bubblesort(arr1 , n);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to the bubble sort array in worst case: %f seconds\n" , cpu_time);


    //best case scenario
    file = fopen("Best.txt" , "r");
    for(int i = 0 ; i < n ; i++){
        fscanf(file , "%d" , &arr2[i]);
    }
    fclose(file);
    printf(":::BEST CASE SCENARIO:::\n");
    start = clock();
    bubblesort(arr1 , n);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to the bubble sort array in best case: %f seconds\n" , cpu_time);


    //average case scenario
    file = fopen("Average.txt" , "r");
    for(int i = 0 ; i < n ; i++){
        fscanf(file , "%d" , &arr3[i]);
    }
    fclose(file);
    printf(":::AVERAGE CASE SCENARIO:::\n");
    start = clock();
    bubblesort(arr1 , n);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to the bubble sort array in Average case: %f seconds\n" , cpu_time);
}
