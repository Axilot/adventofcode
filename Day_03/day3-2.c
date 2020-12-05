#include <stdio.h>

#define LINE_LENGTH 31
#define MAX_LINES 323

void saveMap(char map[]);
int calcXPos(int max, int num, int inc);
int getTrees(char map[], int offset_x, int offset_y);

int main() {
    char map[LINE_LENGTH * MAX_LINES];

    long sol1, sol2, sol3, sol4, sol5;

    sol1 = getTrees(map, 1, 1);
    sol2 = getTrees(map, 3, 1);
    sol3 = getTrees(map, 5, 1);
    sol4 = getTrees(map, 7, 1);
    sol5 = getTrees(map, 1, 2);

    printf("Sol 1: %3ld\nSol 2: %3ld\nSol 3: %3ld\nSol 4: %3ld\nSol 5: %3ld\nSolution: %ld\n", sol1, sol2, sol3, sol4, sol5, sol1 * sol2 * sol3 * sol4 * sol5);
    return 0;
}

int getTrees(char map[], int offset_x, int offset_y) {
    int x = offset_x, y = offset_y;
    int cords = (y * LINE_LENGTH) + x;
    int count = 0;

    saveMap(map);
    while(cords < LINE_LENGTH * MAX_LINES) {
        if (map[cords] == '#') {
            count++;
        }
        y += offset_y;
        x = calcXPos(LINE_LENGTH-1, x, offset_x);
        cords = (y * LINE_LENGTH) + x;
    }
    return count;
}

void saveMap(char map[]) {
    int i;
    char c;
    i = 0;

    while ((c = getchar()) != EOF) {

        if (c != '\n') {
            map[i] = c;
            i++;
        }
    }
    map[i] = '\0';
}

int calcXPos(int max, int num, int inc) {
    if (num + inc > max) {
        int val = max - inc;
        num -= val+1;
    }
    else {
        num += inc;
    }

    return num;
}