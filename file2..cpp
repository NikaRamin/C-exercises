#include <stdio.h>

// a program to open a file and save the given string in a file.

int main(){
    char string[100];
    gets(string);
    int i = 0;
    FILE *fp;
    fp = fopen("E:\\test2.txt","w");
    while(string[i] != '\0'){
        putc(string[i],fp);
        i++;
    }
    fclose(fp);
    printf("DONE!\n");
    return 0;
}
