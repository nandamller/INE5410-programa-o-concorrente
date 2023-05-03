// Fernanda Larissa Müller - 21202109

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>


int main(int argc, char** argv) {
    printf("Processo: %d. Filho de: %d.\n", getpid(), getppid());
    fflush(stdout);
    for (int i = 0; i < 4; i++) {
        if (fork() != 0) {
            printf("Processo: %d. Filho de: %d.\n", getpid(), getppid());
            fflush(stdout);
            for (int j = i; j < 4; j++) {
                if (fork() == 0)
                    break;
                printf("Processo: %d. Filho de: %d.\n", getpid(), getppid());
                fflush(stdout);
            }
        break;
        }
    }   
    
    return 0;
}