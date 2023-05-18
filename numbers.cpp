#include <stdio.h>
#include <string.h>

// This program takes five phone numbers with names and 1.Sorts by the frequency of one number (highest to lowest) 2.Sorts by the number of non-repetitive numbers (lowest to highest)

struct info{
    char name[20];
    char num[11];
    int max = 0;
    int non_rep;
};

//function Prototype
void func1(struct info s1[5],struct info s2);
void func2(struct info s1[5],struct info s2);


int main(){
    int m;
    struct info s1[5],s2;
    

    for(int i = 0 ; i < 5 ; i++ ){
        printf("Enter phone number %d:\n",i+1);
        gets(s1[i].num);
        fflush(stdin);
        printf("Enter name %d:\n",i+1);
        gets(s1[i].name);
    }

    while(1){
        printf("1.Sort by the frequency of one number:(highest to lowest)\n");
        printf("2.Sort by the number of non-repetitive numbers: (lowest to highest)\n3.Exit\n");
        scanf("%d",&m);
        if(m == 3){
            printf("Thank you for using my program.\n");
            break;
        }
        switch(m){
            case 1: func1(s1,s2); break;
            case 2: func2(s1,s2); break;
        }
    }
    
    return 0;
}


void func1(struct info s1[5],struct info s2){
    int m = 0;
    for(int k = 0 ; k < 5 ; k++){
        for(int i = 0 ; i < 11 ; i++){
            if(m > s1[k].max){
                s1[k].max = m ;
            }
            m = 0 ;
            for(int j = i + 1 ; j < 11 ; j++){
                if(s1[k].num[i] == s1[k].num[j]){
                    m++;
                }
            }
        }
    }

    for(int k = 0 ; k < 5 ; k++){
        for(int j = k + 1; j < 5  ; j++){
            if(s1[k].max < s1[j].max) {
                s2 = s1[k];
                s1[k] = s1[j];
                s1[j] = s2;
            }
        }
    }
    printf("Sorted by the frequency of one number:(highest to lowest)\n");
    for(int i = 0 ; i < 5 ; i++){
        printf("Name: %s\n",s1[i].name);
        printf("Number: %s\n",s1[i].num);
    }
}

    void func2(struct info s1[5],struct info s2){
        int h = 0 ; 
        for(int k = 0 ; k < 5 ; k++){
            for(int i = 0 ; i < 11 ; i++){
                h = 0;
                for(int j =  i + 1 ; j < 11 ; j++){
                    if(s1[k].num[i] == s1[k].num[j]){
                        h++;
                    }
                }
                if(h == 0){
                    s1[k].non_rep = (s1[k].non_rep) + 1;
                }
            }
        }
        for(int i = 0 ; i < 5 ; i++){
            for(int j = i + 1 ; j < 5 ; j++){
                if(s1[i].non_rep > s1[j].non_rep){
                    s2 = s1[i];
                    s1[i] = s1[j];
                    s1[j] = s2;
                }
            }
        }
        printf("Sorted by the number of non-repetitive numbers: (lowest to highest)\n");
        for(int i = 0 ; i < 5 ; i++){
            printf("Name: %s\n",s1[i].name);
            printf("Number: %s\n",s1[i].num);
        }
    }
