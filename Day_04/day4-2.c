#include <stdio.h>
#include <string.h>
#include <ctype.h>

void saveData(char data[]);
int checkPassports(char data[]);
int isValid(char passport[]);
int isHex(char hex[]);
int isNineDigits(char id[]);

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
    /* decimal numbers: birth year, issue year, expiration year, height, hair color, eye color, passport id, country id */
    int byr, iyr, eyr, hgt, cid;

    /* string values: eye color, hair color, height */
    char ecl[20], hcl[20], height[10], pid[9];

    char checksum = 1;

    int test;

    if (strstr(passport, "byr:") != NULL) {
        sscanf(strstr(passport, "byr:") + 4, "%d", &byr); 
        if (byr >= 1920 && byr <= 2002) {
            checksum++;
        }
    }

    if (strstr(passport, "iyr:") != NULL) {
        sscanf(strstr(passport, "iyr:") + 4, "%d", &iyr); 
        if (iyr >= 2010 && iyr <= 2020) {
            checksum++;
        }
    }

    if (strstr(passport, "eyr:") != NULL) {
        sscanf(strstr(passport, "eyr:") + 4, "%d", &eyr); 
        if (eyr >= 2020 && eyr <= 2030) {
            checksum++;
        }
    }

    if (strstr(passport, "hgt:") != NULL) {
        sscanf(strstr(passport, "hgt:") + 4, "%d%s", &hgt, height); 
        if (strstr(height, "cm") && hgt >= 150 && hgt <= 193) {
            checksum++;
        }
        else if (strstr(height, "in") && hgt >= 59 && hgt <= 76) {
            checksum++;
        }
    }

    if (strstr(passport, "hcl:") != NULL) {
        sscanf(strstr(passport, "hcl:") + 4, "%s ", hcl); 
        if (isHex(hcl)) {
            checksum++;
        }
    }

    if (strstr(passport, "ecl:") != NULL) {
        sscanf(strstr(passport, "ecl:") + 4, "%s", ecl); 
        if (strcmp(ecl, "amb") == 0 || strcmp(ecl, "blu") == 0 || strcmp(ecl, "brn") == 0 || strcmp(ecl, "gry") == 0 || strcmp(ecl, "grn") == 0 || strcmp(ecl, "hzl") == 0 || strcmp(ecl, "oth") == 0) {
            checksum++;
        }
    }

    if (strstr(passport, "pid:") != NULL) {
        sscanf(strstr(passport, "pid:") + 4, "%s", pid); 
        if (isNineDigits(pid)) {
            checksum++;
        }
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

int isHex(char hex[]) {
    int i;
    if (hex[0] != '#') {
        return 0;
    }
    
    for (i = 1; hex[i] != '\0'; i++) {
        if (!isxdigit(hex[i])) {
            return 0;
        }
    }

    if (i != 7) {
        return 0;
    }

    return 1;
}

int isNineDigits(char id[]) {
    int i = 0;

    while (id[i] != '\0') {
        if (!(id[i] >= '0') && !(id[i] <= '9')) {
            return 0;
        }
        i++;
    }
    if (i != 9) {
        return 0;
    }
    return 1;
}