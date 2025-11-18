#include <stdio.h>


struct Person{
     char name[50];
    int age;
};

int main(){

    int exit = 1;
    struct Person per[100];
    int count = 0;
    
    while(exit == 1){

        printf("Please enter your name: ");
        scanf("%49s", per[count].name);

        printf("Please enter your age: ");
        scanf("%d", &per[count].age);


        printf("To CONTINUE enter '1'. To EXIT enter '2': ");
        scanf("%d", &exit);
        count++;
    }

    if (exit == 2){
        for(int i = 0; i < count; i++){
            printf("Name: %s - Age: %d \n", per[i].name, per[i].age);
        }
    }

    return 0;
}