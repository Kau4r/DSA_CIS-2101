#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef enum { false, true } Bool;
typedef struct {
    int in;
    char by[24];
} pub_t;

typedef struct {
    char title[24];
    char author[24];
    char genre[24];
    unsigned short pages;
} desc_t;

typedef struct {
    unsigned ID;
    desc_t desc;
    double price;
    pub_t published;
} Book_t;

typedef struct node{
    Book_t book;
    struct node *link;
}*Node_p,Node;

typedef struct{
Node_p front;
Node_p rear;
}Queue;

void initQueue(Queue *);
void enQueue(Queue *, char);
void deQueue(Queue *);
void showQueue(Queue);
Bool isFull(Queue) ;
Bool isEmpty(Queue) ;

