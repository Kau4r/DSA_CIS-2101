#include <stdio.h>
#include <stdbool.h>


#define MAX 10

typedef struct{
    char elem[MAX];
    int tail;
    int head;
} Queue;

void initQueue(Queue *);
void enQueue(Queue *, char);
void deQueue(Queue *);
void showQueue(Queue);

int main(){
    Queue T;
    initQueue(&T);
    enQueue(&T, 'A');
    enQueue(&T, 'B');
    enQueue(&T, 'C');
    enQueue(&T, 'D');

    showQueue(T);

    deQueue(&T);
    showQueue(T);

    deQueue(&T);
    deQueue(&T);

    showQueue(T);

    enQueue(&T, 'A');
    enQueue(&T, 'B');
    enQueue(&T, 'C');
    showQueue(T);
}

void initQueue(Queue *Q){
    Q->tail = 7;
    Q->head = 8;
}

bool isFull(Queue T){
    return (T.tail + 2) % MAX == T.head;
}

bool isEmpty(Queue Y){
    return (Y.tail + 1) % MAX == Y.head;
}

void enQueue(Queue *W, char new){
    if (!isFull(*W)){
        W->tail = (W->tail + 1) % MAX;
        W->elem[W->tail] = new;
    }
}

void deQueue(Queue *E){
    if (!isEmpty(*E)){
        E->head = (E->head + 1) % MAX;
    }
}

void showQueue(Queue R){
    int x;
    printf("\n\nQueue: ");
    for (x = R.head; x != (R.tail+1) % MAX; x = (x + 1) % MAX){
        printf("\n%c%d", R.elem[x], x);
    }
    printf("\n\n");

}
