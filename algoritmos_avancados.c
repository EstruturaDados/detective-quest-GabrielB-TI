#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Sala {
    char nome[50];
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;

// Função que cria uma nova sala
Sala* criarSala(const char *nome) {
    Sala* nova = (Sala*) malloc(sizeof(Sala));
    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

// Função que cria toda a árvore da mansão
Sala* criarMansao() {
    // Nó raiz
    Sala* hall = criarSala("Hall de Entrada");

    // Primeira ramificação
    hall->esquerda = criarSala("Sala de Estar");
    hall->direita  = criarSala("Cozinha");

    // Subárvore esquerda
    hall->esquerda->esquerda = criarSala("Biblioteca");
    hall->esquerda->direita  = criarSala("Jardim");

    // Subárvore direita
    hall->direita->esquerda = criarSala("Despensa");
    hall->direita->direita  = criarSala("Garagem");

    return hall;
}

