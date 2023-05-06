#include <stdio.h>
#include <string.h>


/* This code gets the info of five movies, if the user presses 1, they information will be soretd in the alphabetical order of the name of the movies, 
if the user press 2, it will be sorted by the year of the movies, and if the user presses 3, the information will be printed from the highest imdb score to the lowest.
if the user presses 4, the program will end.*/


struct movies{
    char name[20];
    int year;
    float imdb;
};

// Function prototypes
void info(struct movies s1[5]);
void sort_by_name(struct movies s1[5] , struct movies s2);
void sort_by_year(struct movies s1[5] , struct movies s2);
void sort_by_score(struct movies s1[5] , struct movies s2);

int main(){
    struct movies s1[5];
    struct movies s2;
    int n;
    info(s1);
    printf("1.Sort by name.\n2.Sort by year.\n3.Sort by IMDB score.\n4.Exit\n");
    while(1){
        scanf("%d",&n);
        if(n == 4){
            printf("Thank you for using this program.");
            break;
        }
        else{
            switch(n){
                case 1: sort_by_name(s1,s2); break;
                case 2: sort_by_year(s1,s2); break;
                case 3: sort_by_score(s1,s2); break;
            }
        }
    }
    return 0;
}


void info(struct movies s1[5]){
    for(int i = 0 ; i < 5 ; i++){
        printf("Enter the name of movie number %d: ",i+1);
        fflush(stdin);
        fgets(s1[i].name , 20 , stdin);
        printf("Enter the year of movie number %d: ",i+1);
        scanf("%d",&s1[i].year);
        printf("Enter the IMDB score of movie number %d: ",i+1);
        scanf("%f",&s1[i].imdb);
    }
}


void sort_by_name(struct movies s1[5],struct movies s2){
    for(int i = 0 ; i < 5 ; i++){
        for(int j = i+1  ; j < 5 ; j++){
            if(strcmp(s1[i].name,s1[j].name)>0){
                s2 = s1[i];
                s1[i] = s1[j]; 
                s1[j] = s2;
            }
        }
    }
    printf("The list of the movies sorted by name:\n");
    for(int i = 0 ; i < 5 ; i++){
        printf("%d.%s",i+1,s1[i].name);
        printf("Year: %d\n",s1[i].year);
        printf("IMDB score: %g\n",s1[i].imdb);
    }
}

void sort_by_year(struct movies s1[5],struct movies s2){
    int temp;
     for(int i = 0 ; i < 5 ; i++){
        for(int j = i+1  ; j < 5 ; j++){
            if(s1[i].year > s1[j].year){
                s2 = s1[i];
                s1[i] = s1[j]; 
                s1[j] = s2;
            }
        }
    }
     printf("The list of the movies sorted by year: (oldest to the latest) \n");
    for(int i = 0 ; i < 5 ; i++){
        printf("%d.%s",i+1,s1[i].name);
        printf("Year: %d\n",s1[i].year);
        printf("IMDB score: %g\n",s1[i].imdb);
    }
}

void sort_by_score(struct movies s1[5],struct movies s2){
    float temp;
    for(int i = 0 ; i < 5 ; i++){
        for(int j = i+1  ; j < 5 ; j++){
            if(s1[i].imdb < s1[j].imdb){
                s2 = s1[i];
                s1[i] = s1[j]; 
                s1[j] = s2;
            }
        }
    }
    printf("The list of the movies sorted by IMDB score:\n");
     for(int i = 0 ; i < 5 ; i++){
        printf("%d.%s",i+1,s1[i].name);
        printf("Year: %d\n",s1[i].year);
        printf("IMDB score: %g\n",s1[i].imdb);
    }
}


