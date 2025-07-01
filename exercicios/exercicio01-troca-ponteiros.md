# 🔄 Exercício 01: Troca de Ponteiros

## 📊 Dados do Exercício
- **Nível:** 🟢 Fácil
- **Tópico:** Ponteiros e Passagem por Referência
- **Tempo estimado:** 30 minutos
- **Pontuação:** 1 ponto

## 🎯 Objetivo

Implementar diferentes funções de troca usando ponteiros, demonstrando a diferença entre passagem por valor e passagem por referência.

## 📝 Descrição do Problema

Você deve criar um programa que implementa várias funções de troca:

1. **Troca simples** entre dois inteiros
2. **Troca sem variável auxiliar** (usando aritmética)
3. **Troca de strings** (ponteiros para char)
4. **Troca de arrays** (trocar ponteiros)
5. **Função que NÃO funciona** (para demonstrar erro comum)

## 🔍 Especificações

### Funções a Implementar:

```c
// 1. Troca básica com variável auxiliar
void trocar_inteiros(int *a, int *b);

// 2. Troca sem variável auxiliar (usando XOR ou aritmética)
void trocar_sem_aux(int *a, int *b);

// 3. Troca de strings (ponteiros para char)
void trocar_strings(char **str1, char **str2);

// 4. Função INCORRETA para demonstração
void trocar_errado(int a, int b);  // Passagem por valor

// 5. Troca de arrays (trocar ponteiros)
void trocar_arrays(int **arr1, int **arr2, int *tam1, int *tam2);
```

## 📋 Exemplo de Execução

```
🔄 DEMONSTRAÇÃO DE TROCA COM PONTEIROS

=== TESTE 1: Troca Básica ===
Antes: a = 10, b = 20
Após trocar_inteiros(&a, &b): a = 20, b = 10

=== TESTE 2: Troca Sem Auxiliar ===
Antes: x = 5, y = 15
Após trocar_sem_aux(&x, &y): x = 15, y = 5

=== TESTE 3: Troca de Strings ===
Antes: str1 = "Hello", str2 = "World"
Após trocar_strings(&str1, &str2): str1 = "World", str2 = "Hello"

=== TESTE 4: Função Incorreta ===
Antes: p = 100, q = 200
Após trocar_errado(p, q): p = 100, q = 200  ❌ Não funcionou!
Explicação: Passagem por valor não altera as variáveis originais

=== TESTE 5: Troca de Arrays ===
Antes: 
  Array 1: [1, 2, 3] (tamanho: 3)
  Array 2: [10, 20, 30, 40] (tamanho: 4)

Após trocar_arrays(&arr1, &arr2, &tam1, &tam2):
  Array 1: [10, 20, 30, 40] (tamanho: 4)
  Array 2: [1, 2, 3] (tamanho: 3)
```

## 🚀 Código Base (Esqueleto)

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Protótipos das funções
void trocar_inteiros(int *a, int *b);
void trocar_sem_aux(int *a, int *b);
void trocar_strings(char **str1, char **str2);
void trocar_errado(int a, int b);
void trocar_arrays(int **arr1, int **arr2, int *tam1, int *tam2);
void imprimir_array(int *arr, int tamanho, const char *nome);

int main() {
    printf("🔄 DEMONSTRAÇÃO DE TROCA COM PONTEIROS\\n");
    printf("====================================\\n\\n");
    
    // TODO: Implementar os testes
    
    return 0;
}

// TODO: Implementar as funções
void trocar_inteiros(int *a, int *b) {
    // Sua implementação aqui
}

void trocar_sem_aux(int *a, int *b) {
    // Sua implementação aqui
}

void trocar_strings(char **str1, char **str2) {
    // Sua implementação aqui
}

void trocar_errado(int a, int b) {
    // Implementação incorreta para demonstração
}

void trocar_arrays(int **arr1, int **arr2, int *tam1, int *tam2) {
    // Sua implementação aqui
}

void imprimir_array(int *arr, int tamanho, const char *nome) {
    // Sua implementação aqui
}
```

## 💡 Dicas para Resolução

### 🔸 Dica 1: Troca Básica
```c
// Use uma variável temporária
int temp = *a;
*a = *b;
*b = temp;
```

### 🔸 Dica 2: Troca Sem Auxiliar
```c
// Método 1: Aritmética
*a = *a + *b;
*b = *a - *b;
*a = *a - *b;

// Método 2: XOR (cuidado com casos especiais)
if (a != b) {  // Evita zerar se a e b apontam para o mesmo endereço
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
```

### 🔸 Dica 3: Troca de Strings
```c
// Trocar os ponteiros, não o conteúdo
char *temp = *str1;
*str1 = *str2;
*str2 = temp;
```

### 🔸 Dica 4: Função Incorreta
```c
// Esta função não funciona porque usa passagem por valor
void trocar_errado(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    // As mudanças são apenas nas cópias locais!
}
```

## 🎯 Casos de Teste

### Teste 1: Valores Normais
```c
int a = 42, b = 99;
trocar_inteiros(&a, &b);
// Esperado: a = 99, b = 42
```

### Teste 2: Valores Iguais
```c
int x = 10, y = 10;
trocar_sem_aux(&x, &y);
// Esperado: x = 10, y = 10 (sem mudança)
```

### Teste 3: Valores Negativos
```c
int p = -5, q = 15;
trocar_inteiros(&p, &q);
// Esperado: p = 15, q = -5
```

### Teste 4: Strings Vazias/NULL
```c
char *s1 = "";
char *s2 = "teste";
trocar_strings(&s1, &s2);
// Esperado: s1 = "teste", s2 = ""
```

## ⚠️ Cuidados Especiais

### 1. **Verificação de Ponteiros NULL**
```c
if (a == NULL || b == NULL) {
    printf("Erro: Ponteiro NULL\\n");
    return;
}
```

### 2. **Troca XOR com Mesmo Endereço**
```c
// Se a e b apontam para o mesmo endereço, XOR zeraría o valor
if (a != b) {
    // Fazer troca XOR
}
```

### 3. **Alocação Dinâmica**
```c
// Lembre-se de que ao trocar arrays dinâmicos,
// você está trocando a responsabilidade de liberar a memória
```

## 🏆 Critérios de Avaliação

### ✅ Funcionalidade (60%)
- [ ] Troca básica funciona corretamente
- [ ] Troca sem auxiliar implementada
- [ ] Troca de strings funciona
- [ ] Função incorreta demonstra o problema
- [ ] Troca de arrays funciona

### ✅ Qualidade do Código (25%)
- [ ] Código bem comentado
- [ ] Verificação de erros
- [ ] Nomes de variáveis claros
- [ ] Estrutura organizada

### ✅ Demonstração (15%)
- [ ] Output claro e informativo
- [ ] Todos os casos testados
- [ ] Explicações adequadas

## 🎁 Bônus (+0.5 pontos)

- **Implementar menu interativo** para escolher qual troca testar
- **Adicionar função de benchmark** comparando métodos
- **Criar função genérica** que funciona com qualquer tipo
- **Implementar macro** para troca usando pré-processador

## 📚 Conceitos Revisados

- ✅ Ponteiros e endereços de memória
- ✅ Passagem por valor vs passagem por referência
- ✅ Desreferenciamento de ponteiros
- ✅ Ponteiros para ponteiros
- ✅ Manipulação de strings em C
- ✅ Alocação dinâmica básica

## 🔗 Próximos Exercícios

Após dominar este exercício, continue com:
- **Exercício 02:** Aritmética de Ponteiros
- **Exercício 03:** Ponteiros para Ponteiros
- **Exercício 04:** Arrays Dinâmicos

## 📝 Entrega

Crie um arquivo `exercicio01_solucao.c` com:
1. **Código completo** e funcional
2. **Comentários** explicando cada função
3. **Função main** que testa todos os casos
4. **README** opcional explicando sua abordagem

---
**💡 Lembre-se:** O objetivo é entender profundamente como os ponteiros funcionam, não apenas fazer o código compilar!
