#include <stdio.h>
#include <stdlib.h>

//This is a simple program for understanding dynamic arrays.

int main(){
    int *ptr;
    int size;
    printf("Enter the size of elements:\n");
    scanf("%d",&size);
    
    ptr = (int *) malloc(size * sizeof(int));
    //ptr = (int *) calloc(size , sizeof(int));
    // calloc gives all the element of the array a default value of 0.
    
    if(ptr == NULL){
        printf("Memory not allocated.\n");
    }
    else{
        for(int i = 0; i < size ; i++){
            ptr[i] = (i*10)+9;
        }
        printf("The elements of the array are:\n");
        for(int i = 0 ; i< size ;i++){
            printf("%d\t",ptr[i]);
        }
    }
    return 0;
}
