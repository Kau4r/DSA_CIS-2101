#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 8

typedef struct {
    char *Elem_p;
    int count;
} SET;

void insertElem(SET *, char);
void deleteElem(SET *, char);
bool isMember(SET, char);
SET setUnion(SET, SET);
SET setIntersection(SET, SET);
SET setDifference(SET, SET);
void display(SET);

int main() {
    SET X1 = {(char *)malloc(sizeof(char) * MAX), 0};
    insertElem(&X1, 'B');
    insertElem(&X1, 'A');
    insertElem(&X1, 'D');
    insertElem(&X1, 'E');
    insertElem(&X1, 'G');
    insertElem(&X1, 'I');
    insertElem(&X1, 'H');
    insertElem(&X1, 'F');
    display(X1);
}

void insertElem(SET *A, char Elem) {
    int x, y;
    for (x = 0; x < A->count && Elem > A->Elem_p[x]; x++) {
    }
    if (Elem != A->Elem_p[x]) {
        for (y = A->count; y > x; y--) {
            A->Elem_p[y] = A->Elem_p[y - 1];
        }
        A->Elem_p[x] = Elem;
        A->count++;
    }
}

void deleteElem(SET *A, char Elem) {
    int x;
    for (x = 0; x < A->count; x++) {
        if (Elem <= A->Elem_p[x]) {
            A->Elem_p[x] = A->Elem_p[x + 1];
        }
    }
    A->count--;
}

bool isMember(SET A, char Elem) {
    int x;
    for (x = 0; x < A.count && A.Elem_p[x] != Elem; x++) {
    }
    return x < A.count;
}

SET setUnion(SET A, SET B) {
    int x = 0, y = 0;
    SET C = {(char *)malloc(sizeof(char) * (A.count + B.count)), 0};
    while (x < A.count && y < B.count) {
        if (A.Elem_p[x] <= B.Elem_p[y]) {
            if (A.Elem_p[x] == B.Elem_p[y]) {
                y++;
            }
            C.Elem_p[C.count] = A.Elem_p[x];
            x++;
        } else {
            C.Elem_p[C.count] = B.Elem_p[y];
            y++;
        }
        C.count++;
    }

    if (x == A.count) {
        A = B;
        x = y;
    }

    while (x < A.count) {
        C.Elem_p[C.count] = A.Elem_p[x];
        x++;
        C.count++;
    }
    return C;
}

SET setIntersection(SET A, SET B) {
    int x = 0, y = 0, z = 0;
    SET C = {(char *)malloc(sizeof(char) * A.count), 0};
    while (x < A.count && y < B.count) {
        if (A.Elem_p[x] <= B.Elem_p[y]) {
            if (A.Elem_p[x] == B.Elem_p[y]) {

                C.Elem_p[z] = A.Elem_p[x];
                C.count = ++z;
                y++;
            }
            x++;
        } else {
            y++;
        }
    }

    return C;
}

SET setDifference(SET A, SET B) {
    int x = 0, y = 0, z = 0;
    SET C = {(char *)malloc(sizeof(char) * A.count), 0};
    while (x < A.count) {
        if (A.Elem_p[x] < B.Elem_p[y]) {
            C.Elem_p[z] = A.Elem_p[x];
            C.count = ++z;
            x++;
        } else {
            if (A.Elem_p[x] == B.Elem_p[y]) {
                x++;
            }
            y++;
        }
    }
    return C;
}

void display(SET A) {
    int x;
    printf("\nElements:\n");
    for (x = 0; x < A.count; x++) {
        printf("%c ", A.Elem_p[x]);
    }
    printf("\n");
}