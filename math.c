#include <stdio.h>

int main(){
// “Nicholas is 43, next year he’ll be 44. Twice his age is 86. His dog Marty is 3, so the difference is 36.”
    int age = 43;
    char *dogName = "Marty";
    char *namePerson = "Nicholas";
    int dogAge = 3;

    namePerson = "Bill";
    dogAge = 4;

    printf("%s is %d. Next year he will be %d\n", namePerson, age, age+1);
    printf("Twice his age is %d. \n", age*2);
    printf("His dog %s is %d, so the difference is %d. \n", dogName, dogAge, age - dogAge);

    return 0;
}