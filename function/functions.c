#include <stdio.h>

int square(int a);

int main(){

    int result = square(4);

    printf("%d \n", result);
    return 0;
}

int square(int a){
    return a * a;
}