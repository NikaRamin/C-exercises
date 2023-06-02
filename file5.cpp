#include <stdio.h>

//a program that takes the name of a file and prints the number of characters in a file.

void filenum(char str[20]){
    int m = 0;
    FILE *fp = fopen(str,"r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", str);
        return;
    }
    while(fgetc(fp) != EOF){
        m++;
    }
    fclose(fp);
    printf("The number of Characters: %d\n",m);
}

int main(){
    char str[20];
    printf("Enter file name:\n");
    scanf("%s",str);
    filenum(str);
    return 0;
}

