#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

//NikaRamin_4011113024_project.cpp

// function prototypes:
void user_registration();
void settings();
void game();
void calculate_score();
void display_score();
void check_digits();
void display_best_scores();

struct user{
    int id;
    char username[20];
    char password[20];
};

int allscores[100],scorecount=0;

struct log{
    int id;
    float score;
    time_t startTime;
};

int last_id = 1, range ,rep;

void user_registration(){
    FILE *fp;
    struct user user_data;

    fp = fopen("users.txt","a+");

    if(fp == NULL){
        printf("Unable to open the file.\n");
        exit(1);
    }

    printf("Enter username:\n");
    fflush(stdin);
    fgets(user_data.username,20,stdin);
    fflush(stdin);
    printf("Enter password:\n");
    fgets(user_data.password,20,stdin);
    user_data.id = last_id;
    last_id++;

    fprintf(fp,"%d,",user_data.id);
    fputs(user_data.username,fp);
    fputs(",",fp);
    fputs(user_data.password,fp);

    printf("User Successfully registered.\n");

    fclose(fp);
}

void display_score(int score,char name[20]){
    printf("your score is: %d\n",score);
    allscores[scorecount] = score;
    scorecount++;
}

void calculate_score ( char name[20] , int time , int randomNumber , int m){
    /*
    For each second, -1 point.
    For each unique number, 5 points.
    */

    int point=0 , digit[m] , i = 0 ,repeat = 0;

    //printf("time:%d\n",time);

    // calculate point
    while (time > 0){
        point--;
        time--;
    }

    i = 0;
    while (randomNumber > 0){
        repeat = 0;
        digit[i] = randomNumber % 10 ;
        randomNumber = randomNumber / 10 ;
        for (int j = i + 1 ; j <= i ; j++){
            if(digit[j] == digit[i]){
                repeat = 1;
                break;
            }
        }
        if(repeat == 0){
            point += 5;
        }
        i++;
    }

    display_score(point,name);

    // Enter the ID,Score,time in log.txt:
    FILE *fp;
    int id;
    fp = fopen("log.txt","w+");
    printf("What is your ID?\n");
    scanf("%d",&id);
    fprintf(fp,"%d,",id);
    fputs(name,fp);
    fputs(",",fp);
    fprintf(fp,"%d",time);
    fclose(fp);

}

void check_digits(int randomNumber,int playerGuess,int m){

   int checkDigit[m] , i = m-1 , guessDigit[m] , j = m-1 ;

   //printf("m:%d\n",m);

   printf("Hints:\n");
   while (randomNumber > 0){
        checkDigit[i] = randomNumber % 10 ;
        randomNumber = randomNumber / 10 ;
        i--;
    }
    i = m - 1;
    while (playerGuess > 0){
        guessDigit[i] = playerGuess % 10 ;
        playerGuess = playerGuess / 10 ;
        i--;
    }
    for ( i = 0 ; i < m ; i++ ){
        if(checkDigit[i] == guessDigit[i]){
            printf("%d is in the right place.\n",checkDigit[i]);
        }
    }
    for ( i = 0 ; i < m ; i++){
        for( j = i + 1 ; j < m ; j++){
            if(checkDigit[i] == guessDigit[j]){
                printf("%d is present in the right answer.\n",guessDigit[j]);
            }
        }
    }
    printf("\n");
}

void display_best_scores(){
    int temp; 
    for(int i = 0 ; allscores[i] != '\0' ; i++){
        for(int j = i + 1 ; allscores[j] != '\0'; j++){
            if(allscores[i] < allscores [j]){
                temp = allscores[i];
                allscores[i] = allscores[j];
                allscores[j] = temp;
            }
        }
    }
    printf("All the scores (highest to lowest): \n");
    for(int i = 0 ; allscores[i] != '\0' ; i++ ){
        printf("%d\n",allscores[i]);
    }
}

void menu(){
    int choice = 0;
    while(1){
        printf("1.User Registration\n2.Game Settings\n3.Enter the Game\n4.Display Best Scores\n5.Exit\nChoose an option:\n");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            user_registration();
            break;
        case 2:
            settings();
            break;
        case 3:
            game();
            break;
        case 4:
            display_best_scores();
            break;
        case 5:
            printf("Thank you for playing this game.\n");
            exit(1);
            break;
        default:
            printf("\nPlease enter a valid choice.\n");
            break;
        }
    }
}

void settings(){
    FILE *fp;
    printf("Select the number of digits between 4 to 9:\n");
    while(1){
        scanf("%d",&range);
        if( range < 4 || range > 9){
            printf("Please enter a valid choice:\n");
        }
        else{
            break;
        }
    }
    printf("Do you want repetitive number or not?\n1.Yes\n2.No\n");
    while(1){
        scanf("%d",&rep);
        if(rep < 1 || rep > 2){
            printf("Please enter a valid choice:\n");
        }
        else{
            break;
        }
    }

    int stat;
    stat = remove("settings.txt");
    fp = fopen("settings.txt","w+");
    fputs("Number of the digits:",fp);
    fprintf(fp,"%d",range);
    fputs("\n",fp);
    if(rep == 1){
        fputs("repetitive? Yes!\n",fp);
    }
    else{
        fputs("repetitive? No!\n",fp);
    }
    fclose(fp);

    printf("Settings are Successfully set.\n");
}

void game(){

    srand(time(NULL));
    int randomNumber, playerGuess, roundsPlayed = 0;
    time_t startTime, endTime;
    int randomDigitCount,win=0;
    char name[20],password[20];


    // Entering with information:
    printf("What is your name?\n");
    fflush(stdin);
    fgets(name,20,stdin);
    printf("What is your password?\n");
    fgets(password,20,stdin);

    //checking if the password is correct:
    
    //Generating the number of digits and the random number:
    randomDigitCount = 4 + rand() % 6;
    randomNumber = (pow (10, randomDigitCount - 1) + ( rand() % (9 * (int)pow(10, randomDigitCount - 1))));

    printf("%d\n",randomNumber);

    // 12 rounds : 
    while (roundsPlayed < 12)
    { 
        printf("Guess the %d digit number: \n", randomDigitCount);
       
        startTime = time(NULL);

        scanf("%d", &playerGuess);

        endTime = time(NULL); 
        

        if (difftime(endTime , startTime) > randomDigitCount * 10){
            printf("You have exceeded the time limit. Game Over!\n");
            return;
        }

        else if(randomNumber == playerGuess) {
            printf("Congratulations! You guessed right.\n");
            calculate_score(name,int(difftime(endTime , startTime)),randomNumber,randomDigitCount);
            win = 1;
            break;
        }
        else{
            printf("Sorry, you guessed wrong. Try again next round.\n");
            win = 0;
            check_digits(randomNumber,playerGuess,randomDigitCount);
        }
        roundsPlayed++;
    }

    if(win == 0){
        printf("Game Over. You've played 12 rounds.\n");
    }
    
}

int main( ){
    menu();
    return 0;
}
