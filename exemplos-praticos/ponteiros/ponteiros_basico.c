/**
 * 🎯 EXEMPLO PRÁTICO: Introdução aos Ponteiros
 * 
 * Este programa demonstra os conceitos fundamentais de ponteiros:
 * - Declaração de ponteiros
 * - Operadores & e *
 * - Aritmética de ponteiros
 * - Passagem por referência
 * 
 * Compile: gcc ponteiros_basico.c -o ponteiros_basico
 * Execute: ./ponteiros_basico
 */

#include <stdio.h>
#include <stdlib.h>

// Função para demonstrar passagem por valor (não funciona para troca)
void troca_por_valor(int a, int b) {
    printf("\n🔄 Tentativa de troca por valor:\n");
    printf("  Antes da troca: a = %d, b = %d\n", a, b);
    
    int temp = a;
    a = b;
    b = temp;
    
    printf("  Depois da troca: a = %d, b = %d\n", a, b);
    printf("  ⚠️  Apenas as cópias locais foram trocadas!\n");
}

// Função para demonstrar passagem por referência (funciona!)
void troca_por_referencia(int *a, int *b) {
    printf("\n✅ Troca por referência (ponteiros):\n");
    printf("  Antes da troca: *a = %d, *b = %d\n", *a, *b);
    
    int temp = *a;
    *a = *b;
    *b = temp;
    
    printf("  Depois da troca: *a = %d, *b = %d\n", *a, *b);
    printf("  ✅ Valores originais foram trocados!\n");
}

// Função para somar elementos de um vetor usando ponteiros
int soma_vetor(int *vetor, int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += *(vetor + i);  // Aritmética de ponteiros
    }
    return soma;
}

// Função para imprimir um vetor usando ponteiros
void imprime_vetor(int *vetor, int tamanho) {
    printf("Vetor: [ ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", *(vetor + i));
    }
    printf("]\n");
}

int main() {
    printf("🎯 DEMONSTRAÇÃO DE PONTEIROS\n");
    printf("========================================\n");
    
    // ===== PARTE 1: Conceitos Básicos =====
    printf("\n\n📍 PARTE 1: Conceitos Básicos de Ponteiros\n");
    printf("----------------------------------------\n");
    
    int valor = 42;
    int *ptr = &valor;  // ptr aponta para o endereço de valor
    
    printf("\nVariável 'valor':\n");
    printf("  Valor: %d\n", valor);
    printf("  Endereço: %p\n", &valor);
    
    printf("\nPonteiro 'ptr':\n");
    printf("  Valor do ponteiro (endereço que aponta): %p\n", ptr);
    printf("  Valor apontado (*ptr): %d\n", *ptr);
    printf("  Endereço do próprio ponteiro: %p\n", &ptr);
    
    // Modificando valor através do ponteiro
    printf("\n🔧 Modificando valor através do ponteiro:\n");
    printf("  Antes: valor = %d\n", valor);
    *ptr = 100;  // Muda o valor de 'valor' através do ponteiro
    printf("  Depois (*ptr = 100): valor = %d\n", valor);
    
    // ===== PARTE 2: Passagem por Valor vs Referência =====
    printf("\n\n🔄 PARTE 2: Passagem por Valor vs Referência\n");
    printf("--------------------------------------------------\n");
    
    int x = 5, y = 10;
    printf("\nValores originais: x = %d, y = %d\n", x, y);
    
    // Tentativa com passagem por valor
    troca_por_valor(x, y);
    printf("Valores após troca_por_valor: x = %d, y = %d\n", x, y);
    
    // Troca correta com ponteiros
    troca_por_referencia(&x, &y);
    printf("Valores após troca_por_referencia: x = %d, y = %d\n", x, y);
    
    // ===== PARTE 3: Aritmética de Ponteiros =====
    printf("\n\n🧮 PARTE 3: Aritmética de Ponteiros\n");
    printf("----------------------------------------\n");
    
    int vetor[] = {10, 20, 30, 40, 50};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int *ptr_vetor = vetor;  // Nome do vetor é um ponteiro para o primeiro elemento
    
    printf("\nVetor original:\n");
    imprime_vetor(vetor, tamanho);
    
    printf("\nPercorrendo com aritmética de ponteiros:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("  Posição %d: valor = %d, endereço = %p\n", 
               i, *(ptr_vetor + i), (ptr_vetor + i));
    }
    
    // ===== PARTE 4: Operações com Vetores usando Ponteiros =====
    printf("\n\n📊 PARTE 4: Operações com Vetores\n");
    printf("----------------------------------------\n");
    
    int soma = soma_vetor(vetor, tamanho);
    printf("\nSoma dos elementos: %d\n", soma);
    
    // Demonstração de que vetor[i] == *(vetor + i)
    printf("\nEquivalência entre notações:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("  vetor[%d] = %d | *(vetor + %d) = %d | Iguais? %s\n",
               i, vetor[i], i, *(vetor + i),
               (vetor[i] == *(vetor + i)) ? "✅ Sim" : "❌ Não");
    }
    
    // ===== PARTE 5: Ponteiros para Ponteiros =====
    printf("\n\n🎯 PARTE 5: Ponteiros para Ponteiros\n");
    printf("----------------------------------------\n");
    
    int numero = 123;
    int *ptr1 = &numero;      // Ponteiro para int
    int **ptr2 = &ptr1;       // Ponteiro para ponteiro para int
    
    printf("\nCadeia de ponteiros:\n");
    printf("  numero = %d (endereço: %p)\n", numero, &numero);
    printf("  ptr1 = %p, *ptr1 = %d (endereço: %p)\n", ptr1, *ptr1, &ptr1);
    printf("  ptr2 = %p, *ptr2 = %p, **ptr2 = %d\n", ptr2, *ptr2, **ptr2);
    
    // Modificando através do ponteiro duplo
    **ptr2 = 999;
    printf("\nApós **ptr2 = 999:\n");
    printf("  numero = %d\n", numero);
    
    printf("\n\n🎉 Demonstração concluída!\n");
    printf("💡 Principais aprendizados:\n");
    printf("   • Ponteiros armazenam endereços de memória\n");
    printf("   • & obtém o endereço de uma variável\n");
    printf("   • * acessa o valor no endereço apontado\n");
    printf("   • Passagem por referência permite modificar variáveis originais\n");
    printf("   • Aritmética de ponteiros facilita navegação em vetores\n");
    
    return 0;
}
