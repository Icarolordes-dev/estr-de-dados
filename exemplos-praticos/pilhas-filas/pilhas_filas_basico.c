/**
 * 🎯 EXEMPLO PRÁTICO: Pilhas e Filas Básicas
 * 
 * Este programa demonstra implementações básicas de:
 * - Pilha (Stack) com princípio LIFO
 * - Fila (Queue) com princípio FIFO
 * - Operações fundamentais de cada estrutura
 * - Aplicações práticas
 * 
 * Compile: gcc pilhas_filas_basico.c -o pilhas_filas_basico
 * Execute: ./pilhas_filas_basico
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 10

// ===== ESTRUTURA E OPERAÇÕES DA PILHA =====

typedef struct {
    int dados[MAX_SIZE];
    int topo;
} Pilha;

// Inicializar pilha
void pilha_inicializar(Pilha* p) {
    p->topo = -1;
}

// Verificar se pilha está vazia
bool pilha_vazia(Pilha* p) {
    return p->topo == -1;
}

// Verificar se pilha está cheia
bool pilha_cheia(Pilha* p) {
    return p->topo == MAX_SIZE - 1;
}

// Empilhar (push)
bool pilha_push(Pilha* p, int valor) {
    if (pilha_cheia(p)) {
        printf("❌ Erro: Pilha cheia! Não é possível empilhar %d\n", valor);
        return false;
    }
    p->topo++;
    p->dados[p->topo] = valor;
    printf("✅ Empilhado: %d (topo = %d)\n", valor, p->topo);
    return true;
}

// Desempilhar (pop)
int pilha_pop(Pilha* p) {
    if (pilha_vazia(p)) {
        printf("❌ Erro: Pilha vazia! Não há nada para desempilhar\n");
        return -1;
    }
    int valor = p->dados[p->topo];
    p->topo--;
    printf("✅ Desempilhado: %d (novo topo = %d)\n", valor, p->topo);
    return valor;
}

// Espiar o topo (peek)
int pilha_top(Pilha* p) {
    if (pilha_vazia(p)) {
        printf("❌ Pilha vazia!\n");
        return -1;
    }
    return p->dados[p->topo];
}

// Imprimir pilha
void pilha_imprimir(Pilha* p) {
    printf("\n📚 Estado da Pilha (LIFO):\n");
    if (pilha_vazia(p)) {
        printf("   [VAZIA]\n");
        return;
    }
    
    printf("   TOPO\n");
    for (int i = p->topo; i >= 0; i--) {
        printf("   [%2d] %s\n", p->dados[i], (i == p->topo) ? "← TOPO" : "");
    }
    printf("   BASE\n");
}

// ===== ESTRUTURA E OPERAÇÕES DA FILA =====

typedef struct {
    int dados[MAX_SIZE];
    int inicio;
    int fim;
    int tamanho;
} Fila;

// Inicializar fila
void fila_inicializar(Fila* f) {
    f->inicio = 0;
    f->fim = -1;
    f->tamanho = 0;
}

// Verificar se fila está vazia
bool fila_vazia(Fila* f) {
    return f->tamanho == 0;
}

// Verificar se fila está cheia
bool fila_cheia(Fila* f) {
    return f->tamanho == MAX_SIZE;
}

// Enfileirar (enqueue)
bool fila_enqueue(Fila* f, int valor) {
    if (fila_cheia(f)) {
        printf("❌ Erro: Fila cheia! Não é possível enfileirar %d\n", valor);
        return false;
    }
    f->fim = (f->fim + 1) % MAX_SIZE;  // Fila circular
    f->dados[f->fim] = valor;
    f->tamanho++;
    printf("✅ Enfileirado: %d (tamanho = %d)\n", valor, f->tamanho);
    return true;
}

// Desenfileirar (dequeue)
int fila_dequeue(Fila* f) {
    if (fila_vazia(f)) {
        printf("❌ Erro: Fila vazia! Não há nada para desenfileirar\n");
        return -1;
    }
    int valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX_SIZE;  // Fila circular
    f->tamanho--;
    printf("✅ Desenfileirado: %d (tamanho = %d)\n", valor, f->tamanho);
    return valor;
}

// Consultar início da fila (front)
int fila_front(Fila* f) {
    if (fila_vazia(f)) {
        printf("❌ Fila vazia!\n");
        return -1;
    }
    return f->dados[f->inicio];
}

// Imprimir fila
void fila_imprimir(Fila* f) {
    printf("\n🚶‍♀️ Estado da Fila (FIFO):\n");
    if (fila_vazia(f)) {
        printf("   [VAZIA]\n");
        return;
    }
    
    printf("   INÍCIO → ");
    for (int i = 0; i < f->tamanho; i++) {
        int pos = (f->inicio + i) % MAX_SIZE;
        printf("[%2d] ", f->dados[pos]);
        if (i == 0) printf("← SAIR ");
        if (i == f->tamanho - 1) printf("← ENTRAR");
    }
    printf(" ← FIM\n");
}

// ===== APLICAÇÕES PRÁTICAS =====

// Aplicação 1: Verificador de parênteses balanceados usando pilha
bool verificar_parenteses(char* expressao) {
    Pilha pilha;
    pilha_inicializar(&pilha);
    
    printf("\n🔧 Verificando parênteses em: \"%s\"\n", expressao);
    
    for (int i = 0; expressao[i] != '\0'; i++) {
        char c = expressao[i];
        
        if (c == '(' || c == '[' || c == '{') {
            // Abre parênteses: empilha
            pilha_push(&pilha, c);
            printf("   Encontrado '%c' → empilhado\n", c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            // Fecha parênteses: verifica se combina
            if (pilha_vazia(&pilha)) {
                printf("   Erro: '%c' sem parênteses de abertura\n", c);
                return false;
            }
            
            char abertura = pilha_pop(&pilha);
            printf("   Encontrado '%c' → comparando com '%c'\n", c, abertura);
            
            bool combina = (c == ')' && abertura == '(') ||
                          (c == ']' && abertura == '[') ||
                          (c == '}' && abertura == '{');
            
            if (!combina) {
                printf("   Erro: '%c' não combina com '%c'\n", c, abertura);
                return false;
            }
        }
    }
    
    bool balanceado = pilha_vazia(&pilha);
    printf("   Resultado: %s\n", balanceado ? "✅ Balanceado" : "❌ Não balanceado");
    return balanceado;
}

// Aplicação 2: Simulador de atendimento de banco usando fila
void simular_banco() {
    Fila fila_atendimento;
    fila_inicializar(&fila_atendimento);
    
    printf("\n🏦 Simulador de Atendimento Bancário\n");
    printf("========================================\n");
    
    // Chegada de clientes
    printf("\n📥 Chegada de clientes:\n");
    for (int cliente = 1; cliente <= 5; cliente++) {
        fila_enqueue(&fila_atendimento, cliente);
        printf("   Cliente %d entrou na fila\n", cliente);
    }
    
    fila_imprimir(&fila_atendimento);
    
    // Atendimento dos clientes
    printf("\n👥 Atendimento (FIFO - primeiro que chegou é o primeiro atendido):\n");
    while (!fila_vazia(&fila_atendimento)) {
        int cliente = fila_front(&fila_atendimento);
        printf("   🔔 Chamando cliente %d para atendimento...\n", cliente);
        fila_dequeue(&fila_atendimento);
        printf("   ✅ Cliente %d foi atendido\n", cliente);
        fila_imprimir(&fila_atendimento);
        printf("\n");
    }
    
    printf("🎉 Todos os clientes foram atendidos!\n");
}

// Demonstração das operações básicas
void demonstrar_pilha() {
    printf("\n🎯 DEMONSTRAÇÃO DE PILHA (LIFO)\n");
    printf("=====================================\n");
    
    Pilha pilha;
    pilha_inicializar(&pilha);
    
    printf("🔸 Operações de empilhamento:\n");
    pilha_push(&pilha, 10);
    pilha_push(&pilha, 20);
    pilha_push(&pilha, 30);
    pilha_imprimir(&pilha);
    
    printf("\n🔸 Consultando o topo:\n");
    printf("   Topo da pilha: %d\n", pilha_top(&pilha));
    
    printf("\n🔸 Operações de desempilhamento:\n");
    pilha_pop(&pilha);  // Remove 30
    pilha_pop(&pilha);  // Remove 20
    pilha_imprimir(&pilha);
    
    printf("\n🔸 Adicionando mais elementos:\n");
    pilha_push(&pilha, 40);
    pilha_push(&pilha, 50);
    pilha_imprimir(&pilha);
}

void demonstrar_fila() {
    printf("\n🎯 DEMONSTRAÇÃO DE FILA (FIFO)\n");
    printf("===================================\n");
    
    Fila fila;
    fila_inicializar(&fila);
    
    printf("🔸 Operações de enfileiramento:\n");
    fila_enqueue(&fila, 100);
    fila_enqueue(&fila, 200);
    fila_enqueue(&fila, 300);
    fila_imprimir(&fila);
    
    printf("\n🔸 Consultando o início:\n");
    printf("   Início da fila: %d\n", fila_front(&fila));
    
    printf("\n🔸 Operações de desenfileiramento:\n");
    fila_dequeue(&fila);  // Remove 100
    fila_dequeue(&fila);  // Remove 200
    fila_imprimir(&fila);
    
    printf("\n🔸 Adicionando mais elementos:\n");
    fila_enqueue(&fila, 400);
    fila_enqueue(&fila, 500);
    fila_imprimir(&fila);
}

int main() {
    printf("🎯 ESTRUTURAS LINEARES: PILHAS E FILAS\n");
    printf("==================================================\n");
    
    // Demonstração das operações básicas
    demonstrar_pilha();
    demonstrar_fila();
    
    // Aplicações práticas
    printf("\n\n🌟 APLICAÇÕES PRÁTICAS\n");
    printf("========================\n");
    
    // Aplicação 1: Verificador de parênteses
    verificar_parenteses("((()))");     // Balanceado
    verificar_parenteses("([{}])");     // Balanceado
    verificar_parenteses("((()");       // Não balanceado
    verificar_parenteses("())");        // Não balanceado
    verificar_parenteses("([)]");       // Não balanceado
    
    // Aplicação 2: Simulador de banco
    simular_banco();
    
    printf("\n\n🎓 RESUMO DOS CONCEITOS\n");
    printf("========================\n");
    printf("📚 PILHA (Stack):\n");
    printf("   • Princípio: LIFO (Last-In, First-Out)\n");
    printf("   • Operações: push(), pop(), top(), isEmpty()\n");
    printf("   • Aplicações: Desfazer, navegador, chamadas de função\n\n");
    
    printf("🚶‍♀️ FILA (Queue):\n");
    printf("   • Princípio: FIFO (First-In, First-Out)\n");
    printf("   • Operações: enqueue(), dequeue(), front(), isEmpty()\n");
    printf("   • Aplicações: Atendimento, impressão, sistemas operacionais\n\n");
    
    printf("💡 A escolha entre pilha e fila depende da natureza do problema!\n");
    
    return 0;
}
