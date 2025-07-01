# 🌐 Aula 08: Representação de Grafos

## 📊 Dados da Aula
- **Disciplina:** Estruturas de Dados
- **Professor:** [Nome do Professor]
- **Data:** [Data da Aula]
- **Duração:** 2 horas

## 🎯 Objetivos de Aprendizagem
Ao final desta aula, você será capaz de:
- Compreender as diferentes formas de representar grafos
- Implementar matriz de adjacência e lista de adjacência
- Comparar vantagens e desvantagens de cada representação
- Aplicar a representação mais adequada para diferentes problemas
- Analisar complexidade de espaço e tempo das operações

## 📚 Conteúdo Teórico

### 1. Revisão: O que são Grafos?

```
🌟 Analogia: Rede Social
Imagine o Facebook ou Instagram:
- Cada pessoa = VÉRTICE
- Cada amizade = ARESTA
- Seguir alguém = ARESTA DIRECIONADA
```

**Definição Formal:**
- G = (V, E) onde:
  - V = conjunto de vértices
  - E = conjunto de arestas

### 2. Tipos de Grafos

| Tipo | Característica | Exemplo |
|------|----------------|---------|
| **Simples** | Sem múltiplas arestas | Mapa de cidades |
| **Múltiplo** | Múltiplas arestas entre vértices | Voos entre cidades |
| **Direcionado** | Arestas têm direção | Rua de mão única |
| **Não-direcionado** | Arestas bidirecionais | Estrada de mão dupla |
| **Ponderado** | Arestas têm peso | Distância entre cidades |
| **Não-ponderado** | Todas as arestas iguais | Amizade no Facebook |

### 3. Representação por Matriz de Adjacência

```
🎨 Visualização:
    A B C D
A [ 0 1 0 1 ]
B [ 1 0 1 0 ]
C [ 0 1 0 1 ]
D [ 1 0 1 0 ]

💡 Interpretação:
- A[i][j] = 1: existe aresta de i para j
- A[i][j] = 0: não existe aresta
```

**Estrutura em C:**
```c
#define MAX_VERTICES 100
int matriz[MAX_VERTICES][MAX_VERTICES];
```

#### Vantagens da Matriz de Adjacência:
- ✅ Verificação rápida de aresta: O(1)
- ✅ Fácil implementação
- ✅ Adequada para grafos densos
- ✅ Operações em grafos simples

#### Desvantagens da Matriz de Adjacência:
- ❌ Uso de memória: O(V²)
- ❌ Inserção/remoção de vértice: O(V²)
- ❌ Iteração sobre vizinhos: O(V)
- ❌ Desperdício em grafos esparsos

### 4. Representação por Lista de Adjacência

```
🎨 Visualização:
A -> [B, D]
B -> [A, C]
C -> [B, D]
D -> [A, C]

💡 Cada vértice mantém uma lista de seus vizinhos
```

**Estrutura em C:**
```c
typedef struct No {
    int vertice;
    struct No* proximo;
} No;

typedef struct {
    No* cabeca;
} ListaAdjacencia[MAX_VERTICES];
```

#### Vantagens da Lista de Adjacência:
- ✅ Uso eficiente de memória: O(V + E)
- ✅ Iteração rápida sobre vizinhos: O(grau)
- ✅ Inserção/remoção de aresta: O(1)
- ✅ Adequada para grafos esparsos

#### Desvantagens da Lista de Adjacência:
- ❌ Verificação de aresta: O(grau)
- ❌ Implementação mais complexa
- ❌ Overhead de ponteiros

### 5. Comparativo de Complexidades

| Operação | Matriz | Lista |
|----------|--------|-------|
| **Espaço** | O(V²) | O(V + E) |
| **Adicionar vértice** | O(V²) | O(1) |
| **Adicionar aresta** | O(1) | O(1) |
| **Remover aresta** | O(1) | O(grau) |
| **Verificar aresta** | O(1) | O(grau) |
| **Listar vizinhos** | O(V) | O(grau) |

### 6. Quando Usar Cada Representação?

```
🤔 Escolha da Representação:

MATRIZ DE ADJACÊNCIA:
- Grafos densos (muitas arestas)
- Verificações frequentes de aresta
- Grafos pequenos
- Algoritmos que precisam de acesso aleatório

LISTA DE ADJACÊNCIA:
- Grafos esparsos (poucas arestas)
- Iteração frequente sobre vizinhos
- Grafos grandes
- Economia de memória é importante
```

### 7. Representações Alternativas

#### 7.1 Lista de Arestas
```c
typedef struct {
    int origem, destino, peso;
} Aresta;

Aresta arestas[MAX_ARESTAS];
```

**Quando usar:**
- Algoritmos que processam todas as arestas
- Kruskal para árvore geradora mínima
- Grafos muito esparsos

#### 7.2 Matriz de Incidência
```
        e1 e2 e3 e4
    A [ 1  1  0  0 ]
    B [-1  0  1  0 ]
    C [ 0 -1 -1  1 ]
    D [ 0  0  0 -1 ]
```

**Quando usar:**
- Análise teórica de grafos
- Cálculos matriciais
- Grafos com múltiplas arestas

### 8. Implementação Híbrida

```c
typedef struct {
    // Para operações rápidas
    int matriz[MAX_V][MAX_V];
    
    // Para economia de espaço
    ListaAdjacencia* lista;
    
    int num_vertices;
    bool usa_matriz;  // Escolha dinâmica
} GrafoHibrido;
```

## 🛠️ Exemplos Práticos

### Exemplo 1: Grafo de Amizades
```
   Ana ---- Bruno
    |         |
    |         |
  Clara ---- Diego

Matriz:           Lista:
     A B C D      Ana: [Bruno, Clara]
A [ 0 1 1 0 ]    Bruno: [Ana, Diego]  
B [ 1 0 0 1 ]    Clara: [Ana, Diego]
C [ 1 0 0 1 ]    Diego: [Bruno, Clara]
D [ 0 1 1 0 ]
```

### Exemplo 2: Mapa de Cidades (Ponderado)
```
São Paulo --400km-- Rio de Janeiro
    |                      |
  350km                  450km
    |                      |
Campinas ----200km---- Belo Horizonte

Matriz com pesos:
        SP  RJ  CP  BH
    SP [ 0 400 350  0 ]
    RJ [400  0   0 450]
    CP [350  0   0 200]
    BH [ 0 450 200  0 ]
```

## 💡 Dicas de Implementação

### 1. Escolha da Representação
```c
// Função para escolher representação
RepresentacaoGrafo escolher_representacao(int vertices, int arestas) {
    double densidade = (2.0 * arestas) / (vertices * (vertices - 1));
    
    if (densidade > 0.5) {
        return MATRIZ_ADJACENCIA;  // Grafo denso
    } else {
        return LISTA_ADJACENCIA;   // Grafo esparso
    }
}
```

### 2. Conversão Entre Representações
```c
// Converter matriz para lista
void matriz_para_lista(int matriz[][MAX_V], ListaAdj lista[], int v) {
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (matriz[i][j] != 0) {
                inserir_aresta_lista(lista, i, j, matriz[i][j]);
            }
        }
    }
}
```

### 3. Detecção Automática
```c
typedef struct {
    void* representacao;
    TipoRep tipo;
    
    // Funções polimórficas
    bool (*tem_aresta)(void* grafo, int u, int v);
    void (*add_aresta)(void* grafo, int u, int v);
} GrafoGenerico;
```

## 🎮 Exercícios Práticos

### Exercício 1: Análise de Representação
**Problema:** Para cada cenário, escolha a melhor representação:

a) Rede social com 1 milhão de usuários, 2 milhões de amizades
b) Tabuleiro de xadrez 8x8 para movimentos de peças  
c) Mapa rodoviário do Brasil
d) Grafo completo com 50 vértices

### Exercício 2: Implementação
**Problema:** Implemente uma função que:
- Receba um grafo em matriz de adjacência
- Converta para lista de adjacência
- Compare o uso de memória

### Exercício 3: Análise de Complexidade
**Problema:** Para um grafo com V vértices e E arestas:
- Calcule o tempo para encontrar todos os vértices alcançáveis
- Compare matriz vs lista de adjacência
- Determine o ponto de equilíbrio

## 🚀 Aplicações Reais

### 1. Sistemas de Recomendação
```
Usuários -> Produtos comprados
Matriz: Usuário x Produto
Lista: Cada usuário -> lista de produtos
```

### 2. Redes de Computadores
```
Roteadores -> Conexões diretas
Matriz: Para roteamento rápido
Lista: Para economia de memória
```

### 3. Bioinformática
```
Proteínas -> Interações
Lista: Redes de interação esparsas
Matriz: Análises densas de expressão
```

### 4. Jogos
```
Mapa do jogo -> Caminhos possíveis
Matriz: Mapas pequenos, acesso rápido
Lista: Mundos abertos, economia de memória
```

## 📈 Métricas de Decisão

### Fórmula de Densidade
```
densidade = 2|E| / (|V|(|V|-1))

Se densidade > 0.5: usar matriz
Se densidade < 0.5: usar lista
```

### Análise de Memória
```
Matriz: V² * sizeof(int) bytes
Lista: (V + 2E) * sizeof(pointer) bytes

Ponto de equilíbrio: E ≈ V²/4
```

### Análise de Operações
```
Se verificações de aresta > iterações: matriz
Se iterações > verificações: lista
```

## 🔗 Links Úteis

### Recursos Didáticos
- [Visualizador de Grafos Online](https://graphonline.ru/)
- [Graph Algorithm Visualizer](https://visualgo.net/en/graphds)

### Exemplos Práticos
- [`/exemplos-praticos/grafos/grafos_basico.c`](../exemplos-praticos/grafos/grafos_basico.c)
- [Implementação de Conversões](../exemplos-praticos/grafos/conversoes.c)

### Próximas Aulas
- **Aula 09:** Algoritmos de Busca em Grafos (BFS/DFS)
- **Aula 10:** Algoritmos de Caminho Mínimo
- **Aula 11:** Árvores Geradoras Mínimas

## 📝 Resumo da Aula

1. **Matriz de Adjacência**: Boa para grafos densos, verificação rápida de arestas
2. **Lista de Adjacência**: Boa para grafos esparsos, economia de memória
3. **Escolha**: Baseada na densidade do grafo e operações mais frequentes
4. **Aplicações**: Cada representação tem seus casos de uso ideais

## 🏠 Tarefa de Casa

1. Implemente conversão entre as duas representações
2. Analise a densidade do grafo das suas amizades no Facebook
3. Compare o uso de memória para grafos de diferentes densidades
4. Pesquise outras representações (lista de arestas, matriz de incidência)

---
**Próxima aula:** Algoritmos de Busca em Grafos (BFS e DFS)
