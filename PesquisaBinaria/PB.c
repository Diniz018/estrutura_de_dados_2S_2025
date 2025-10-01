#include <stdio.h>
#include <stdlib.h>
#define ERRO

int PB(int * V, int N, int Chave);

int main(){

    int Numeros[] = {1, 2, 4, 5, 6, 7, 8, 10, 12, 14, 16, 18, 20, 21, 22};
    int Tamanho = sizeof(Numeros) / sizeof(int); // ou Numeros[0]
    int Elemento = 15;
    int Posicao = PB(Numeros, 0, Tamanho - 1, Elemento);

    if (Posicao != ERRO) printf("O elemento está na posicao %d.\n", Posicao);
    else printf("O elemento não está no vetor!!!\n");

}

int PB(int * V, int N, int Chave){

    int Esquerda = 0; // Início da partição 
    int Direita = N - 1; // Final da partição 

    while (Esquerda <= Direita){
        int Meio = (Esquerda + Direita) / 2;
        if(V[Meio] == Chave) return Meio;
        else if (V[Meio] < Chave) Esquerda = Meio + 1; // Descartando a 1 metade
        else Direita = Meio - 1; // Descartando a 2 meetade 
    }

    return ERRO;

}

int PB_Recursivo(int * V, int Esquerda, int Direita, int Chave) {

    if(Esquerda > Direita) return ERRO;
    int Meio = (Esquerda + Direita) / 2;

    if(V[Meio] == Chave) return Meio;
    else if(V[Meio] < Chave) PB_Recursivo(V, Meio + 1, Direita, Chave);
    else return PB_Recursivo(V, Esquerda, Meio - 1, Chave);
}