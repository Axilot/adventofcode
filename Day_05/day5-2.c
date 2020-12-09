#include <stdio.h>

#define MAX_LENGTH 1000

int calcSeatID(char seat[]);
int getHighestNumber(int numbers[]);
void saveNumbers(int numbers[]);
int checkForNumber(int numbers[], int num, int length);

int main()
{
    int numbers[MAX_LENGTH], compare[MAX_LENGTH];
    saveNumbers(numbers);

    for (int n = 0; n < MAX_LENGTH; n++) {
        compare[n] = n;
    }


    /* We could adjust this value with the lowest number in the list, but for now we won't :D */
    int i = 1;

    /* Check if there is a seat that doesnt exist but two seats that are next to the seat that doesn't exist */
    while (i < MAX_LENGTH) {
        if (i < getHighestNumber(numbers)) {
            if (!checkForNumber(numbers, compare[i], MAX_LENGTH) && checkForNumber(numbers, compare[i+1], MAX_LENGTH) && checkForNumber(numbers, compare[i-1], MAX_LENGTH)) {
                printf("Your seat id is: %d\n", compare[i]);
            }
        }
        i++;
    }

    return 0;
}

int calcSeatID(char seat[])
{
    int row, column;
    int min = 0, max = 127;
    for (int i = 0; i < 7; i++) {
        if (seat[i] == 'B') {
            min = (max+1+min) / 2;
        }
        else if (seat[i] == 'F') {
            max = (max+min+1) / 2 - 1;
        }
        row = min;
    }
    min = 0;
    max = 7;
    for (int i = 6; i < 10; i++) {
        if (seat[i] == 'R') {
            min = (max+1+min) / 2;
        }
        else if (seat[i] == 'L') {
            max = (max+min+1) / 2 - 1;
        }
        column = min;
    }

    return row * 8 + column;
}

int getHighestNumber(int numbers[])
{
    int i = 0, highestNumber = 0;

    while (i < MAX_LENGTH) {
        if (numbers[i] > highestNumber) {
            highestNumber = numbers[i];
        }
        i++;
    }

    return highestNumber;
}

void saveNumbers(int numbers[])
{
    int num, i = 0;
    char line[11];
    for (i = 0; i < MAX_LENGTH; i++) {
        numbers[i] = 0;
    }

    i = 0;

    while (fgets(line, 1000, stdin) && i < MAX_LENGTH) {
        num = calcSeatID(line);
        numbers[i] = num;
        i++;
    }
}

int checkForNumber(int numbers[], int num, int length)
{
    int i = 0;

    while (i < length) {
        if (numbers[i] == num) {
            return 1;
        }
        i++;
    }

    return 0;
}