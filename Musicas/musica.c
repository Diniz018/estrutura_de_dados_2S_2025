#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "musica.h"

Musica * criarMusica(char * Titulo, char * Autor, int Ano) {

    Musica * X = (Musica *) malloc(sizeof(Musica));
    if(X == NULL){
        printf("Erro: não foi possível alocar memória para um item (Musica)");
        return NULL;
    }

    strcpy(X->Titulo, Titulo);
    strcpy(X->Autor, Autor);
    X->Ano = Ano;
    X->Proximo = NULL;
    X->Anterior = NULL;

    return X;
}