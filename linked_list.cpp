#include <stdio.h>
#include <stdlib.h>

//This is a simple linked list program that has a menu of 10 options that the user can choose.

struct node{
    int data;
    struct node *link;
};

struct node *first = NULL;
struct node *last = NULL;

// function prototypes
void fadd(int data);
void fshow();
void fsearch(int input);
void freverse();
void fdelete(int node);
void fadd_first(int input);
void fswap(int node1,int node2);
void fsort();
void fshift(int input);

int main(){
    int n,input,node1,node2;
    while(1){
        printf("1.Add new information\n2.Show the list.\n3.Search in the list.\n");
        printf("4.reverse the list.\n5.Delete a node.\n6.Add to first\n");
        printf("7.Swap two nodes.\n8.Sort the list.\n9.Shift the list to the right.\n10.Exit.\n");
        scanf("%d",&n);
        if(n==10){
            printf("Thank you for using this program.\n");
            break;
        }
        switch(n){
            case 1: {
                printf("Enter your data:\n");
                scanf("%d",&input);
                fadd(input);
                break;
            }
            case 2: fshow(); break;
            case 3: {
                printf("Enter your data:\n");
                scanf("%d",&input);
                fsearch(input);
                break;
            }
            case 4: freverse(); break;
            case 5: {
                printf("Which node you want to delete?\n");
                scanf("%d",&input);
                fdelete(input);
                break;
            }
            case 6:{
                printf("Enter your data:\n");
                scanf("%d",&input);
                fadd_first(input);
                break;
            }
            case 7:{
                printf("Enter the number of the first node:\n");
                scanf("%d",&node1);
                printf("Enter the number of the second node:\n");
                scanf("%d",&node2);
                fswap(node1,node2);
                break;
            }
            case 8: fsort(); break;
            case 9: {
                printf("How many nodes do you want to shift;\n");
                scanf("%d",&input);
                fshift(input); 
                break;
                }
        }
    }
}

void fadd(int data){
    struct node *temp;
    temp = (struct node *) malloc (sizeof(struct node));
    temp -> data = data;
    temp->link= NULL;
    if(!first){
        first = temp;
        last = temp;
    }
    else{
        last -> link = temp;
        last = temp;
    }
}

void fshow(){
    struct node *temp = first;
    printf("[First] -> ");
    for(;temp; temp = temp->link){
        printf("[%d] -> ",temp->data);
    }
    printf(" [End]\n");
}

void fsearch(int input){
    struct node *temp = first;
    int yes = 0;
    for( ; temp ; temp = temp->link){
        if(temp->data == input){
            printf("Yes. The input number is present in the list.\n");
            yes = 1;
        }
    }
    if(yes == 0){
        printf("No. The input number isn't present in the list.\n");
    }
}

void freverse(){
    struct node *current = first;
    struct node *prev = NULL;
    struct node *next = NULL;

    while(current){
        next = current -> link;
        current -> link = prev;
        current = next;
        prev = current;
    }

    first = prev;
}

void fdelete(int node){
    struct node *current = first;
    struct node *next = NULL;
    struct node *prev = NULL;
    int i = 1;
    while(current){
        next = current -> link;
        if(node == 1){
            first = next;
        }
        if(i != node){
            i++;
        }
        else if(i == node){
            prev -> link = next;
            break;
        }
        prev = current;
        current = next;
    }
}

void fadd_first(int input){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp -> data = input;
    temp -> link = first;
    first = temp;
}

void fswap(int node1,int node2){
    struct node *temp1=first,*temp2=first;
    int tempint;
    for(int i = 1 ; temp1 ; temp1 = temp1->link){
        if(i == node1){
            break;
        }
        else{
            i++;
        }
    }
    for(int j = 1 ; temp2 ; temp2 = temp2 -> link){
        if(j == node2){
            break;
        }
        else{
            j++;
        }
    }
    tempint = temp1->data;
    temp1->data = temp2->data;
    temp2->data = tempint;
}

void fsort(){
    struct node *current = first;
    struct node *next = NULL;
    int tempint;
    for( ; current ; current = current -> link){
        next = current -> link;
        while(next){
            if(current -> data > next -> data){
            tempint = current -> data;
            current -> data = next -> data;
            next -> data = tempint;
            }
            next = next -> link;
        }
    }
}

void fshift(int input){
    struct node *temp = first;
    struct node *prev = NULL;
    int length = 0;
    for(;temp ; temp = temp -> link){
        length++;
    }
    temp = first;
    last -> link = first;
    for( int i = 0 ; i < length - input ; ){
        prev = temp;
        temp = temp -> link;
        i++;
    }
    first = temp;
    prev -> link = NULL;
    last = prev;
}
