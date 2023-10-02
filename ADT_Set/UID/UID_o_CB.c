#include <stdbool.h>
#include <stdio.h>

#define MAX 8

typedef struct {
    char Elem;
    int nxt;
} Node;

typedef struct {
    Node nodes[MAX];
    int avail;
} VH;

typedef struct {
    VH vHeap;
    int head;
} SET;

void initVH(SET *);
int allocSpace(SET *);
void deallocSpace(SET *, int);
void insertElem(SET *, char);
void deleteElem(SET *, char);
bool isMember(SET, char);
SET setUnion(SET, SET);
SET setIntersection(SET, SET);
SET setDifference(SET, SET);
void displayElem(SET);

int main(void) {
    SET A, B, C;
    initVH(&A);
    initVH(&B);
    insertElem(&A, 'A');
    insertElem(&A, 'B');
    insertElem(&A, 'F');
    insertElem(&A, 'C');
    insertElem(&A, 'E');
    insertElem(&A, 'G');
    insertElem(&B, 'C');
    insertElem(&B, 'G');
    insertElem(&B, 'B');
    insertElem(&B, 'A');
    insertElem(&B, 'D');
    displayElem(A);
    displayElem(B);
    C = setDifference(A, B);
    displayElem(C);
}

void insertElem(SET *D, char Elem) {
    int newNode = allocSpace(D);
    if (newNode != -1) {
        int *trav;
        for (trav = &D->head; *trav != -1 && D->vHeap.nodes[*trav].Elem < Elem;
             trav = &D->vHeap.nodes[*trav].nxt) {
        }
        D->vHeap.nodes[newNode].nxt = *trav;
        D->vHeap.nodes[newNode].Elem = Elem;
        *trav = newNode;
    }
}

void deleteElem(SET *G, char Elem) {
    int *trav, temp;
    for (trav = &G->head; *trav != -1 && G->vHeap.nodes[*trav].Elem != Elem;
         trav = &G->vHeap.nodes[*trav].nxt) {
    }
    if (*trav != -1) {
        temp = *trav;
        *trav = G->vHeap.nodes[temp].nxt;
        deallocSpace(G, temp);
    }
}

bool isMember(SET E, char Elem) {
    for (; E.head != -1 && E.vHeap.nodes[E.head].Elem != Elem;
         E.head = E.vHeap.nodes[E.head].nxt) {
    }
    return E.head != -1;
}

SET setUnion(SET A, SET B) {
    SET C;
    initVH(&C);
    int *Cptr = &C.head;

    while (A.head != -1 && B.head != -1) {
        *Cptr = allocSpace(&C);
        if (*Cptr != -1) {
            if (A.vHeap.nodes[A.head].Elem <= B.vHeap.nodes[B.head].Elem) {
                if (A.vHeap.nodes[A.head].Elem == B.vHeap.nodes[B.head].Elem) {
                    B.head = B.vHeap.nodes[B.head].nxt;
                }
                C.vHeap.nodes[*Cptr].Elem = A.vHeap.nodes[A.head].Elem;
                A.head = A.vHeap.nodes[A.head].nxt;
            } else {
                C.vHeap.nodes[*Cptr].Elem = B.vHeap.nodes[B.head].Elem;
                B.head = B.vHeap.nodes[B.head].nxt;
            }

            Cptr = &C.vHeap.nodes[*Cptr].nxt;
        }
    }

    if (B.head != -1) {
        A.head = B.head;
    }
    while (A.head != -1) {
        *Cptr = allocSpace(&C);
        if (*Cptr != -1) {
            C.vHeap.nodes[*Cptr].Elem = A.vHeap.nodes[A.head].Elem;
            A.head = A.vHeap.nodes[A.head].nxt;
            Cptr = &C.vHeap.nodes[*Cptr].nxt;
        }
    }
    *Cptr = -1;
    return C;
}

SET setIntersection(SET A, SET B) {
    SET C;
    initVH(&C);
    int *Cptr = &C.head;

    while (A.head != -1 && B.head != -1) {
        if (A.vHeap.nodes[A.head].Elem <= B.vHeap.nodes[B.head].Elem) {
            if (A.vHeap.nodes[A.head].Elem == B.vHeap.nodes[B.head].Elem) {
                *Cptr = allocSpace(&C);
                if (*Cptr != -1) {
                    C.vHeap.nodes[*Cptr].Elem = A.vHeap.nodes[A.head].Elem;
                    Cptr = &C.vHeap.nodes[*Cptr].nxt;
                }
                B.head = B.vHeap.nodes[B.head].nxt;
            }
            A.head = A.vHeap.nodes[A.head].nxt;
        } else {
            B.head = B.vHeap.nodes[B.head].nxt;
        }
    }

    *Cptr = -1;
    return C;
}

SET setDifference(SET A, SET B) {
    SET C;
    initVH(&C);
    int *Cptr = &C.head;

    while (A.head != -1 && B.head != -1) {
        if (A.vHeap.nodes[A.head].Elem < B.vHeap.nodes[B.head].Elem) {
            *Cptr = allocSpace(&C);
            if (*Cptr != -1) {
                C.vHeap.nodes[*Cptr].Elem = A.vHeap.nodes[A.head].Elem;
                Cptr = &C.vHeap.nodes[*Cptr].nxt;
            }
            A.head = A.vHeap.nodes[A.head].nxt;
        } else {
            if (A.vHeap.nodes[A.head].Elem == B.vHeap.nodes[B.head].Elem) {
                A.head = A.vHeap.nodes[A.head].nxt;
            }
            B.head = B.vHeap.nodes[B.head].nxt;
        }
    }

    *Cptr = -1;
    return C;
}

void displayElem(SET E) {
    printf("\nElements:\n");
    for (; E.head != -1; E.head = E.vHeap.nodes[E.head].nxt) {
        printf("\n%c", E.vHeap.nodes[E.head].Elem);
    }
    printf("\n");
}

void initVH(SET *A) {
    int x;
    for (x = 0; x < MAX; x++) {
        A->vHeap.nodes[x].nxt = x - 1;
    }
    A->vHeap.avail = MAX - 1;
    A->head = -1;
}

int allocSpace(SET *B) {
    int ndx = B->vHeap.avail;
    if (ndx != -1) {
        B->vHeap.avail = B->vHeap.nodes[ndx].nxt;
    }
    return ndx;
}

void deallocSpace(SET *C, int newAvail) {
    if (newAvail >= 0 && newAvail < MAX) {
        C->vHeap.nodes[newAvail].nxt = C->vHeap.avail;
        C->vHeap.avail = newAvail;
    }
}
