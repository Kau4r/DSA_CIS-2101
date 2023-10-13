/******************************************************************
 * Project Name:  List, Set and Dictionary                        *
 * Programmer  :  Put your Name here                              *
 * Date Completed: March 25, 2023                                 *
 ******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VH_SIZE 0XC     // size of Virtual Heap
#define OPEN_DSIZE 0XA  // size of Open Hash Table
#define CLOSE_DSIZE 0XC // size of Close Hash Table
#define LIST_SIZE 0XF   // size of the array implementation of List
/******************************************************************************
 * Data Structure Definition:                                                 *
 ******************************************************************************/
typedef struct {
    char name[24]; // Chocolate name
    int weight;    // Chocolate weight in grams
} chocoDesc;

typedef struct {
    char prodID[8]; //  product ID uniquely identifies the products; EMPTY or
                    //  DELETED
    chocoDesc prodDesc; //  product description
    float prodPrice;    //  product price
    int prodQty;        //  product count or quantity
} product;              //  product record

typedef struct {
    product elem;
    int next;
} prodNode; // Product node, used in cursor-based implementation of Set

/************************
 * Virtual Heap         *
 ************************/
typedef struct {
    prodNode VH_node[VH_SIZE];
    int avail;
} VHeap;

/******************************************
 * Cursor-Based Implementation of SET     *
 ******************************************/
typedef struct {
    int elemIndex; // index of the 1st element in the set
    int count;     // holds the actual number of elements in the set
    VHeap *VHptr;  // holds the pointer to the virtual heap
} cursorSet;

/********************************************
 * Open Hashing Implementation of Dictionary*
 ********************************************/
typedef struct {
    int header[OPEN_DSIZE]; // array of sets
    int count;              // total number of elements in the dictionary
    VHeap *dicVHptr;        // holds the pointer to the virtual heap
} openDic;

/**********************************************
 * Closed Hashing with 2 pass loading          *
 **********************************************/
#define EMPTY "empty" // stored in product ID field
#define DELETED "del" // stored in product ID field *

typedef product
    closeDic[CLOSE_DSIZE]; // Definition of the closed hash dictionary

typedef struct {
    product prod[LIST_SIZE];
    int last; // index of the last element; -1 if list is empty
} List;

void pause() {
    printf("\n\nPress any key to continue...\n");
    getchar();
    system("clear");
}
/**********************************************************
 * Function Prototypes                                    *
 *********************************************************/
//---Problem #1 ---
void initVHeap(VHeap *VH);
cursorSet initCursorSet(VHeap *VH);
void displayVHeap(VHeap V);
void displaySet(cursorSet A);

//---Problem #2 ---
int mallocInVHeap(VHeap *VH);
void insertSorted(cursorSet *A, product P);
void populateSet(cursorSet *A);

//---Problem #3 ---
int openHash(char *IDen);
openDic initOpenDict(VHeap *VH);
openDic convertToOpenDict(cursorSet *A);
void displayOpenDict(openDic D);

//---Problem #4 ---
void freeInVHeap(VHeap *VH, int ndx);
void deleteDict(openDic *D, char *IDen);

//---Problem #5 ---
int closeHash(char *ID);
void initCloseDict(closeDic CD);
closeDic *convertToCloseDict(openDic *D);
void displayCloseDict(closeDic CD);

/************************************************************************************
 * READ ME FIRST before ANSWERING * 1)  To facilitate the checking of the
 *machine problem, follow the instructions * in each PROBLEM #. * 2)  To
 *accomplish the task for each PROBLEM, a series of function calls may be *
 *       necessary. * 3)  Write you answer BELOW THE COMMENTS. DO NOT DELETE
 *COMMENTS                *
 *                                                                                  *
 ***********************************************************************************/
int main() {
    system("clear");
    /*---------------------------------------------------------------------------------
     * 	Problem #1 ::  1) Initializes the virtual heap and the cursor Set * 2)
     *Displays the contents  virtual heap and cursor Set          *
     *--------------------------------------------------------------------------------*/
    printf("\n\n\nProblem #1:: ");
    printf("\n------------");
    // Declare variables needed for Problem #1
    VHeap heap;
    cursorSet Cset;

    // Function Calls for Problem #1
    initVHeap(&heap);
    Cset = initCursorSet(&heap);
    displayVHeap(heap);
    displaySet(Cset);

    /*---------------------------------------------------------------------------------
     * 	Problem #2 ::  1) Populates the Cursor set which is sorted in ascending
     *order * according to ID                                             * 2)
     *Displays the Cursor set                                     *
     *--------------------------------------------------------------------------------*/
    printf("\n\n\nProblem #2:: ");
    printf("\n------------");
    // Declare variables needed for Problem #2
    // Function Calls for Problem #2
    populateSet(&Cset);
    displaySet(Cset);

    /*---------------------------------------------------------------------------------
     * 	Problem #3 ::  1) Converts the Cursor set into an Open Hash Dictionary *
     *                 2) Displays the Open Hash Dictionary * 3) Displays the
     *empty Cursor set.                              *
     *--------------------------------------------------------------------------------*/
    printf("\n\n\nProblem #3:: ");
    printf("\n------------");
    // Declare variables needed for Problem #3
    openDic OD;
    // Function Calls for Problem #3
    OD = convertToOpenDict(&Cset);
    displayOpenDict(OD);
    displaySet(Cset);
    /*---------------------------------------------------------------------------------
     * 	Problem #4 ::  1) Perform 3 delete operations on the Open Hash
     *Dictionary     * 2) Displays the Open Hash Dictionary * 3) Displays the
     *Virtual Heap                                   *
     *--------------------------------------------------------------------------------*/
    printf("\n\n\nProblem #4:: ");
    printf("\n------------");
    // Declare variables needed for Problem #4
    char delete01[] = "1703";
    char delete02[] = "1358";
    char delete03[] = "1601";

    // Function Calls for Problem #4
    deleteDict(&OD, delete01);
    deleteDict(&OD, delete02);
    deleteDict(&OD, delete03);
    displayOpenDict(OD);
    displayVHeap(heap);

    /*------------------------------------------------------------------------------------
     * 	Problem #5 :: 1) Converts the Open Hash Dictionary into a Closed Hash
     *Dictionary * 2) Displays the Closed Hash Dictionary * 3) Displays the
     *virtual heap                                       *
     *---------------------------------------------------------------------------------*/
    printf("\n\n\nProblem #5:: ");
    printf("\n------------");
    // Declare variables needed for Problem #5
    closeDic *clos;
    // Function Calls for Problem #5
    clos = convertToCloseDict(&OD);
    displayCloseDict(*clos);
    displayVHeap(heap);

    return 0;
}

/************************************************************
 *  Problem 1:: Function Definitions                          *
 ************************************************************/
void initVHeap(VHeap *VH) {
    int i;
    for (i = 0; i < VH_SIZE; i++) {
        strcpy(VH->VH_node[i].elem.prodID, "    ");
        VH->VH_node[i].next = i - 1;
    }
    VH->avail = VH_SIZE - 1;
}

cursorSet initCursorSet(VHeap *VH) { return (cursorSet){-1, 0, VH}; }

void displayVHeap(VHeap V) {
    // Variable Declaration here
    int i;

    printf("\n\nDetails of the Virtual Heap :: ");
    printf("\n------------------------------");
    printf("\nAvailable Index  ::  %d", V.avail);   // Complete this statement
    printf("\nVHeap Address    ::  %p", V.VH_node); // Complete this statemet

    printf("\n\n%10s", "Index");
    printf("%10s", "Prod ID");
    printf("%15s", "Next Field");
    printf("\n%10s%10s%15s", "-----", "-------", "----------");

    // Write your code here
    for (i = 0; i < VH_SIZE; i++) {
        printf("\n%8d %10s %10d", i, V.VH_node[i].elem.prodID,
               V.VH_node[i].next);
    }

    printf("\n\n");
    pause();
}

void displaySet(cursorSet A) {
    int x;

    printf("\n\nDetails of the Set :: ");
    printf("\n---------------------");
    printf("\nNo. of elements ::  %d", A.count); // Complete this code
    printf("\n\n%-7s", "ID");
    printf("%-12s", "Choco Name");
    printf("%-15s", "Choco Weight");
    printf("%-10s", "VHeap Index");
    printf("\n%-7s%-12s%-15s%-10s", "--", "----------", "------------",
           "-----------");

    // Write your code here
    for (x = A.elemIndex; x != -1 && A.count!=0; x = A.VHptr->VH_node[x].next) {
        printf("\n%-7s%-12s%-15d%-10d", A.VHptr->VH_node[x].elem.prodID,
               A.VHptr->VH_node[x].elem.prodDesc.name,
               A.VHptr->VH_node[x].elem.prodDesc.weight, x);
    }

    printf("\n\n");
    pause();
}

/************************************************************
 *  Problem 2:: Function Definitions                         *
 ************************************************************/
int mallocInVHeap(VHeap *VH) {
    int ndx = VH->avail;
    if (ndx != -1) {
        VH->avail = VH->VH_node[ndx].next;
    }
    return ndx;
}

void insertSorted(cursorSet *A, product P) {
    if (A->count < VH_SIZE) {
        int y;
        for (y = A->elemIndex;
             y != -1 && strcmp(P.prodID, A->VHptr->VH_node[y].elem.prodID) != 0;
             y = A->VHptr->VH_node[y].next) {
        }
        if (y != -1) {
            printf("\nProduct with ID:%s already exists in the set", P.prodID);
        } else {
            int newNode = mallocInVHeap(A->VHptr);
            if (newNode != -1) {
                int *x;
                for (x = &A->elemIndex;
                     *x != -1 &&
                     strcmp(P.prodID, A->VHptr->VH_node[*x].elem.prodID) > 0;
                     x = &A->VHptr->VH_node[*x].next) {
                }

                A->VHptr->VH_node[newNode].next = *x;
                A->VHptr->VH_node[newNode].elem = P;
                *x = newNode;
                A->count++;
            }
        }
    } else {
        printf("\nNo Available Space. Product with ID:%s cannot be inserted",
               P.prodID);
    }
}

void populateSet(cursorSet *A) {
    const int COUNT = 15;
    product data[] = {
        {"1701", {"Toblerone", 135}, 150.75, 20},
        {"1356", {"Ferrero", 200}, 250.75, 85},
        {"1109", {"Patchi", 50}, 99.75, 35},
        {"1550", {"Cadbury", 120}, 200.00, 30},
        {"1807", {"Mars", 100}, 150.75, 20},
        {"1201", {"Kitkat", 50}, 97.75, 40},
        {"1450", {"Ferrero", 100}, 150.50, 50},
        {"1701", {"Toblerone", 50}, 90.75, 80},
        {"1601", {"Meiji", 75}, 75.50, 60},
        {"1310", {"Nestle", 100}, 124.50, 70},
        {"1807", {"Valor", 120}, 149.50, 90},
        {"1455", {"Tango", 75}, 49.50, 100},
        {"1703", {"Toblerone", 100}, 125.75, 60},
        {"1284", {"Lindt", 100}, 250.75, 15},
        {"1688", {"Guylian", 50}, 99.75, 35},

    };
    // Inserts each element of the array to the cursor set
    // Write your code here!!
    int i;
    for (i = 0; i < COUNT; i++) {
        insertSorted(&(*A), data[i]);
    }

    pause();
}

/************************************************************
 *  Problem 3:: Function Definitions                        *
 ************************************************************/
int openHash(char *prodID) {
    int x, val = 0;
    for (x = 0; prodID[x] != '\0'; x++) {
        val += prodID[x] - '0';
    }
    return val % OPEN_DSIZE;
}

openDic initOpenDict(VHeap *VH) {
    openDic A;
    initVHeap(VH);
    A.dicVHptr = VH;
    A.count = 0;
    int x;
    for (x = 0; x < OPEN_DSIZE; x++) {
        A.header[x] = -1;
    }
    return A;
}

openDic convertToOpenDict(cursorSet *A) {
    VHeap temp = *(A->VHptr);
    openDic retDict = initOpenDict(A->VHptr);
    A->count = 0;

    int x, *last;
    for (x = A->elemIndex; x != -1; x = temp.VH_node[x].next) {
        int ndx = openHash(temp.VH_node[x].elem.prodID);
        int newnode = mallocInVHeap(retDict.dicVHptr);

        if (newnode != -1) {
            last = &retDict.header[ndx];
            while (*last != -1) {
                last = &retDict.dicVHptr->VH_node[*last].next;
            }

            retDict.dicVHptr->VH_node[newnode].next = -1;
            retDict.dicVHptr->VH_node[newnode].elem = temp.VH_node[x].elem;
            *last = newnode;
            retDict.count++;
        }
    }
    return retDict;
}

void displayOpenDict(openDic D) {
    int x, y;
    // Variable declaration here

    printf("\n\nDetails of the Open Hash Dictionary:: ");
    printf("\n-------------------------------------");

    printf("\nNo. of elements :: %d", D.count);
    printf("\n\n%-7s", "GROUPS");
    printf("%15s", "ID Numbers");
    printf("\n%-7s%15s", "------", "----------");

    // Write your code here
    for (x = 0; x < OPEN_DSIZE && D.count != 0; x++) {
        printf("\nGroup[%d] ::", x);
        for (y = D.header[x]; y != -1; y = D.dicVHptr->VH_node[y].next) {
            printf(" %-7s", D.dicVHptr->VH_node[y].elem.prodID);
        }
    }

    printf("\n\n");
    pause();
}

/************************************************************
 *  Problem 4:: Function Definitions                        *
 ************************************************************/
void freeInVHeap(VHeap *VH, int ndx) {
    if (ndx > -1 && ndx < OPEN_DSIZE) {
        VH->VH_node[ndx].next = VH->avail;
        VH->avail = ndx;
    }
}

void deleteDict(openDic *D, char *IDen) {
    if (D->count != 0) {
        int *x;
        int ndx = openHash(IDen);
        int temp;
        for (x = &D->header[ndx];
             *x != -1 &&
             strcmp(D->dicVHptr->VH_node[*x].elem.prodID, IDen) != 0;
             x = &D->dicVHptr->VH_node[*x].next) {
        }

        if (*x != -1) {
            temp = *x;
            strcpy(D->dicVHptr->VH_node[temp].elem.prodID, "    ");
            *x = D->dicVHptr->VH_node[temp].next;
            freeInVHeap(D->dicVHptr, temp);
            D->count--;
        }
    }
}

/************************************************************
 *  Problem 5:: Function Definitions                        *
 ************************************************************/
int closeHash(char *ID) {
    int x, val = 0;
    for (x = 0; ID[x] != '\0'; x++) {
        val += ID[x] - '0';
    }
    return val % CLOSE_DSIZE;
}

void initCloseDict(closeDic CD) {
    int x;
    for (x = 0; x < CLOSE_DSIZE; x++) {
        strcpy(CD[x].prodID, EMPTY);
    }
}

closeDic *convertToCloseDict(openDic *D) {
    closeDic *CD = (closeDic *)malloc(sizeof(closeDic));
    initCloseDict(*CD);
    List L = {{}, -1};
    int x, y;
    for (x = 0; x < OPEN_DSIZE; x++) {
        for (y = D->header[x]; y != -1; y = D->dicVHptr->VH_node[y].next) {
            int ndx = closeHash(D->dicVHptr->VH_node[y].elem.prodID);
            if (strcmp((*CD)[ndx].prodID, EMPTY) == 0) {
                (*CD)[ndx] = D->dicVHptr->VH_node[y].elem;
            } else {
                L.last++;
                L.prod[L.last] = D->dicVHptr->VH_node[y].elem;
            }
        }
    }

    return CD;
}

void displayCloseDict(closeDic CD) {
    int x;
    // Variable declaration here

    printf("\n\nDetails of Closed Hash Dictionary :: ");
    printf("\n-------------------------------------");
    printf("\n\n%-6s", "Index");
    printf("%-10s", "ChocoID");
    printf("%-15s", "Choco Name");
    printf("\n%-6s%-10s%-15s", "-----", "-------", "----------");

    // Write your code here
    for (x = 0; x < CLOSE_DSIZE; x++) {
        printf("\n%-6d%-10s%-15s", x, CD[x].prodID, CD[x].prodDesc.name);
    }

    printf("\n\n");
    pause();
}
