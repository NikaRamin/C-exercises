#include <stdio.h>

int main(){
    char a[50],b[50];
    char j = 'a';
    int i = 0;
    for(i = 0 ; i < 50 && j <= 'z' ; i++ , j++){
        a[i] = j;
    }
    a[i] = '\n';
    j = 'A';
    for(i = 0; i < 50 && j <= 'Z'; i++ , j++){
        b[i] = j;
    }
    b[i] = '\n';
    FILE *fp;
    fp = fopen("E:\\test1.txt","w");
    i = 0;
    while(a[i] != '\0'){
        putc(a[i],fp);
        i++;
    }
    i=0;
    while(b[i] != '\0'){
        putc(b[i],fp);
        i++;
    }
    fclose(fp);
    printf("DONE!\n");
    return 0;
}