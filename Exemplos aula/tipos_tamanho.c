// Fernanda Larissa Müller - 21202109

#include <stdio.h>

void main() {
    printf("%ld\n", sizeof(char));

    /*usualmente o tamanho de uma palavra definida pelo hardware/SO
    (e.g., 16, 32 ou 64 bits)*/
    printf("%ld\n", sizeof(int));

    // pelo menos 16 bits
    printf("%ld\n", sizeof(short int));

    // pelo menos 32 bits
    printf("%ld\n", sizeof(long int));

    // Idem int, mas sem sinal
    printf("%ld\n", sizeof(unsigned int));

    // usualmente 32 bits
    printf("%ld\n", sizeof(float));

    // usualmente 64 bits
    printf("%ld\n", sizeof(double));

    // pelo menos 64 bits
    printf("%ld\n", sizeof(long double));
}