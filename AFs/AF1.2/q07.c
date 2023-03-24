/*Fernanda Larissa Müller - 21202109*/

#include <stdio.h>

int* g(int* a) {
    return a++;
}

int f(int a) {
    return *g(&a);
}

int h() {
    int a = 23;
    f(a);
    return a;
}

int f_(int a) { 
    return a; 
}

int main(void) {
    printf("Alternativa b:\n");
    printf("%d\n", h());

    printf("Alternativa c:\n");
    printf("%d, %d\n", f(3), f_(3));

    return 0;
}