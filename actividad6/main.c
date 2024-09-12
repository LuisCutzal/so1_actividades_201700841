#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();  // Crear un proceso hijo

    if (pid < 0) {
        // Si `fork()` falla
        perror("fork failed");
        exit(1);
    }
    
    if (pid == 0) {
        // Este es el proceso hijo
        printf("Proceso hijo con PID %d se va a terminar.\n", getpid());
        exit(0);  // El proceso hijo termina y se convierte en zombie
    } else {
        // Este es el proceso padre
        printf("Proceso padre con PID %d, el hijo es %d.\n", getpid(), pid);
        printf("Esperando 60 segundos para que el hijo permanezca como zombie.\n");

        // Esperar 60 segundos
        sleep(60);

        // Ahora el proceso padre espera al hijo para que salga del estado zombie
        wait(NULL);
        printf("El proceso zombie ha sido recolectado.\n");
    }

    return 0;
}
