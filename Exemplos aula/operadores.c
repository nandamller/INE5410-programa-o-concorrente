// Fernanda Larissa Müller - 21202109

#include <stdio.h>

int main() {
    int x = 10;
    int y = 20;

    for (int i = 0; i < x; i++) {
        printf("Y vale %d\n", y);
        y++;
    }

    for (;;) {
        printf("for infinito se não tiver break!\n");
        printf("Y: %d\n", y);
        y++;
        
        if (y > 35) {
            break;
        }
    }

    printf("Saiu do for 'infinito'!\n");

    return 0;
}