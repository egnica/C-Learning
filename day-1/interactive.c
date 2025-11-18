#include <stdio.h>


int main(){

int age = 0;


while(!age){
    printf("Enter your age: ");
    scanf("%d", &age);
}

 printf("Your age is %d", age);
    return 0;
}