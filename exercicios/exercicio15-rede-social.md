# 🌐 Exercício 15: Rede Social Simples

## 📊 Dados do Exercício
- **Nível:** 🟡 Médio
- **Tópico:** Grafos e Algoritmos de Busca
- **Tempo estimado:** 120 minutos
- **Pontuação:** 2 pontos

## 🎯 Objetivo

Implementar uma rede social simples usando grafos, demonstrando conceitos de conexões entre usuários, busca de caminhos, detecção de comunidades e análise de rede.

## 📝 Descrição do Problema

Sua rede social deve suportar:

1. **Cadastro de usuários** com perfil básico
2. **Sistema de amizades** (conexões bidirecionais)
3. **Busca de usuários** e conexões
4. **Caminho entre usuários** (graus de separação)
5. **Sugestões de amizade** (amigos em comum)
6. **Análise da rede** (estatísticas e métricas)
7. **Comunidades** (grupos densamente conectados)
8. **Visualização da rede** (representação textual)

## 🔍 Especificações Técnicas

### Estruturas Necessárias:

```c
#define MAX_USUARIOS 100
#define MAX_NOME 50
#define MAX_EMAIL 80

typedef struct {
    int id;
    char nome[MAX_NOME];
    char email[MAX_EMAIL];
    int idade;
    char cidade[50];
    int num_amigos;
    bool ativo;
} Usuario;

typedef struct NoAmigo {
    int id_amigo;
    time_t data_amizade;
    struct NoAmigo* proximo;
} NoAmigo;

typedef struct {
    Usuario usuarios[MAX_USUARIOS];
    NoAmigo* lista_amigos[MAX_USUARIOS];  // Lista de adjacência
    int matriz_amizade[MAX_USUARIOS][MAX_USUARIOS];  // Matriz de adjacência
    int total_usuarios;
    int total_amizades;
    bool usar_matriz;  // Escolher representação
} RedeSocial;

typedef struct {
    int caminho[MAX_USUARIOS];
    int tamanho;
    int graus_separacao;
} CaminhoAmizade;

typedef struct {
    int membros[MAX_USUARIOS];
    int tamanho;
    float densidade;
} Comunidade;
```

### Funções Principais:

```c
// Inicialização e limpeza
RedeSocial* criar_rede();
void liberar_rede(RedeSocial* rede);

// Gerenciamento de usuários
int adicionar_usuario(RedeSocial* rede, const char* nome, const char* email, 
                      int idade, const char* cidade);
bool remover_usuario(RedeSocial* rede, int id);
Usuario* buscar_usuario(RedeSocial* rede, int id);
Usuario* buscar_por_email(RedeSocial* rede, const char* email);

// Sistema de amizades
bool adicionar_amizade(RedeSocial* rede, int id1, int id2);
bool remover_amizade(RedeSocial* rede, int id1, int id2);
bool sao_amigos(RedeSocial* rede, int id1, int id2);
int* obter_amigos(RedeSocial* rede, int id, int* count);

// Algoritmos de busca e análise
CaminhoAmizade* encontrar_caminho(RedeSocial* rede, int origem, int destino);
int* sugerir_amigos(RedeSocial* rede, int id, int* count);
int* amigos_em_comum(RedeSocial* rede, int id1, int id2, int* count);

// Análise da rede
void calcular_estatisticas(RedeSocial* rede);
float calcular_densidade_rede(RedeSocial* rede);
int encontrar_usuario_mais_popular(RedeSocial* rede);
Comunidade* detectar_comunidades(RedeSocial* rede, int* num_comunidades);

// Visualização
void exibir_rede_completa(RedeSocial* rede);
void exibir_perfil_usuario(RedeSocial* rede, int id);
void exibir_grafo_amizades(RedeSocial* rede, int id, int profundidade);
```

## 📋 Exemplo de Execução

```
🌐 REDE SOCIAL SIMPLES - GraphBook

========================================
👥 USUÁRIOS ONLINE: 8
🤝 TOTAL DE AMIZADES: 12
📊 DENSIDADE DA REDE: 21.4%
⭐ USUÁRIO MAIS POPULAR: Ana Silva (6 amigos)
========================================

1. 👤 Gerenciar Usuários
2. 🤝 Gerenciar Amizades  
3. 🔍 Buscar e Explorar
4. 📊 Análise da Rede
5. 🎯 Sugestões e Recomendações
6. 🌐 Visualizar Rede
7. 📈 Relatórios
0. 🚪 Sair

👉 Escolha uma opção: 3

🔍 BUSCAR E EXPLORAR
━━━━━━━━━━━━━━━━━━━━━━━━

1. 🔎 Buscar Usuário
2. 🛤️ Encontrar Caminho entre Usuários
3. 👥 Amigos em Comum
4. 🌟 Graus de Separação
5. 🔄 Voltar ao Menu

👉 Escolha: 2

🛤️ ENCONTRAR CAMINHO ENTRE USUÁRIOS
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

📝 ID do usuário origem: 1
📝 ID do usuário destino: 5

🔍 Buscando caminho de Ana Silva para Carlos Pereira...

✅ CAMINHO ENCONTRADO!
━━━━━━━━━━━━━━━━━━━━━━━━

👤 Ana Silva (ID: 1)
    ↓ (amigos desde 15/03/2023)
👤 Bruno Costa (ID: 2)  
    ↓ (amigos desde 22/07/2023)
👤 Diana Santos (ID: 4)
    ↓ (amigos desde 10/11/2023)
👤 Carlos Pereira (ID: 5)

📊 ANÁLISE DO CAMINHO:
   🎯 Graus de separação: 3
   🕐 Caminho mais antigo: 15/03/2023
   🕑 Conexão mais recente: 10/11/2023
   📏 Distância social: Média

========================================

👉 Escolha uma opção: 4

📊 ANÁLISE DA REDE
━━━━━━━━━━━━━━━━━━━━━━━━

🌐 ESTATÍSTICAS GERAIS:
   👥 Total de usuários: 8
   🤝 Total de amizades: 12
   📊 Densidade da rede: 21.4%
   📈 Grau médio: 3.0 amigos por usuário
   📏 Diâmetro da rede: 4 conexões
   🌟 Coeficiente de clustering: 0.67

👑 TOP USUÁRIOS:
   🥇 Ana Silva      - 6 amigos (super conectada)
   🥈 Bruno Costa    - 4 amigos (bem conectada)
   🥉 Diana Santos   - 3 amigos (conectada)

🏙️ DISTRIBUIÇÃO POR CIDADE:
   📍 São Paulo: 3 usuários (37.5%)
   📍 Rio de Janeiro: 2 usuários (25.0%)
   📍 Belo Horizonte: 2 usuários (25.0%)
   📍 Salvador: 1 usuário (12.5%)

👥 COMUNIDADES DETECTADAS:
   🟢 Comunidade 1: Ana, Bruno, Diana (densidade: 83%)
   🔵 Comunidade 2: Carlos, Eduardo (densidade: 100%)
   🟡 Comunidade 3: Fernanda, Gabriel, Helena (densidade: 67%)

========================================

👉 Escolha uma opção: 6

🌐 VISUALIZAR REDE
━━━━━━━━━━━━━━━━━━━━━━

1. 🕸️ Mapa Completo da Rede
2. 👤 Perfil Detalhado de Usuário
3. 🌟 Rede de Amizades (1º grau)
4. 🌐 Rede Expandida (2º grau)

👉 Escolha: 1

🕸️ MAPA COMPLETO DA REDE SOCIAL
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

                    Ana Silva (SP)
                   ╱   │   │   ╲
                  ╱    │   │    ╲
                 ╱     │   │     ╲
          Bruno (RJ) ──┘   │      ╲── Diana (SP)
              │            │           │
              │            │           │
              │       Eduardo (BH) ────┘
              │            │
              │            │
        Fernanda (SP) ──────┘
              │
              │
        Gabriel (BH) ── Helena (SSA)

🔗 LEGENDA:
   ── Amizade direta
   │  Conexão vertical
   ╱╲ Conexões múltiplas

📊 MÉTRICAS POR USUÁRIO:
┌─────┬─────────────────┬────────┬──────────────┬──────────────┬─────────────┐
│ ID  │ Nome            │ Cidade │ Nº Amigos    │ Centralidade │ Influência  │
├─────┼─────────────────┼────────┼──────────────┼──────────────┼─────────────┤
│ 1   │ Ana Silva       │ SP     │ 6 (⭐⭐⭐⭐⭐)│ 0.87         │ 94.2        │
│ 2   │ Bruno Costa     │ RJ     │ 4 (⭐⭐⭐⭐)  │ 0.71         │ 78.6        │
│ 3   │ Carlos Pereira  │ BH     │ 2 (⭐⭐)     │ 0.43         │ 45.1        │
│ 4   │ Diana Santos    │ SP     │ 3 (⭐⭐⭐)   │ 0.62         │ 67.8        │
│ 5   │ Eduardo Lima    │ BH     │ 3 (⭐⭐⭐)   │ 0.58         │ 62.3        │
│ 6   │ Fernanda Costa  │ SP     │ 2 (⭐⭐)     │ 0.41         │ 41.7        │
│ 7   │ Gabriel Santos  │ BH     │ 2 (⭐⭐)     │ 0.35         │ 38.9        │
│ 8   │ Helena Oliveira │ SSA    │ 1 (⭐)      │ 0.21         │ 25.4        │
└─────┴─────────────────┴────────┴──────────────┴──────────────┴─────────────┘
```

## 🚀 Código Base (Esqueleto)

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

// Definições e estruturas (como mostrado acima)

// Protótipos das funções principais
RedeSocial* criar_rede();
void liberar_rede(RedeSocial* rede);
int adicionar_usuario(RedeSocial* rede, const char* nome, const char* email, 
                      int idade, const char* cidade);
// ... outros protótipos

// Algoritmos de grafos
void bfs_caminho(RedeSocial* rede, int origem, int destino, CaminhoAmizade* resultado);
void dfs_comunidades(RedeSocial* rede, int usuario, bool visitado[], int comunidade[], int* tamanho);
float calcular_centralidade(RedeSocial* rede, int id);

// Funções de demonstração
void popular_rede_exemplo(RedeSocial* rede);
void menu_principal(RedeSocial* rede);

int main() {
    RedeSocial* rede = criar_rede();
    
    // Carregar dados de exemplo
    popular_rede_exemplo(rede);
    
    printf("🌐 Bem-vindo ao GraphBook!\n");
    menu_principal(rede);
    
    liberar_rede(rede);
    return 0;
}

// TODO: Implementar todas as funções
```

## 💡 Dicas para Implementação

### 🔸 Dica 1: Busca em Largura (BFS) para Caminho Mínimo
```c
CaminhoAmizade* encontrar_caminho(RedeSocial* rede, int origem, int destino) {
    int fila[MAX_USUARIOS];
    int visitado[MAX_USUARIOS] = {0};
    int pai[MAX_USUARIOS];
    int inicio = 0, fim = 0;
    
    // Inicializar
    for (int i = 0; i < MAX_USUARIOS; i++) pai[i] = -1;
    
    // BFS
    fila[fim++] = origem;
    visitado[origem] = 1;
    
    while (inicio < fim) {
        int atual = fila[inicio++];
        
        if (atual == destino) {
            // Reconstruir caminho
            return reconstruir_caminho(pai, origem, destino);
        }
        
        // Explorar vizinhos
        NoAmigo* amigo = rede->lista_amigos[atual];
        while (amigo != NULL) {
            if (!visitado[amigo->id_amigo]) {
                visitado[amigo->id_amigo] = 1;
                pai[amigo->id_amigo] = atual;
                fila[fim++] = amigo->id_amigo;
            }
            amigo = amigo->proximo;
        }
    }
    
    return NULL;  // Não há caminho
}
```

### 🔸 Dica 2: Sugestões de Amizade
```c
int* sugerir_amigos(RedeSocial* rede, int id, int* count) {
    int* sugestoes = malloc(MAX_USUARIOS * sizeof(int));
    int pontuacao[MAX_USUARIOS] = {0};
    *count = 0;
    
    // Para cada amigo do usuário
    NoAmigo* amigo = rede->lista_amigos[id];
    while (amigo != NULL) {
        // Para cada amigo do amigo
        NoAmigo* amigo_do_amigo = rede->lista_amigos[amigo->id_amigo];
        while (amigo_do_amigo != NULL) {
            int candidato = amigo_do_amigo->id_amigo;
            
            // Se não é o próprio usuário e não são amigos
            if (candidato != id && !sao_amigos(rede, id, candidato)) {
                pontuacao[candidato]++;  // Amigo em comum
            }
            
            amigo_do_amigo = amigo_do_amigo->proximo;
        }
        amigo = amigo->proximo;
    }
    
    // Ordenar por pontuação e retornar top suggestions
    // ... implementar ordenação ...
    
    return sugestoes;
}
```

### 🔸 Dica 3: Detecção de Comunidades (Algoritmo Simples)
```c
Comunidade* detectar_comunidades(RedeSocial* rede, int* num_comunidades) {
    bool visitado[MAX_USUARIOS] = {false};
    Comunidade* comunidades = malloc(MAX_USUARIOS * sizeof(Comunidade));
    *num_comunidades = 0;
    
    for (int i = 0; i < rede->total_usuarios; i++) {
        if (!visitado[i] && rede->usuarios[i].ativo) {
            Comunidade* nova = &comunidades[*num_comunidades];
            nova->tamanho = 0;
            
            // DFS para encontrar componente conectado
            dfs_comunidade(rede, i, visitado, nova);
            
            // Calcular densidade da comunidade
            nova->densidade = calcular_densidade_comunidade(rede, nova);
            
            (*num_comunidades)++;
        }
    }
    
    return comunidades;
}
```

### 🔸 Dica 4: Cálculo de Centralidade
```c
float calcular_centralidade(RedeSocial* rede, int id) {
    int soma_distancias = 0;
    int usuarios_alcancaveis = 0;
    
    // Para cada usuário, calcular distância
    for (int i = 0; i < rede->total_usuarios; i++) {
        if (i != id && rede->usuarios[i].ativo) {
            CaminhoAmizade* caminho = encontrar_caminho(rede, id, i);
            if (caminho != NULL) {
                soma_distancias += caminho->graus_separacao;
                usuarios_alcancaveis++;
                free(caminho);
            }
        }
    }
    
    if (usuarios_alcancaveis == 0) return 0.0;
    
    // Centralidade = 1 / distância média
    float distancia_media = (float)soma_distancias / usuarios_alcancaveis;
    return 1.0 / distancia_media;
}
```

## 🎯 Casos de Teste

### Teste 1: Operações Básicas
```
1. Adicionar 5 usuários
2. Criar amizades entre eles
3. Verificar se são amigos
4. Buscar usuários por email
5. Remover uma amizade
```

### Teste 2: Algoritmos de Busca
```
1. Encontrar caminho entre usuários conectados
2. Verificar caminho inexistente
3. Testar sugestões de amizade
4. Calcular amigos em comum
```

### Teste 3: Análise de Rede
```
1. Calcular densidade com diferentes números de usuários
2. Encontrar usuário mais popular
3. Detectar comunidades
4. Calcular centralidade
```

### Teste 4: Casos Extremos
```
1. Rede vazia
2. Usuário sem amigos (isolado)
3. Rede completamente conectada
4. Dois grupos desconectados
```

## 🌟 Funcionalidades Extras

### 1. **Sistema de Posts e Feed**
```c
typedef struct Post {
    int id_autor;
    char conteudo[500];
    time_t timestamp;
    int curtidas;
    struct Post* proximo;
} Post;
```

### 2. **Recomendações Avançadas**
```c
// Baseadas em interesses, idade, localização
float calcular_compatibilidade(Usuario* u1, Usuario* u2);
```

### 3. **Métricas de Influência**
```c
typedef struct {
    float pagerank;
    float betweenness;
    float closeness;
    int reach;  // Alcance em 2 graus
} MetricasInfluencia;
```

## ⚠️ Considerações de Performance

### 1. **Escolha de Representação**
```c
// Para redes esparsas: lista de adjacência
// Para redes densas: matriz de adjacência
void otimizar_representacao(RedeSocial* rede) {
    float densidade = calcular_densidade_rede(rede);
    rede->usar_matriz = (densidade > 0.5);
}
```

### 2. **Cache de Caminhos**
```c
typedef struct {
    int origem, destino;
    CaminhoAmizade* caminho;
    time_t timestamp;
} CacheCaminho;
```

## 🏆 Critérios de Avaliação

### ✅ Implementação do Grafo (40%)
- [ ] Estruturas bem definidas
- [ ] Operações básicas corretas
- [ ] Gerenciamento de memória adequado
- [ ] Escolha apropriada de representação

### ✅ Algoritmos (35%)
- [ ] BFS/DFS implementados corretamente
- [ ] Busca de caminho funcional
- [ ] Sugestões de amizade
- [ ] Detecção básica de comunidades

### ✅ Análise e Métricas (15%)
- [ ] Cálculo de densidade
- [ ] Estatísticas da rede
- [ ] Centralidade básica
- [ ] Relatórios informativos

### ✅ Interface e Usabilidade (10%)
- [ ] Menu organizado
- [ ] Visualização clara
- [ ] Tratamento de erros
- [ ] Dados de exemplo

## 🎁 Bônus (+1 ponto)

- **Algoritmo PageRank** para ranking de usuários
- **Visualização gráfica** com caracteres ASCII
- **Sistema de recomendações** avançado
- **Detecção de comunidades** com algoritmo sofisticado
- **Métricas de rede** completas (diâmetro, clustering)
- **Persistência** com arquivos
- **Interface interativa** com cores

## 📚 Conceitos Revisados

- ✅ Representação de grafos
- ✅ Algoritmos BFS e DFS
- ✅ Análise de redes sociais
- ✅ Detecção de comunidades
- ✅ Métricas de centralidade
- ✅ Teoria dos grafos aplicada

## 🔗 Aplicações Reais

- **Redes sociais:** Facebook, LinkedIn, Twitter
- **Sistemas de recomendação:** Netflix, Amazon
- **Análise de redes:** Gephi, NetworkX
- **Bioinformática:** Redes de proteínas
- **Transporte:** Redes de rotas

## 📝 Entrega

Estrutura sugerida:
```
exercicio15/
├── src/
│   ├── rede_social.c    # Implementação principal
│   ├── rede_social.h    # Estruturas e protótipos
│   ├── algoritmos.c     # BFS, DFS, análise
│   ├── visualizacao.c   # Funções de display
│   └── dados_exemplo.c  # População inicial
├── dados/
│   └── usuarios.txt     # Dados persistentes
├── Makefile
└── README.md
```

---
**🚀 Desafio Supremo:** Implementar um algoritmo que detecta usuários influenciadores e calcula seu PageRank na rede!
