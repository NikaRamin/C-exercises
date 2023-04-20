#include <stdio.h>

//A program in C language to swap the first and the last word in a string

int main(){
    char str[100];
    char first[100];
    char last [100];
    char middle[100];
    int space = 0 ;
    gets(str);

    // the number of spaces
    for(int i = 0 ; str[i] != '\0' ; i++ ){
        if(str[i] == ' '){
            space++;
        }
    }

    //storing the first word in another array
    for(int i = 0 ; str[i] != ' ' ; i++){
        first[i]=str[i];
    }

    //storing the last word in another array
    for(int i = 0,j=0,count=0 ; str[i] != '\0'; i++){
        if(str[i]==' '){
            j++;
        }
        if(j==space){
            last[count]=str[i+1];
            count++;
        }
    }

    //storing the middle of the sentence in another array
    for(int i = 0,j = 0,count=0 ; str[i] != '\0';i++){
        if(str[i]==' '){
            j++;
        }
        if(j>=1 && j<space){
            middle[count]=str[i];
            count++;
        }
    }
    
    //printing all the arrays
    
    for(int i = 0 ; last[i]!= '\0' ; i++){
        printf("%c",last[i]);
    }
    
    for(int i = 0 ; middle[i]!= '\0' ; i++){
        printf("%c",middle[i]);
    }
    printf(" ");
    for(int i = 0 ; first[i]!= '\0' ; i++){
        printf("%c",first[i]);
    }

    return 0;
}
