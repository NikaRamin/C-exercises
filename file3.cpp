#include <stdio.h>

int main(){
    FILE *fp;
    char tab = '\t', enter = '\n';
    fp = fopen("E:\\test3.txt","w");
    for(int i = 'a' ;i <= 'z'; i++){
        putc(i,fp);
        putc(tab,fp);
        fprintf(fp,"%d",i);
        putc(enter,fp);
    }
    for(int i = 'A' ;i <= 'Z'; i++){
        putc(i,fp);
        putc(tab,fp);
        fprintf(fp,"%d",i);
        putc(enter,fp);
    }
    fclose(fp);
    printf("DONE!\n");

    return 0;
}