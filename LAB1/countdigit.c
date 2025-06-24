// #include<stdio.h>
// #include<string.h>
// void main(){
//     char num[10];
//     printf("Enter the Number: ");
//     scanf("%s" , &num);
//     int count;
//     count = strlen(num);
//     printf("%d" , count);
// }

// #include<stdio.h>
// void main(){
//     int n;
//     printf("Enter the Digit: ");
//     scanf("%d" , &n);
//     int count = 0;
//     while(n != 0){
//         n /= 10;
//         count++;
//     }
//     printf("%d" , count);
// }

#include<stdio.h>
int countdigit(int);
void main(){
    int n ,c;
    printf("Enter the Digit: ");
    scanf("%d" , &n);
    c = countdigit(n);
    printf("%d" , c);

}

int countdigit(int n){
    if(n == 0){
        return 0;
    }else{
        return 1 + countdigit(n / 10);
    }
}