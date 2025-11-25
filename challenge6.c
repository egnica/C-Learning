#include <stdio.h>

int userMenuInput;
struct ledPattern
{
    char patternName[50];
    int lightPattern[8];
};

struct ledPattern ledPatternArray[50];

int count = 0;
void newLedPattern();
void printAll();


int main(){
   do
   {
    printf("1) Create a new LED pattern \n");
    printf("2) Show all saved patterns \n");
    printf("3) Exit the program \n");
    printf("-> ");
    scanf("%d", &userMenuInput);

    switch (userMenuInput)
    {
    case 1:
        newLedPattern();
        break;

    case 2:
        printAll();
        break;
    
    case 3:
        printf("exiting program \n");
        break;

    default:
        printf("Invalid option. Try again.\n");
        break;
    }


   } while (userMenuInput != 3);

    return 0;
}

void newLedPattern() {

    if (count >= 50) {
        printf("Pattern list is full!\n");
        return;
    }

    struct ledPattern led;
    int patternCount = 0;

    printf("Enter Pattern Name: ");
    scanf("%49s", led.patternName);

    printf("...entering pattern loop... \n");

    while (patternCount < 8) {
        int value;

        do {
            printf("Enter on = 1/off = 0 for spot %d: ", patternCount);
            scanf("%d", &value);
        } while (value != 0 && value != 1);

        led.lightPattern[patternCount] = value;
        patternCount++;
    }

    ledPatternArray[count] = led;
    count++;
}

void printAll(){
    int quickCount = 0; 
    for(int x = 0; x < count; x++){
        printf("%s \n", ledPatternArray[x].patternName);
        printf("Pattern: \n");
        while(quickCount < 8){
            printf("%d \n", ledPatternArray[x].lightPattern[quickCount]);
            quickCount++;
        }
        quickCount = 0;
    }
}