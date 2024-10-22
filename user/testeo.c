#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main() {
    for (int i = 1; i <= 20; i++) {
        int pid = fork();
        if (pid == 0) {
            printf("Ejecutando proceso %d\n", i);
            sleep(1);
            exit(0);
        }
        if (pid < 0) {
            printf("Error: no se pudo crear el proceso %d\n", i);
            exit(1);
        }
        wait(0);
    }
    printf("Todos los procesos hijos terminaron.\n");
    exit(0);
}
