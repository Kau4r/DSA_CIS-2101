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

typedef struct{
    Book_t book;
    int link;
} Node;

typedef struct{
    Node Nodes[MAX];
    int Avail;
} VirtualHeap;

typedef int List;

void initVheap(VirtualHeap *);
void insorted( VirtualHeap*, List*, Book_t);
void deleteAt(VirtualHeap*,List*,Book_t);
Book_t retrieve(VirtualHeap,List,unsigned);
Bool isEmpty(List);
void makeNull(VirtualHeap*,List*);
void displayList(VirtualHeap,List );
int allocSpace(VirtualHeap*);
void deallocSpace(VirtualHeap*,List);

int main(){
    VirtualHeap VH;
    List BookStore = -1;
}


void initVheap(VirtualHeap *);
void insorted( VirtualHeap*, List*, Book_t);
void deleteAt(VirtualHeap*,List*,Book_t);
Book_t retrieve(VirtualHeap,List,unsigned);
Bool isEmpty(List A){
    return A == -1;
}
void makeNull(VirtualHeap*,List*);
void displayList(VirtualHeap,List );
int allocSpace(VirtualHeap*);
void deallocSpace(VirtualHeap*,List);