#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct {
    char Nome[150]; //Gasta 150 + 1 ("\0") = 151 caracteres
    char Telefone[16]; // 17 caracteres
    char Endereco[200]; // 201 caracteres 
} Pessoa;

int main (){

    Pessoa X;

    strcpy(X.Nome, "Italo Diniz");
    strcpy(X.Telefone, "(61) 98356-8348");
    strcpy(X.Endereco, "Csb 7 Lote 6/7 Tag Sul");
    
    printf("%s\t%s\t\t%s\n", X.Nome, X.Telefone, X.Endereco);
    
    return 0;

}