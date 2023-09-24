#include <stdio.h>
#include <stdlib.h>

// typedef struct {
//    int ID;
//    char  LN[16], FN[24], MI;  //Lastname, Firstname, Middle Initial
//    char course[8];          
//    int yearLevel;
// }Studrec;

typedef struct node {
    char elem;
    struct node *link;
}*lList;   //Definition of the List

void push(char,lList*);
void pop(lList*);
void top(lList);
void showStack(lList);

int main(){
    lList Stack=NULL;
    push('a',&Stack);
    showStack(Stack);

    push('b',&Stack);
    showStack(Stack);

    push('c',&Stack);
    showStack(Stack);

    top(Stack);

    pop(&Stack);
    showStack(Stack);
    pop(&Stack);
    showStack(Stack);
    pop(&Stack);
    showStack(Stack);
}

void push(char data,lList* top){
    lList new=(lList)malloc(sizeof(struct node));
    if(new!=NULL){
        new->elem=data;
        new->link=(*top);
        (*top)=new;
    }
}

void pop(lList* top){
    lList temp=NULL;
    temp=*top;
    *top=temp->link;
    free(temp);
}

void top(lList top){
    printf("\n\n Top Element is '%c'",top->elem);
}

void show(lList top){
    printf("\n\nStack:\n");
    for(;top!=NULL;top=top->link){
        printf("%c",top->elem);
        printf("\n");
    }

}
