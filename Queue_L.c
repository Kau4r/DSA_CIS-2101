#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char elem;
    struct node *link;
}*lList; 

typedef struct{
    lList front;
    lList rear;
}Queue;

void Enqueue(Queue*,char);
void Dequeue(Queue*);
void Peek(Queue);
void showQ(Queue);

int main(){
    Queue A={NULL,NULL};
    Enqueue(&A,'a');
    showQ(A);
    Enqueue(&A,'b');
    showQ(A);
    Enqueue(&A,'c');
    showQ(A);
    
    Peek(A);

    showQ(A);
    Dequeue(&A);
    showQ(A);
    Dequeue(&A);
    showQ(A);
    Dequeue(&A);

}

void Enqueue(Queue* B,char data){
    lList newNode=(lList)malloc(sizeof(struct node));
    if(newNode!=NULL){
        newNode->elem=data;
        newNode->link=NULL;
      if(B->front ==NULL){
        B->front = newNode; 
      }else{
        B->rear->link=newNode;
      }      
        B->rear=newNode;
    }
}

void Dequeue(Queue* Q){
    lList del=NULL;
    if(Q->front!=NULL){
        del=Q->front;
        Q->front=del->link;
        free(del);
    }
}

void Peek(Queue O){
    printf("\n\n Front: %c ",O.front->elem);
}

void showQ(Queue H){
    lList trav=NULL;
    printf("\n\nBANANAQUEUE: ");
    for(trav= H.front;trav!=NULL;trav=trav->link){
        printf("%c",trav->elem);
        if(trav->link!=NULL){
            printf(",");
        }
    }
}
