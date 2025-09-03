#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

// Função rand () gera um número pseudo-aleatório 

#define TAMANHO 2000

int main (){

    int V[TAMANHO];

    srand(time(NULL));

    for(int i = 0; i < TAMANHO; i++) V[i] = rand();

    clock_t T0 = clock(); // Para marcar o ínicio da contagem

    for(int i = 0; i < TAMANHO; i++) printf("%d\t", V[i]);

    clock_t TF = clock(); // Para marcar o final da contagem 

    double TempoCPU = ((double)(TF - T0)) / CLOCKS_PER_SEC; 

    printf("\n\nTempo de CPU: %lf seg\n", TempoCPU);

    return 0;
}