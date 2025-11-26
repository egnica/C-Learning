#include <stdio.h>
#include <string.h>

#define MAX_PATTERNS 50
#define LED_COUNT 8

struct ledPattern {
    char patternName[50];
    int lightPattern[LED_COUNT];
};

// Global storage (still fine for now)
struct ledPattern ledPatternArray[MAX_PATTERNS];
int patternCount = 0;

// --- Function Prototypes ---
void createPattern(struct ledPattern *p);
void addPattern(struct ledPattern patterns[], int *count, const struct ledPattern *newP);
void printPattern(const struct ledPattern *p);
void printAll(const struct ledPattern patterns[], int count);

int main() {
    int userMenuInput;

    do {
        printf("1) Create a new LED pattern \n");
        printf("2) Show all saved patterns \n");
        printf("3) Exit the program \n");
        printf("-> ");
        scanf("%d", &userMenuInput);

        switch (userMenuInput) {
            case 1: {
                struct ledPattern temp;
                createPattern(&temp);
                addPattern(ledPatternArray, &patternCount, &temp);
                break;
            }
            case 2:
                printAll(ledPatternArray, patternCount);
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    } while (userMenuInput != 3);

    return 0;
}

// --- Create a pattern (pointer-based version) ---
void createPattern(struct ledPattern *p) {
    printf("Enter Pattern Name: ");
    scanf("%49s", p->patternName);

    printf("...entering pattern loop...\n");

    for (int i = 0; i < LED_COUNT; i++) {
        int value;
        do {
            printf("Enter on = 1/off = 0 for spot %d: ", i);
            scanf("%d", &value);
        } while (value != 0 && value != 1);

        p->lightPattern[i] = value;
    }
}

// --- Add pattern to array (ESP32-style parameter passing) ---
void addPattern(struct ledPattern patterns[], int *count, const struct ledPattern *newP) {
    if (*count >= MAX_PATTERNS) {
        printf("Pattern list is full!\n");
        return;
    }

    patterns[*count] = *newP;  // copy struct contents
    (*count)++;
}

// --- Print one pattern ---
void printPattern(const struct ledPattern *p) {
    printf("%s\n", p->patternName);
    printf("Pattern: ");

    for (int i = 0; i < LED_COUNT; i++) {
        printf("%d ", p->lightPattern[i]);
    }
    printf("\n");
}

// --- Print all patterns ---
void printAll(const struct ledPattern patterns[], int count) {
    if (count == 0) {
        printf("No patterns saved.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printPattern(&patterns[i]);
        printf("\n");
    }
}
