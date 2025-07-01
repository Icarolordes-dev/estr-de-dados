# 🎯 AULA 04: Estruturas Lineares - Pilhas e Filas

[![YouTube](https://img.shields.io/badge/▶️-Assista%20no%20YouTube-red.svg)](https://www.youtube.com/watch?v=m50hOwEw8BU)

> 🎯 **Objetivo**: Introduzir e diferenciar duas estruturas de dados fundamentais que organizam informações de forma sequencial: pilhas e filas.

---

## 📋 Agenda da Aula

1. [O que são Estruturas Lineares?](#1-o-que-são-estruturas-lineares)
2. [Pilhas (Stacks) - Princípio LIFO](#2-pilhas-stacks-o-princípio-lifo)
3. [Filas (Queues) - Princípio FIFO](#3-filas-queues-o-princípio-fifo)
4. [Comparação Final](#4-comparação-final-pilha-vs-fila)

---

## 1. 📏 O que são Estruturas Lineares?

### 🔗 Definição
> **Estruturas Lineares**: Estruturas de dados onde os elementos são organizados em uma **sequência**, um após o outro.

### ✅ Características
- Cada elemento tem um **antecessor** e um **sucessor** (exceto nas pontas)
- Seguem uma **única linha** de organização
- Acesso sequencial aos elementos

### 🆚 Contraste com Estruturas Não Lineares
- **Lineares**: Pilhas, filas, listas → uma sequência
- **Não Lineares**: Árvores, grafos → um elemento conecta-se a vários outros

---

## 2. 📚 Pilhas (Stacks): O Princípio LIFO

### 🎯 Princípio Fundamental
> **LIFO (Last-In, First-Out)**: O **último a entrar** é o **primeiro a sair**.

### 🥞 Analogia Clássica
**Pilha de Pratos**:
- Você sempre coloca um novo prato no **topo**
- Quando vai pegar um, retira o que está no **topo**
- O último prato colocado é o primeiro a ser retirado

### 🎯 Visualização
```
    ┌─────────┐
    │  TOP    │ ← push/pop acontecem aqui
    │ elem 3  │
    ├─────────┤
    │ elem 2  │
    ├─────────┤
    │ elem 1  │
    └─────────┘
      BASE
```

### 🛠️ Operações Fundamentais

#### 1. `push` (Empilhar)
- **Função**: Adiciona elemento no **topo**
- **Complexidade**: O(1)

```c
void push(Pilha* p, int valor) {
    if (p->topo < MAX_SIZE - 1) {
        p->topo++;
        p->dados[p->topo] = valor;
    }
}
```

#### 2. `pop` (Desempilhar)
- **Função**: Remove e retorna elemento do **topo**
- **Complexidade**: O(1)

```c
int pop(Pilha* p) {
    if (!isEmpty(p)) {
        int valor = p->dados[p->topo];
        p->topo--;
        return valor;
    }
    return -1; // Pilha vazia
}
```

#### 3. `top/peek` (Espiar)
- **Função**: Consulta o topo **sem remover**
- **Complexidade**: O(1)

```c
int top(Pilha* p) {
    if (!isEmpty(p)) {
        return p->dados[p->topo];
    }
    return -1; // Pilha vazia
}
```

#### 4. `isEmpty` (Verificar se vazia)
- **Função**: Verifica se a pilha está vazia
- **Complexidade**: O(1)

```c
bool isEmpty(Pilha* p) {
    return p->topo == -1;
}
```

### 🎮 Implementação em C

```c
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int dados[MAX_SIZE];
    int topo;
} Pilha;

// Inicializar pilha
void inicializar(Pilha* p) {
    p->topo = -1;
}

// Verificar se está vazia
bool isEmpty(Pilha* p) {
    return p->topo == -1;
}

// Verificar se está cheia
bool isFull(Pilha* p) {
    return p->topo == MAX_SIZE - 1;
}

// Empilhar
void push(Pilha* p, int valor) {
    if (isFull(p)) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    p->topo++;
    p->dados[p->topo] = valor;
    printf("Empilhado: %d\n", valor);
}

// Desempilhar
int pop(Pilha* p) {
    if (isEmpty(p)) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    int valor = p->dados[p->topo];
    p->topo--;
    printf("Desempilhado: %d\n", valor);
    return valor;
}
```

### 🌟 Aplicações Reais de Pilhas

#### 1. **🌐 Histórico de Navegador (Botão "Voltar")**
```
Navegação:
Página A → push(A)
Página B → push(B)  
Página C → push(C)

Pilha: [A][B][C] ← topo

Clicar "Voltar": pop() → retorna C, volta para B
```

#### 2. **↩️ Função Desfazer (Ctrl+Z)**
```
Ações do usuário:
Digitar "Hello" → push(DIGITAR, "Hello")
Apagar "o"     → push(APAGAR, "o")
Formatar Bold  → push(FORMATAR, BOLD)

Ctrl+Z: pop() → desfaz formatação
Ctrl+Z: pop() → refaz o "o"
Ctrl+Z: pop() → apaga "Hello"
```

#### 3. **📞 Chamada de Funções**
```c
void funcaoA() {
    // push(funcaoA) na pilha de chamadas
    funcaoB();
    // return: pop(funcaoA)
}

void funcaoB() {
    // push(funcaoB) na pilha de chamadas  
    funcaoC();
    // return: pop(funcaoB)
}

// Pilha de chamadas: [funcaoA][funcaoB][funcaoC]
```

### ⚠️ Limitações das Pilhas

- **Overflow**: Pilha cheia (implementação fixa)
- **Underflow**: Tentar remover de pilha vazia
- **Acesso Limitado**: Só consegue acessar o topo

---

## 3. 🚶‍♀️ Filas (Queues): O Princípio FIFO

### 🎯 Princípio Fundamental
> **FIFO (First-In, First-Out)**: O **primeiro a entrar** é o **primeiro a sair**.

### 🏦 Analogia Clássica
**Fila de Banco**:
- Primeira pessoa que chega é a primeira a ser atendida
- Novos clientes entram no **final**
- Atendimento acontece no **início**

### 🎯 Visualização
```
INÍCIO (saída)                    FIM (entrada)
    ↓                                ↓
┌─────┬─────┬─────┬─────┐       ┌─────┐
│elem1│elem2│elem3│elem4│ ← ← ← │novo │
└─────┴─────┴─────┴─────┘       └─────┘
   ↑                              ↑
dequeue                        enqueue
```

### 🛠️ Operações Fundamentais

#### 1. `enqueue` (Enfileirar)
- **Função**: Adiciona elemento no **final**
- **Complexidade**: O(1)

```c
void enqueue(Fila* f, int valor) {
    if (!isFull(f)) {
        f->fim = (f->fim + 1) % MAX_SIZE;
        f->dados[f->fim] = valor;
        f->tamanho++;
    }
}
```

#### 2. `dequeue` (Desenfileirar)
- **Função**: Remove elemento do **início**
- **Complexidade**: O(1)

```c
int dequeue(Fila* f) {
    if (!isEmpty(f)) {
        int valor = f->dados[f->inicio];
        f->inicio = (f->inicio + 1) % MAX_SIZE;
        f->tamanho--;
        return valor;
    }
    return -1; // Fila vazia
}
```

#### 3. `front` (Consultar início)
- **Função**: Consulta primeiro elemento **sem remover**
- **Complexidade**: O(1)

```c
int front(Fila* f) {
    if (!isEmpty(f)) {
        return f->dados[f->inicio];
    }
    return -1; // Fila vazia
}
```

### 🎮 Implementação em C (Fila Circular)

```c
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int dados[MAX_SIZE];
    int inicio;
    int fim;
    int tamanho;
} Fila;

// Inicializar fila
void inicializar(Fila* f) {
    f->inicio = 0;
    f->fim = -1;
    f->tamanho = 0;
}

// Verificar se está vazia
bool isEmpty(Fila* f) {
    return f->tamanho == 0;
}

// Verificar se está cheia
bool isFull(Fila* f) {
    return f->tamanho == MAX_SIZE;
}

// Enfileirar
void enqueue(Fila* f, int valor) {
    if (isFull(f)) {
        printf("Erro: Fila cheia!\n");
        return;
    }
    f->fim = (f->fim + 1) % MAX_SIZE;  // Fila circular
    f->dados[f->fim] = valor;
    f->tamanho++;
    printf("Enfileirado: %d\n", valor);
}

// Desenfileirar
int dequeue(Fila* f) {
    if (isEmpty(f)) {
        printf("Erro: Fila vazia!\n");
        return -1;
    }
    int valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX_SIZE;  // Fila circular
    f->tamanho--;
    printf("Desenfileirado: %d\n", valor);
    return valor;
}
```

### 🌟 Aplicações Reais de Filas

#### 1. **🖨️ Fila de Impressão**
```
Documentos enviados:
1. Relatório.pdf    → enqueue
2. Foto.jpg         → enqueue  
3. Planilha.xlsx    → enqueue

Impressora processa:
1. Relatório.pdf    ← dequeue (primeiro a ser impresso)
2. Foto.jpg         ← dequeue
3. Planilha.xlsx    ← dequeue
```

#### 2. **📞 Call Center**
```
Chamadas chegando:
Cliente A (09:00) → enqueue
Cliente B (09:01) → enqueue
Cliente C (09:02) → enqueue

Atendimento:
Cliente A atendido primeiro ← dequeue
Cliente B atendido segundo  ← dequeue
Cliente C atendido terceiro ← dequeue
```

#### 3. **💻 Sistema Operacional**
```
Processos aguardando CPU:
Processo A (alta prioridade) → enqueue
Processo B (média prioridade) → enqueue
Processo C (baixa prioridade) → enqueue

CPU executa na ordem de chegada
```

### ⚠️ Limitações das Filas

- **Capacidade Fixa**: Em implementações com vetor
- **Acesso Limitado**: Só início e fim são acessíveis
- **Problema do Middle**: Não consegue acessar elementos no meio

---

## 4. 📊 Comparação Final: Pilha vs. Fila

### 📋 Tabela Comparativa

| **Característica** | **Pilha (Stack)** | **Fila (Queue)** |
|-------------------|-------------------|------------------|
| **Princípio** | **LIFO** (Last-In, First-Out) | **FIFO** (First-In, First-Out) |
| **Analogia** | 🥞 Pilha de pratos | 🏦 Fila de banco |
| **Entrada** | 🔝 No topo (`push`) | 🔚 No final (`enqueue`) |
| **Saída** | 🔝 Do topo (`pop`) | 🔜 Do início (`dequeue`) |
| **Uso Ideal** | 🔄 Ações recentes, "desfazer" | ⏩ Processamento em ordem |
| **Aplicações** | 🌐 Navegador, 🔧 Compiladores | 🖨️ Impressão, 📞 Atendimento |

### 🎯 Quando Usar Cada Uma?

#### 🔝 Use **Pilha** quando:
- Precisa acessar o **último elemento** adicionado
- Implementa função **"desfazer"**
- Processa dados em **ordem reversa**
- Gerencia **chamadas de função**

#### ⏩ Use **Fila** quando:
- Precisa processar na **ordem de chegada**
- Implementa **justiça** no atendimento
- Gerencia **recursos compartilhados**
- Simula **processos do mundo real**

### 💡 Insight do Professor
> **A chave é compreender a natureza do problema para escolher a estrutura que o modela de forma mais natural e eficiente.**

---

## 🎓 Resumo da Aula

### ✅ Conceitos Aprendidos

1. **📏 Estruturas Lineares**: Organização sequencial de elementos
2. **🔝 Pilhas (LIFO)**: Último a entrar, primeiro a sair
3. **⏩ Filas (FIFO)**: Primeiro a entrar, primeiro a sair
4. **🛠️ Implementações**: Operações fundamentais em C
5. **🌟 Aplicações**: Problemas reais que cada estrutura resolve

### 🎯 Próxima Aula

**Aula 05**: [Listas Dinâmicas](./aula05-listas-dinamicas.md) - Estruturas flexíveis e encadeadas

---

## 🛠️ Exercícios Práticos

### 🎯 Exercício 1: Calculadora com Pilha
Implemente uma calculadora que usa pilha para expressões em notação pós-fixa.

### 🎯 Exercício 2: Simulador de Fila de Banco
Crie um simulador que gerencia clientes em uma fila de atendimento.

### 🎯 Exercício 3: Verificador de Parênteses
Use pilha para verificar se parênteses estão balanceados em uma expressão.

---

## 🔗 Links Úteis

- [📁 Exemplos de Pilhas e Filas](../exemplos-praticos/pilhas-filas/)
- [🧩 Exercícios Práticos](../exercicios/)
- [📚 Recursos sobre Estruturas Lineares](../recursos/)

---

📅 **Data**: Aula Ao Vivo 4  
🎥 **Vídeo**: [YouTube](https://www.youtube.com/watch?v=m50hOwEw8BU)  
⏰ **Duração**: ~60 minutos
