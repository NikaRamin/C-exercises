#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This program takes three numbers, the first two are the range of the random number and the random number shouldn't be a multiple of the third number.

int func(int range1 , int range2 , int mazrab){
    srand(time(0));
    int n;
    while(1){
        n = rand();
        if(n>=range1 && n <= range2){
            if(n % mazrab != 0){
                return n;
            }
            else{
                continue;
            }
        }
        else{
            continue;
        }
    }
}

int main(){
    int range1, range2, mazrab,output;
    scanf("%d",&range1);
    scanf("%d",&range2);
    scanf("%d",&mazrab);
    output = func(range1,range2,mazrab);
    printf("%d",output);
    return 0;
}
