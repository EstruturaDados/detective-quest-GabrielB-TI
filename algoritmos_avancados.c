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

void explorarSalas(Sala* atual) {
    char opcao;

    while (atual != NULL) {
        printf("\nVocê está na: %s\n", atual->nome);

        //(sala sem caminhos)
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Fim do caminho! Não há mais portas para explorar.\n");
            break;
        }

        printf("Escolha o caminho:\n");
        if (atual->esquerda != NULL) printf("  (e) Ir para a esquerda -> %s\n", atual->esquerda->nome);
        if (atual->direita  != NULL) printf("  (d) Ir para a direita -> %s\n", atual->direita->nome);
        printf("  (s) Sair da exploração\n");
        printf("Opção: ");
        scanf(" %c", &opcao);

        if (opcao == 'e' && atual->esquerda != NULL) {
            atual = atual->esquerda;
        } 
        else if (opcao == 'd' && atual->direita != NULL) {
            atual = atual->direita;
        } 
        else if (opcao == 's') {
            printf("\nVocê decidiu sair da exploração.\n");
            break;
        } 
        else {
            printf("\nOpção inválida! Tente novamente.\n");
        }
    }
}

// Função principal
int main() {
    Sala* mansao = criarMansao();

    printf("=== Mapa da Mansão com Árvore Binária ===\n");
    explorarSalas(mansao);

    printf("\nExploração encerrada.\n");
    return 0;
}
