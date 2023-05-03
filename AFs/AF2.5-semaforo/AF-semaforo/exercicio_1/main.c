#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <stdlib.h>

FILE* out;

// criação do semáforo s
sem_t a, b;

void *thread_a(void *args) {
    for (int i = 0; i < *(int*)args; ++i) {
	//      +---> arquivo (FILE*) destino
	//      |    +---> string a ser impressa
	//      v    v
        
        // solicita acesso a região crítica
        sem_wait(&a);

        fprintf(out, "A");
        fflush(stdout);

        // libera acesso a região crítica
        sem_post(&b);
    }
    return NULL;
}

void *thread_b(void *args) {
    for (int i = 0; i < *(int*)args; ++i) {
        // solicita acesso a região crítica
        sem_wait(&b);

        fprintf(out, "B");
        fflush(stdout);

        // libera acesso a região crítica
        sem_post(&a);
    }
    return NULL;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Uso: %s [ITERAÇÕES]\n", argv[0]);
        return 1;
    }
    int iters = atoi(argv[1]);
    srand(time(NULL));
    out = fopen("result.txt", "w");

    pthread_t ta, tb;

    // iniciando os semáforos s
    sem_init(&a, 0, 1);
    sem_init(&b, 0, 1);

    // Cria threads
    pthread_create(&ta, NULL, thread_a, &iters);
    pthread_create(&tb, NULL, thread_b, &iters);

    // Espera pelas threads
    pthread_join(ta, NULL);
    pthread_join(tb, NULL);

    // destruindo o semáforo s
    sem_destroy(&a);
    sem_destroy(&b);

    //Imprime quebra de linha e fecha arquivo
    fprintf(out, "\n");
    fclose(out);
  
    return 0;
}
