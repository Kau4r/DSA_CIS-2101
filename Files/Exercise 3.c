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
void readAppendFile();

int main() {
    readAppendFile();
    return 0;
}

void readAppendFile() {
    FILE *fp = fopen("/home/kau4r/Documents/VsCoder/C/Files/students (1).dat",
                     "ab"),
         *fp1 =
             fopen("/home/kau4r/Documents/VsCoder/C/Files/students.dat", "rb");
    if (fp != NULL && fp1 != NULL) {
        displayHeader();
        Studtype x;
        while (fread(&x, sizeof(Studtype), 1, fp1) != 0) {
            displayStudent(x);
            fwrite(&x, sizeof(Studtype), 1, fp);
        }
        fclose(fp1);
        fclose(fp);
    }
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
