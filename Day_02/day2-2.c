#include <stdio.h>

#define MAX_LENGTH 50

int main() {
    int posa, posb, count;
    char c;
    char password[MAX_LENGTH];
    count = 0;
    while (scanf("%d-%d %c: %s\n", &posa, &posb, &c, password) != EOF) {
        /* Check if password meets requirements: */

        if (password[posa-1] == c && password[posb-1] != c) {
            count++;
        }

        if (password[posb-1] == c && password[posa-1] != c) {
            count++;
        }
    }

    printf("Amount of valid passwords: %d\n", count);
    return 0;
}