#include <stdio.h>

#define MAX_LENGTH 50

int main()
{
    int min, max, tempcount, count, i;
    char c;
    char password[MAX_LENGTH];
    count = 0;

    while (scanf("%d-%d %c: %s\n", &min, &max, &c, password) != EOF) {
        tempcount = i = 0;

        while (password[i] != '\0') {
            if (password[i] == c) {
                tempcount++;
            }
            i++;
        }
        if (tempcount >= min && tempcount <= max) {
            count++;
        }
    }

    printf("Amount of valid passwords: %d\n", count);
    return 0;
}