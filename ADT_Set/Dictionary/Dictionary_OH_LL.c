#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct node {
    char Letter;
    struct node *next;
} *List, *Dictionary[MAX];

void initDictionary(Dictionary);
int hash(char);
void inSort(Dictionary, char);
void delete(Dictionary, char);
bool isMember(Dictionary, char);
void show(Dictionary);

int main() {
    Dictionary carlo;
    show(carlo);
}

void initDictionary(Dictionary D) {
    int x;
    for (x = 0; x < MAX; x++) {
        D[x] = NULL;
    }
}

int hash(char val) { return toupper(val) - 'A' % MAX; }

void inSort(Dictionary D, char X) {
    int ndx = hash(X);
    List *trav;
    List new = (List)malloc(sizeof(struct node));
    for (trav = &D[ndx]; *trav != NULL && X > D[ndx]->Letter;
         trav = &(*trav)->next) {
    }
    new->Letter = X;
    new->next = *trav;
    *trav = new;
}

void delete(Dictionary D, char X) {
    int ndx = hash(X);
    List *trav;
    List del;
    for (trav = &D[ndx]; *trav != NULL && X != D[ndx]->Letter;
         trav = &(*trav)->next) {
    }
    if (*trav != NULL) {
        del = *trav;
        *trav = del->next;
        free(del);
    }
}

bool isMember(Dictionary D, char X) {
    int ndx = hash(X);
    List trav;
    for (trav = D[ndx]; trav != NULL && X != D[ndx]->Letter;
         trav = trav->next) {
    }

    return trav != NULL;
}

void show(Dictionary D) {
    int x;
    List trav;
    for (x = 0; x < MAX; x++) {
        for (trav = D[x]; trav != NULL; trav = trav->next) {
            printf("%d", printf("Hello"));
        }
    }
}
