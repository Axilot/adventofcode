#include <stdio.h>
#include <string.h>

void saveData(char data[]);
int checkPassports(char data[]);
int isValid(char passport[]);

int main()
{
    /* Stores our input file */
    char input[30000];
    int validPasswords;

    saveData(input);
    validPasswords = checkPassports(input);
    printf("Valid passwords: %d\n", validPasswords);

    return 0;
}

void saveData(char data[])
{
    int i;
    char c, isNewline;
    isNewline = 0;

    for (i = 0; (c = getchar()) != EOF; i++) {
        data[i] = c;
    }
    data[i] = '\0';

    for (i = 0; data[i] != EOF; i++) {
        if (data[i] == '\n' && data[i+1] != '\n') {
            data[i] = ' ';
        }
    }
}

int checkPassports(char data[])
{
    int i = 0, n = 0, count = 0;
    char line[1000];

    while (data[i] != '\0') {
        line[n] = data[i];
        if (line[n] == '\n') {
            line[n] = '\0';
            if (isValid(line)) {
                count++;
            }
            while (n != 0) {
                line[n] = 0;
                n--;
            }
        }
        
        i++;
        n++;
    }
    if (isValid(line)) {
        count++;
    }
    return count;
}

int isValid(char passport[])
{
    /* birth year, issue year, expiration year, height, hair color, eye color, passport id, country id */
    int byr, iyr, eyr, hgt, pid, cid;

    char ecl[20], hcl[20];

    char checksum = 1;

    if (strstr(passport, "byr:") != NULL) {
        sscanf(strstr(passport, "byr:") + 4, "%d", &byr); 
        checksum++;
    }

    if (strstr(passport, "iyr:") != NULL) {
        sscanf(strstr(passport, "iyr:") + 4, "%d", &iyr); 
        checksum++;
    }

    if (strstr(passport, "eyr:") != NULL) {
        sscanf(strstr(passport, "eyr:") + 4, "%d", &eyr); 
        checksum++;
    }

    if (strstr(passport, "hgt:") != NULL) {
        sscanf(strstr(passport, "hgt:") + 4, "%d", &hgt); 
        checksum++;
    }

    if (strstr(passport, "hcl:") != NULL) {
        sscanf(strstr(passport, "hcl:") + 4, "%s ", hcl); 
        checksum++;
    }

    if (strstr(passport, "ecl:") != NULL) {
        sscanf(strstr(passport, "ecl:") + 4, "%s", ecl); 
        checksum++;
    }

    if (strstr(passport, "pid:") != NULL) {
        sscanf(strstr(passport, "pid:") + 4, "%d", &pid); 
        checksum++;
    }

    if (strstr(passport, "cid:") != NULL) {
        sscanf(strstr(passport, "cid:") + 4, "%d", &cid); 
        /* Not relevant */
    }

    /* Check if it passed all requirements */
    if (checksum == 8) {
        return 1;
    }
    return 0;
}
