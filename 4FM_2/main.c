#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "quicksort.h"

int main (){

    int Vetor[] = {3, 6, 4, 5, 1, 7, 2};
    int Tamanho = sizeof(Vetor) / sizeof(int);

    QuickSort(Vetor, 0, Tamanho - 1);
    ExibirVetor(Vetor, Tamanho);

}