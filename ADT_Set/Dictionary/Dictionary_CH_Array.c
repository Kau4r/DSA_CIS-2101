#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define DELETED '!'
#define EMPTY ' '
#define MAX 10

typedef char Dictionary[MAX];

void addElem(Dictionary, char);
bool isMember(Dictionary, char);
void deleteElem(Dictionary, char);
void initDict(Dictionary);
void displayHash(Dictionary);
int hash(char);

int main() {
    Dictionary Dic;
    initDict(Dic);
    addElem(Dic, 'Z');
    displayHash(Dic);
    addElem(Dic, 'F');
    displayHash(Dic);
    addElem(Dic, 'B');
    displayHash(Dic);
    addElem(Dic, 'L');
    displayHash(Dic);
    addElem(Dic, 'K');
    displayHash(Dic);
    addElem(Dic, 'P');
    displayHash(Dic);
    addElem(Dic, 'G');
    displayHash(Dic);
    addElem(Dic, 'A');
    displayHash(Dic);
    addElem(Dic, 'D');
    displayHash(Dic);
    addElem(Dic,'I');
    displayHash(Dic);
    deleteElem(Dic,'K');
    displayHash(Dic);
    deleteElem(Dic,'A');
    displayHash(Dic);
    addElem(Dic, 'A');
    displayHash(Dic);
    addElem(Dic, 'K');
    displayHash(Dic);
}

void initDict(Dictionary A) {
    int x;
    for (x = 0; x < MAX; x++) {
        A[x] = EMPTY;
    }
}

int hash(char T) { return (toupper(T) - 65) % MAX; }

void addElem(Dictionary B, char D) {
    if (!isMember(B, D)) {
        int ndx = hash(D);
        int x;
        for (x = ndx;B[x] != EMPTY && B[x] != DELETED ; x = (x + 1) % MAX) {}
        B[x] = D;
    }
}

bool isMember(Dictionary G, char F) {
    int ndx = hash(F);
    int x;
    for (x = ndx; x != ((ndx - 1) + MAX) % MAX && G[x] != EMPTY && G[x] != F ; x = (x + 1) % MAX) {}
    return G[x] == F;
}

void deleteElem(Dictionary H, char V) {
    int ndx = hash(V);
    int x;
    for (x = ndx; H[x] != V && H[x] != EMPTY; x = (x + 1) % MAX) {}
    if (H[x] != EMPTY) {
        H[x] = DELETED;
    }
}

void displayHash(Dictionary X) {
    int x;
    char z;
    printf("\nDictionary\n");
    for(x=0 ; x < MAX ; x++){
        z=X[x];
        printf("[%d] = %s\n", x,(X[x] == DELETED) ? "DELETED" : (X[x] == EMPTY) ? "EMPTY" : &z);
    }
}