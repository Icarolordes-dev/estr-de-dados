/**
 * 🎯 EXEMPLO PRÁTICO: Grafos Básicos
 * 
 * Este programa demonstra as duas principais formas de representar grafos:
 * - Matriz de Adjacência
 * - Lista de Adjacência
 * 
 * Inclui exemplos práticos baseados nas 7 Pontes de Königsberg
 * e aplicações em redes sociais e mapas.
 * 
 * Compile: gcc grafos_basico.c -o grafos_basico
 * Execute: ./grafos_basico
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Definições para o tamanho máximo do grafo
#define MAX_VERTICES 10

// ===== ESTRUTURAS PARA LISTA DE ADJACÊNCIA =====
typedef struct No {
    int vertice;
    int peso;           // Para grafos ponderados
    struct No* proximo;
} No;

typedef struct {
    No* cabeca;
    char nome[20];      // Nome do vértice (ex: "João", "Cidade A")
} ListaAdjacencia;

// ===== ESTRUTURA PARA GRAFO =====
typedef struct {
    int matriz[MAX_VERTICES][MAX_VERTICES];  // Matriz de adjacência
    ListaAdjacencia lista[MAX_VERTICES];     // Lista de adjacência
    int num_vertices;
    bool eh_direcionado;
    bool eh_ponderado;
} Grafo;

// ===== FUNÇÕES AUXILIARES =====

void limpar_tela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pausar() {
    printf("\nPressione Enter para continuar...");
    getchar();
    getchar();
}

// ===== FUNÇÕES DE INICIALIZAÇÃO =====

Grafo* criar_grafo(int num_vertices, bool direcionado, bool ponderado) {
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    
    grafo->num_vertices = num_vertices;
    grafo->eh_direcionado = direcionado;
    grafo->eh_ponderado = ponderado;
    
    // Inicializar matriz de adjacência
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            grafo->matriz[i][j] = 0;
        }
    }
    
    // Inicializar lista de adjacência
    for (int i = 0; i < MAX_VERTICES; i++) {
        grafo->lista[i].cabeca = NULL;
        sprintf(grafo->lista[i].nome, "V%d", i);
    }
    
    return grafo;
}

void definir_nome_vertice(Grafo* grafo, int vertice, const char* nome) {
    if (vertice >= 0 && vertice < grafo->num_vertices) {
        strcpy(grafo->lista[vertice].nome, nome);
    }
}

// ===== FUNÇÕES PARA MATRIZ DE ADJACÊNCIA =====

void adicionar_aresta_matriz(Grafo* grafo, int origem, int destino, int peso) {
    if (origem >= 0 && origem < grafo->num_vertices && 
        destino >= 0 && destino < grafo->num_vertices) {
        
        if (grafo->eh_ponderado) {
            grafo->matriz[origem][destino] = peso;
        } else {
            grafo->matriz[origem][destino] = 1;
        }
        
        // Se não é direcionado, adiciona a aresta inversa
        if (!grafo->eh_direcionado) {
            grafo->matriz[destino][origem] = grafo->matriz[origem][destino];
        }
    }
}

void imprimir_matriz_adjacencia(Grafo* grafo) {
    printf("\n🔢 MATRIZ DE ADJACÊNCIA\n");
    printf("=" * 40);
    printf("\n\n    ");
    
    // Cabeçalho das colunas
    for (int i = 0; i < grafo->num_vertices; i++) {
        printf("%8s", grafo->lista[i].nome);
    }
    printf("\n");
    
    // Linhas da matriz
    for (int i = 0; i < grafo->num_vertices; i++) {
        printf("%s", grafo->lista[i].nome);
        for (int j = 0; j < grafo->num_vertices; j++) {
            printf("%8d", grafo->matriz[i][j]);
        }
        printf("\n");
    }
    
    printf("\n💡 Interpretação:\n");
    printf("   • 0 = Não há conexão\n");
    if (grafo->eh_ponderado) {
        printf("   • Número > 0 = Peso da aresta\n");
    } else {
        printf("   • 1 = Há conexão\n");
    }
}

// ===== FUNÇÕES PARA LISTA DE ADJACÊNCIA =====

void adicionar_aresta_lista(Grafo* grafo, int origem, int destino, int peso) {
    if (origem >= 0 && origem < grafo->num_vertices && 
        destino >= 0 && destino < grafo->num_vertices) {
        
        // Criar novo nó
        No* novo_no = (No*)malloc(sizeof(No));
        novo_no->vertice = destino;
        novo_no->peso = peso;
        novo_no->proximo = grafo->lista[origem].cabeca;
        grafo->lista[origem].cabeca = novo_no;
        
        // Se não é direcionado, adiciona a aresta inversa
        if (!grafo->eh_direcionado) {
            No* novo_no_inv = (No*)malloc(sizeof(No));
            novo_no_inv->vertice = origem;
            novo_no_inv->peso = peso;
            novo_no_inv->proximo = grafo->lista[destino].cabeca;
            grafo->lista[destino].cabeca = novo_no_inv;
        }
    }
}

void imprimir_lista_adjacencia(Grafo* grafo) {
    printf("\n📋 LISTA DE ADJACÊNCIA\n");
    printf("=" * 40);
    printf("\n");
    
    for (int i = 0; i < grafo->num_vertices; i++) {
        printf("%s -> ", grafo->lista[i].nome);
        
        No* atual = grafo->lista[i].cabeca;
        if (atual == NULL) {
            printf("∅ (nenhuma conexão)");
        } else {
            while (atual != NULL) {
                if (grafo->eh_ponderado) {
                    printf("%s(peso:%d)", grafo->lista[atual->vertice].nome, atual->peso);
                } else {
                    printf("%s", grafo->lista[atual->vertice].nome);
                }
                atual = atual->proximo;
                if (atual != NULL) {
                    printf(" -> ");
                }
            }
        }
        printf("\n");
    }
}

// ===== ANÁLISE DO GRAFO =====

int calcular_grau_vertice(Grafo* grafo, int vertice) {
    int grau = 0;
    
    if (grafo->eh_direcionado) {
        // Para grafos direcionados, calcular grau de saída
        for (int i = 0; i < grafo->num_vertices; i++) {
            if (grafo->matriz[vertice][i] > 0) {
                grau++;
            }
        }
    } else {
        // Para grafos não direcionados
        for (int i = 0; i < grafo->num_vertices; i++) {
            if (grafo->matriz[vertice][i] > 0) {
                grau++;
            }
        }
    }
    
    return grau;
}

bool eh_conexo(Grafo* grafo) {
    // Verificação simplificada para grafos pequenos
    // Em grafos maiores, usaríamos DFS ou BFS
    
    for (int i = 0; i < grafo->num_vertices; i++) {
        bool tem_conexao = false;
        for (int j = 0; j < grafo->num_vertices; j++) {
            if (i != j && (grafo->matriz[i][j] > 0 || grafo->matriz[j][i] > 0)) {
                tem_conexao = true;
                break;
            }
        }
        if (!tem_conexao && grafo->num_vertices > 1) {
            return false;
        }
    }
    return true;
}

void analisar_grafo(Grafo* grafo) {
    printf("\n📊 ANÁLISE DO GRAFO\n");
    printf("=" * 40);
    printf("\n");
    
    printf("Tipo: %s %s\n", 
           grafo->eh_direcionado ? "Direcionado" : "Não-direcionado",
           grafo->eh_ponderado ? "Ponderado" : "Simples");
    
    printf("Número de vértices: %d\n", grafo->num_vertices);
    
    // Calcular número de arestas
    int num_arestas = 0;
    for (int i = 0; i < grafo->num_vertices; i++) {
        for (int j = 0; j < grafo->num_vertices; j++) {
            if (grafo->matriz[i][j] > 0) {
                num_arestas++;
            }
        }
    }
    if (!grafo->eh_direcionado) {
        num_arestas /= 2; // Cada aresta é contada duas vezes
    }
    printf("Número de arestas: %d\n", num_arestas);
    
    // Grau dos vértices
    printf("\nGrau dos vértices:\n");
    for (int i = 0; i < grafo->num_vertices; i++) {
        int grau = calcular_grau_vertice(grafo, i);
        printf("  %s: grau %d", grafo->lista[i].nome, grau);
        
        if (grau == 0) printf(" (isolado)");
        else if (grau == grafo->num_vertices - 1) printf(" (conectado a todos)");
        
        printf("\n");
    }
    
    // Conectividade
    printf("\nConectividade: %s\n", eh_conexo(grafo) ? "✅ Conexo" : "❌ Desconexo");
}

// ===== EXEMPLOS CLÁSSICOS =====

void exemplo_pontes_konigsberg() {
    printf("\n🌉 EXEMPLO: As 7 Pontes de Königsberg\n");
    printf("=" * 50);
    printf("\n");
    printf("Problema histórico que deu origem à teoria dos grafos!\n");
    printf("Pergunta: É possível atravessar todas as 7 pontes exatamente uma vez?\n\n");
    
    // Criar grafo das pontes de Königsberg
    Grafo* konigsberg = criar_grafo(4, false, false);
    
    // Definir nomes dos vértices (massas de terra)
    definir_nome_vertice(konigsberg, 0, "Norte");
    definir_nome_vertice(konigsberg, 1, "Sul");
    definir_nome_vertice(konigsberg, 2, "Leste");
    definir_nome_vertice(konigsberg, 3, "Oeste");
    
    // Adicionar as 7 pontes
    adicionar_aresta_matriz(konigsberg, 0, 1, 1); // Norte-Sul: 1 ponte
    adicionar_aresta_matriz(konigsberg, 0, 2, 2); // Norte-Leste: 2 pontes
    adicionar_aresta_matriz(konigsberg, 0, 3, 2); // Norte-Oeste: 2 pontes
    adicionar_aresta_matriz(konigsberg, 1, 2, 1); // Sul-Leste: 1 ponte
    adicionar_aresta_matriz(konigsberg, 1, 3, 1); // Sul-Oeste: 1 ponte
    
    // Reconstruir para lista de adjacência
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (konigsberg->matriz[i][j] > 0) {
                // Adicionar múltiplas arestas se necessário
                for (int k = 0; k < konigsberg->matriz[i][j]; k++) {
                    adicionar_aresta_lista(konigsberg, i, j, 1);
                }
            }
        }
    }
    
    imprimir_matriz_adjacencia(konigsberg);
    analisar_grafo(konigsberg);
    
    printf("\n🎯 Solução de Euler (1736):\n");
    printf("Para existir um caminho que passe por todas as arestas exatamente\n");
    printf("uma vez, o grafo deve ter no máximo 2 vértices de grau ímpar.\n");
    printf("Neste caso, todos os 4 vértices têm grau ímpar!\n");
    printf("Conclusão: ❌ IMPOSSÍVEL atravessar todas as pontes uma só vez.\n");
    
    free(konigsberg);
    pausar();
}

void exemplo_rede_social() {
    limpar_tela();
    printf("\n👥 EXEMPLO: Rede Social (Instagram/Facebook)\n");
    printf("=" * 50);
    printf("\n");
    printf("Modelando relações de 'seguir' em uma rede social.\n");
    printf("Grafo DIRECIONADO: A seguir B não implica B seguir A.\n\n");
    
    Grafo* rede = criar_grafo(5, true, false); // Direcionado, não ponderado
    
    // Definir usuários
    definir_nome_vertice(rede, 0, "Alice");
    definir_nome_vertice(rede, 1, "Bob");
    definir_nome_vertice(rede, 2, "Carol");
    definir_nome_vertice(rede, 3, "Dave");
    definir_nome_vertice(rede, 4, "Eva");
    
    // Relações de "seguir"
    adicionar_aresta_matriz(rede, 0, 1, 1); // Alice segue Bob
    adicionar_aresta_matriz(rede, 0, 2, 1); // Alice segue Carol
    adicionar_aresta_matriz(rede, 1, 0, 1); // Bob segue Alice (recíproco)
    adicionar_aresta_matriz(rede, 1, 3, 1); // Bob segue Dave
    adicionar_aresta_matriz(rede, 2, 0, 1); // Carol segue Alice
    adicionar_aresta_matriz(rede, 2, 4, 1); // Carol segue Eva
    adicionar_aresta_matriz(rede, 3, 1, 1); // Dave segue Bob
    adicionar_aresta_matriz(rede, 4, 2, 1); // Eva segue Carol
    adicionar_aresta_matriz(rede, 4, 3, 1); // Eva segue Dave
    
    // Reconstruir lista de adjacência
    for (int i = 0; i < rede->num_vertices; i++) {
        for (int j = 0; j < rede->num_vertices; j++) {
            if (rede->matriz[i][j] > 0) {
                adicionar_aresta_lista(rede, i, j, 1);
            }
        }
    }
    
    imprimir_matriz_adjacencia(rede);
    imprimir_lista_adjacencia(rede);
    analisar_grafo(rede);
    
    printf("\n💡 Aplicações em Redes Sociais:\n");
    printf("• Sugestão de amigos (amigos em comum)\n");
    printf("• Detecção de influenciadores (alto grau de entrada)\n");
    printf("• Algoritmos de recomendação\n");
    printf("• Detecção de comunidades\n");
    
    free(rede);
    pausar();
}

void exemplo_mapa_cidades() {
    limpar_tela();
    printf("\n🗺️  EXEMPLO: Mapa de Cidades (GPS/Google Maps)\n");
    printf("=" * 50);
    printf("\n");
    printf("Modelando rotas entre cidades com distâncias.\n");
    printf("Grafo NÃO-DIRECIONADO PONDERADO: estradas de mão dupla com quilometragem.\n\n");
    
    Grafo* mapa = criar_grafo(6, false, true); // Não direcionado, ponderado
    
    // Definir cidades
    definir_nome_vertice(mapa, 0, "São Paulo");
    definir_nome_vertice(mapa, 1, "Rio de Janeiro");
    definir_nome_vertice(mapa, 2, "Belo Horizonte");
    definir_nome_vertice(mapa, 3, "Brasília");
    definir_nome_vertice(mapa, 4, "Salvador");
    definir_nome_vertice(mapa, 5, "Curitiba");
    
    // Adicionar rotas com distâncias (km)
    adicionar_aresta_matriz(mapa, 0, 1, 430);  // SP - RJ
    adicionar_aresta_matriz(mapa, 0, 2, 580);  // SP - BH
    adicionar_aresta_matriz(mapa, 0, 3, 1150); // SP - Brasília
    adicionar_aresta_matriz(mapa, 0, 5, 410);  // SP - Curitiba
    adicionar_aresta_matriz(mapa, 1, 2, 440);  // RJ - BH
    adicionar_aresta_matriz(mapa, 2, 3, 740);  // BH - Brasília
    adicionar_aresta_matriz(mapa, 2, 4, 1200); // BH - Salvador
    adicionar_aresta_matriz(mapa, 3, 4, 1130); // Brasília - Salvador
    
    // Reconstruir lista de adjacência
    for (int i = 0; i < mapa->num_vertices; i++) {
        for (int j = 0; j < mapa->num_vertices; j++) {
            if (mapa->matriz[i][j] > 0) {
                adicionar_aresta_lista(mapa, i, j, mapa->matriz[i][j]);
            }
        }
    }
    
    imprimir_matriz_adjacencia(mapa);
    imprimir_lista_adjacencia(mapa);
    analisar_grafo(mapa);
    
    printf("\n💡 Aplicações em Mapas:\n");
    printf("• Algoritmo de Dijkstra (menor caminho)\n");
    printf("• Planejamento de rotas otimizadas\n");
    printf("• Análise de tráfego e congestionamentos\n");
    printf("• Logística de entregas\n");
    
    free(mapa);
    pausar();
}

// ===== COMPARAÇÃO MATRIZ vs LISTA =====

void comparar_representacoes() {
    limpar_tela();
    printf("\n⚖️  COMPARAÇÃO: Matriz vs Lista de Adjacência\n");
    printf("=" * 55);
    printf("\n");
    
    printf("┌─────────────────────┬─────────────────────┬─────────────────────┐\n");
    printf("│    CARACTERÍSTICA   │   MATRIZ ADJACÊNCIA │   LISTA ADJACÊNCIA  │\n");
    printf("├─────────────────────┼─────────────────────┼─────────────────────┤\n");
    printf("│ Espaço (Memória)    │ O(V²) - sempre      │ O(V + E) - eficiente│\n");
    printf("│ Verificar Aresta    │ O(1) - instantâneo  │ O(grau) - sequencial│\n");
    printf("│ Listar Vizinhos     │ O(V) - percorre linha│ O(grau) - direto   │\n");
    printf("│ Adicionar Aresta    │ O(1) - simples      │ O(1) - no início    │\n");
    printf("│ Grafos Esparsos     │ ❌ Desperdiça espaço │ ✅ Muito eficiente  │\n");
    printf("│ Grafos Densos       │ ✅ Eficiente         │ ❌ Muitos ponteiros │\n");
    printf("│ Implementação       │ ✅ Mais simples      │ ❌ Mais complexa    │\n");
    printf("└─────────────────────┴─────────────────────┴─────────────────────┘\n");
    
    printf("\n🎯 QUANDO USAR CADA UMA:\n\n");
    
    printf("📊 MATRIZ DE ADJACÊNCIA:\n");
    printf("  ✅ Grafos densos (muitas arestas)\n");
    printf("  ✅ Verificações frequentes de conectividade\n");
    printf("  ✅ Algoritmos que precisam de acesso rápido\n");
    printf("  ✅ Grafos pequenos a médios\n");
    printf("  ❌ Grafos esparsos (poucas arestas)\n");
    printf("  ❌ Grafos muito grandes\n\n");
    
    printf("📋 LISTA DE ADJACÊNCIA:\n");
    printf("  ✅ Grafos esparsos (poucas arestas)\n");
    printf("  ✅ Percorrer vizinhos é comum\n");
    printf("  ✅ Grafos que mudam frequentemente\n");
    printf("  ✅ Grafos muito grandes\n");
    printf("  ❌ Verificações frequentes de arestas específicas\n");
    printf("  ❌ Grafos muito densos\n\n");
    
    printf("💡 DICA PRÁTICA:\n");
    printf("   Em aplicações reais, a escolha depende do padrão de uso:\n");
    printf("   • Redes sociais: Lista (esparsas, mudam frequentemente)\n");
    printf("   • Mapas rodoviários: Lista (esparsas, geograficamente limitadas)\n");
    printf("   • Grafos completos: Matriz (todas as conexões existem)\n");
    
    pausar();
}

// ===== MENU PRINCIPAL =====

void mostrar_menu() {
    limpar_tela();
    printf("🎯 GRAFOS BÁSICOS - MENU INTERATIVO\n");
    printf("=" * 40);
    printf("\n");
    printf("Escolha uma opção:\n\n");
    printf("1️⃣  🌉 As 7 Pontes de Königsberg (Problema Histórico)\n");
    printf("2️⃣  👥 Rede Social (Grafo Direcionado)\n");
    printf("3️⃣  🗺️  Mapa de Cidades (Grafo Ponderado)\n");
    printf("4️⃣  ⚖️  Comparar Matriz vs Lista\n");
    printf("5️⃣  📚 Teoria dos Grafos (Conceitos)\n");
    printf("0️⃣  🚪 Sair\n");
    printf("\n" + "=" * 40);
    printf("\nSua escolha: ");
}

void mostrar_teoria() {
    limpar_tela();
    printf("\n📚 TEORIA DOS GRAFOS - CONCEITOS FUNDAMENTAIS\n");
    printf("=" * 55);
    printf("\n");
    
    printf("🎯 DEFINIÇÃO:\n");
    printf("   Um grafo G = (V, E) onde:\n");
    printf("   • V = conjunto de vértices (nós)\n");
    printf("   • E = conjunto de arestas (conexões)\n\n");
    
    printf("🔄 TIPOS DE GRAFOS:\n");
    printf("   • Direcionado: arestas têm sentido (→)\n");
    printf("   • Não-direcionado: arestas são bidirecionais (↔)\n");
    printf("   • Ponderado: arestas têm peso/custo\n");
    printf("   • Simples: sem laços nem múltiplas arestas\n\n");
    
    printf("📊 PROPRIEDADES IMPORTANTES:\n");
    printf("   • Grau: número de conexões de um vértice\n");
    printf("   • Caminho: sequência de vértices conectados\n");
    printf("   • Ciclo: caminho que volta ao vértice inicial\n");
    printf("   • Conectividade: possibilidade de ir de qualquer vértice a outro\n\n");
    
    printf("🌍 APLICAÇÕES NO MUNDO REAL:\n");
    printf("   • 🌐 Internet: páginas (vértices) e links (arestas)\n");
    printf("   • 👥 Redes sociais: pessoas e relacionamentos\n");
    printf("   • 🗺️  GPS: cidades e estradas\n");
    printf("   • ⚡ Redes elétricas: usinas e transmissão\n");
    printf("   • 🧬 Biologia: proteínas e interações\n");
    printf("   • 🤖 IA: redes neurais e processamento\n\n");
    
    printf("🎯 ALGORITMOS CLÁSSICOS:\n");
    printf("   • Busca em largura (BFS)\n");
    printf("   • Busca em profundidade (DFS)\n");
    printf("   • Dijkstra (menor caminho)\n");
    printf("   • Floyd-Warshall (todos os caminhos)\n");
    printf("   • Kruskal/Prim (árvore geradora mínima)\n");
    
    pausar();
}

// ===== FUNÇÃO PRINCIPAL =====

int main() {
    int opcao;
    
    do {
        mostrar_menu();
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                exemplo_pontes_konigsberg();
                break;
            case 2:
                exemplo_rede_social();
                break;
            case 3:
                exemplo_mapa_cidades();
                break;
            case 4:
                comparar_representacoes();
                break;
            case 5:
                mostrar_teoria();
                break;
            case 0:
                limpar_tela();
                printf("\n🎉 Obrigado por explorar o mundo dos Grafos!\n");
                printf("💡 Continue estudando - grafos são fundamentais na computação!\n\n");
                break;
            default:
                printf("\n❌ Opção inválida! Tente novamente.\n");
                pausar();
        }
    } while (opcao != 0);
    
    return 0;
}

/**
 * 🎓 PONTOS DE APRENDIZADO:
 * 
 * 1. REPRESENTAÇÃO:
 *    • Matriz: boa para grafos densos, acesso O(1)
 *    • Lista: boa para grafos esparsos, economia de memória
 * 
 * 2. APLICAÇÕES PRÁTICAS:
 *    • Problemas históricos (Pontes de Königsberg)
 *    • Redes sociais (grafos direcionados)
 *    • Sistemas de navegação (grafos ponderados)
 * 
 * 3. ANÁLISE:
 *    • Grau dos vértices
 *    • Conectividade
 *    • Densidade do grafo
 * 
 * 4. ESCOLHA DA ESTRUTURA:
 *    • Considere o padrão de uso
 *    • Analise espaço vs tempo
 *    • Pense na escalabilidade
 */