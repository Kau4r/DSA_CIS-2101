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
void writeFile();

int main(){
    writeFile();
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
void writeFile(){
    Studtype Studs[5];
    Studs[0]=(Studtype){{"Xander",'T',"Labide"},2,"BSPSYCH",4};
    Studs[1]=(Studtype){{"Matt",'B',"Magdadaro"},3132012,"BSCOMM",2};
    Studs[2]=(Studtype){{"Carlo",'A',"Juab"},432132,"BSCS",3};
    Studs[3]=(Studtype){{"Julz",'O',"Cortes"},52102606,"BSCS",5};
    Studs[4]=(Studtype){{"Achille",'M',"Lanutan"},6,"BSIT",2};
    int x;
    FILE *fp=fopen("/home/kau4r/Documents/VsCoder/C/Files/students.dat","wb");
    if(fp!=NULL){
        displayHeader();
        for(x=0;x<5;x++){
            displayStudent(Studs[x]);
            fwrite(&(Studs[x]),sizeof(Studtype),1,fp);
        }


        fclose(fp);
    }
}


