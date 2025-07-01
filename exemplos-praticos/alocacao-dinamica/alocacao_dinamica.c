/**
 * 🎯 EXEMPLO PRÁTICO: Alocação Dinâmica de Memória
 * 
 * Este programa demonstra conceitos fundamentais de alocação dinâmica:
 * - malloc(), calloc(), realloc(), free()
 * - Gerenciamento de memória
 * - Arrays dinâmicos
 * - Estruturas dinâmicas
 * - Prevenção de vazamentos de memória
 * 
 * Compile: gcc alocacao_dinamica.c -o alocacao_dinamica
 * Execute: ./alocacao_dinamica
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// ===== ESTRUTURAS PARA DEMONSTRAÇÃO =====

typedef struct {
    char nome[50];
    int idade;
    float salario;
} Pessoa;

typedef struct {
    Pessoa* pessoas;
    int tamanho;
    int capacidade;
} CadastroDinamico;

// ===== FUNÇÕES DE UTILIDADE =====

void limpar_tela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pausar() {
    printf("\n🔽 Pressione Enter para continuar...");
    getchar();
    getchar();
}

void cabecalho(const char* titulo) {
    printf("\n" "="*50 "\n");
    printf("🎯 %s\n", titulo);
    printf("="*50 "\n");
}

// ===== DEMONSTRAÇÃO 1: ARRAYS DINÂMICOS =====

void demonstrar_arrays_dinamicos() {
    cabecalho("ARRAYS DINÂMICOS");
    
    printf("📋 Criando um array dinâmico de inteiros...\n\n");
    
    // 1. Alocar memória para 5 inteiros
    int tamanho_inicial = 5;
    int* numeros = malloc(tamanho_inicial * sizeof(int));
    
    if (numeros == NULL) {
        printf("❌ Erro: Falha na alocação de memória!\n");
        return;
    }
    
    printf("✅ Alocados %d inteiros (%zu bytes)\n", 
           tamanho_inicial, tamanho_inicial * sizeof(int));
    
    // 2. Preencher o array
    printf("\n📝 Preenchendo o array:\n");
    for (int i = 0; i < tamanho_inicial; i++) {
        numeros[i] = (i + 1) * 10;
        printf("   numeros[%d] = %d\n", i, numeros[i]);
    }
    
    // 3. Redimensionar o array
    printf("\n🔄 Redimensionando para 8 elementos...\n");
    int novo_tamanho = 8;
    numeros = realloc(numeros, novo_tamanho * sizeof(int));
    
    if (numeros == NULL) {
        printf("❌ Erro: Falha no redimensionamento!\n");
        return;
    }
    
    printf("✅ Array redimensionado para %d elementos\n", novo_tamanho);
    
    // 4. Preencher novos elementos
    for (int i = tamanho_inicial; i < novo_tamanho; i++) {
        numeros[i] = (i + 1) * 10;
        printf("   numeros[%d] = %d (novo)\n", i, numeros[i]);
    }
    
    // 5. Exibir array completo
    printf("\n📊 Array final:\n[ ");
    for (int i = 0; i < novo_tamanho; i++) {
        printf("%d ", numeros[i]);
    }
    printf("]\n");
    
    // 6. Liberar memória
    free(numeros);
    printf("\n🗑️ Memória liberada com sucesso!\n");
    
    pausar();
}

// ===== DEMONSTRAÇÃO 2: MALLOC VS CALLOC =====

void demonstrar_malloc_vs_calloc() {
    cabecalho("MALLOC vs CALLOC");
    
    int tamanho = 5;
    
    // Teste com malloc
    printf("🔸 Usando malloc():\n");
    int* array_malloc = malloc(tamanho * sizeof(int));
    
    printf("   Valores iniciais (lixo de memória):\n   ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array_malloc[i]);
    }
    printf("\n");
    
    // Teste com calloc
    printf("\n🔸 Usando calloc():\n");
    int* array_calloc = calloc(tamanho, sizeof(int));
    
    printf("   Valores iniciais (zerados):\n   ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array_calloc[i]);
    }
    printf("\n");
    
    // Comparação
    printf("\n📋 Comparação:\n");
    printf("   malloc(): Mais rápido, valores indefinidos\n");
    printf("   calloc(): Mais lento, valores zerados\n");
    printf("   Use malloc() quando for inicializar depois\n");
    printf("   Use calloc() quando precisar de zeros\n");
    
    free(array_malloc);
    free(array_calloc);
    
    pausar();
}

// ===== DEMONSTRAÇÃO 3: ESTRUTURAS DINÂMICAS =====

CadastroDinamico* criar_cadastro() {
    CadastroDinamico* cadastro = malloc(sizeof(CadastroDinamico));
    
    if (cadastro == NULL) {
        return NULL;
    }
    
    cadastro->capacidade = 2;  // Começar pequeno para mostrar redimensionamento
    cadastro->tamanho = 0;
    cadastro->pessoas = malloc(cadastro->capacidade * sizeof(Pessoa));
    
    if (cadastro->pessoas == NULL) {
        free(cadastro);
        return NULL;
    }
    
    return cadastro;
}

bool adicionar_pessoa(CadastroDinamico* cadastro, const char* nome, int idade, float salario) {
    // Verificar se precisa redimensionar
    if (cadastro->tamanho >= cadastro->capacidade) {
        printf("   📈 Redimensionando cadastro de %d para %d pessoas...\n", 
               cadastro->capacidade, cadastro->capacidade * 2);
        
        int nova_capacidade = cadastro->capacidade * 2;
        Pessoa* novo_array = realloc(cadastro->pessoas, nova_capacidade * sizeof(Pessoa));
        
        if (novo_array == NULL) {
            printf("   ❌ Erro: Falha no redimensionamento!\n");
            return false;
        }
        
        cadastro->pessoas = novo_array;
        cadastro->capacidade = nova_capacidade;
        printf("   ✅ Redimensionamento concluído!\n");
    }
    
    // Adicionar nova pessoa
    Pessoa* nova_pessoa = &cadastro->pessoas[cadastro->tamanho];
    strcpy(nova_pessoa->nome, nome);
    nova_pessoa->idade = idade;
    nova_pessoa->salario = salario;
    
    cadastro->tamanho++;
    
    printf("   ✅ Adicionado: %s (%d anos, R$ %.2f)\n", nome, idade, salario);
    return true;
}

void exibir_cadastro(CadastroDinamico* cadastro) {
    printf("\n📋 Cadastro Atual (%d/%d):\n", cadastro->tamanho, cadastro->capacidade);
    printf("   +------------------+-------+----------+\n");
    printf("   | Nome             | Idade | Salário  |\n");
    printf("   +------------------+-------+----------+\n");
    
    for (int i = 0; i < cadastro->tamanho; i++) {
        Pessoa* p = &cadastro->pessoas[i];
        printf("   | %-16s | %5d | %8.2f |\n", p->nome, p->idade, p->salario);
    }
    
    printf("   +------------------+-------+----------+\n");
    printf("   Memória usada: %zu bytes\n", 
           sizeof(CadastroDinamico) + (cadastro->capacidade * sizeof(Pessoa)));
}

void liberar_cadastro(CadastroDinamico* cadastro) {
    if (cadastro != NULL) {
        free(cadastro->pessoas);
        free(cadastro);
        printf("🗑️ Cadastro liberado da memória\n");
    }
}

void demonstrar_estruturas_dinamicas() {
    cabecalho("ESTRUTURAS DINÂMICAS - CADASTRO DE PESSOAS");
    
    printf("📋 Criando cadastro dinâmico...\n");
    CadastroDinamico* cadastro = criar_cadastro();
    
    if (cadastro == NULL) {
        printf("❌ Erro: Falha na criação do cadastro!\n");
        return;
    }
    
    printf("✅ Cadastro criado com capacidade inicial: %d pessoas\n", cadastro->capacidade);
    
    // Adicionar pessoas
    printf("\n👥 Adicionando pessoas:\n");
    adicionar_pessoa(cadastro, "Ana Silva", 25, 3500.00);
    adicionar_pessoa(cadastro, "Bruno Costa", 30, 4200.00);
    
    exibir_cadastro(cadastro);
    
    printf("\n👥 Adicionando mais pessoas (vai redimensionar):\n");
    adicionar_pessoa(cadastro, "Carlos Pereira", 28, 3800.00);
    adicionar_pessoa(cadastro, "Diana Santos", 32, 5100.00);
    adicionar_pessoa(cadastro, "Eduardo Lima", 27, 3600.00);
    
    exibir_cadastro(cadastro);
    
    liberar_cadastro(cadastro);
    
    pausar();
}

// ===== DEMONSTRAÇÃO 4: PROBLEMAS COMUNS =====

void demonstrar_problemas_comuns() {
    cabecalho("PROBLEMAS COMUNS E COMO EVITÁ-LOS");
    
    printf("⚠️ 1. VAZAMENTO DE MEMÓRIA:\n");
    printf("   ❌ Ruim:\n");
    printf("      int* ptr = malloc(100 * sizeof(int));\n");
    printf("      // ... usar ptr ...\n");
    printf("      // ESQUECEU DE FAZER free(ptr)!\n\n");
    
    printf("   ✅ Bom:\n");
    printf("      int* ptr = malloc(100 * sizeof(int));\n");
    printf("      // ... usar ptr ...\n");
    printf("      free(ptr);\n");
    printf("      ptr = NULL;  // Evita uso acidental\n\n");
    
    printf("⚠️ 2. USO APÓS LIBERAÇÃO:\n");
    printf("   ❌ Ruim:\n");
    printf("      free(ptr);\n");
    printf("      ptr[0] = 10;  // ERRO! Acesso a memória liberada\n\n");
    
    printf("   ✅ Bom:\n");
    printf("      free(ptr);\n");
    printf("      ptr = NULL;\n");
    printf("      // Agora qualquer acesso a ptr causará erro visível\n\n");
    
    printf("⚠️ 3. LIBERAÇÃO DUPLA:\n");
    printf("   ❌ Ruim:\n");
    printf("      free(ptr);\n");
    printf("      free(ptr);  // ERRO! Liberação dupla\n\n");
    
    printf("   ✅ Bom:\n");
    printf("      free(ptr);\n");
    printf("      ptr = NULL;\n");
    printf("      // free(NULL) é seguro\n\n");
    
    printf("⚠️ 4. ACESSO FORA DOS LIMITES:\n");
    printf("   ❌ Ruim:\n");
    printf("      int* arr = malloc(5 * sizeof(int));\n");
    printf("      arr[10] = 100;  // ERRO! Acesso fora dos limites\n\n");
    
    printf("   ✅ Bom:\n");
    printf("      int* arr = malloc(5 * sizeof(int));\n");
    printf("      // Sempre verificar limites antes de acessar\n");
    printf("      if (index >= 0 && index < 5) arr[index] = valor;\n");
    
    pausar();
}

// ===== DEMONSTRAÇÃO 5: BOAS PRÁTICAS =====

void demonstrar_boas_praticas() {
    cabecalho("BOAS PRÁTICAS DE ALOCAÇÃO DINÂMICA");
    
    printf("✅ 1. SEMPRE VERIFICAR RETORNO DE MALLOC:\n");
    printf("   int* ptr = malloc(size);\n");
    printf("   if (ptr == NULL) {\n");
    printf("       // Tratar erro de alocação\n");
    printf("       return ERRO_MEMORIA;\n");
    printf("   }\n\n");
    
    printf("✅ 2. USAR SIZEOF COM TIPO, NÃO NÚMERO:\n");
    printf("   ❌ Ruim:   malloc(4 * n);  // E se int mudar de tamanho?\n");
    printf("   ✅ Bom:    malloc(sizeof(int) * n);\n");
    printf("   ✅ Melhor: malloc(n * sizeof(*ptr));  // Tipo do ponteiro\n\n");
    
    printf("✅ 3. INICIALIZAR PONTEIROS:\n");
    printf("   int* ptr = NULL;  // Sempre inicializar\n");
    printf("   ptr = malloc(size);\n\n");
    
    printf("✅ 4. LIBERAR E ANULAR:\n");
    printf("   free(ptr);\n");
    printf("   ptr = NULL;  // Evita uso acidental\n\n");
    
    printf("✅ 5. FUNÇÃO DE LIMPEZA:\n");
    printf("   void cleanup(int** ptr) {\n");
    printf("       if (ptr && *ptr) {\n");
    printf("           free(*ptr);\n");
    printf("           *ptr = NULL;\n");
    printf("       }\n");
    printf("   }\n\n");
    
    printf("✅ 6. USAR VALGRIND PARA DEPURAÇÃO:\n");
    printf("   $ valgrind --leak-check=full ./programa\n");
    printf("   // Detecta vazamentos e uso incorreto de memória\n");
    
    pausar();
}

// ===== MENU PRINCIPAL =====

void exibir_menu() {
    limpar_tela();
    printf("🎯 DEMONSTRAÇÃO: ALOCAÇÃO DINÂMICA DE MEMÓRIA\n");
    printf("="*50 "\n");
    printf("1. 📊 Arrays Dinâmicos\n");
    printf("2. 🔄 malloc() vs calloc()\n");
    printf("3. 🏗️ Estruturas Dinâmicas (Cadastro)\n");
    printf("4. ⚠️ Problemas Comuns\n");
    printf("5. ✅ Boas Práticas\n");
    printf("6. 🎮 Demonstração Interativa\n");
    printf("0. 🚪 Sair\n");
    printf("="*50 "\n");
    printf("📝 Escolha uma opção: ");
}

void demonstracao_interativa() {
    cabecalho("DEMONSTRAÇÃO INTERATIVA");
    
    printf("🎮 Vamos criar um array dinâmico juntos!\n\n");
    
    int tamanho;
    printf("📊 Quantos números você quer armazenar? ");
    scanf("%d", &tamanho);
    
    // Alocar array
    int* numeros = malloc(tamanho * sizeof(int));
    if (numeros == NULL) {
        printf("❌ Erro na alocação!\n");
        return;
    }
    
    printf("✅ Array de %d inteiros alocado!\n\n", tamanho);
    
    // Preencher array
    printf("📝 Digite os %d números:\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        printf("   Número %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }
    
    // Exibir resultados
    printf("\n📊 Seu array:\n[ ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", numeros[i]);
    }
    printf("]\n");
    
    // Calcular estatísticas
    int soma = 0, maior = numeros[0], menor = numeros[0];
    for (int i = 0; i < tamanho; i++) {
        soma += numeros[i];
        if (numeros[i] > maior) maior = numeros[i];
        if (numeros[i] < menor) menor = numeros[i];
    }
    
    printf("\n📈 Estatísticas:\n");
    printf("   Soma: %d\n", soma);
    printf("   Média: %.2f\n", (float)soma / tamanho);
    printf("   Maior: %d\n", maior);
    printf("   Menor: %d\n", menor);
    printf("   Memória usada: %zu bytes\n", tamanho * sizeof(int));
    
    free(numeros);
    printf("\n🗑️ Memória liberada!\n");
    
    pausar();
}

// ===== FUNÇÃO PRINCIPAL =====

int main() {
    int opcao;
    
    do {
        exibir_menu();
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                demonstrar_arrays_dinamicos();
                break;
            case 2:
                demonstrar_malloc_vs_calloc();
                break;
            case 3:
                demonstrar_estruturas_dinamicas();
                break;
            case 4:
                demonstrar_problemas_comuns();
                break;
            case 5:
                demonstrar_boas_praticas();
                break;
            case 6:
                demonstracao_interativa();
                break;
            case 0:
                printf("\n👋 Obrigado por usar o programa!\n");
                printf("💡 Lembre-se: Todo malloc() precisa de um free()!\n");
                break;
            default:
                printf("❌ Opção inválida! Tente novamente.\n");
                pausar();
        }
    } while (opcao != 0);
    
    return 0;
}
