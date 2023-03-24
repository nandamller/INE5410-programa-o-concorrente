/*Fernanda Larissa Müller - 21202109*/

#include <stdio.h>

int a(int x) {
    if (x % 4 == 0) {
        if (x % 100) return -1;
        else if (!(x % 400)) return 1;
        
        return 0;
    }
}

int b(int x) {
    return !(x % 400) || ((x % 100) && !(x%4));
}

int c(int x) {
    if (x % 4 == 0) {
        if (x % 100 == 0) return 0;
        else if (!(x % 400)) return 1;
        
        return 1;
    }
}

int d(int x) {
    return (!(x % 400) || (x % 100)) && !(x%4);
}

int e(int x) {
    return (x % 400 == 0 || x % 100) && x % 4 == 0;
}

int f(int x) {
    return x % 400 == 0 || (x % 100 && x % 4 == 0);
}

int main(void) {
    printf("Função a\n");
    printf("2000: %d\n", a(2000));
    printf("2020: %d\n", a(2020));
    printf("2200: %d\n", a(2200));

    printf("Função b\n");
    printf("2000: %d\n", b(2000));
    printf("2020: %d\n", b(2020));
    printf("2200: %d\n", b(2200));

    printf("Função c\n");
    printf("2000: %d\n", c(2000));
    printf("2020: %d\n", c(2020));
    printf("2200: %d\n", c(2200));

    printf("Função d\n");
    printf("2000: %d\n", d(2000));
    printf("2020: %d\n", d(2020));
    printf("2200: %d\n", d(2200));

    printf("Função e\n");
    printf("2000: %d\n", e(2000));
    printf("2020: %d\n", e(2020));
    printf("2200: %d\n", e(2200));

    printf("Função f\n");
    printf("2000: %d\n", f(2000));
    printf("2020: %d\n", f(2020));
    printf("2200: %d\n", f(2200));

    return 0;
}