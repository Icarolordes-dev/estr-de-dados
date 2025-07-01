# 🎯 AULA 06: Pilhas e Filas com Listas Dinâmicas

[![YouTube](https://img.shields.io/badge/▶️-Assista%20no%20YouTube-red.svg)](https://www.youtube.com/watch?v=KMGw4HBC8uc)

> 🎯 **Objetivo**: Combinar o poder das listas dinâmicas com pilhas e filas, criando estruturas flexíveis que podem crescer indefinidamente.

---

## 📋 Agenda da Aula

1. [Avisos Importantes](#1-avisos-iniciais)
2. [Pilhas com Listas Dinâmicas](#2-estrutura-de-dados-1-pilhas-stacks)
3. [Filas com Listas Dinâmicas](#3-estrutura-de-dados-2-filas-queues)
4. [Comparação e Boas Práticas](#4-comparação-cuidados-e-boas-práticas)
5. [Avisos Finais](#5-conclusão-e-novos-avisos)

---

## 1. 📢 Avisos Iniciais

### 📚 **Biblioteca Digital**
- Nova biblioteca digital da Unicesumar disponível no Studio
- Livros e artigos acadêmicos acessíveis online

### 📝 **Atividade MAPA**
- **CORREÇÃO IMPORTANTE**: Linguagem alterada de Python para **C**
- Arquivo atualizado disponível em "Material da Disciplina"
- ⚠️ **Não usar** a versão antiga que estava no estúdio

### ⏰ **Prazos Importantes**
- **Atividade 1**: Encerrando em breve
- **Atividades 2, 3 e MAPA**: Em andamento
- **Monitorar prazos** para não perder pontuação

### 🎓 **Eventos Acadêmicos**
- **Semana de Conhecimentos Gerais**: Até 22/06
  - 16h complementares
  - Até 1 ponto na média
- **Programa Ampliar**: Revisão entre 30/06 e 04/07

### 🌐 **Plano de Contingência**
- Link alternativo no Microsoft Teams como "Plano B"
- Backup para instabilidades de streaming

---

## 2. 📚 Estrutura de Dados 1: Pilhas (Stacks)

### 🔄 Revisão: Conceito LIFO
> **LIFO (Last-In, First-Out)**: O **último** elemento a entrar é o **primeiro** a sair.

### 🍽️ Analogia Visual: Pilha de Pratos
- Sempre **empilha** no topo
- Sempre **desempilha** do topo
- Acesso apenas ao elemento mais recente

### 🏗️ Implementação com Listas Dinâmicas

#### **Vantagem Crucial**: Tamanho Ilimitado
- **Pilha com Array**: Limitada pelo tamanho fixo
- **Pilha com Lista**: Cresce indefinidamente (limite = memória disponível)

#### 🎯 Estrutura do Nó
```c
struct Node {
    int data;           // Dado armazenado
    struct Node *next;  // Ponteiro para o próximo nó
};

typedef struct {
    struct Node *topo;  // Ponteiro para o topo da pilha
    int tamanho;        // Contador de elementos (opcional)
} PilhaDinamica;
```

#### 🎯 Visualização da Pilha Dinâmica
```
    TOPO
     ↓
┌─────────┐    ┌─────────┐    ┌─────────┐
│ DADO:30 │ → │ DADO:20 │ → │ DADO:10 │ → NULL
│ next: • │    │ next: • │    │ next: • │
└─────────┘    └─────────┘    └─────────┘
    ↑              ↑              ↑
  3º push       2º push       1º push
(mais recente)                (mais antigo)
```

### ⚙️ Operações Fundamentais

#### 1. 📥 **Push (Empilhar)**
```c
void push(PilhaDinamica *pilha, int valor) {
    // 1. Criar novo nó
    struct Node *novo_no = malloc(sizeof(struct Node));
    if (novo_no == NULL) {
        printf("Erro: Memória insuficiente!\n");
        return;
    }
    
    // 2. Configurar o novo nó
    novo_no->data = valor;
    novo_no->next = pilha->topo;  // Aponta para o antigo topo
    
    // 3. Atualizar o topo
    pilha->topo = novo_no;        // Novo nó vira o topo
    pilha->tamanho++;
    
    printf("✅ Empilhado: %d\n", valor);
}
```

#### 2. 📤 **Pop (Desempilhar)**
```c
int pop(PilhaDinamica *pilha) {
    // 1. Verificar se pilha não está vazia
    if (pilha->topo == NULL) {
        printf("❌ Erro: Pilha vazia!\n");
        return -1; // Valor de erro
    }
    
    // 2. Guardar referências
    struct Node *temp = pilha->topo;
    int valor = temp->data;
    
    // 3. Atualizar o topo
    pilha->topo = temp->next;
    
    // 4. Liberar memória
    free(temp);
    pilha->tamanho--;
    
    printf("✅ Desempilhado: %d\n", valor);
    return valor;
}
```

#### 3. 👁️ **Peek/Top (Espiar)**
```c
int peek(PilhaDinamica *pilha) {
    if (pilha->topo == NULL) {
        printf("❌ Pilha vazia!\n");
        return -1;
    }
    
    return pilha->topo->data;
}
```

#### 4. ❓ **isEmpty (Está Vazia?)**
```c
int isEmpty(PilhaDinamica *pilha) {
    return pilha->topo == NULL;
}
```

### 🌍 Aplicações e Vantagens

#### ✅ **Vantagens da Pilha Dinâmica**
- **Sem Limite de Tamanho**: Cresce conforme necessário
- **Eficiência de Memória**: Usa apenas o necessário
- **Operações O(1)**: Push e pop em tempo constante

#### 🎯 **Aplicações Comuns**
1. **Função "Desfazer/Refazer"** em editores
2. **Botão "Voltar"** em navegadores
3. **Call Stack** de funções em programação
4. **Validação de expressões** balanceadas
5. **Algoritmos recursivos** convertidos para iterativos

---

## 3. 🚶 Estrutura de Dados 2: Filas (Queues)

### 🔄 Revisão: Conceito FIFO
> **FIFO (First-In, First-Out)**: O **primeiro** elemento a entrar é o **primeiro** a sair.

### 🏦 Analogia Visual: Fila de Pessoas
- **Chegada**: Final da fila
- **Atendimento**: Início da fila
- **Justiça**: Primeiro que chega, primeiro que sai

### 🏗️ Implementação com Listas Dinâmicas

#### **Diferença Crucial**: Dois Ponteiros
- **Pilha**: Apenas `topo`
- **Fila**: `início` (frente) + `fim` (traseira)

#### 🎯 Estrutura da Fila
```c
typedef struct {
    struct Node *inicio;  // Ponteiro para o primeiro da fila
    struct Node *fim;     // Ponteiro para o último da fila
    int tamanho;          // Contador de elementos
} FilaDinamica;
```

#### 🎯 Visualização da Fila Dinâmica
```
INÍCIO                                               FIM
  ↓                                                   ↓
┌─────────┐    ┌─────────┐    ┌─────────┐    ┌─────────┐
│ DADO:10 │ → │ DADO:20 │ → │ DADO:30 │ → │ DADO:40 │ → NULL
│ next: • │    │ next: • │    │ next: • │    │ next: • │
└─────────┘    └─────────┘    └─────────┘    └─────────┘
    ↑              ↑              ↑              ↑
 1º chegou      2º chegou      3º chegou     4º chegou
(sai primeiro)                              (sai último)

← DEQUEUE (desenfileirar)    ENQUEUE (enfileirar) →
```

### ⚙️ Operações Fundamentais

#### 1. 📥 **Enqueue (Enfileirar)**
```c
void enqueue(FilaDinamica *fila, int valor) {
    // 1. Criar novo nó
    struct Node *novo_no = malloc(sizeof(struct Node));
    if (novo_no == NULL) {
        printf("Erro: Memória insuficiente!\n");
        return;
    }
    
    // 2. Configurar o novo nó
    novo_no->data = valor;
    novo_no->next = NULL;  // Será o último, aponta para NULL
    
    // 3. Casos especiais
    if (fila->fim == NULL) {
        // Fila estava vazia
        fila->inicio = novo_no;
        fila->fim = novo_no;
    } else {
        // Fila tinha elementos
        fila->fim->next = novo_no;  // Último aponta para novo
        fila->fim = novo_no;        // Novo vira o último
    }
    
    fila->tamanho++;
    printf("✅ Enfileirado: %d\n", valor);
}
```

#### 2. 📤 **Dequeue (Desenfileirar)**
```c
int dequeue(FilaDinamica *fila) {
    // 1. Verificar se fila não está vazia
    if (fila->inicio == NULL) {
        printf("❌ Erro: Fila vazia!\n");
        return -1;
    }
    
    // 2. Guardar referências
    struct Node *temp = fila->inicio;
    int valor = temp->data;
    
    // 3. Atualizar o início
    fila->inicio = temp->next;
    
    // 4. Caso especial: se ficou vazia
    if (fila->inicio == NULL) {
        fila->fim = NULL;  // Importante! Ambos pontos para NULL
    }
    
    // 5. Liberar memória
    free(temp);
    fila->tamanho--;
    
    printf("✅ Desenfileirado: %d\n", valor);
    return valor;
}
```

#### 3. 👁️ **Front (Ver a Frente)**
```c
int front(FilaDinamica *fila) {
    if (fila->inicio == NULL) {
        printf("❌ Fila vazia!\n");
        return -1;
    }
    
    return fila->inicio->data;
}
```

### 🌍 Aplicações e Vantagens

#### ✅ **Vantagens da Fila Dinâmica**
- **Sem Limite**: Cresce indefinidamente
- **Gerenciamento Justo**: FIFO garante ordem
- **Eficiência**: Operações O(1)

#### 🎯 **Aplicações Comuns**
1. **Fila de Impressão** de documentos
2. **Sistemas de Atendimento** (call center, hospital)
3. **Gerenciamento de Processos** do SO
4. **Sistemas de Mensagens** (email, chat)
5. **Algoritmos BFS** (Busca em Largura)

---

## 4. ⚖️ Comparação, Cuidados e Boas Práticas

### 📊 Quadro Comparativo Final

| **Característica** | **Pilha Dinâmica** | **Fila Dinâmica** |
|---------------------|--------------------|--------------------|
| **Princípio** | **LIFO** (Last-In, First-Out) | **FIFO** (First-In, First-Out) |
| **Ponteiros** | Um (`topo`) | Dois (`início` e `fim`) |
| **Inserção** | No topo (`push`) | No fim (`enqueue`) |
| **Remoção** | Do topo (`pop`) | Do início (`dequeue`) |
| **Complexidade** | O(1) para ambas operações | O(1) para ambas operações |
| **Memória** | Apenas elementos existentes | Apenas elementos existentes |
| **Casos de Uso** | Desfazer, call stack | Atendimento, processamento |

### ⚠️ Pontos Críticos ("Armadilhas")

#### 1. 🎯 **Manipulação de Ponteiros**
- **Risco**: Erro ao reatribuir `topo`, `início` ou `fim`
- **Consequência**: "Quebra" a lógica da estrutura
- **Prevenção**: Testar cada operação passo a passo

#### 2. 🕳️ **Verificação de Estrutura Vazia**
```c
// ❌ PERIGOSO
int valor = pop(pilha);  // E se pilha estiver vazia?

// ✅ SEGURO
if (!isEmpty(pilha)) {
    int valor = pop(pilha);
} else {
    printf("Pilha vazia, não é possível desempilhar!\n");
}
```

#### 3. 🧠 **Vazamento de Memória (Memory Leak)**
```c
// ❌ VAZAMENTO - Esqueceu de liberar
struct Node *temp = pilha->topo;
pilha->topo = temp->next;
// free(temp); ← ESQUECEU!

// ✅ CORRETO
struct Node *temp = pilha->topo;
pilha->topo = temp->next;
free(temp);  // ✅ Libera a memória
```

#### 4. 🎯 **Ponteiros Soltos (Dangling Pointers)**
```c
// ❌ PERIGOSO - Usar ponteiro após free
struct Node *temp = pilha->topo;
free(temp);
temp->data = 10;  // ❌ ERRO! Acesso após liberação

// ✅ SEGURO
struct Node *temp = pilha->topo;
int valor = temp->data;  // Salva valor antes
free(temp);
temp = NULL;  // Boa prática
```

#### 5. 🚨 **Caso Especial das Filas**
```c
// Quando fila fica vazia, AMBOS ponteiros devem ser NULL
if (fila->inicio == NULL) {
    fila->fim = NULL;  // ⚠️ CRÍTICO! Não esquecer
}
```

### 💡 **Boas Práticas de Implementação**

#### 1. 🧪 **Sempre Testar Estados Extremos**
- Estrutura vazia
- Um único elemento
- Múltiplos elementos

#### 2. 🔍 **Verificações de Segurança**
```c
// Sempre verificar malloc
struct Node *novo = malloc(sizeof(struct Node));
if (novo == NULL) {
    printf("Erro: Sem memória!\n");
    return;
}
```

#### 3. 🗑️ **Limpeza Completa**
```c
void liberar_pilha(PilhaDinamica *pilha) {
    while (!isEmpty(pilha)) {
        pop(pilha);  // Remove e libera cada nó
    }
}
```

---

## 5. 🎓 Conclusão e Novos Avisos

### ✅ **Conceitos Dominados**
1. **LIFO vs FIFO**: Dois paradigmas fundamentais
2. **Nós e Ponteiros**: Base das estruturas dinâmicas
3. **Operações O(1)**: Eficiência em inserção/remoção
4. **Gestão de Memória**: Alocação e liberação responsável

### 🎯 **Importância dos Trade-offs**
- **Flexibilidade** (tamanho dinâmico) vs **Complexidade** (gestão de ponteiros)
- **Eficiência** (O(1)) vs **Overhead** (ponteiros extras)
- **Sem limites** vs **Responsabilidade** (memory management)

### 📢 **Novos Avisos**

#### 🏆 **Live do Hackathon**
- **Data**: 16/06 às 19h
- **Objetivo**: Prestigiar os melhores projetos
- Oportunidade de ver aplicações práticas

#### 🎓 **Programa de Monitoria**
- **Programa Ampliar**: Inscrições abertas
- **Áreas**: Exatas, Física, Química e Tecnologia
- Oportunidade de reforçar aprendizado

### 🎯 **Próxima Aula**
**Aula 07**: [Introdução aos Grafos](./aula07-intro-grafos.md) - Estruturas não-lineares complexas

---

## 🛠️ Exercícios Práticos

### 🎯 Exercício 1: Calculadora com Pilha
Implemente uma calculadora que usa pilha para avaliar expressões pós-fixas:
- Entrada: "3 4 + 2 *"
- Saída: 14

### 🎯 Exercício 2: Simulador de Atendimento
Crie um sistema de fila para simular atendimento médico:
- Diferentes prioridades
- Tempo de espera
- Múltiplos atendentes

### 🎯 Exercício 3: Validador de Parênteses
Use pilha para verificar se expressões estão balanceadas:
- "{[()]}" ✅ Válida
- "{[(])}" ❌ Inválida

### 🎯 Exercício 4: Sistema de Desfazer/Refazer
Implemente um editor simples com:
- Pilha para "desfazer" (Ctrl+Z)
- Pilha para "refazer" (Ctrl+Y)
- Operações: inserir, apagar, formatar

---

## 🔗 Links Úteis

- [📁 Exemplos de Pilhas e Filas Dinâmicas](../exemplos-praticos/pilhas-filas/)
- [🧩 Exercícios Avançados](../exercicios/)
- [📚 Algoritmos com Estruturas Lineares](../recursos/)
- [🛠️ Ferramentas de Debug Memory](../recursos/ferramentas.md)

---

📅 **Data**: Aula Ao Vivo 6  
🎥 **Vídeo**: [YouTube](https://www.youtube.com/watch?v=KMGw4HBC8uc)  
⏰ **Duração**: ~90 minutos (incluindo Q&A)
