#include <stdio.h>

typedef struct {
    char FN[24]; // firstname
    char MI;     // middle initial
    char LN[16]; // lastname
} Nametype;

typedef struct {
    Nametype name;
    int ID;
    char course[8]; // BSCS, BSIS, BSIT
    int yrLevel;
} Studtype;

void displayHeader();
void displayStudent(Studtype S);
void readFile();

int main() {
    readFile();
    return 0;
}

void displayHeader() {
    printf("\n\n");
    printf("%-10s", "ID No.");
    printf("%-16s", "Lastname");
    printf("%-22s", "Firstname");
    printf("%-4s", "MI");
    printf("%-8s", "Course");
    printf("%4s", "Year");
    printf("\n");
    printf("%-10s", "========");
    printf("%-16s", "========");
    printf("%-22s", "=============");
    printf("%-4s", "===");
    printf("%-8s", "======");
    printf("%5s", "=====");
}
void displayStudent(Studtype S) {
    printf("\n%-10d%-16s%-23s%-4c%-8s%2d", S.ID, S.name.LN, S.name.FN,
           S.name.MI, S.course, S.yrLevel);
}
void readFile() {
    FILE *fp;
    if (!(fp = fopen("/home/kau4r/Documents/VsCoder/C/Files/students.dat",
                     "rb"))) {
        printf("\nCannot Find File!!!!");
    } else {
        Studtype stud;
        displayHeader();
        while (fread(&stud, sizeof(Studtype), 1, fp) != 0) {
            displayStudent(stud);
        }
        fclose(fp);
    }
}
