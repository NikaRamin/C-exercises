#include <stdio.h>

//A program in C language to multiply the two given matrices

int main(){
    int m,n,p;
    printf("m = ");
    scanf("%d",&m);
    printf("n = ");
    scanf("%d",&n);
    printf("p = ");
    scanf("%d",&p);
    int A[m][n];
    int B[n][p];


    // Scanning the information of the first matrice
    printf("A :\n");
    for(int i = 0 ; i<m ; i++){
        for(int j = 0; j<n ; j++){
            printf("%d,%d = ",i+1,j+1);
            scanf("%d",&A[i][j]);
        }
    }

    // scanning the information of the second matrice
    printf("B :\n");
    for(int i = 0 ; i<n ; i++){
        for(int j = 0; j<p ; j++){
            printf("%d,%d = ",i+1,j+1);
            scanf("%d",&B[i][j]);
        }
    }

    int C[m][p];
    int sum = 0;

    // multiplying two matrices and storing it in a third matrice
   for(int i = 0 ; i < m ; i++){
    for(int j = 0 ; j < p ; j++){
        sum = 0 ; 
        for(int k = 0 ; k < n ; k++){
            sum += A[i][k]*B[k][j];
        }
        C[i][j] = sum ; 
    }
   }

    // Printing the information of the third matrice
    printf("A×B :\n");
    for(int k = 0; k < m ; k++){
            for(int h = 0 ; h < p ; h++){
               printf("%d,%d = ",k+1,h+1);
               printf("%d\n",C[k][h]);
            }
        }
    
    return 0;
}
