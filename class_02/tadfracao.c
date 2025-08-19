#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int Num;
    int Den;
} Fracao;

int calcularMDC(int A, int B);
Fracao simplificarFracao(Fracao F);
Fracao criarFracao(int N, int D);
void exibirFracao(Fracao F);
Fracao somarFracao(Fracao F, Fracao G);
Fracao subtrairFracao(Fracao F, Fracao G);
Fracao multiplicarFracao(Fracao F, Fracao G);
Fracao dividirFracao(Fracao F, Fracao G);

int main(){

    system("cls");

    Fracao F1 = criarFracao(24,30);
    F1 = simplificarFracao(F1);
    exibirFracao(F1); // será exibido 4/5
    
    Fracao F2 = criarFracao(-30,40);
    F2 = simplificarFracao(F2);
    exibirFracao(F2); // será exibido -3 /4

    Fracao F3 = criarFracao(37,42);
    F3 = simplificarFracao(F3);
    exibirFracao(F3); // será exibido 37/42

    Fracao F4 = criarFracao(5,6);
    Fracao F5 = criarFracao(4,9);
    Fracao F6 = somarFracao(F4, F5);
    exibirFracao(F6);    

    Fracao F7 = criarFracao(5,6);
    Fracao F8 = criarFracao(4,9);
    Fracao F9 = subtrairFracao(F7, F8);
    exibirFracao(F9);

    Fracao F10 = criarFracao(5,6);
    Fracao F11 = criarFracao(4,9);
    Fracao F12 = multiplicarFracao(F10, F11);
    exibirFracao(F12);    

    Fracao F13 = criarFracao(5,6);
    Fracao F14 = criarFracao(4,9);
    Fracao F15 = dividirFracao(F13, F14);
    exibirFracao(F15);

    Fracao exercicio1 = criarFracao(3,4);
    Fracao exercicio2 = criarFracao(7,9);
    Fracao exercicio3 = criarFracao(5,12);
    Fracao resultadoexercicio12 = subtrairFracao(exercicio1,exercicio2);
    Fracao resultadoexercicio123 = somarFracao(resultadoexercicio12, exercicio3);
    exibirFracao(resultadoexercicio123);
    


    return 0;
}

int calcularMDC(int A, int B){ 

    if (A < 0) A = -A;
    if (B < 0) B = -B;

    while(A % B != 0){
        int temp = A;
        A = B;
        B = temp % B;
    }
    
    return(B);
}

Fracao simplificarFracao(Fracao F){
    int mdc = calcularMDC(F.Num, F.Den);
    F.Num /= mdc;
    F.Den /= mdc;
    
    return F;
}

Fracao criarFracao(int N, int D){
    Fracao F;
    F.Num = N;
    F.Den = D;
    return F;
}

void exibirFracao(Fracao F){
    printf("%d / %d \n", F.Num, F.Den);
    return ; 
}

Fracao somarFracao(Fracao F, Fracao G){
    Fracao respostasoma;
    respostasoma.Den = F.Den * G.Den;
    respostasoma.Num = (F.Num * G.Den) + (G.Num * F.Den);
    respostasoma = simplificarFracao(respostasoma);
    return respostasoma;
}

Fracao subtrairFracao(Fracao F, Fracao G){
    Fracao respostasub;
    respostasub.Den =  F.Den * G.Den;
    respostasub.Num = (F.Num * G.Den) - (G.Num * F.Den);
    respostasub = simplificarFracao(respostasub);
    return respostasub;
}

Fracao multiplicarFracao(Fracao F, Fracao G){
    Fracao respostamult;
    respostamult.Den = F.Den * G.Den;
    respostamult.Num = F.Num * G.Num;
    respostamult = simplificarFracao(respostamult);
    return respostamult;
}

Fracao dividirFracao(Fracao F, Fracao G){
    Fracao respostadiv;
    respostadiv.Den = F.Den * G.Num;
    respostadiv.Num = F.Num * G.Den;
    respostadiv = simplificarFracao(respostadiv);
    return respostadiv;
}