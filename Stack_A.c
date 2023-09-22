#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct{
    char elem[MAX];
    int top;
}aList;

aList bagolista();
void push(char,aList*);
void pop(aList*);
void top(aList);
void showStack(aList);

void isFull(aList);
 void isEmpty(aList);

int main(){
    aList L=bagolista();
    push('A',&L);
    showStack(L);
    push('B',&L);
    showStack(L);
    push('C',&L);
    showStack(L);
    
    top(L);

    pop(&L);
    showStack(L);
    pop(&L);
    showStack(L);
    pop(&L);
    showStack(L);
}

aList bagolista(){
    aList retlist={{},MAX};
    return retlist;
}

void push(char data ,aList* A){
    A->elem[--A->top]=data;
}

void pop(aList* B){
    ++B->top;
}

void top(aList C){
    printf("\n\nTopperware = '%c'",C.elem[C.top]);
}

void showStack(aList A){
    int i;
    printf("\n\nStack:\n");
    for(i=A.top;i<MAX;i++){
        printf("\n%c",A.elem[i]);
    }
}

void isFull(aList B){
    if(B.top==0){
        printf("List is Full!!");
    }else{
        printf("Not Full");
    }
}

void isEmpty(aList C){
    if(C.top==MAX){
        printf("List is Empty!!");
    }else{
        printf("SOMETHING INSIDE OF ME SNAPPED");
    }
}