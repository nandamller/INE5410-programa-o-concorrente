// Fernanda Larissa Müller - 21202109

#include <stdio.h>

/*
argc vai ser o número de entradas mais 1, porque 1 sempre 
vem do chamado do programa. Já o argv vai ser uma lista 
que contém os parâmetros passado para o programa.
*/

int main(int argc, char *argv[]) {
    if (argc == 1) printf("Sem argumento de entrada.\n");
    else {
        int i;
        for (i=1; i<argc; i++)
            printf("argv[%d] = %s\n", i, argv[i]);
    }
    return 0;
}