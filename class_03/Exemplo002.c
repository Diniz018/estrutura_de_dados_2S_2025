#include <stdio.h>
#include <stdlib.h>

int main () {
    FILE * fp; // fp é um ponteiro para arquivo 
    fp = fopen("teste.txt", "w"); // abre o texto.txt para escrita 

    if(fp == NULL){
        printf("ERRO ao abrir arquivo\n");
        exit(1);
    }

    printf("Arquivo aberto/criado!\n");

    fclose(fp);

    return 0;
}