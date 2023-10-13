#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef enum { false, true } Bool;

typedef struct {
    unsigned ID;
    double price;
    struct {
        char title[24];
        char author[24];
        char genre[24];
        unsigned short pages;
    } desc;
    struct {
        int in;
        char by[24];
    } published;
} Book_t;

typedef struct {
    Book_t book[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *);
void enQueue(Queue *, Book_t);
void deQueue(Queue *);
void showQueue(Queue);
Bool isFull(Queue);
Bool isEmpty(Queue);

int main() {}

void initQueue(Queue *A) {
    A->front = 0;
    A->rear = -1;
}

void enQueue(Queue *B, Book_t newBook) {
    if (!isFull(*B)) {
        B->rear = (1 + B->rear) % MAX;
        B->book[B->rear]=newBook;
    }
}
void deQueue(Queue *C) {
    if (!isEmpty(*C)) {
        C->front = (1 + C->front) % MAX;
    }
}
void showQueue(Queue D) {
    if (!isEmpty(D)) {
        int x;
        for (x = D.front; x != (D.rear + 1) % MAX;x=(D.front + 1) % MAX){
            pritnf("\n%d",x);
        }
    }
}

Bool isFull(Queue F) { return ((F.rear + 2) % MAX) == F.front; }
Bool isEmpty(Queue G) { return ((G.rear + 1) % MAX) == G.front; }