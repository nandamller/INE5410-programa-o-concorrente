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
    pid_t pid_neto = fork();

    if (pid_neto == 0) {
        printf("Processo %d, filho de %d\n", getpid(), getppid());
        sleep(5);
        printf("Processo %d finalizado\n", getpid());
    }
}

void cria_filho(){
    pid_t pid = fork();

    if (pid == 0) {
        printf("Processo %d, filho de %d\n", getpid(), getppid());
        fflush(stdout);
        printf("Processo %d finalizado\n", getpid());
        fflush(stdout);
        exit(0);
    } else if(pid > 0) {
        while(wait(NULL) >= 0);
    } else {
        printf("Erro ao criar filho!");
    }

}

int main(int argc, char** argv) {
    for (int i = 0; i < 2; i++) {
        cria_filho();
    }
    
    printf("Processo principal %d finalizado\n", getpid());
    fflush(stdout);   
    return 0;
}
