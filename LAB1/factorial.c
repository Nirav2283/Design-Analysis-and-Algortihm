#include<stdio.h>
void main(){
    int n;
    printf("Enter the number: ");
    scanf("%d" , &n);
    int fact = 1;
    int i;
    for(i = 1 ; i <= n ;i++){
        fact = fact * i;
    }
    printf("%d" , fact);
}