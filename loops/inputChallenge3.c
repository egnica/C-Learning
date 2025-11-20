#include <stdio.h>

int main(){

    int userMenu;
    int userNumber;
    int numArray[100];
    int count = 0;
    int sumOf = 0;
    do
    {
        
        printf("Menu: \n 1) Add a number \n 2) Show all numbers entered \n 3) Show the sum of all numbers \n 4) Clear all numbers \n 5) Quit \n" );
        printf("-> ");
        scanf("%d", &userMenu);

        if(count >= 100){
            printf("Number array is full");
            break;
        }

switch (userMenu)
{
case 1:
    printf("please enter number: ");
    scanf("%d", &userNumber);

    numArray[count] = userNumber;
    sumOf += userNumber;
    count++;
    break;
case 2:
    printf("Here are all of the numbers entered: \n");
    for(int x = 0; x < count; x++){
        printf("%d \n",numArray[x]);
    }
    break;
case 3:
    printf("Here is the sum of all of the numbers: %d \n", sumOf);
    break;
case 4:
    printf("All numbers cleared. \n");
    count = 0;
    sumOf = 0;
    break;
case 5:
    printf("Logging out... \n");
    break;

default:
    printf("Invalid number. Enter 1-5.\n");
}        
    } while (userMenu != 5);
    
    return 0;
}