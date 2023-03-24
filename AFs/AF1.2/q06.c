/*Fernanda Larissa Müller - 21202109*/

#include <stdio.h>

int f(int a) {
    if (a % 2 != 0 && a < 20) {
        return a;
    } else if (&a) {
        if (a < 0) return 2*a;
    } else {
        return 27;
    }
    return 31;
}

int main(void) {
    printf("Alternativa a:\n");
    printf("%d\n", f(2));

    printf("Alternativa b:\n");
    printf("%d\n", f(-3));
    
    printf("Alternativa c:\n");
    printf("%d\n", f(0));
    
    printf("Alternativa d:\n");
    printf("%d\n", f(-2));

    return 0;
}