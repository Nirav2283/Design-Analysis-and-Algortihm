#include<stdio.h>
void main(){
    int n;
    printf("Enter the number of term: ");
    scanf("%d" , &n);
    int sum = 0;
    for(int i = 1 ; i <= n ; i++){
        sum += i;
    }
    printf("Sum of the first %d is %d" , n ,sum);

}

