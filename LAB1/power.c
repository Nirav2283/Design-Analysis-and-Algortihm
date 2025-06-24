// #include<stdio.h>
// void main(){
//     int x , y; 
//     printf("Enter the base: ");
//     scanf("%d" , &x);
//     printf("Enter the power: ");
//     scanf("%d" , &y);
//     int temp = x;
//     for(int i = 1 ; i < y ;i++){
//         x = temp  *  x;
//     }
//     printf("%d" , x);
// }

#include<stdio.h>
int power(int , int);
void main(){
    int x , y , p;
    printf("Enter the base: ");
    scanf("%d" , &x);
    printf("Enter the power: ");
    scanf("%d" , &y);
    p = power(x , y);
    printf("%d" , p);
}

int power(int x , int y){
    if(y == 0) {
        return 1;
    }else{
        return x * power(x , y - 1);
    }
}