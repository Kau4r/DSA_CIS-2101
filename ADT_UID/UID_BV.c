#include <stdbool.h>
#include <stdio.h>

#define MAX 8

typedef char SET[MAX];

void insertElem(SET, char);
void deleteElem(SET, char);
bool isMember(SET, char);
SET *setUnion(SET, SET);
SET *setIntersection(SET, SET);
SET *setDifference(SET, SET);
void display(SET);

int main(void) {
    SET A={0},B={0},*C;
    insertElem(A, 4);
    insertElem(A, 1);
    insertElem(A, 7);
    insertElem(A, 3);

    insertElem(B, 4);
    insertElem(B, 6);
    insertElem(B, 5);
    insertElem(B, 3);

    display(A);
    display(B);

    C=setIntersection(A,B);
    display(*C);

}

void insertElem(SET A, char ndx) {
    if (ndx < MAX) {
        A[ndx] = 1;
    }
}

void deleteElem(SET B, char ndx) {
    if (ndx < MAX) {
        B[ndx] = 0;
    }
}

bool isMember(SET C, char ndx) { return C[ndx] == 1; }

SET *setUnion(SET A, SET B) {
    SET *C = (SET *)calloc(sizeof(SET),1);
    int x;
    for (x = 0; x < MAX; x++) {
        (*C)[x] = A[x] | B[x];
    }
    return C;
}

SET *setIntersection(SET A, SET B) {
    SET *C = (SET *)calloc(sizeof(SET),1);
    int x;
    for (x = 0; x < MAX; x++) {
        (*C)[x] = A[x] & B[x];
    }
    return C;
}

SET *setDifference(SET A, SET B) {
    SET *C = (SET *)calloc(sizeof(SET),1);
    int x;
    for (x = 0; x < MAX; x++) {
        (*C)[x] = A[x] & ~B[x];
    }
    return C;
}

void display(SET A) {
    int x;
    for (x = 0; x < MAX; x++) {
        if (A[x] == 1) {
            printf("%d", x);
        }
    }
    printf("\n");
}
