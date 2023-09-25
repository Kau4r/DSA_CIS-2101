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

typedef struct node {
    Book_t book;
    struct node *link;
} Node, *List;

List initList();
void insorted(List *, Book_t);
void deleteAt(List *, int);
Bool locate(List, unsigned);
Book_t retrieve(List, unsigned);
Bool isEmpty(List);
void makeNull(List *);
void displayList(List main);

int main(void) {
    List BookStore = initList();
    insorted(&BookStore, (Book_t){2,
                                  {"Harry Potter and carlo", "J.K tRolling",
                                   "Non-Fiction", 2050},
                                  200.00,
                                  {2017, "carlo"}});
    insorted(&BookStore, (Book_t){3,
                                  {"all the words are yours",
                                   "tyler knott gregson", "Poetry", 50},
                                  500.00,
                                  {2012, "me"}});
    
    locate(BookStore, 2); 
    
    insorted(&BookStore, retrieve(BookStore, 2));
    
    deleteAt(&BookStore, 2);
    
    makeNull(&BookStore);

    displayList(BookStore);
}

List initList() {
    printf("Initializing Book List");
    return NULL;
}

void insorted(List *main, Book_t newBook) {
    List newNode = (List)malloc(sizeof(Node));
    if (newNode != NULL) {
        List *trav;
        for (trav = main; *trav != NULL && newBook.ID < (*trav)->book.ID;
             trav = &(*trav)->link) {
        }
        newNode->link = *trav;
        newNode->book = newBook;
        *trav = newNode;
        printf("\nBook #%d Added", newBook.ID);
    }
}

void deleteAt(List *main, int pos) {
    List *trav;
    List temp;
    int x;
    for (trav = main, x = 0; *trav != NULL && x < pos - 1;
         trav = &(*trav)->link, x++) {
    }
    if (*trav != NULL) {
        temp = *trav;
        *trav = temp->link;
        printf("\nBook #%d", temp->book.ID);
        free(temp);
        printf(" Deleted");
    }
}

Bool locate(List main, unsigned findID) {
    List trav;
    for (trav = main; trav != NULL && findID != trav->book.ID;
         trav = trav->link) {
    }
    if (trav != NULL) {
        printf("\nBook #%d Found!", findID);
    }
    return trav != NULL;
}

Book_t retrieve(List main, unsigned findID) {
    List trav;
    Book_t retBook = {0U, {"xxxxx", "xxxxx", "xxxxx", 0U}, 0.0, {0, "xxxxx"}};
    for (trav = main; trav != NULL && findID != trav->book.ID;
         trav = trav->link) {
    }
    if (trav != NULL) {
        retBook = trav->book;
        printf("\nBook #%d retrieved!", retBook.ID);
    }
    return retBook;
}

Bool isEmpty(List main) { return main == NULL; }

void makeNull(List *main) {
    List *trav = main;
    List temp;
    while (*trav != NULL) {
        temp = *trav;
        *trav = temp->link;
        free(temp);
    }
    printf("\nBook Store Sold Out");
}

void displayList(List main) {
    List trav;
    if (main == NULL) {
        printf("\nits just a store now");
    } else {
        printf("\nBook Store:");
    }
    for (trav = main; trav != NULL; trav = trav->link) {
        printf("\nBook #%d", trav->book.ID);
    }
}