#include <stdio.h>
#include <stdlib.h>

#define MAX 10
typedef struct{
    char elem;
    int link;
} Nodes;

typedef struct{
    Nodes Node[MAX];
    int Avail;
} VH;

typedef int List;

VH initVHeap(void);
void showVH(VH);
int allocspc(VH*);
void push(VH*,List*,char );
void deallocspc(List*,VH*);

int main(){
    VH heap = initVHeap();
    List head=-1;
    push(&heap,&head,'A');
    push(&heap,&head,'A');
    push(&heap,&head,'A');
    push(&heap,&head,'A');
    push(&heap,&head,'A');

    showVH(heap);
}

void push(VH* T,List *R,char datum){
    List newNode=allocspc(T);
    if(newNode!=1){
        T->Node[newNode].elem=datum;
        T->Node[newNode].link=*R;
        *R=newNode;
    }
}

int allocspc(VH *Q){
    List new=Q->Avail;
    if(new!=-1){
        Q->Avail=Q->Node[new].link;
    }
    return new;
}

VH initVHeap(void){
    VH new;
    new.Avail=MAX-1;
    int x;
    for (x = 0; x < MAX; x++){
        new.Node[x].link = x-1;
        new.Node[x].elem = 'X';
    }
    return new;
}

void showVH(VH sh){
    int x;
    printf("\n\nIndex\tData\tLink\n");
    for (x = 0; x < MAX; x++){
        printf("%3d\t%3c\t%d\n", x, sh.Node[x].elem, sh.Node[x].link);
    }
    printf("\n\tAvail\n\t%3d\n\n", sh.Avail);
}

void deallocspc(List* front,VH* vHeap){
    if(front >= 0 && front < MAX){
        vHeap->Node[*front].link=vHeap->Avail;
        vHeap->Avail=*front;
    }
}
