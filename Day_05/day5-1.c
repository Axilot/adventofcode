#include <stdio.h>

#define MAX_LENGTH 1000

int calcSeatID(char seat[]);
int getHighestNumber(int numbers[]);
void saveNumbers(int numbers[]);

int main()
{
    int numbers[MAX_LENGTH];
    saveNumbers(numbers);

    printf("Highest seat id: %d\n", getHighestNumber(numbers));
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

    while (fgets(line, MAX_LENGTH, stdin) && i < MAX_LENGTH) {
        num = calcSeatID(line);
        numbers[i] = num;
        i++;
    }
}