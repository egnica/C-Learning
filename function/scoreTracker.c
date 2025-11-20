#include <stdio.h>

void scoreCapture();
void displayAll();
float average();
int highScore();
int lowScore();
void clearScores();
int hasScores();

    int score;
    int scoreArray[50];
    int userMenuInput;
    int count = 0;

int main(){
    
    

    do
    {
        printf("Menu: \n");
        printf("1️⃣ Add a new player's score \n");
        printf("2️⃣ Display all scores \n");
        printf("3️⃣ Calculate and print the average score \n");
        printf("4️⃣ Find the highest score \n");
        printf("5️⃣ Find the lowest score \n");
        printf("6️⃣ Clear all scores \n");
        printf("7️⃣ Quit the program \n");
        printf("-> ");
        scanf("%d", &userMenuInput);


       switch (userMenuInput)
       {
       case 1:
       if(count >= 50){
         printf("Number array is full. Cannot add more.\n");
         break;
       }
       scoreCapture();
       break;

       case 2:
        if (!hasScores()) break;
        displayAll();
       break;

       case 3:
        if (!hasScores()) break;
        float aveResult = average();
        printf("The average score is: %f \n", aveResult);
        break;

        case 4:
        {
        if (!hasScores()) break;
        int highScoreResult = highScore();
        printf("The highest score is: %d \n", highScoreResult);
        break;
        }
        case 5:
        {
        if (!hasScores()) break;
        int lowScoreResult = lowScore();
        printf("The lowest score is: %d \n", lowScoreResult);
        break;
        }
        case 6:
        if (!hasScores()) break;
        clearScores();
        printf("All scores have been cleared \n");
        break;

        case 7:
        printf("logging out... \n");
        break;

       default:
        printf("Invalid number. Enter 1-7.\n");
        break;
       }
    } while (
        userMenuInput != 7
    );
    
    return 0;
}

void scoreCapture(){
    printf("Enter your score: ");
    scanf("%d", &score);
    scoreArray[count] = score;
    count ++;
}

void displayAll(){
    for(int i = 0; i < count; i++){
        printf("%d \n", scoreArray[i]);
    }
}

float average(){
    float sum = 0;
    for(int i = 0; i < count; i++){
        sum += scoreArray[i];
    }
    return sum/count;
}
int highScore(){
    int high = 0;
for(int i = 0; i < count; i++){
    if(scoreArray[i] > high){
        high = scoreArray[i];
    }
}
   return high;
}

int lowScore(){
    int low = scoreArray[0];
    for(int i = 0; i < count; i++){
        if(low > scoreArray[i]){
            low = scoreArray[i];
        }
    }
    return low;
}
void clearScores(){
    count = 0;
}

int hasScores() {
    if (count == 0) {
        printf("No numbers have been entered.\n");
        return 0;   
    }
    return 1;          
}