#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char Elem;
    struct node *link;
} c_type, *SET;

void insertElem(SET *, char);
void deleteElem(SET *, char);
bool isMember(SET, char);
SET setUnion(SET, SET);
SET setIntersection(SET, SET);
SET setDifference(SET, SET);
void displayElem(SET);

int main() {
    SET A = NULL, B = NULL, C = NULL;
    int x;
    char stanlee[] = "FEDCBA";
    char carlo[] = "IHEB";

    for (x = 0; carlo[x] != '\0'; x++) {
        insertElem(&A, carlo[x]);
    }

    for (x = 0; stanlee[x] != '\0'; x++) {
        insertElem(&B, stanlee[x]);
    }

    displayElem(A);
    displayElem(B);

    C = setIntersection(A, B);

    displayElem(C);

    return 0;
}

void insertElem(SET *X, char Elem) {
    SET new = (SET)malloc(sizeof(struct node));
    if (new != NULL) {
        SET *trav;
        for (trav = X; *trav != NULL && (*trav)->Elem < Elem;
             trav = &(*trav)->link) {
        }
        new->Elem = Elem;
        new->link = (*trav);
        (*trav) = new;
    }
}

void deleteElem(SET *Y, char Elem) {
    SET *trav, temp;
    for (trav = Y; *trav != NULL && (*trav)->Elem != Elem;
         trav = &(*trav)->link) {
    }
    if (*trav != NULL) {
        temp = *trav;
        *trav = temp->link;
        free(temp);
    }
}

bool isMember(SET A, char Elem) {
    for (; A != NULL && A->Elem != Elem; A = A->link) {
    }
    return A != NULL;
}

SET setDifference(SET A, SET B) {
    SET C = NULL;
    SET *C_end = &C;

    while (A != NULL) {

        if (B == NULL || A->Elem < B->Elem) {
            *C_end = (SET)malloc(sizeof(c_type));
            if (C_end != NULL) {
                (*C_end)->Elem = A->Elem;
                C_end = &(*C_end)->link;
            }
            A = A->link;
        } else {
            if (A->Elem == B->Elem) {
                A = A->link;
            }
            B = B->link;
        }
    }

    *C_end = NULL;
    return C;
}

SET setUnion(SET A, SET B) {
    SET C = NULL;
    SET *C_end = &C;

    while (A != NULL && B != NULL) {
        *C_end = (SET)malloc(sizeof(c_type));
        if (C_end != NULL) {

            if (A->Elem <= B->Elem) {
                if (A->Elem == B->Elem) {
                    B = B->link;
                }
                (*C_end)->Elem = A->Elem;
                A = A->link;
            } else {
                (*C_end)->Elem = B->Elem;
                B = B->link;
            }
            C_end = &(*C_end)->link;
        }
    }

    if (B != NULL) {
        A = B->link;
    }

    while (A != NULL) {
        *C_end = (SET)malloc(sizeof(c_type));
        if (C_end != NULL) {
            (*C_end)->Elem = A->Elem;
            A = A->link;
            C_end = &(*C_end)->link;
        }
    }
    *C_end = NULL;
    return C;
}

SET setIntersection(SET A, SET B) {
    SET C = NULL;
    SET *C_end = &C;

    while (A != NULL && B != NULL) {

        if (A->Elem == B->Elem) {
            *C_end = (SET)malloc(sizeof(c_type));
            if (C_end != NULL) {
                (*C_end)->Elem = A->Elem;
                C_end = &(*C_end)->link;
            }
            A = A->link;
            B = B->link;
        } else if (A->Elem > B->Elem) {
            B = B->link;
        } else {
            A = A->link;
        }
    }

    *C_end = NULL;
    return C;
}

void displayElem(SET X) {
    printf("\Elements\n");
    for (; X != NULL; X = X->link) {
        printf("%c", X->Elem);
    }
    printf("\n");
}
