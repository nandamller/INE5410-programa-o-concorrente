/*Fernanda Larissa Müller*/

struct estrutura {
    int a;
    float b;
};

int main(void) {
    struct estrutura s;
    s.a = 3490; /* atribuição a um elemento da struct! */
    s.b = 3.14159; /* atribuição a um elemento da struct! */
    printf("Valor do campo a: %d\n", s.a);
    return 0;
}