#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "equipe.h"

/*Implementação das funções cujos protótipos foram definidos em "equipe.h"*/

Equipe * LeDados(char * NomeArquivo) {

    Equipe * X = malloc( NumeroEquipes * sizeof(Equipe)); /* Alocando dinamicamente memória para 20 equipes */
    if (X == NULL) {
        printf("ERRO: não foi possível alocar memória para o vetor de equipes.\n");
        exit(ERRO);
    }

    FILE * fp = fopen(NomeArquivo, "r"); /* Abrindo NomeArquivo para LEITURA */
    if (fp == NULL) {
        printf("ERRO: não foi possível abrir o arquivo %s.\n", NomeArquivo);
        exit(ERRO)
    }

    printf("O arquivo foi aberto com SUCESSO!\n");

    char Cabecalho[200];
    fscanf(fp, "%s", Cabecalho); /* Para "desconsiderar" a primeira linha do arquivo. */

    /* Lendo as informações de cada um dos times. */

    int i = 0; /* Para aguardar informações a respeito do índice do vetor de Equipes*/

    while(
        fscanf(
            fp,
            "%d;%[^;];%[^;];%d;%d;%d;%d;%d;%d;%d;%d\n",
            &X[i].Pos, X[i].Estado, X[i].Time, &X[i].Pts, &X[i].J, &X[i].V, &X[i].E, &X[i].D, &X[i].GP, &X[i].GC, &X[i].SG
        ) == 11
        {
            X[i].Aproveitamento = (float) X[i].Pts / (3)
        }
    )
}