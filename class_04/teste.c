#include <stdio.h>
#include <stdlib.h>

#define ERRO -1 

int PesquisaSequencial(int *V, int N, int Chave) {
    for (int i = 0; i < N; i++) {
        if (V[i] == Chave) {
            return i;
        }
    }
    return ERRO;
}

int main() {
    system("cls"); // cuidado: só funciona no Windows

    int Numeros[] = {
        14, 39, 37, 11, 43, 25, 19, 32, 16, 22,
        40, 13, 28, 35, 10, 45, 20, 38, 17, 24,
        30, 41, 15, 27, 33, 18, 26, 39, 12, 21, 123
    };

    int Tamanho = sizeof(Numeros) / sizeof(int);
    int Elemento = 12; 
    int Posicao = PesquisaSequencial(Numeros, Tamanho, Elemento);

    if (Posicao != ERRO)
        printf("O elemento está na posição %d.\n", Posicao);
    else
        printf("O elemento %d não está no vetor.\n", Elemento);

    return 0;
}
