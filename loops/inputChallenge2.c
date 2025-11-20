#include <stdio.h>

int main(){

int sumOf = 0;
int userNum;

while(1){

printf("Enter a number: ");
scanf("%d", &userNum);

    if(userNum == -1){
        break;
    }

    sumOf += userNum;
}
printf("Final Total: %d \n", sumOf);

    return 0;
}