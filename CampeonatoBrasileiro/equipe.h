/*Definição do Tipo Abstrato de dados EQUIPE*/

#ifndef EQUIPE_H
#define EQUIPE_H

#define NumeroEquipes 20

typedef struct {
    int Pos; // Posição (ou classificação da equip no campeonato)
    char Estado [30];
    char Time [50];
    int Pts; // Número de pontos conquistados = 3 * V + 1 * E
    int J; // Jogos
    int V; // Vitórias  
    int E; // Empates
    int D; // Derrotas 
    int GP; // Gols pró (marcados)
    int GC; // Gols contra (sofridos)
    int SG; // Saldo de Gols = GP - GC 
    float Aproveitamento; // Aproveitamento = Pts / (3 * J)
} Equipe;

/* Retorna o vetor de equipes (Equipe *) associado ao arquivo (NomeArquivo) */

Equipe * LeDados(char * NomeArquivo);




#endif