# 🎯 AULA 05: Listas Dinâmicas (Encadeadas)

[![YouTube](https://img.shields.io/badge/▶️-Assista%20no%20YouTube-red.svg)](https://www.youtube.com/watch?v=0aoF8fQjchM)

> 🎯 **Objetivo**: Introduzir o conceito de Listas Dinâmicas (Encadeadas), contrastando-as com estruturas estáticas e demonstrando implementação prática em C.

---

## 📋 Agenda da Aula

1. [Introdução Conceitual](#1-introdução-conceitual-às-listas-dinâmicas)
2. [Componentes Fundamentais: O "Nó"](#2-componentes-fundamentais-o-nó-node)
3. [Vantagens vs. Vetores](#3-vantagens-e-comparação-com-vetores-arrays)
4. [Implementação em C](#4-implementação-em-linguagem-c)
5. [Variações de Listas](#5-variações-de-listas-dinâmicas)

---

## 1. 🎯 Introdução Conceitual às Listas Dinâmicas

### 🎨 Analogia Principal
> **Lista de Compras Flexível**: Diferente de uma folha de papel com espaço limitado (vetor), uma lista dinâmica é como usar vários "post-its", onde cada um aponta para o próximo, permitindo adicionar novos itens infinitamente.

### 📋 Definição
> **Lista Dinâmica**: Uma estrutura de dados onde os elementos são **encadeados** (ligados) por meio de **ponteiros**. Eles não precisam estar em posições de memória sequenciais.

### ✨ Características Principais
- **Flexibilidade**: Cresce e diminui conforme a necessidade
- **Encadeamento**: Elementos conectados por ponteiros
- **Não Sequencial**: Elementos podem estar em qualquer lugar da memória
- **Inserção/Remoção Eficiente**: Apenas reajuste de ponteiros

---

## 2. 🧩 Componentes Fundamentais: O "Nó" (Node)

### 🏗️ Estrutura de um Nó
Cada elemento de uma lista dinâmica é chamado de **Nó** e funciona como um "pacote" de informações.

#### 📦 Componentes do Nó:
1. **Dado (Data)**: A informação útil que se deseja armazenar
2. **Ponteiro (Pointer)**: O "endereço" que aponta para o próximo nó

### 🎯 Visualização de um Nó
```
┌─────────────┬───────────────┐
│    DADO     │   PONTEIRO    │
│   (ex: 10)  │ (-> próximo)  │
└─────────────┴───────────────┘
```

### 🔗 Lista Encadeada Simples
```
INÍCIO
  │
  ▼
┌─────┬───┐    ┌─────┬───┐    ┌─────┬───┐    ┌─────┬───┐
│ 10  │ •─┼───▶│ 20  │ •─┼───▶│ 30  │ •─┼───▶│ 40  │ ∅ │
└─────┴───┘    └─────┴───┘    └─────┴───┘    └─────┴───┘
  nó 1           nó 2           nó 3           nó 4
                                               (fim)
```

### 🚩 Marcação do Fim
- O último nó tem seu ponteiro apontando para **NULL**
- Indica que a sequência terminou
- Evita acessos inválidos

---

## 3. 📊 Vantagens e Comparação com Vetores (Arrays)

### 🥊 Listas Dinâmicas vs. Vetores

| **Característica** | **Listas Dinâmicas** | **Vetores (Arrays)** |
|-------------------|----------------------|----------------------|
| **Tamanho** | 🎨 **Flexível** - Cresce/diminui em runtime | 🔒 **Fixo** - Definido na compilação |
| **Uso de Memória** | 💡 **Eficiente** - Só aloca o necessário | ⚠️ **Potencialmente ineficiente** - Reserva bloco fixo |
| **Inserção/Remoção** | 🚀 **Muito eficiente** - Apenas reajusta ponteiros | 🐌 **Custosa** - Desloca múltiplos elementos |
| **Acesso a Elementos** | 🐌 **Sequencial** - Percorre desde o início | 🚀 **Direto (Indexado)** - Acesso instantâneo |
| **Overhead de Memória** | ⚠️ **Ponteiros extras** - Cada nó tem ponteiro | 💡 **Mínimo** - Apenas os dados |

### 🎯 Exemplo Prático: Inserção no Meio

#### 🐌 Inserção em Vetor (Custosa)
```
Vetor inicial: [10][20][30][40][50]
Inserir 25 na posição 2:

Passo 1: Deslocar elementos
[10][20][  ][30][40][50]  ← Abrir espaço
         ↑
    Inserir aqui

Passo 2: Inserir novo elemento  
[10][20][25][30][40][50]

Custo: O(n) - precisa mover n-2 elementos
```

#### 🚀 Inserção em Lista (Eficiente)
```
Lista inicial: [10]→[20]→[30]→[40]→NULL
Inserir 25 entre 20 e 30:

Passo 1: Criar novo nó
[25]→[30]

Passo 2: Reajustar ponteiros
[10]→[20]→[25]→[30]→[40]→NULL
         ↑    ↑
       Novo   Antiga
      ligação ligação

Custo: O(1) - apenas reajuste de ponteiros
```

---

## 4. 💻 Implementação em Linguagem C

### 🏗️ Definição da Estrutura

```c
#include <stdio.h>
#include <stdlib.h>

// Definição do nó
struct Node {
    int data;           // Onde a informação é guardada
    struct Node *next;  // Ponteiro para o próximo nó
};

// Typedef para facilitar o uso
typedef struct Node Node;
```

### 🔧 Operações Fundamentais

#### 1. **Criar um Novo Nó**
```c
Node* criar_no(int valor) {
    // Aloca memória para um novo nó
    Node* novo_no = malloc(sizeof(Node));
    
    if (novo_no == NULL) {  // Verificação de segurança
        printf("Erro: Falha na alocação de memória!\n");
        return NULL;
    }
    
    // Inicializa o nó
    novo_no->data = valor;
    novo_no->next = NULL;
    
    return novo_no;
}
```

#### 2. **Inserir no Início**
```c
Node* inserir_inicio(Node* head, int valor) {
    Node* novo_no = criar_no(valor);
    
    if (novo_no == NULL) return head;  // Falha na criação
    
    // O novo nó aponta para o antigo primeiro
    novo_no->next = head;
    
    // O novo nó se torna o primeiro
    return novo_no;  // Novo head
}
```

#### 3. **Inserir no Final**
```c
Node* inserir_final(Node* head, int valor) {
    Node* novo_no = criar_no(valor);
    
    if (novo_no == NULL) return head;  // Falha na criação
    
    // Lista vazia: novo nó é o primeiro
    if (head == NULL) {
        return novo_no;
    }
    
    // Encontrar o último nó
    Node* atual = head;
    while (atual->next != NULL) {
        atual = atual->next;
    }
    
    // Conectar o novo nó ao final
    atual->next = novo_no;
    
    return head;  // Head não muda
}
```

#### 4. **Remover Elemento**
```c
Node* remover_elemento(Node* head, int valor) {
    if (head == NULL) return NULL;  // Lista vazia
    
    // Remoção do primeiro elemento
    if (head->data == valor) {
        Node* novo_head = head->next;
        free(head);
        return novo_head;
    }
    
    // Buscar o elemento no meio/final
    Node* atual = head;
    while (atual->next != NULL && atual->next->data != valor) {
        atual = atual->next;
    }
    
    // Elemento encontrado
    if (atual->next != NULL) {
        Node* no_removido = atual->next;
        atual->next = no_removido->next;  // Pula o nó removido
        free(no_removido);               // Libera memória
    }
    
    return head;
}
```

#### 5. **Imprimir Lista**
```c
void imprimir_lista(Node* head) {
    printf("Lista: ");
    
    Node* atual = head;
    while (atual != NULL) {
        printf("[%d] ", atual->data);
        if (atual->next != NULL) {
            printf("→ ");
        }
        atual = atual->next;
    }
    
    printf("→ NULL\n");
}
```

#### 6. **Liberar Toda a Lista**
```c
void liberar_lista(Node* head) {
    Node* atual = head;
    Node* proximo;
    
    while (atual != NULL) {
        proximo = atual->next;  // Salva referência do próximo
        free(atual);           // Libera o nó atual
        atual = proximo;       // Avança para o próximo
    }
    
    printf("Lista liberada da memória.\n");
}
```

### 🎮 Exemplo de Uso Completo

```c
int main() {
    Node* lista = NULL;  // Lista inicialmente vazia
    
    printf("🎯 Demonstração de Lista Dinâmica\n\n");
    
    // Inserções
    printf("📥 Inserindo elementos:\n");
    lista = inserir_final(lista, 10);
    lista = inserir_final(lista, 20);
    lista = inserir_final(lista, 30);
    imprimir_lista(lista);
    
    lista = inserir_inicio(lista, 5);
    printf("Após inserir 5 no início:\n");
    imprimir_lista(lista);
    
    // Remoção
    printf("\n🗑️ Removendo elemento 20:\n");
    lista = remover_elemento(lista, 20);
    imprimir_lista(lista);
    
    // Limpeza
    printf("\n🧹 Liberando memória:\n");
    liberar_lista(lista);
    
    return 0;
}
```

---

## 5. 🎨 Variações de Listas Dinâmicas

### 1. 🔄 Lista Duplamente Encadeada

**🎯 Características:**
- Cada nó possui **dois ponteiros**: `next` e `previous`
- Permite navegação em **ambas as direções**

#### 🏗️ Estrutura:
```c
struct NodeDuplo {
    int data;
    struct NodeDuplo *next;     // Próximo nó
    struct NodeDuplo *previous; // Nó anterior
};
```

#### 🎯 Visualização:
```
NULL ←─┬─────┬─→ ←─┬─────┬─→ ←─┬─────┬─→ ←─┬─────┬─ NULL
       │ 10  │     │ 20  │     │ 30  │     │ 40  │
       └─────┘     └─────┘     └─────┘     └─────┘
```

**✅ Vantagens:**
- Navegação bidirecional
- Remoção mais eficiente (não precisa percorrer desde o início)

**⚠️ Desvantagens:**
- Maior uso de memória (ponteiro extra)
- Lógica mais complexa para manutenção

### 2. 🔄 Lista Circular

**🎯 Características:**
- O ponteiro do **último elemento** aponta para o **primeiro**
- Não há `NULL` no final
- Cria um **ciclo** contínuo

#### 🎯 Visualização:
```
     ┌─────┐    ┌─────┐    ┌─────┐    ┌─────┐
  ┌─▶│ 10  │───▶│ 20  │───▶│ 30  │───▶│ 40  │─┐
  │  └─────┘    └─────┘    └─────┘    └─────┘ │
  └─────────────────────────────────────────────┘
```

**✅ Aplicações:**
- Carrossel de fotos
- Round-robin em sistemas operacionais
- Jogos com turnos circulares

---

## 🎮 Exemplo Prático Avançado: Lista de Tarefas

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura mais complexa: nó com dados heterogêneos
struct Task {
    char titulo[50];
    char descricao[100];
    int completada;        // 0 = não, 1 = sim
    struct Task *next;
};

typedef struct Task Task;

// Criar nova tarefa
Task* criar_tarefa(char* titulo, char* descricao) {
    Task* nova_tarefa = malloc(sizeof(Task));
    
    if (nova_tarefa == NULL) return NULL;
    
    strcpy(nova_tarefa->titulo, titulo);
    strcpy(nova_tarefa->descricao, descricao);
    nova_tarefa->completada = 0;  // Inicialmente não completada
    nova_tarefa->next = NULL;
    
    return nova_tarefa;
}

// Adicionar tarefa à lista
Task* adicionar_tarefa(Task* head, char* titulo, char* descricao) {
    Task* nova_tarefa = criar_tarefa(titulo, descricao);
    
    if (nova_tarefa == NULL) return head;
    
    // Inserir no início (mais eficiente)
    nova_tarefa->next = head;
    return nova_tarefa;
}

// Imprimir todas as tarefas
void imprimir_tarefas(Task* head) {
    printf("\n📋 Lista de Tarefas:\n");
    printf("=====================================\n");
    
    Task* atual = head;
    int contador = 1;
    
    while (atual != NULL) {
        printf("%d. [%s] %s\n", 
               contador,
               atual->completada ? "✅" : "⏳",
               atual->titulo);
        printf("   Descrição: %s\n", atual->descricao);
        printf("\n");
        
        atual = atual->next;
        contador++;
    }
    
    if (head == NULL) {
        printf("   Nenhuma tarefa cadastrada.\n");
    }
}

// Exemplo de uso da lista de tarefas
void exemplo_lista_tarefas() {
    Task* lista_tarefas = NULL;
    
    printf("🎯 Sistema de Lista de Tarefas\n");
    
    // Adicionar tarefas
    lista_tarefas = adicionar_tarefa(lista_tarefas, 
                                   "Estudar Listas", 
                                   "Revisar conceitos de listas dinâmicas");
    
    lista_tarefas = adicionar_tarefa(lista_tarefas, 
                                   "Fazer Exercícios", 
                                   "Implementar 3 exercícios práticos");
    
    lista_tarefas = adicionar_tarefa(lista_tarefas, 
                                   "Projeto Final", 
                                   "Desenvolver aplicação usando estruturas");
    
    // Mostrar tarefas
    imprimir_tarefas(lista_tarefas);
    
    // Completar uma tarefa
    if (lista_tarefas != NULL) {
        lista_tarefas->completada = 1;  // Marca primeira como completa
        printf("✅ Tarefa '%s' marcada como completa!\n", lista_tarefas->titulo);
    }
    
    // Mostrar tarefas atualizadas
    imprimir_tarefas(lista_tarefas);
    
    // Liberar memória (simplificado)
    // ... código de liberação ...
}
```

---

## 🎓 Resumo da Aula

### ✅ Conceitos Aprendidos

1. **🧩 Estrutura do Nó**: Dado + ponteiro para próximo
2. **🔗 Encadeamento**: Elementos conectados por ponteiros
3. **🎨 Flexibilidade**: Tamanho dinâmico, adaptável
4. **⚡ Eficiência**: Inserção/remoção O(1) com ponteiro correto
5. **🎯 Implementação**: Operações básicas em C
6. **🔄 Variações**: Lista dupla e circular

### 🎯 Próxima Aula

**Aula 06**: [Pilhas e Filas com Listas Dinâmicas](./aula06-pilhas-filas-dinamicas.md) - Combinando conceitos

---

## 🛠️ Exercícios Práticos

### 🎯 Exercício 1: Lista de Números
Implemente uma lista dinâmica que permite inserir números em ordem crescente.

### 🎯 Exercício 2: Lista de Strings
Crie uma lista de nomes que permite busca por nome específico.

### 🎯 Exercício 3: Lista Duplamente Encadeada
Implemente uma lista duplamente encadeada com navegação bidirecional.

---

## 🔗 Links Úteis

- [📁 Exemplos de Listas](../exemplos-praticos/listas/)
- [🧩 Exercícios Práticos](../exercicios/)
- [📚 Recursos sobre Ponteiros](../recursos/)

---

📅 **Data**: Aula Ao Vivo 5  
🎥 **Vídeo**: [YouTube](https://www.youtube.com/watch?v=0aoF8fQjchM)  
⏰ **Duração**: ~60 minutos
