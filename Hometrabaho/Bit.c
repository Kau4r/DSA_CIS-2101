#include <stdio.h>

void displayBi(int);

int main(){
    displayBi(2147483647);
}

void displayBi(int value){
    unsigned int mask= 1 << (sizeof(int)*8-1);
    int x;

    for(x=0;x < sizeof(int)*8;x++){
            printf("%d",(value&mask)?1:0);

            mask>>=1;

        if ((x + 1) % 4 == 0){
            printf(" ");
        }
    }
}


void intToBinary(int num) {
    if (num == 0) {
        printf("Binary: 0\n");
        return;
    }

    int numBits = sizeof(int) * 8;
    int i;

    printf("Binary:");

    for (i = numBits - 1; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if ((i + 1) % 4 == 0) {
            printf(" ");
        }
        printf("%d", bit);
    }

    printf("\n");
}
