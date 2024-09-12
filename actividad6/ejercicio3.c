#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* thread_function(void* arg) {
    printf("Hilo ejecutándose\n");
    return NULL;
}

int main() {
    pid_t pid;
    pthread_t thread;

    // Primer fork: Crear proceso hijo
    pid = fork();
    
    if (pid < 0) {
        perror("Error en fork");
        exit(1);
    }

    if (pid == 0) { // Proceso hijo
        // Segundo fork dentro del proceso hijo
        fork();

        // Crear hilo en el proceso hijo
        if (pthread_create(&thread, NULL, thread_function, NULL) != 0) {
            perror("Error creando el hilo");
            exit(1);
        }

        // Esperar a que el hilo termine
        pthread_join(thread, NULL);
    }

    // Tercer fork (en ambos procesos: el padre original y el hijo)
    fork();

    // Pausa para que puedas verificar los procesos y hilos con ps
    sleep(10);

    return 0;
}
