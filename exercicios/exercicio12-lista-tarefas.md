# 📝 Exercício 12: Lista de Tarefas (Todo List)

## 📊 Dados do Exercício
- **Nível:** 🟡 Médio
- **Tópico:** Listas Ligadas Dinâmicas
- **Tempo estimado:** 75 minutos
- **Pontuação:** 2 pontos

## 🎯 Objetivo

Implementar um sistema de lista de tarefas (Todo List) usando listas ligadas, com funcionalidades completas de CRUD (Create, Read, Update, Delete), prioridades, categorias e persistência.

## 📝 Descrição do Problema

Sua lista de tarefas deve suportar:

1. **Adicionar tarefas** com título, descrição, prioridade e categoria
2. **Listar tarefas** com diferentes filtros e ordenações
3. **Marcar como concluída** ou não concluída
4. **Editar tarefas** existentes
5. **Remover tarefas** 
6. **Buscar tarefas** por título ou categoria
7. **Estatísticas** do progresso
8. **Salvar/carregar** de arquivo (bônus)

## 🔍 Especificações Técnicas

### Estruturas Necessárias:

```c
typedef enum {
    BAIXA = 1,
    MEDIA = 2,
    ALTA = 3,
    URGENTE = 4
} Prioridade;

typedef enum {
    TRABALHO,
    PESSOAL,
    ESTUDO,
    SAUDE,
    OUTROS
} Categoria;

typedef struct {
    int dia, mes, ano;
    int hora, minuto;
} DateTime;

typedef struct Tarefa {
    int id;
    char titulo[100];
    char descricao[500];
    Prioridade prioridade;
    Categoria categoria;
    bool concluida;
    DateTime criada;
    DateTime prazo;
    struct Tarefa* proxima;
} Tarefa;

typedef struct {
    Tarefa* cabeca;
    int total_tarefas;
    int proximo_id;
} ListaTarefas;
```

### Funções Principais:

```c
// Gerenciamento da lista
ListaTarefas* criar_lista();
void liberar_lista(ListaTarefas* lista);

// CRUD básico
Tarefa* criar_tarefa(const char* titulo, const char* descricao, 
                     Prioridade prio, Categoria cat);
void adicionar_tarefa(ListaTarefas* lista, Tarefa* tarefa);
bool remover_tarefa(ListaTarefas* lista, int id);
Tarefa* buscar_tarefa(ListaTarefas* lista, int id);
bool editar_tarefa(ListaTarefas* lista, int id);

// Operações especiais
void marcar_concluida(ListaTarefas* lista, int id);
void listar_tarefas(ListaTarefas* lista, int filtro);
void buscar_por_titulo(ListaTarefas* lista, const char* busca);
void buscar_por_categoria(ListaTarefas* lista, Categoria cat);

// Estatísticas e relatórios
void mostrar_estatisticas(ListaTarefas* lista);
void listar_por_prioridade(ListaTarefas* lista);
void listar_pendentes(ListaTarefas* lista);
void listar_vencidas(ListaTarefas* lista);

// Persistência (bônus)
bool salvar_arquivo(ListaTarefas* lista, const char* arquivo);
bool carregar_arquivo(ListaTarefas* lista, const char* arquivo);
```

## 📋 Exemplo de Execução

```
📝 SISTEMA DE LISTA DE TAREFAS

========================================
📊 ESTATÍSTICAS ATUAIS:
   Total de tarefas: 5
   ✅ Concluídas: 2 (40%)
   ⏳ Pendentes: 3 (60%)
   🔥 Urgentes: 1
   ⚠️ Vencidas: 1
========================================

1. ➕ Adicionar Nova Tarefa
2. 📋 Listar Todas as Tarefas  
3. ✅ Marcar como Concluída
4. ✏️ Editar Tarefa
5. 🗑️ Remover Tarefa
6. 🔍 Buscar Tarefas
7. 📊 Relatórios e Filtros
8. 💾 Salvar/Carregar
0. 🚪 Sair

👉 Escolha uma opção: 1

➕ ADICIONAR NOVA TAREFA
━━━━━━━━━━━━━━━━━━━━━━━━━━

📝 Título: Estudar para prova de Estruturas de Dados
📄 Descrição: Revisar pilhas, filas e listas ligadas
🔥 Prioridade [1-Baixa, 2-Média, 3-Alta, 4-Urgente]: 3
📂 Categoria [0-Trabalho, 1-Pessoal, 2-Estudo, 3-Saúde, 4-Outros]: 2
📅 Prazo (DD/MM/AAAA HH:MM): 15/12/2024 23:59

✅ Tarefa #6 adicionada com sucesso!

========================================

👉 Escolha uma opção: 2

📋 LISTA DE TAREFAS (5 tarefas)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

┌─────┬──────────────────────────────────┬──────────┬───────────┬─────────┬──────────┐
│ ID  │ Título                           │ Categoria│ Prioridade│ Status  │ Prazo    │
├─────┼──────────────────────────────────┼──────────┼───────────┼─────────┼──────────┤
│ 001 │ Fazer compras no mercado         │ PESSOAL  │ MÉDIA     │ ✅ FEITO│ Sem prazo│
│ 002 │ Reunião com cliente              │ TRABALHO │ ALTA      │ ⏳ PEND │ Hoje 14h │
│ 003 │ Exercitar-se na academia         │ SAÚDE    │ BAIXA     │ ✅ FEITO│ Diário   │
│ 004 │ Entregar relatório               │ TRABALHO │ URGENTE   │ ⚠️ VENC │ Ontem    │
│ 005 │ Ligar para dentista              │ SAÚDE    │ MÉDIA     │ ⏳ PEND │ Amanhã   │
│ 006 │ Estudar Estruturas de Dados      │ ESTUDO   │ ALTA      │ ⏳ PEND │ 15/12 23h│
└─────┴──────────────────────────────────┴──────────┴───────────┴─────────┴──────────┘

🔍 Legenda: ✅ = Concluída, ⏳ = Pendente, ⚠️ = Vencida

========================================

👉 Escolha uma opção: 7

📊 RELATÓRIOS E FILTROS
━━━━━━━━━━━━━━━━━━━━━━━━━━

1. 🔥 Tarefas por Prioridade
2. ⏳ Apenas Pendentes  
3. ✅ Apenas Concluídas
4. ⚠️ Tarefas Vencidas
5. 📂 Por Categoria
6. 📈 Estatísticas Detalhadas

👉 Escolha: 1

🔥 TAREFAS POR PRIORIDADE
━━━━━━━━━━━━━━━━━━━━━━━━━━

🚨 URGENTE (1 tarefa):
   #004 - Entregar relatório [TRABALHO] ⚠️ VENCIDA

🔴 ALTA (2 tarefas):
   #002 - Reunião com cliente [TRABALHO] ⏳ PENDENTE
   #006 - Estudar Estruturas de Dados [ESTUDO] ⏳ PENDENTE

🟡 MÉDIA (2 tarefas):
   #001 - Fazer compras no mercado [PESSOAL] ✅ CONCLUÍDA
   #005 - Ligar para dentista [SAÚDE] ⏳ PENDENTE

🟢 BAIXA (1 tarefa):
   #003 - Exercitar-se na academia [SAÚDE] ✅ CONCLUÍDA
```

## 🚀 Código Base (Esqueleto)

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Definições de tipos (como mostrado acima)

// Protótipos das funções
ListaTarefas* criar_lista();
void liberar_lista(ListaTarefas* lista);
Tarefa* criar_tarefa(const char* titulo, const char* descricao, 
                     Prioridade prio, Categoria cat);
void adicionar_tarefa(ListaTarefas* lista, Tarefa* tarefa);
// ... outros protótipos

// Funções de utilidade
void limpar_tela();
void pausar();
char* obter_nome_categoria(Categoria cat);
char* obter_nome_prioridade(Prioridade prio);
DateTime obter_data_atual();
bool data_vencida(DateTime prazo);

int main() {
    ListaTarefas* lista = criar_lista();
    menu_principal(lista);
    liberar_lista(lista);
    return 0;
}

// TODO: Implementar todas as funções
```

## 💡 Dicas para Implementação

### 🔸 Dica 1: Inserção Ordenada por Prioridade
```c
void adicionar_ordenado(ListaTarefas* lista, Tarefa* nova) {
    if (lista->cabeca == NULL || nova->prioridade > lista->cabeca->prioridade) {
        nova->proxima = lista->cabeca;
        lista->cabeca = nova;
        return;
    }
    
    Tarefa* atual = lista->cabeca;
    while (atual->proxima && atual->proxima->prioridade >= nova->prioridade) {
        atual = atual->proxima;
    }
    
    nova->proxima = atual->proxima;
    atual->proxima = nova;
}
```

### 🔸 Dica 2: Busca Flexível
```c
Tarefa* buscar_por_titulo_parcial(ListaTarefas* lista, const char* busca) {
    Tarefa* atual = lista->cabeca;
    
    while (atual != NULL) {
        if (strstr(atual->titulo, busca) != NULL) {
            return atual;  // Encontrou
        }
        atual = atual->proxima;
    }
    
    return NULL;  // Não encontrou
}
```

### 🔸 Dica 3: Formatação de Data
```c
char* formatar_data(DateTime dt) {
    static char buffer[20];
    
    if (dt.dia == 0) {
        strcpy(buffer, "Sem prazo");
    } else {
        snprintf(buffer, sizeof(buffer), "%02d/%02d/%04d %02d:%02d",
                dt.dia, dt.mes, dt.ano, dt.hora, dt.minuto);
    }
    
    return buffer;
}
```

### 🔸 Dica 4: Remoção Segura
```c
bool remover_tarefa(ListaTarefas* lista, int id) {
    if (lista->cabeca == NULL) return false;
    
    // Caso especial: primeiro elemento
    if (lista->cabeca->id == id) {
        Tarefa* temp = lista->cabeca;
        lista->cabeca = lista->cabeca->proxima;
        free(temp);
        lista->total_tarefas--;
        return true;
    }
    
    // Buscar elemento
    Tarefa* atual = lista->cabeca;
    while (atual->proxima && atual->proxima->id != id) {
        atual = atual->proxima;
    }
    
    if (atual->proxima) {
        Tarefa* temp = atual->proxima;
        atual->proxima = temp->proxima;
        free(temp);
        lista->total_tarefas--;
        return true;
    }
    
    return false;
}
```

## 🎯 Casos de Teste

### Teste 1: Operações Básicas
```
1. Adicionar 3 tarefas com prioridades diferentes
2. Listar todas (verificar ordenação)
3. Marcar uma como concluída
4. Remover uma tarefa
5. Verificar contagens corretas
```

### Teste 2: Busca e Filtros
```
1. Buscar por título parcial
2. Filtrar por categoria
3. Listar apenas pendentes
4. Listar por prioridade
```

### Teste 3: Casos Extremos
```
1. Lista vazia (todas as operações)
2. Remover tarefa inexistente
3. Buscar em lista vazia
4. Adicionar tarefa com título muito longo
```

### Teste 4: Datas e Prazos
```
1. Tarefas com prazos vencidos
2. Tarefas sem prazo
3. Ordenação por data de vencimento
```

## 🌟 Funcionalidades Extras

### 1. **Sistema de Tags**
```c
typedef struct Tag {
    char nome[30];
    struct Tag* proxima;
} Tag;

// Adicionar campo tags à estrutura Tarefa
Tag* tags;
```

### 2. **Histórico de Alterações**
```c
typedef struct Historico {
    DateTime quando;
    char operacao[50];
    char detalhes[200];
    struct Historico* proximo;
} Historico;
```

### 3. **Subtarefas**
```c
typedef struct Subtarefa {
    char titulo[100];
    bool concluida;
    struct Subtarefa* proxima;
} Subtarefa;

// Adicionar à estrutura Tarefa
Subtarefa* subtarefas;
```

## ⚠️ Tratamento de Erros

### 1. **Validação de Entrada**
```c
bool validar_tarefa(const char* titulo, const char* descricao) {
    if (titulo == NULL || strlen(titulo) == 0) {
        printf("Erro: Título não pode estar vazio\n");
        return false;
    }
    
    if (strlen(titulo) > 99) {
        printf("Erro: Título muito longo (máximo 99 caracteres)\n");
        return false;
    }
    
    return true;
}
```

### 2. **Verificação de Memória**
```c
Tarefa* nova_tarefa = malloc(sizeof(Tarefa));
if (nova_tarefa == NULL) {
    printf("Erro: Falha na alocação de memória\n");
    return NULL;
}
```

## 🏆 Critérios de Avaliação

### ✅ Funcionalidade (60%)
- [ ] CRUD completo funcionando
- [ ] Sistema de prioridades
- [ ] Busca e filtros
- [ ] Marcação de conclusão
- [ ] Estatísticas básicas

### ✅ Estrutura de Dados (25%)
- [ ] Lista ligada implementada corretamente
- [ ] Inserção e remoção eficientes
- [ ] Gerenciamento de memória adequado
- [ ] Uso correto de ponteiros

### ✅ Interface e Usabilidade (15%)
- [ ] Menu intuitivo
- [ ] Listagem formatada
- [ ] Mensagens claras
- [ ] Tratamento de erros

## 🎁 Bônus (+1 ponto)

- **Persistência em arquivo** (salvar/carregar)
- **Sistema de notificações** para prazos
- **Estatísticas avançadas** com gráficos ASCII
- **Importação/exportação** CSV
- **Sistema de backup** automático
- **Interface colorida** com ANSI colors

## 📚 Conceitos Revisados

- ✅ Listas ligadas dinâmicas
- ✅ Alocação e liberação de memória
- ✅ Estruturas complexas aninhadas
- ✅ Enumerações e uniões
- ✅ Funções de busca e ordenação
- ✅ Manipulação de strings
- ✅ Gerenciamento de datas

## 🔗 Aplicações Reais

- **Aplicativos de produtividade:** Todoist, Any.do
- **Gerenciamento de projetos:** Trello, Asana
- **Sistemas de tickets:** Jira, ServiceNow
- **CRM:** Salesforce, HubSpot

## 📝 Entrega

Estrutura de arquivos sugerida:
```
exercicio12/
├── src/
│   ├── todo.c           # Implementação principal
│   ├── todo.h           # Cabeçalhos e estruturas
│   ├── utils.c          # Funções utilitárias
│   └── persistencia.c   # Salvar/carregar (bônus)
├── dados/
│   └── tarefas.txt      # Arquivo de dados
├── Makefile             # Compilação
└── README.md            # Documentação
```

Comandos de compilação:
```bash
gcc -Wall -Wextra -std=c99 src/*.c -o todo
./todo
```

---
**🎯 Desafio Extra:** Implementar um sistema de lembretes que notifica sobre tarefas próximas do vencimento!
