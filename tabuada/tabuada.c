#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int n;
    int q;
    if (argc == 2){
        n = atoi(argv[1]);
        q = 10;
    }else if (argc == 3){
        n = atoi(argv[1]);
        q = atoi(argv[2]);
    }else{
        printf("Erro! \n");
        printf("tabuada <Número da tabuada> <Quantia de soluções>\n");
        printf("O padrão para a quantia de soluções inicial é 10\n");
        return 0;
    }
    printf("Tabuada do %d\n", n);
    for (int i = 1; i <= q; i++){
        printf("%d x %d = %d\n", n, i, n*i);
    }
    return 0;
}