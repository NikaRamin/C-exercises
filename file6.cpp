
#include <stdio.h>

void ffile(char name[20]);

int main() {
    char name[20];
    ffile(name);
    return 0;
}

void ffile(char name[20]) {
    int line = 0;
    printf("Enter the file name:\n");
    scanf("%s", name);
    FILE *fp = fopen(name, "r");
    if (fp == NULL) {
        printf("Failed to open file: %s\n", name);
        return;
    }
    int c = fgetc(fp);
    while (c != EOF) {
        if (c == '\n') {
            line++;
        }
        c = fgetc(fp);
    }
    fclose(fp);
    printf("There are %d lines in this code", line);
}