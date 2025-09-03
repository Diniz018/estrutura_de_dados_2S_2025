#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

// Função rand () gera um número pseudo-aleatório 

#define TAMANHO 500000

int main (){

    int V[TAMANHO];

    srand(time(NULL));

    for(int i = 0; i < TAMANHO; i++) V[i] = rand();
    for(int i = 0; i < TAMANHO; i++) printf("%d\t", V[i]);

    return 0;
}