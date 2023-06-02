#include <stdio.h>

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