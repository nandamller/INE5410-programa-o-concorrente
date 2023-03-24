/*Fernanda Larissa Müller - 21202109*/

#include <stdio.h>
#include <stdlib.h>

void a(int data[][5], int ROW, int COL) {
    for (int i = 0; i < ROW; i++) {
        for (int j = i; j >= 0; j--) {
            data[i][j] = rand() % 100 + 1;
        }
    }
}

void b(int data[][5], int ROW, int COL) {
    for (int i = 0; i <= ROW; i++) {
        for (int j = i; j <= COL; j++) {
            data[i][j] = rand() % 100 + 1;
        }
    }
}

void c(int data[][5], int ROW, int COL) {
    for (int i = 0; i < ROW; i++) {
        for (int j = i; j < COL; j++) {
            data[i][j] = rand() % 100 + 1;
        }
    }
}

void d(int data[][5], int ROW, int COL) {
    for (int i = 0; i < ROW; i++) {
        for (int j = i; j < COL; j++) {
            data[j][i] = rand() % 100 + 1;
        }
    }
}

void e(int data[][5], int ROW, int COL) {
    for (int i = 0; i < COL; i++) {
        for (int j = i; j < ROW; j++) {
            data[i][j] = rand() % 100 + 1;
        }
    }
}

void f(int data[][5], int ROW, int COL) {
    for (int i = 0; i < ROW; i++) {
        for (int j = i; j >= 0; j--) {
            data[j][i] = rand() % 100 + 1;
        }
    }
}

void print_matriz(int data[][5], int ROW, int COL) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
}

void zera(int data[][5], int ROW, int COL) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            data[j][i] = 0;
        }
    }
}

int main(void) {
    int ROW = 5, COL = 5;
    
    int data[ROW][COL];
    zera(data, ROW, COL);
    a(data, ROW, COL);
    printf("Alternativa a:\n");
    print_matriz(data, ROW, COL);

    zera(data, ROW, COL);
    b(data, ROW, COL);
    printf("Alternativa b:\n");
    print_matriz(data, ROW, COL);

    zera(data, ROW, COL);
    c(data, ROW, COL);
    printf("Alternativa c:\n");
    print_matriz(data, ROW, COL);

    zera(data, ROW, COL);
    d(data, ROW, COL);
    printf("Alternativa d:\n");
    print_matriz(data, ROW, COL); 

    zera(data, ROW, COL);
    e(data, ROW, COL);
    printf("Alternativa e:\n");
    print_matriz(data, ROW, COL); 

    zera(data, ROW, COL);
    f(data, ROW, COL);
    printf("Alternativa f:\n");
    print_matriz(data, ROW, COL); 

    return 0;
}