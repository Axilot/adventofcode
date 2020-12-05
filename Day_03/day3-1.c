#include <stdio.h>

#define LINE_LENGTH 31
#define MAX_LINES 323

void saveMap(char map[]);
int calcXPos(int max, int num, int inc);
int getTrees(char map[], int offset_x, int offset_y);

int main() {
    char map[LINE_LENGTH * MAX_LINES];
    int numberOfTrees;
    numberOfTrees = getTrees(map, 3, 1);
    printf("Number of trees: %d\n", numberOfTrees);
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