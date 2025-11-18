#include <stdio.h>

int main(){

    int age = 43;

if(age < 18){
   printf("You are a minor \n");
}else if (age >= 65){
   printf("You are an adult \n");
}else{
   printf("You are a senior \n");
}

    int temp = 75;
    int isRaining = 0; // 0 = false, 1 = true
    int hasJacket = 1;

    if (temp > 70 && !isRaining)
    {
        printf("Nice weather! \n");
    }
    if (isRaining == 1 || temp < 50)
    {
        printf("Bring an Umbrella \n");
    } 
    if (temp < 40 && hasJacket)
    {
         printf("You'll be fine\n");
}
    if (!isRaining){
    printf("Clear skies\n");
}

    
    return 0;
}