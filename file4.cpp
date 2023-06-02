#include <stdio.h>

//A program to get the name of two files and add the info of first file to the second one.

void filejoin(FILE *fp1,FILE*fp2,char str1[20],char str2[20]);


int main(){
char str1[20],str2[20];
FILE *fp1,*fp2;
filejoin(fp1,fp2,str1,str2);
    return 0;
}

void filejoin(FILE *fp1,FILE*fp2,char str1[20],char str2[20]){
    printf("Enter the name of file number one:\n");
    gets(str1);
    printf("Enter the name of file number two:\n");
    gets(str2);
    fp1 = fopen(str1,"r");
    fp2 = fopen(str2,"a");
    char c;
    while(!feof(fp1)){
        c = getc(fp1);
        putc(c,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    printf("DONE!");
}
