#include <stdio.h>

int main(){
    int age;

    
    do
    {
        printf("Please enter age: ");
        scanf("%d", &age);

            if (age < 1 || age > 120) {
            printf("Invalid age, try again: \n");
        }
      
    } while (age < 1 || age > 120);
  

printf("Accepted Age: %d \n", age);
    return 0;
}