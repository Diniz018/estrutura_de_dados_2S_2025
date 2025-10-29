#include <stdio.h>
#include <stdlib.h>

#include "musica.h"

int main() {

    Musica * D = criarMusica("Aquarela", "Toquinho", 1983);
    Musica * E = criarMusica("Romaria", "Renato Teixeira", 1978);
    Musica * F = criarMusica("Eu nasci há dez mil anos atrás", "Raul Seixas", 1976);
    Musica * G = criarMusica("Calice", "Chico Buarque e Gilberto Gil", 1978);
    Musica * H = criarMusica("Tempo Perdido", "Renato Russo", 1986);

    // Construindo o encadeamento D, E, F, G, H

    D->Proximo = E;
    E->Anterior = D; 
    E->Proximo = F;
    F->Anterior = E;
    F->Proximo = G;
    G->Anterior = F;
    G->Proximo = H; 
    H->Anterior = G;

}