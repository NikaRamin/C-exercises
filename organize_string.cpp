#include <stdio.h>

int main(){
    char string[50];
    char temp;
    scanf("%s",string);
    for(int i = 0 ; string[i] != '\0' ; i++){
        for(int j = i + 1 ; string[j] != '\0' ; j++){
            if(string[i] > string[j]){
               temp = string[i] ;
               string[i] = string[j];
               string[j] = temp ; 
            }
        }
    }
    printf("%s",string);
}