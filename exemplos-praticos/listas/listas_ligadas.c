/**
 * 🎯 EXEMPLO PRÁTICO: Listas Ligadas (Dinâmicas)
 * 
 * Este programa demonstra implementações de:
 * - Lista Ligada Simples
 * - Lista Duplamente Ligada
 * - Lista de Tarefas (aplicação prática)
 * - Operações fundamentais: inserir, remover, buscar
 * 
 * Compile: gcc listas_ligadas.c -o listas_ligadas
 * Execute: ./listas_ligadas
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// ===== LISTA LIGADA SIMPLES =====

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Criar novo nó
Node* criar_no(int valor) {
    Node* novo = malloc(sizeof(Node));
    if (novo == NULL) {
        printf("❌ Erro: Falha na alocação de memória!\n");
        return NULL;
    }
    novo->data = valor;
    novo->next = NULL;
    return novo;
}

// Inserir no início
Node* inserir_inicio(Node* head, int valor) {
    Node* novo = criar_no(valor);
    if (novo == NULL) return head;
    
    novo->next = head;
    printf("✅ Inserido %d no início\n", valor);
    return novo;  // Novo head
}

// Inserir no final
Node* inserir_final(Node* head, int valor) {
    Node* novo = criar_no(valor);
    if (novo == NULL) return head;
    
    // Lista vazia
    if (head == NULL) {
        printf("✅ Inserido %d em lista vazia\n", valor);
        return novo;
    }
    
    // Encontrar último nó
    Node* atual = head;
    while (atual->next != NULL) {
        atual = atual->next;
    }
    
    atual->next = novo;
    printf("✅ Inserido %d no final\n", valor);
    return head;
}

// Inserir em posição específica
Node* inserir_posicao(Node* head, int valor, int posicao) {
    if (posicao == 0) {
        return inserir_inicio(head, valor);
    }
    
    Node* novo = criar_no(valor);
    if (novo == NULL) return head;
    
    Node* atual = head;
    for (int i = 0; i < posicao - 1 && atual != NULL; i++) {
        atual = atual->next;
    }
    
    if (atual == NULL) {
        printf("❌ Posição %d inválida\n", posicao);
        free(novo);
        return head;
    }
    
    novo->next = atual->next;
    atual->next = novo;
    printf("✅ Inserido %d na posição %d\n", valor, posicao);
    return head;
}

// Remover elemento por valor
Node* remover_valor(Node* head, int valor) {
    if (head == NULL) {
        printf("❌ Lista vazia, não é possível remover %d\n", valor);
        return NULL;
    }
    
    // Remover primeiro elemento
    if (head->data == valor) {
        Node* novo_head = head->next;
        free(head);
        printf("✅ Removido %d (era o primeiro)\n", valor);
        return novo_head;
    }
    
    // Buscar elemento no meio/final
    Node* atual = head;
    while (atual->next != NULL && atual->next->data != valor) {
        atual = atual->next;
    }
    
    if (atual->next == NULL) {
        printf("❌ Valor %d não encontrado na lista\n", valor);
        return head;
    }
    
    Node* removido = atual->next;
    atual->next = removido->next;
    free(removido);
    printf("✅ Removido %d da lista\n", valor);
    return head;
}

// Buscar elemento
bool buscar_valor(Node* head, int valor) {
    Node* atual = head;
    int posicao = 0;
    
    while (atual != NULL) {
        if (atual->data == valor) {
            printf("✅ Valor %d encontrado na posição %d\n", valor, posicao);
            return true;
        }
        atual = atual->next;
        posicao++;
    }
    
    printf("❌ Valor %d não encontrado\n", valor);
    return false;
}

// Contar elementos
int contar_elementos(Node* head) {
    int count = 0;
    Node* atual = head;
    while (atual != NULL) {
        count++;
        atual = atual->next;
    }
    return count;
}

// Imprimir lista
void imprimir_lista(Node* head) {
    if (head == NULL) {
        printf("Lista: [VAZIA]\n");
        return;
    }
    
    printf("Lista: ");
    Node* atual = head;
    while (atual != NULL) {
        printf("[%d]", atual->data);
        if (atual->next != NULL) {
            printf(" → ");
        }
        atual = atual->next;
    }
    printf(" → NULL\n");
}

// Liberar lista
void liberar_lista(Node* head) {
    Node* atual = head;
    Node* proximo;
    int liberados = 0;
    
    while (atual != NULL) {
        proximo = atual->next;
        free(atual);
        atual = proximo;
        liberados++;
    }
    
    printf("🗑️ Liberados %d nós da memória\n", liberados);
}

// ===== LISTA DUPLAMENTE LIGADA =====

typedef struct NodeDuplo {
    int data;
    struct NodeDuplo* next;
    struct NodeDuplo* prev;
} NodeDuplo;

// Criar nó duplo
NodeDuplo* criar_no_duplo(int valor) {
    NodeDuplo* novo = malloc(sizeof(NodeDuplo));
    if (novo == NULL) return NULL;
    
    novo->data = valor;
    novo->next = NULL;
    novo->prev = NULL;
    return novo;
}

// Inserir no início (lista dupla)
NodeDuplo* inserir_inicio_duplo(NodeDuplo* head, int valor) {
    NodeDuplo* novo = criar_no_duplo(valor);
    if (novo == NULL) return head;
    
    if (head != NULL) {
        head->prev = novo;
    }
    novo->next = head;
    
    printf("✅ Inserido %d no início (lista dupla)\n", valor);
    return novo;
}

// Imprimir lista dupla (frente para trás)
void imprimir_lista_dupla_frente(NodeDuplo* head) {
    printf("Lista Dupla (→): ");
    if (head == NULL) {
        printf("[VAZIA]\n");
        return;
    }
    
    NodeDuplo* atual = head;
    while (atual != NULL) {
        printf("[%d]", atual->data);
        if (atual->next != NULL) {
            printf(" ↔ ");
        }
        atual = atual->next;
    }
    printf(" ↔ NULL\n");
}

// Imprimir lista dupla (trás para frente)
void imprimir_lista_dupla_tras(NodeDuplo* head) {
    if (head == NULL) {
        printf("Lista Dupla (←): [VAZIA]\n");
        return;
    }
    
    // Ir até o final
    NodeDuplo* atual = head;
    while (atual->next != NULL) {
        atual = atual->next;
    }
    
    printf("Lista Dupla (←): ");
    while (atual != NULL) {
        printf("[%d]", atual->data);
        if (atual->prev != NULL) {
            printf(" ↔ ");
        }
        atual = atual->prev;
    }
    printf(" ↔ NULL\n");
}

// ===== LISTA DE TAREFAS (APLICAÇÃO PRÁTICA) =====

typedef struct Task {
    char titulo[50];
    char descricao[100];
    int prioridade;    // 1=baixa, 2=média, 3=alta
    bool concluida;
    struct Task* next;
} Task;

// Criar nova tarefa
Task* criar_tarefa(const char* titulo, const char* descricao, int prioridade) {
    Task* nova = malloc(sizeof(Task));
    if (nova == NULL) return NULL;
    
    strncpy(nova->titulo, titulo, sizeof(nova->titulo) - 1);
    nova->titulo[sizeof(nova->titulo) - 1] = '\0';
    
    strncpy(nova->descricao, descricao, sizeof(nova->descricao) - 1);
    nova->descricao[sizeof(nova->descricao) - 1] = '\0';
    
    nova->prioridade = prioridade;
    nova->concluida = false;
    nova->next = NULL;
    
    return nova;
}

// Adicionar tarefa (ordenada por prioridade)
Task* adicionar_tarefa(Task* head, const char* titulo, const char* descricao, int prioridade) {
    Task* nova = criar_tarefa(titulo, descricao, prioridade);
    if (nova == NULL) return head;
    
    // Lista vazia ou nova tarefa tem prioridade maior
    if (head == NULL || nova->prioridade > head->prioridade) {
        nova->next = head;
        printf("✅ Tarefa '%s' adicionada (prioridade %d)\n", titulo, prioridade);
        return nova;
    }
    
    // Encontrar posição correta
    Task* atual = head;
    while (atual->next != NULL && atual->next->prioridade >= nova->prioridade) {
        atual = atual->next;
    }
    
    nova->next = atual->next;
    atual->next = nova;
    printf("✅ Tarefa '%s' adicionada (prioridade %d)\n", titulo, prioridade);
    return head;
}

// Marcar tarefa como concluída
void concluir_tarefa(Task* head, const char* titulo) {
    Task* atual = head;
    while (atual != NULL) {
        if (strcmp(atual->titulo, titulo) == 0) {
            atual->concluida = true;
            printf("✅ Tarefa '%s' marcada como concluída!\n", titulo);
            return;
        }
        atual = atual->next;
    }
    printf("❌ Tarefa '%s' não encontrada\n", titulo);
}

// Imprimir lista de tarefas
void imprimir_tarefas(Task* head) {
    printf("\n📋 LISTA DE TAREFAS\n");
    printf("==========================================\n");
    
    if (head == NULL) {
        printf("Nenhuma tarefa cadastrada.\n");
        return;
    }
    
    Task* atual = head;
    int contador = 1;
    
    while (atual != NULL) {
        const char* prioridade_str;
        switch (atual->prioridade) {
            case 3: prioridade_str = "🔴 ALTA"; break;
            case 2: prioridade_str = "🟡 MÉDIA"; break;
            case 1: prioridade_str = "🟢 BAIXA"; break;
            default: prioridade_str = "❓ INDEFINIDA"; break;
        }
        
        printf("%d. [%s] %s - %s\n", 
               contador,
               atual->concluida ? "✅" : "⏳",
               atual->titulo,
               prioridade_str);
        
        printf("   📝 %s\n\n", atual->descricao);
        
        atual = atual->next;
        contador++;
    }
}

// Demonstração das operações
void demonstrar_lista_simples() {
    printf("🎯 DEMONSTRAÇÃO: Lista Ligada Simples\n");
    printf("=====================================\n");
    
    Node* lista = NULL;
    
    // Inserções
    printf("\n📥 Inserindo elementos:\n");
    lista = inserir_final(lista, 10);
    lista = inserir_final(lista, 20);
    lista = inserir_final(lista, 30);
    imprimir_lista(lista);
    
    lista = inserir_inicio(lista, 5);
    printf("Após inserir 5 no início:\n");
    imprimir_lista(lista);
    
    lista = inserir_posicao(lista, 15, 2);
    printf("Após inserir 15 na posição 2:\n");
    imprimir_lista(lista);
    
    // Buscas
    printf("\n🔍 Buscando elementos:\n");
    buscar_valor(lista, 20);
    buscar_valor(lista, 99);
    
    printf("Total de elementos: %d\n", contar_elementos(lista));
    
    // Remoções
    printf("\n🗑️ Removendo elementos:\n");
    lista = remover_valor(lista, 15);
    lista = remover_valor(lista, 5);
    imprimir_lista(lista);
    
    // Limpeza
    printf("\n🧹 Liberando memória:\n");
    liberar_lista(lista);
}

void demonstrar_lista_dupla() {
    printf("\n🎯 DEMONSTRAÇÃO: Lista Duplamente Ligada\n");
    printf("========================================\n");
    
    NodeDuplo* lista_dupla = NULL;
    
    printf("\n📥 Inserindo elementos:\n");
    lista_dupla = inserir_inicio_duplo(lista_dupla, 30);
    lista_dupla = inserir_inicio_duplo(lista_dupla, 20);
    lista_dupla = inserir_inicio_duplo(lista_dupla, 10);
    
    printf("\n📊 Visualizando em ambas as direções:\n");
    imprimir_lista_dupla_frente(lista_dupla);
    imprimir_lista_dupla_tras(lista_dupla);
}

void demonstrar_lista_tarefas() {
    printf("\n🎯 DEMONSTRAÇÃO: Sistema de Tarefas\n");
    printf("===================================\n");
    
    Task* tarefas = NULL;
    
    // Adicionar tarefas com diferentes prioridades
    tarefas = adicionar_tarefa(tarefas, "Estudar Listas", "Revisar conceitos de listas ligadas", 2);
    tarefas = adicionar_tarefa(tarefas, "Bug Crítico", "Corrigir falha no sistema de login", 3);
    tarefas = adicionar_tarefa(tarefas, "Documentação", "Atualizar README do projeto", 1);
    tarefas = adicionar_tarefa(tarefas, "Reunião", "Reunião de planejamento da sprint", 2);
    tarefas = adicionar_tarefa(tarefas, "Backup", "Fazer backup do servidor", 3);
    
    imprimir_tarefas(tarefas);
    
    // Concluir algumas tarefas
    printf("🎯 Concluindo tarefas:\n");
    concluir_tarefa(tarefas, "Bug Crítico");
    concluir_tarefa(tarefas, "Documentação");
    
    imprimir_tarefas(tarefas);
}

int main() {
    printf("🎯 ESTRUTURAS DINÂMICAS: LISTAS LIGADAS\n");
    printf("========================================\n");
    
    // Demonstrações
    demonstrar_lista_simples();
    demonstrar_lista_dupla();
    demonstrar_lista_tarefas();
    
    printf("\n\n🎓 RESUMO DOS CONCEITOS\n");
    printf("========================\n");
    printf("🔗 LISTA LIGADA SIMPLES:\n");
    printf("   • Cada nó contém: DADO + PONTEIRO para próximo\n");
    printf("   • Inserção/remoção eficiente: O(1) com ponteiro correto\n");
    printf("   • Acesso sequencial: O(n) para buscar elemento\n\n");
    
    printf("🔄 LISTA DUPLAMENTE LIGADA:\n");
    printf("   • Cada nó contém: ANTERIOR + DADO + PRÓXIMO\n");
    printf("   • Navegação bidirecional\n");
    printf("   • Maior uso de memória, mais flexibilidade\n\n");
    
    printf("💡 VANTAGENS:\n");
    printf("   • Tamanho dinâmico (cresce/diminui conforme necessário)\n");
    printf("   • Inserção/remoção eficiente em qualquer posição\n");
    printf("   • Uso eficiente de memória (só aloca o necessário)\n\n");
    
    printf("⚠️ DESVANTAGENS:\n");
    printf("   • Acesso sequencial (não há acesso direto por índice)\n");
    printf("   • Overhead de memória (ponteiros extras)\n");
    printf("   • Cache-unfriendly (elementos podem estar espalhados)\n\n");
    
    printf("🎯 Use listas ligadas quando:\n");
    printf("   • Tamanho dos dados é imprevisível\n");
    printf("   • Inserções/remoções são frequentes\n");
    printf("   • Não precisa de acesso aleatório rápido\n");
    
    return 0;
}
