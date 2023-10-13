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

typedef struct {
    Book_t *book;
    int count;
} List;

List initList();
void insorted(List *, Book_t);
void deleteID(List *, unsigned);
Bool locate(List, unsigned);
Book_t retrieve(List, unsigned);
Bool isFull(List);
Bool isEmpty(List);
void makeNull(List *);
void displayList(List);

int main() {
    List carlo = initList();
    printf("List Initialized...");
    displayList(carlo);
    insorted(&carlo, (Book_t){2,
                              {"Harry Potter and carlo", "J.K tRolling",
                               "Non-Fiction", 2050},
                              200.00,
                              {2017, "carlo"}});
    displayList(carlo);
    makeNull(&carlo);
    displayList(carlo);
    printf("\n\nAfterNull");

    insorted(&carlo, (Book_t){1,
                              {"Harry Potter and carlo", "J.K tRolling",
                               "Non-Fiction", 2050},
                              200.00,
                              {2017, "carlo"}});

    insorted(&carlo, (Book_t){3,
                              {"Harry Potter and carlo", "J.K tRolling",
                               "Non-Fiction", 2050},
                              200.00,
                              {2017, "carlo"}});
    insorted(&carlo, (Book_t){4,
                              {"Harry Potter and carlo", "J.K tRolling",
                               "Non-Fiction", 2050},
                              200.00,
                              {2017, "carlo"}});
    displayList(carlo);
    deleteID(&carlo, 3U);
    displayList(carlo);
}

List initList() { return (List){(Book_t *)malloc(sizeof(Book_t)*MAX), 0}; }

void insorted(List *main, Book_t add) {
    if (!isFull(*main)) {
        int x;
        for (x = main->count; x > 0 && add.ID < main->book[x - 1].ID; x--) {
            main->book[x] = main->book[x - 1];
        }
        main->book[x] = add;
        main->count++;
    }
}

void deleteID(List *main, unsigned delID) {
    if (!isEmpty(*main)) {
        int x;
        for (x = 0; x < main->count - 1; x++) {
            if (delID < main->book[x + 1].ID) {
                main->book[x] = main->book[x + 1];
            }
        }
        main->count--;
    }
}

Bool locate(List main, unsigned findID) {
    int x;
    for (x = 0; x < main.count && findID != main.book[x].ID; x++) {
    }
    return findID == main.book[x].ID;
}

Book_t retrieve(List main, unsigned findID) {
    Book_t retBook = {0U, {"xxxxx", "xxxxx", "xxxxx", 0U}, 0.0, {0, "xxxxx"}};
    int x;
    for (x = 0; x < main.count && findID != main.book[x].ID; x++) {
    }
    if (x != main.count) {
        retBook = main.book[x];
    }
    return retBook;
}

Bool isFull(List main) { return (main.count == MAX) ? true : false; }

Bool isEmpty(List main) { return (main.count == 0) ? true : false; }

void makeNull(List *main) { main->count = 0; }

void displayList(List main) {
    if (!isEmpty(main)) {
        int x;
        for (x = 0; x < main.count; x++) {
            printf("\nBook #%d", main.book[x].ID);
        }
    } else {
        printf("\nList is empty!!!\n\n");
    }
}
