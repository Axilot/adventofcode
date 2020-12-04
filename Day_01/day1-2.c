#include <stdio.h>

#define MAX_NUMBERS 1000 /* Sets a limit on how many numbers can actually be saved */
#define MAX_DIGITS 8 /* Sets a limit on how many digits can be stored in each number */

/* Save all numbers into array */
void saveNumbersFromFile(int numbers[]);

int main() {
    int numbers[MAX_NUMBERS];
    int i, n, z;
    for (i = 0; i < MAX_NUMBERS; i++) {
        numbers[i] = 0;
    }

    saveNumbersFromFile(numbers);

    for (i = 0; i < MAX_NUMBERS; i++) {
        for (n = 0; n < MAX_NUMBERS; n++) {
            for (z = 0; z < MAX_NUMBERS; z++) {
                if (numbers[i] + numbers[n] + numbers[z] == 2020 && numbers[i] != 0 && numbers[n] != 0 && numbers[z] != 0) {
                    printf("The searched number is: %d\n", numbers[i] * numbers[n] * numbers[z]);
                    goto finished;
                }
            }
        }
    }

    finished:
    return 0;
}

void saveNumbersFromFile(int numbers[]) {
    int currNumber[MAX_DIGITS]; /* Stores the current number in special format */
    int i, n, z, c;
    
    /* Set some initial values */
    i = z = n = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            int num, mult;

            num = 0;
            mult = 1;


            for (z = i-1; z >= 0; z--) {
                num += currNumber[z] * mult;
                mult *= 10;
            }

            numbers[n] = num;
            n++;

            for (i = MAX_DIGITS-1; i >= 0; i--) {
                currNumber[i] = 0;
            }

            i = 0;
        }
        else {
            if (c >= '0' && c <= '9') {
                currNumber[i] = c - '0';
                i++;
            }
        }
    }
}