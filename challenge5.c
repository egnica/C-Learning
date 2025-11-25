#include <stdio.h>
void addItem();
void listAll();
int titleSearch();
int stringCompare(char *a, char *b);
int findIndexRecord();
void editRecord(int index);
void deleteRecord();
void deleteAll();
void saveTXT();
void loadFile();
int count = 0;
struct movies
{
    char movieTitle[50];
    int yearReleased;
    int starsReceived;
};

struct movies movieArray[100];


int main(){

loadFile();

int userNumMenu;



    do
    {
        printf("1) Add item \n");
        printf("2) List all items \n");
        printf("3) Search for an item by title \n");
        printf("4) Edit an item \n");
        printf("5) Delete an item \n");
        printf("6) Clear all items \n");
        printf("7) Save items to file \n");
        printf("8) Quit \n");
        printf("-> ");
        scanf("%d", &userNumMenu);

    if(userNumMenu > 8 || userNumMenu < 1){
        printf("Invalid entry");
        break;
       } 
        switch (userNumMenu)

        {
        case 1:
            addItem();
            break;

        case 2:
            listAll();
            break;

        case 3:
        {
            int index = titleSearch();

            if(index != -1){
                printf("Title: %s \n", movieArray[index].movieTitle);
                printf("Year Released: %d \n", movieArray[index].yearReleased);
                printf("Stars Received: %d \n", movieArray[index].starsReceived);
            }else{
                printf("Title Not Found \n");
            }
       
            break;

        }
        case 4:
        {
           int num = findIndexRecord();

           if (num != -1) {
                editRecord(num);
            } else {
                printf("Record Not Found \n");
            }
             break;
        }
        case 5:
            deleteRecord();
            break;

        case 6:
            deleteAll();
            break;

        case 7:
            saveTXT();
            break;
        
        default:
            printf("Program has ended \n");
            break;
        }

    

    
}while (userNumMenu != 8);



return 0;
}





// functions
void addItem(){

   struct movies m;

   printf("Movie Title: ");
   scanf("%49s", m.movieTitle);
   printf("Year Released: ");
   scanf("%d", &m.yearReleased);
   printf("Stars Rated: ");
   scanf("%d", &m.starsReceived);
   
   movieArray[count] = m;
   count++;
}

void listAll(){
    
    for(int x = 0; x < count; x++){
        printf("Index: %d \n", x);
        printf("Title: %s \n", movieArray[x].movieTitle);
        printf("Year Released: %d \n", movieArray[x].yearReleased);
        printf("Starts Received: %d \n", movieArray[x].starsReceived);
        printf("------------------------- \n");
    }
}
int titleSearch(){

    char userEnter[50];

    printf("Seach this title: ");
    scanf("%49s", userEnter);
    for(int x = 0; x < count; x++){
        if(stringCompare(userEnter, movieArray[x].movieTitle)){
            return x;
        }
    }

    return -1;

}
int stringCompare(char *a, char *b){
    int countA = 0;
    int countB = 0;

    while(a[countA] != '\0' || b[countB] != '\0'){

        if(a[countA] != b[countB]){
            return 0;
        } 
        countA++;
        countB++;
    }
     return 1;
}
int findIndexRecord(){

    int userIndex;

    printf("Enter the index of the record you want to edit: ");
    scanf("%d", &userIndex);

  
        if (userIndex <= count){
            return userIndex;
        }
  
    return -1;
}

void editRecord(int index){
    
    struct movies mov;

    printf("Movie Title: ");
    scanf("%49s", mov.movieTitle);
    printf("Year Released: ");
    scanf("%d", &mov.yearReleased);
    printf("Stars Rated: ");
    scanf("%d", &mov.starsReceived);

    movieArray[index] = mov;
  
}
void deleteRecord(){

    int index;

    printf("Enter the index you would like to delete: ");
    scanf("%d", &index);

    if (index < 0 || index >= count) {
        printf("Invalid index\n");
        return;
    }

    movieArray[index] = movieArray[count - 1];
    count--;
}
void deleteAll(){

    int yesNo;

    printf("Are you sure you want to delete all records?\n 1 = 'delete' | 2 = 'exit': "); 
    scanf("%d", &yesNo);

    if(yesNo == 1){
        count = 0;
        printf("All records have been deleted \n");
    }
}

void saveTXT(){

    FILE *file = fopen("save.txt", "w");

    for(int x = 0; x < count; x++){
        fprintf(file, "%s %d %d \n", movieArray[x].movieTitle, movieArray[x].yearReleased, movieArray[x].starsReceived);
    }

    fclose(file);
    printf("File Saved \n");
}
void loadFile(){


   
 FILE * file = fopen("save.txt", "r");

    if (file == NULL) {
    return;
    }

    count = 0;
    while (fscanf(file, "%49s %d %d",
              movieArray[count].movieTitle,
              &movieArray[count].yearReleased,
              &movieArray[count].starsReceived) == 3) {

    count++;
}
     fclose(file);
}