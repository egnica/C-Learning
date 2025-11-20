#include <stdio.h>

int main(){

    // printf("degradation \n");
    // for(int y = 10; y > 0; y--){
    //     printf("%d \n", y);
    // }

    // printf("Custom \n");
    // for(int i = 0; i <= 20; i += 2){
    //     printf("%d \n", i);
    // }

    int userNum;
    int inc;

    printf("please enter a number: ");
    scanf("%d", &userNum);

    printf("Enter a number to increment by: ");
    scanf("%d", &inc);

       if (inc <= 0) {
        printf("Increment must be greater than zero.\n");
        return 1;
    }

        if (userNum <= 0) {
        printf("User Number must be greater than zero.\n");
        return 1;
    }

    for(int x = 0; x <= userNum; x += inc){
        printf("%d \n", x);
    }

    return 0;
}