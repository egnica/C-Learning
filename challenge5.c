#include <stdio.h>

int userNumMenu;

int count;

struct Movies
{
   char movieName[50];
   int yearReleased;
   int starRating;
};

struct Movies movieArray[50];

void createNewRecord();
void showAllRecords();

int main(){

    do
    {
        printf("1) Add item \n");
        printf("2) List all items \n");
        printf("3) Search for an item \n");
        printf("4) Edit an item \n");
        printf("5) Delete an item \n");
        printf("6) Clear all items \n");
        printf("7) Save items to file \n");
        printf("8) Quit \n");
        printf("->");
        scanf("%d", &userNumMenu);

        

        switch (userNumMenu)
        {
        case 1:
            createNewRecord();
            break;
        case 2:
            showAllRecords();
            break;
        
        default:
        printf("Exited Program");
        break;
        }

    } while (userNumMenu != 8);
    

    return 0;
}

void createNewRecord(){
    

    printf("Movie Title: ");
    scanf("%49s", movieArray[count].movieName);
    printf("Year Released: ");
    scanf("%d", &movieArray[count].yearReleased);
    printf("How many starts: ");
    scanf("%d", &movieArray[count].starRating);

    count++;

}

void showAllRecords(){
    
    for(int x = 0; x < count; x++){
        printf("index: %d", x);
        printf("%s \n", movieArray[x].movieName);
        printf("%d \n", movieArray[x].yearReleased);
        printf("%d \n", movieArray[x].starRating);
        printf("------- \n");
    }

}