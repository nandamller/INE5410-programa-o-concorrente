/*Fernanda Larissa Müller - 21202109*/
#include <stdio.h>

typedef struct {
    float x, y;
} ponto_t;

int main(void) {
    ponto_t q = {23.0, 27.0};
    ponto_t* p = &q;

    //a
    // p->++x;

    //b
    q.x = q.y = p->x *= 2;

    //c
    //q.x = p
    
    //d
    // q->x++;

    return 0;
}
