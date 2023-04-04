/*Fernanda Larissa Müller - 21202109*/

#include <stdio.h>
#include <stdlib.h>

void column_to_row_major(int *dataA, int *dataB, int tam) {
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            *(dataB + (i * tam) + j) = *(dataA + (j * tam) + i);
        }
    }
}

void a(int *dataA, int *dataB, int tam) {
    for (int i = 0; i < tam; i++)
  for (int j = 0; j < tam; j++)
    dataB[j*tam+i] = dataA[j*tam+i];
}

void b(int *dataA, int *dataB, int TAM) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            dataB[j*TAM+i] = dataA[i*TAM+j];
}

void c(int *dataA, int *dataB, int TAM) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            dataB[i*TAM+j] = dataA[i*TAM+j];
}

void d(int *dataA, int *dataB, int TAM) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            dataB[i*TAM+j] = dataA[j*TAM+i];
}

void print_matrizes(int *dataA, int *dataB, int tam) {
    // Imprime a matriz column-major
    printf("Matriz column-major:\n");
    
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            printf("%d ", *(dataA + (j * tam) + i));
        }
        printf("\n");
    }

    // Imprime a matriz row-major
    printf("Matriz row-major:\n");
    
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            printf("%d ", *(dataB + (j * tam) + i));
        }
        printf("\n");
    }
}

int main() {
    int tam = 3;

    int *dataA = (int*) malloc(tam * tam * sizeof(int));
    int *dataB = (int*) malloc(tam * tam * sizeof(int));

    // Preenche a matriz column-major
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            *(dataA + (j * tam) + i) = i * tam + j;
        }
    }

    // Converte para a matriz row-major
    column_to_row_major(dataA, dataB, tam);
    printf("Conversão correta:\n");
    print_matrizes(dataA, dataB, tam);

    a(dataA, dataB, tam);
    printf("\nAlternativa a:\n");
    print_matrizes(dataA, dataB, tam);

    b(dataA, dataB, tam);
    printf("\nAlternativa b:\n");
    print_matrizes(dataA, dataB, tam);

    c(dataA, dataB, tam);
    printf("\nAlternativa c:\n");
    print_matrizes(dataA, dataB, tam);

    d(dataA, dataB, tam);
    printf("\nAlternativa d:\n");
    print_matrizes(dataA, dataB, tam);

    free(dataA);
    free(dataB);

    return 0;
}
