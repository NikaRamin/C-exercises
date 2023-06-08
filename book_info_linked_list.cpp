#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A program that stores the information of books in a linked list. The menu has options of what to do with the stored information.

struct data{
        char name[20];
        int year;
};

struct node{
    struct data s1;
    struct node *link;
};



// function prototypes
struct node* fadd(struct node *first);
void fsort(struct node*first);
struct node* freverse(struct node*first);
void fshow(struct node *first);



int main(){
    struct node *first = NULL;
    int n;
    while(1){
        printf("1.Add a new book.\n2.Sort the books.\n3.Reverse the linked list.\n4.Show all of the information.\n5.Exit.\n");
        scanf("%d",&n);
        if(n==5){
            printf("Thank you for using this program.\n");
            break;
        }
        switch(n){
            case 1: first = fadd(first); break;
            case 2: fsort(first);break;
            case 3: first = freverse(first);break;
            case 4: fshow(first); break;
        }
    }



    return 0;
}

struct node* fadd(struct node *first){

    if(!first){
        first = (struct node *)malloc(sizeof(struct node));
        printf("Enter the name of the book:\n");
        fflush(stdin);
        fgets(first->s1.name,20,stdin);
        printf("Enter the year of the book:\n");
        scanf("%d",&first->s1.year);
        return first;
    }

    else{
        struct node *cf = first;
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter the name of the book:\n");
        fflush(stdin);
        fgets(temp->s1.name,20,stdin);
        printf("Enter the year of the book:\n");
        scanf("%d",&temp->s1.year);
        for(; cf->link ; cf = cf->link){
        
        }
        cf -> link = temp;
        return first;
    }
}

struct node* freverse(struct node*first){
    struct node *prev = NULL;
    struct node *next = NULL;
    struct node *current = first;

    while(current){
        next = current -> link;
        current -> link = prev;
        prev = current;
        current = next;
    }
    first = prev;
    return first;
}

void fshow(struct node *first){
    struct node *temp = first;
    for(; temp ; temp = temp->link){
        puts(temp->s1.name);
        printf("%d",temp->s1.year);
        printf("\n-------------\n");
    }
}

void fsort(struct node *first){
    struct node *temp = first;
    struct node *next;
    char ch[20],ch2[20];
    int cy;
    for( ; temp ; temp = temp -> link){
        next = temp -> link;
        for( ; next ; next = next -> link){
            if(strcmp(temp->s1.name,next->s1.name)>0){
                strcpy(ch,temp->s1.name);
                strcpy(ch2,next->s1.name);
                memset(temp->s1.name,NULL,20);
                memset(next->s1.name,NULL,20);
                strcpy(temp->s1.name,ch2);
                strcpy(next->s1.name,ch);
                cy = temp->s1.year;
                temp->s1.year = next->s1.year;
                next->s1.year = cy;
            }
            else if(strcmp(temp->s1.name,next->s1.name)==0){
                if(temp->s1.year < next->s1.year){
                    cy = temp->s1.year;
                    temp->s1.year = next->s1.year;
                    next->s1.year = cy;
                }
            }
        }
    }
}
