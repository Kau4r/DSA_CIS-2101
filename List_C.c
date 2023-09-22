#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    char data;
    int link;
} nodeType;

typedef struct{
    nodeType Nodes[MAX];
    int Avail;
} VirtualHeap;

typedef int Clist;

void initVheap(VirtualHeap *);
void displayVH(VirtualHeap);
void displayList(Clist, VirtualHeap);
void insertFirst(char, VirtualHeap*, Clist*);
void deallocSpace(Clist,VirtualHeap*);
int allocSpace(VirtualHeap*);
void deleteFirstOcc(char,VirtualHeap*,Clist*);

int main(){
    VirtualHeap Carlo;
    Clist list = -1;
    initVheap(&Carlo);
    displayVH(Carlo);
    insertFirst('C', &Carlo, &list);
    displayList(list,Carlo);
    insertFirst('B', &Carlo, &list);
    displayList(list,Carlo);
    insertFirst('A', &Carlo, &list);
    displayList(list,Carlo);

    displayVH(Carlo);

    deleteFirstOcc('A',&Carlo,&list);
    displayList(list,Carlo);
    deleteFirstOcc('B',&Carlo,&list);
    displayList(list,Carlo);    
    deleteFirstOcc('C',&Carlo,&list);
    displayList(list,Carlo);

    displayVH(Carlo);
}

int allocSpace(VirtualHeap *A){
    int ndx = A->Avail;
    if (ndx != -1){
        A->Avail = A->Nodes[ndx].link;
    }
    return ndx;
}

void initVheap(VirtualHeap *ptr){
    ptr->Avail = MAX - 1;
    int x;
    for (x = 0; x < MAX; x++){
        ptr->Nodes[x].link = x - 1;
    }
}

void displayVH(VirtualHeap ptr){
    int x;
    printf("\n\nIndex\tData\tLink\n");
    for (x = 0; x < MAX; x++){
        printf("%3d\t%3c\t%d\n", x, ptr.Nodes[x].data, ptr.Nodes[x].link);
    }
    printf("\n\tAvail\n\t%3d", ptr.Avail);
}

void displayList(Clist L, VirtualHeap VH){
    Clist trav;
    printf("\n\nData Set\n\n");

    for (trav = L; trav != -1; trav = VH.Nodes[trav].link){
        printf("Data: %c\n", VH.Nodes[trav].data);
    }
}

void insertFirst(char new, VirtualHeap *ptr, Clist *head){
    Clist newNode=allocSpace(ptr);
    if(newNode!=-1){
        ptr->Nodes[newNode].link=*head;
        ptr->Nodes[newNode].data=new;
        *head=newNode;
    }
}

void deleteFirstOcc(char del,VirtualHeap *B,Clist *he){
    Clist * trav,temp;
    for(trav=he;*trav!=-1 && B->Nodes[*trav].data!=del;trav=&(B->Nodes[*trav].link)){}
    if (*trav != -1 ){
        temp=*trav;
        *trav=B->Nodes[temp].link;
        deallocSpace(temp,B);
    }
}

void deallocSpace(Clist ndx,VirtualHeap *del){
    if(ndx < MAX && ndx>= 0){
        del->Nodes[ndx].link= del->Avail;
        del->Avail=ndx;
    }
}