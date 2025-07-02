/**
 * 🎯 EXEMPLO PRÁTICO: Lista Duplamente Ligada e Circular
 *
 * Demonstra:
 * - Lista duplamente ligada
 * - Lista circular
 * - Inserção, remoção, busca, navegação
 * - Aplicação lúdica: playlist de músicas
 *
 * Compile: gcc listas_dupla_circular.c -o listas_dupla_circular
 * Execute: ./listas_dupla_circular
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NOME 50

// ===== ESTRUTURA DE NÓ =====
typedef struct No {
    char nome[MAX_NOME];
    struct No* prox;
    struct No* ant;
} No;

// ===== ESTRUTURA DA LISTA =====
typedef struct {
    No* inicio;
    No* fim;
    int tamanho;
    bool circular;
} ListaDupla;

// ===== FUNÇÕES DE LISTA =====

ListaDupla* criar_lista(bool circular) {
    ListaDupla* lista = malloc(sizeof(ListaDupla));
    lista->inicio = lista->fim = NULL;
    lista->tamanho = 0;
    lista->circular = circular;
    return lista;
}

No* criar_no(const char* nome) {
    No* novo = malloc(sizeof(No));
    strcpy(novo->nome, nome);
    novo->prox = novo->ant = NULL;
    return novo;
}

void inserir_final(ListaDupla* lista, const char* nome) {
    No* novo = criar_no(nome);
    if (!lista->inicio) {
        lista->inicio = lista->fim = novo;
        if (lista->circular) {
            novo->prox = novo->ant = novo;
        }
    } else {
        novo->ant = lista->fim;
        novo->prox = lista->circular ? lista->inicio : NULL;
        lista->fim->prox = novo;
        if (lista->circular) lista->inicio->ant = novo;
        lista->fim = novo;
    }
    lista->tamanho++;
    printf("✅ Música '%s' adicionada à playlist!\n", nome);
}

void remover_nome(ListaDupla* lista, const char* nome) {
    if (!lista->inicio) return;
    No* atual = lista->inicio;
    int i = 0;
    do {
        if (strcmp(atual->nome, nome) == 0) {
            if (atual == lista->inicio) lista->inicio = atual->prox;
            if (atual == lista->fim) lista->fim = atual->ant;
            if (atual->ant) atual->ant->prox = atual->prox;
            if (atual->prox) atual->prox->ant = atual->ant;
            free(atual);
            lista->tamanho--;
            printf("🗑️ Música '%s' removida!\n", nome);
            return;
        }
        atual = atual->prox;
        i++;
    } while (lista->circular ? (atual != lista->inicio && i < lista->tamanho) : atual);
    printf("❌ Música '%s' não encontrada!\n", nome);
}

void exibir_playlist(ListaDupla* lista) {
    if (!lista->inicio) {
        printf("🎵 Playlist vazia!\n");
        return;
    }
    printf("🎶 Playlist (%s):\n", lista->circular ? "Circular" : "Linear");
    No* atual = lista->inicio;
    int i = 1;
    do {
        printf("%2d. %s\n", i++, atual->nome);
        atual = atual->prox;
    } while (lista->circular ? (atual != lista->inicio) : atual);
}

void liberar_lista(ListaDupla* lista) {
    if (!lista->inicio) { free(lista); return; }
    No* atual = lista->inicio;
    int count = 0;
    do {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
        count++;
    } while (lista->circular ? (atual != lista->inicio && count < lista->tamanho) : atual);
    free(lista);
}

// ===== MENU LÚDICO =====
void menu() {
    printf("\n🎵 MENU PLAYLIST\n");
    printf("1. Adicionar música\n");
    printf("2. Remover música\n");
    printf("3. Exibir playlist\n");
    printf("0. Sair\n");
    printf("Escolha: ");
}

int main() {
    printf("🎯 EXEMPLO: LISTA DUPLA E CIRCULAR - PLAYLIST\n");
    int op;
    char nome[MAX_NOME];
    ListaDupla* playlist = criar_lista(true); // Circular
    do {
        menu();
        scanf("%d", &op); getchar();
        switch (op) {
            case 1:
                printf("Nome da música: ");
                fgets(nome, MAX_NOME, stdin);
                nome[strcspn(nome, "\n")] = 0;
                inserir_final(playlist, nome);
                break;
            case 2:
                printf("Nome da música para remover: ");
                fgets(nome, MAX_NOME, stdin);
                nome[strcspn(nome, "\n")] = 0;
                remover_nome(playlist, nome);
                break;
            case 3:
                exibir_playlist(playlist);
                break;
            case 0:
                printf("👋 Saindo...\n");
                break;
            default:
                printf("❌ Opção inválida!\n");
        }
    } while (op != 0);
    liberar_lista(playlist);
    return 0;
}
