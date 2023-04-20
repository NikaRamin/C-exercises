#include <stdio.h>
#include <string.h>

int main(){

    char str1[100],str2[100],str3[100];
    int len1 = 0 ,len2 = 0 , len3 = 0;
    int count = 0 ;
    char temp;
    int freq = 0;
    
    memset(str3,0,sizeof(str3));

    gets(str1);
    gets(str2);

    while(str1[len1] != '\0'){
        len1++;
    }
    while(str2[len2] != '\0'){
        len2++;
    }

    for(int i = 0 ; i < len1 ; i++){
        for(int j = 0 ; j < len2 ; j++){
            if(str1[i]==str2[j] && str1[i] != ' '){
                for(int k = 0 ; k < count ; k++){
                    if(str3[k]==str1[i]){
                        freq = 1 ;  
                        break;
                    }
                }
                if(freq == 0){
                    str3[count] = str1[i];
                    count++;
                }
            }
            freq = 0;
        }
    }

    while(str3[len3] != '\0'){
        len3++;
    }

    for(int i = 0 ; i < len3 ; i++ ){
        for(int j = i + 1 ; j < len3 ; j++){
            if(str3[i] > str3[j]){
                temp = str3[i];
                str3[i] = str3[j];
                str3[j] = temp;
            }
        }
    }

    int underline;
    underline = len3;
    
    for(int i = 0 ; i < len3 ; i++){
        printf("%c",str3[i]);
        if(underline > 1){
            printf(" - ");
            underline--;
        }
    }

    return 0;
}

