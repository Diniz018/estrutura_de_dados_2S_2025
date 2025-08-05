#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int Numerador;
    int Denominador;
} Fracao;

Fracao criarFracao(int N, int D) {
    Fracao F;
    F.Numerador = N;
    F.Denominador = D;
    return F;

}

int main(){

    int t = sizeof(Fracao);
    printf("Tamanho: %d", t);

    Fracao F1 = criarFracao(7,2);
    printf("o valor de F1 eh %.2f.\n", F1.Numerador/F1.Denominador);
    
}