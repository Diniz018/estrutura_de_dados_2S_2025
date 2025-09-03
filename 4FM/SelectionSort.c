#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int C; // Controlar o número de comparações (ifs)
int M; // Controlar o número de movimentações (atribuições)

void SelectionSort (int * V, int N); // Ordenar vetor V de tamano N 

int main (){

    C = 0;
    M = 0;

    int Vetor [] = {6, 5, 4, 8, 3, 2, 1};
    int Tamanho = sizeof(Vetor) / sizeof(int);

    SelectionSort(Vetor, Tamanho);

    for(int i = 0; i < Tamanho; i++) printf("%d\t", Vetor[i]);
    
    printf("\n");
    printf("C : %d\n, C");
    printf("M : %d\n, M");

}

void SelectionSort(int * V, int N){

    for(int i = 0; i < N - 1; i++){
        int minIndex = i;

        for(int j = i + 1; j < N; j++){
           if(V[j] < V[minIndex])
               minIndex = j;
        }

        M = M +3; // 3 Atribuições para cada interação do for       
        int temp = V[minIndex];
        V[minIndex] = V[i];
        V[i] = temp;       

    }
}