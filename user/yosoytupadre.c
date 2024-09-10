#include "user/user.h"
#include "kernel/stat.h"
#include "kernel/types.h"

int main(){
    int ppid = getppid();
    printf("mi padre tiene PID: %d\n", ppid);
    int ancestro = getancestor(2);
    if( ancestro != -1){
        printf("Ancestro PID: %d\n",ancestro);
    } else {
        printf("No hay ancestro %d\n",2);
    }

    exit(0);
}