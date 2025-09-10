#include <stdio.h> 
#include <stdlib.h>
#include <time.h> 

void InsertionSort(int * V, int N);
void ExibirVetor(int * V, int N);

int main(){

    int Conjunto[] = {1, 9, 7, 8, 5, 2};
    int Tamanho = sizeof(Conjunto) / sizeof(int);

    clock_t T0 = clock();
    InsertionSort(Conjunto)
}