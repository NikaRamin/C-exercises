#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//This program plays a random X O game, then shows the board and the winner.

int main(){
    char board[3][3];
    int rand1,w=0;
    srand(time(0));
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            rand1 = rand() % 2 ;
            switch(rand1){
                case 0 : board[i][j] = 'O'; break;
                case 1 : board[i][j] = 'X' ; break;
            }
        }
    }
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            printf("%c  ",board[i][j]);
        }
        printf("\n");
    }
        if(w == 0){
            for(int i = 0 ; i < 3 ; i++){
                int m = 0;
                int n = 0;
                if(w==1){
                    break;
                }
                for(int j = 0 ; j < 3 ; j++){
                    if(board[i][j]=='O'){
                        m++;
                    }
                    else if(board[i][j]=='X'){
                        n++;
                    }
                    if(m == 3 && n != 3 ){
                        printf("O wins.\n");
                        w = 1;
                        break;
                    }
                    if(n == 3 && m != 3 ){
                        printf("X wins.\n");
                        w = 1;
                        break;
                    }
                    if(m==3 && n==3){
                        w = 0;
                    }
                }
            }
        }
    if(w == 0){
        for(int j = 0 ; j < 3 ; j++){
            int m = 0;
            int n = 0;
            if(w==1){
                    break;
            }
            for(int i = 0 ; i < 3 ; i++){
                if(board[i][j]== 'O'){
                    m++;
                }
                if(board[i][j]== 'X'){
                    n++;
                }
                if(m==3 && n != 3){
                    if(w==0){
                        printf("O wins.\n");
                        w = 1;
                        break;
                    }
                }
                if(n==3 && m != 3 ){
                    if(w==0){
                        printf("X wins.\n");
                        w = 1;
                        break;
                    }
                }
                if(n == 3 && m == 3){
                    w = 0;
                    break;
                }
            }
        }
    }
    if(w==0){
        for(int i = 0 ; i < 3 ; i++){
            int m = 0;
            int n = 0;
            if(w==1){
                    break;
            }
            if(board[i][i]=='O'){
                m++; 
            }
            else if(board[i][i]=='X'){
                n++;
            }
            if(m == 3 && n !=3){
                if(w==0){
                    printf("O wins.\n");
                    w = 1;
                    break;
                }
            }
            if(n == 3 && m != 3){
                if(w==0){
                    printf("X wins.\n");
                    w = 1;
                    break;
                }
            }
        }
    }
    if(w==0){
        for(int i = 0 ; i < 3 ; i++){
            int m = 0; 
            int n = 0;
            if(w==1){
                    break;
            }
            for(int j = 2 ; j <=0 ; j--){
                if(board[i][j]=='O'){
                    m++;
                }
                if(board[i][j]=='X'){
                    n++;
                }
                if(n==3){
                    if(w==0){
                        printf("X wins.\n");
                        w = 1; 
                        break;
                    }
                }
                if(m==3){
                    if(w==0){
                        printf("O wins.\n");
                        w = 1;
                        break;
                    }
                }
            }
        }
    }
    if(w == 0){
        printf("X = O");
    }
    return 0;
}
