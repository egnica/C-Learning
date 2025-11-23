#include <stdio.h>

void contactCapture();
void listAll();
int nameSearch();
int stringComp(char *a, char *b);
int numMenuSelect;
int count = 0;
struct Contact
    {
        char name[50];
        char phone[20];
        char email[50];
    };
struct Contact contactArray[50];
char searchName[50];
void deleteRecord();
void saveContacts();
void loadContacts();


int main(){

    int startUp = 0;

    if(startUp == 0){
        loadContacts();
        startUp++;
    }
    
    

do{

    printf("1. Add a new contact \n");
    printf("2. List all contacts \n");
    printf("3. Search for a contact by name \n");
    printf("4. Delete a contact by index \n");
    printf("5. Save all contacts to a file\n");
    printf("6. Quit \n");
    printf("-> ");
    scanf("%d", &numMenuSelect);

    switch (numMenuSelect)
    {
    case 1:
        contactCapture();
        break;
    case 2:
        listAll();
        break;
    case 3: {
    int returnNum = nameSearch();
    printf("Name: %s \n", contactArray[returnNum].name);
    printf("Phone: %s \n", contactArray[returnNum].phone);
    printf("Email: %s \n", contactArray[returnNum].email);
    break;  
    }
    case 4: {
        deleteRecord();
        break;
    }
    case 5:
    saveContacts();
    break;
   

    default:
    printf("Why don't you make like a tree, and get out of here!");
        break;
    }




}while(numMenuSelect != 6);



    return 0;



}

void contactCapture(){

struct Contact c;

printf("Name: ");
scanf("%49s", c.name);

printf("Phone: ");
scanf("%19s", c.phone);

printf("Email: ");
scanf("%49s", c.email);

contactArray[count] = c;
count++;        

}

void listAll(){
    for(int x = 0; x < count; x++){
        printf("Profile --- ");
        printf("%d:\n", x);
        printf("Name: %s \n",contactArray[x].name);
        printf("Phone: %s \n",contactArray[x].phone);
        printf("Email: %s \n",contactArray[x].email);
        printf("------- \n");
    }

}

int nameSearch(){

    printf("Enter Name to Search:");
    scanf("%49s", searchName);

 

    for(int x = 0; x < count; x++){
        if(stringComp(searchName, contactArray[x].name)) {
            return x;
        }
    }
    return -1;
}

int stringComp(char *a, char *b){
    int countA = 0;
    int countB = 0;

    while(a[countA] != '\0' && b[countB] != '\0'){

        if(a[countA] != b[countB]){
            return 0;
        }

        countA++;
        countB++;
    }
    return (a[countA] == '\0' && b[countB] == '\0');

}

void deleteRecord(){

    int index;

    printf("enter the index you want to delete: ");
    scanf("%d", &index);

    for(int x = index; x < count - 1; x++){
       contactArray[x] = contactArray[x+1];
    }

    count--;

}

void saveContacts(){
    FILE *file = fopen("contact.txt", "w");

    for(int x = 0; x < count; x++){
         fprintf(file,"%s %s %s \n",  contactArray[x].name,  contactArray[x].phone,  contactArray[x].email);
    }

   fclose(file);

}

void loadContacts(){
    FILE *file = fopen("contact.txt", "r");

    if(file == NULL) {
        printf("No contact file found");
    }

    count = 0;


    while (count < 50) {

        int readCount = fscanf(file, "%49s %19s %49s",
                               contactArray[count].name,
                               contactArray[count].phone,
                               contactArray[count].email);

        if (readCount != 3) {
            break; // stop loading
        }

        count++;
    }

    fclose(file);
    printf("Loaded %d contacts from contact.txt\n", count);

}