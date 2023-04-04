// Fernanda Larissa Müller - 21202109
// Henrique Pereira Ramos - 21203360

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

//       (pai)      
//         |        
//    +----+----+
//    |         |   
// filho_1   filho_2



int main(int argc, char** argv) {
    // criando 1° filho
    pid_t pid_filho1 = fork();

    // se ele for filho entra no laço
    if (pid_filho1 == 0) {
        printf("Processo filho %d criado!\n", getpid());
        fflush(stdout);
    } 
    // se ele for pai
    else if (pid_filho1 > 0) {
        printf("Processo pai criou %d\n", pid_filho1);
        fflush(stdout);
        
        // esperando o 1° filho terminar
        while(wait(NULL) >= 0);

        // criando 2° filho
        pid_t pid_filho2 = fork();

        // se ele for filho entra no laço
        if (pid_filho2 == 0) {
            printf("Processo filho %d criado!\n", getpid());
            fflush(stdout);
        } 
        // se ele for pai
        else if (pid_filho2 > 0) {
            printf("Processo pai criou %d\n", pid_filho2);
            fflush(stdout);

            // esperando o 2° filho terminar
            while(wait(NULL) >= 0);

            printf("Processo pai finalizado!\n");
            fflush(stdout);
        }
        
    }
    
   
    
    return 0;
}
