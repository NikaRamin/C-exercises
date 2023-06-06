#include <stdio.h>
#include <string.h>

// A program that stores the information of students in a file. When adding new inforamtion, it checks if the student number has been used before.
// It also searches for a student number in the file.

// function prototypes
void fadd(FILE *fp,struct node s1);
void fsearch(FILE *fp,struct node s1);


struct node{
    char name[20];
    char number[15];
    char subject[20];

};

int main(){
    int n;
    struct node s1;
    FILE *fp;
    while(1){
        printf("1.Add a new student's information.\n2.Search for a student number in the file.\n");
        printf("3.Exit.\n");
        scanf("%d",&n);
        if(n==3){
            printf("Thank you for using this program.\n");
            break;
        }
        switch(n){
            case 1: printf("Enter student's student number:\n"); fadd(fp,s1); break;
            case 2: printf("Enter student's student number:\n"); fsearch(fp,s1); break;
        }
    }
    return 0;
}


void fadd(FILE *fp,struct node s1){
    char ch;
    int i = 0 ,sum = 0;
    fp = fopen("students_info.text","a+");
    fflush(stdin);
    fgets(s1.number,15,stdin);
    rewind(fp);
    while(!feof(fp)){
        ch = fgetc(fp);
        if(ch >= '0' && ch <= '9'){
            if(ch == s1.number[i]){
                sum++;
                i++;
            }
            else{
                sum = 0;
                i = 0;
            }
            if(sum == 10){
                printf("This number exists. Enter another student number:\n");
                fgets(s1.number,15,stdin);
                rewind(fp);
            }
        }
    }
        printf("Enter student's name:\n");
        fgets(s1.name,20,stdin);
        fputs(s1.name,fp);
        fputs(" - ",fp);
        fputs(s1.number,fp);
        fputs(" - ",fp);
        printf("Enter student's subject in university:\n");
        fgets(s1.subject,20,stdin);
        fputs(s1.subject,fp);
        fputs("\n",fp);
        fclose(fp);

}

void fsearch(FILE *fp,struct node s1){
    char ch;
    int i = 0 ,sum = 0 ,tekrar = 0;
    fp = fopen("students_info.text","r+");
    fflush(stdin);
    fgets(s1.number,15,stdin);
    while(!feof(fp) && s1.number[i] != '\0'){
        ch = fgetc(fp);
        if(ch >= '0' && ch <= '9'){
            if(ch == s1.number[i]){
                sum++;
                i++;
            }
            else{
                sum = 0;
                i = 0;
            }
            if(sum == 10){
                printf("This number exists.\n");
                tekrar = 1;
                break;
                
            }
        }
    }
    if(tekrar == 0){
    printf("This number doesn't exist.\n");
    }
}
