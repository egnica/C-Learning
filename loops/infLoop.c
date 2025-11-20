#include <stdio.h>

int main() {

    // int x = 0;

    // while (1) {   // infinite loop
    //     printf("x = %d\n", x);
    //     x++;

    //     if (x > 10) {
    //         break;  // stops the infinite loop
    //     }
    // }

    // printf("Loop ended.\n");

    int userNum;

    while(1){
        printf("Please enter a number: \n");
        scanf("%d", &userNum);

        if (userNum == -1){
            break;
        };
        printf("You entered %d \n", userNum);

    };

    printf("Program Ended \n");
    return 0;
}