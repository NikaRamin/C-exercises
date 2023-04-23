#include <stdio.h>
#include <string.h>

/* The user gives the program a number such as n, then the user gives it n words with the
length of n, the program prints the first letters, then the second letters ...
*/ 

int n; 

int main(){
    scanf("%d",&n);
    char arr[n][n];
    char temp[n];
    int m = 0 ;

    //storing the info in a Two-dimensional array
    for(int i = 0 ; i < n ; i++){
        m = 0;
        scanf("%s",temp);
        for(int j = 0 ; j < n ; j++){
            arr[i][j] = temp[m];
            m++;
        }
    }
    
    // printing the array 
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            printf("%c",arr[j][i]);
        }
        printf("\n");
    }
    
    return 0;
}