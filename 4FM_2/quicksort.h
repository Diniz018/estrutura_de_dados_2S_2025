#ifndef QUICKSORT_h
#define QUICKSORT_H

void ExibirVetor(int * V, int N);  // Exibir o Vetor V, de tamanho N
void TrocarElemento(int * A, int * B);

int Particao(int * V, int Inf, int Sup); // Determinar a posição do pivô (pivot)
void QuickSort(int * V, int Inf, int Sup);


#endif