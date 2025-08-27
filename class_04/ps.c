#include <stdio.h>
#include <stdlib.h>

#define ERRO -1 

/*Retorna (devolve) a POSIÇÃO do elemento CHAVE no vetor V, de tamanho N. */

int PesquisaSequencial(int * V, int N, int Chave);

/*Implementação da main ...*/

int main(){

    system("cls");

    int Numeros[] = {
        14, 39, 37, 11, 43, 25, 19, 32, 16, 22,
        40, 13, 28, 35, 10, 45, 20, 38, 17, 24,
        30, 41, 15, 27, 33, 18, 26, 39, 12, 21, 123
    };

    int Tamanho = sizeof(Numeros) / sizeof(int); // 120 B (tamanho do vetor) / 4 B (tamanho do int)
    int Elemento = 16; 
    int Posicao = PesquisaSequencial(Numeros, Tamanho, Elemento);

    if(Posicao != ERRO) printf("O elemento está na posição %d.\n", Posicao);
    else printf("O elemento não está no vetor.\n", Elemento);

    return 0;

}