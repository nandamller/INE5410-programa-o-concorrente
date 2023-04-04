// Fernanda Larissa Müller - 21202109
// Henrique Pereira Ramos - 21203360

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdio.h>
#include <unistd.h>

//                          (principal)
//                               |
//              +----------------+--------------+
//              |                               |
//           filho_1                         filho_2
//              |                               |
//    +---------+-----------+          +--------+--------+
//    |         |           |          |        |        |
// neto_1_1  neto_1_2  neto_1_3     neto_2_1 neto_2_2 neto_2_3

// ~~~ printfs  ~~~
//      principal (ao finalizar): "Processo principal %d finalizado\n"
// filhos e netos (ao finalizar): "Processo %d finalizado\n"
//    filhos e netos (ao inciar): "Processo %d, filho de %d\n"

// Obs:
// - netos devem esperar 5 segundos antes de imprmir a mensagem de finalizado (e terminar)
// - pais devem esperar pelos seu descendentes diretos antes de terminar

void cria_neto() {
    for (int i = 0; i < 3; i++) {
        pid_t pid = fork();

        if (pid == 0) {
            printf("Processo %d, filho de %d\n", getpid(), getppid());
            fflush(stdout);

            // espera os 5 segundos
            sleep(5);
            
            printf("Processo %d finalizado\n", getpid());
            fflush(stdout);

            // para encerrar o processo neto
            exit(0);
            break;
        } else if(pid < 0) {
            printf("Erro ao criar neto!");
        }
    }
}

void cria_filho(){
    for (int i = 0; i < 2; i++) {
        pid_t pid = fork();

        if (pid == 0) {
            printf("Processo %d, filho de %d\n", getpid(), getppid());
            fflush(stdout);

            cria_neto();
            while(wait(NULL) >= 0);

            printf("Processo %d finalizado\n", getpid());
            fflush(stdout);

            // para encerrar o processo filho
            exit(0);
            break;
        } else if(pid < 0) {
            printf("Erro ao criar filho!");
        }
    }
}

int main(int argc, char** argv) {
    cria_filho();

    while(wait(NULL) >= 0);
    printf("Processo principal %d finalizado\n", getpid());
    fflush(stdout);   
    return 0;
}
