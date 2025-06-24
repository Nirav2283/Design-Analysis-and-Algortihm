#include<stdio.h>
void main(){
    int n , n1 = 0 , n2 = 1 , n3;
    printf("Enter the Number of term: ");
    scanf("%d" , &n);
    printf("%d %d " , n1 , n2);
    for(int i = 0 ; i < n - 2 ; i++){
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
        printf("%d " , n3);
        
    }

}