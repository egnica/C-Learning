#include <stdio.h>
// WHILE exit != 2:
//     ask user for a name
//     ask user for an age
//     store that name + age somewhere
//     continue
// WHEN exit == 2:
//     print all the people entered

struct Person{
    char name[50];
    int age;
};

int main(){

    int exit = 0;

    struct Person people[100];
    int count = 0;
    
    while(exit != 2){

        printf("Please enter a name: ");
        scanf("%49s", people[count].name);

        printf("Please enter your age: ");
        scanf("%d", &people[count].age);


        printf("Do you want to continue? 1=continue, 2=exit: ");
        scanf("%d", &exit);
        count++;
    }

    if(exit == 2){
        for(int i = 0; i < count; i++){
           printf("Name: %s - Age: %d\n", people[i].name, people[i].age);
        };
    };


    return 0;
}