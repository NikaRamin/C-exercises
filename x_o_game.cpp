#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    char board[3][3];
    int rand1,w=0,turn,n=0,i,j;
    srand(time(0));
    turn = rand() % 2;
    while(1){
        i = rand() % 3;
        j = rand() % 3;
        if(turn==0){
            if(board[i][j] != 'O' && board[i][j] != 'X'){
                board[i][j] = 'O';
                turn = 1;
                n++;
            }
        }
        if(turn == 1){
            if(board[i][j] != 'O' && board[i][j] != 'X'){
                board[i][j] = 'X';
                turn = 0;
                n++;
            }
        }
        if(n==9){
            break;
        }
    }

    for(i = 0 ; i < 3 ; i++){
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
        printf("X = O\n");
    }
    return 0;
}
