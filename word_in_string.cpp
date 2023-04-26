#include <stdio.h>
#include <string.h>

// This program checks if a word is present in a string and prints the number of repetition

int main(){

    char str[250] , word[25];
    int m = 0 , counter = 0 , flag = 0;

    fgets(str , 250 , stdin);
    fgets(word , 25 , stdin);

    for(int i = 0 ; i < 250 ; i++){
            if(str[i] != ' '&& str[i]!='\0'){
                if(str[i] == word[m]){
                    flag = 1 ;
                    m++;
                    continue;
                }
                else{
                    m = 0;
                    flag = 0;
                }
            }
            else if(str[i] == ' '){
                if(flag == 1){
                    counter++;
                }
                m = 0;
                flag = 0;
            }
            else if(str[i]=='\0'){
                if(flag == 1){
                    counter++;
                }
                break;
            }
    }
   
   if(counter==0){
    printf("No\n");
    printf("%d",counter);
   }
   else{
    printf("Yes\n");
    printf("%d",counter);
   }

    return 0;
}

