#include <stdio.h>

int main(){

int userInput;
int values[100];    
int count = 0;

while(1){

    printf("enter a number: ");
    scanf("%d", &userInput);

    if(userInput == -1){
        break;
    }
    if(count >= 100){
        printf("Array full! Stopping input.\n");
        break;
    }

    values[count] = userInput;
    count++;
}
printf("You entered: \n");
for(int x = 0; x < count; x++){
    printf("%d \n", values[x]);
};

    return 0;
}