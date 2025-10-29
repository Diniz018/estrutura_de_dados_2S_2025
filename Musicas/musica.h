#ifndef MUSICA_H
#define MUSICA_H

typedef struct Musica {

    char Titulo[50];
    char Autor[100];
    int Ano; 
    struct Musica * Anterior; 
    struct Musica * Proximo;
      
} Musica; 

Musica * criarMusica(char * Titulo, char * Autor, int Ano);

#endif