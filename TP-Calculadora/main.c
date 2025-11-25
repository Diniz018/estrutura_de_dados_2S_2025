// main.c - para testes locais apenas
#include <stdio.h>
#include <string.h>
#include "expressao.h"

int main() {
    char expr[512];

    printf("\nDigite expressao POS-FIXA: ");
    fgets(expr, 512, stdin);

    expr[strcspn(expr, "\n")] = '\0';

    char *infixa = getFormaInFixa(expr);
    float valor = getValorPosFixa(expr);

    printf("\nForma Infixa : %s", infixa ? infixa : "ERRO");
    printf("\nValor        : %f\n", valor);

    return 0;
}
