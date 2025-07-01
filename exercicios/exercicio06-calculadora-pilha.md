# 🧮 Exercício 06: Calculadora com Pilha

## 📊 Dados do Exercício
- **Nível:** 🟡 Médio
- **Tópico:** Pilhas (Stacks) e Expressões Matemáticas
- **Tempo estimado:** 90 minutos
- **Pontuação:** 2 pontos

## 🎯 Objetivo

Implementar uma calculadora que usa pilhas para avaliar expressões matemáticas, incluindo conversão de notação infixa para pós-fixa (Reverse Polish Notation - RPN).

## 📝 Descrição do Problema

Sua calculadora deve ser capaz de:

1. **Avaliar expressões em notação pós-fixa** (ex: "3 4 + 2 *" = 14)
2. **Converter notação infixa para pós-fixa** (ex: "3 + 4 * 2" → "3 4 2 * +")
3. **Avaliar expressões em notação infixa** (combinando 1 e 2)
4. **Suportar operadores:** +, -, *, /, ^, (, )
5. **Tratar precedência** e associatividade
6. **Detectar erros** nas expressões

## 🔍 Especificações Técnicas

### Estruturas Necessárias:

```c
#define MAX_SIZE 100

typedef struct {
    double dados[MAX_SIZE];
    int topo;
} PilhaNumeros;

typedef struct {
    char dados[MAX_SIZE];
    int topo;
} PilhaOperadores;
```

### Funções Principais:

```c
// Operações da pilha
void pilha_push_num(PilhaNumeros *p, double valor);
double pilha_pop_num(PilhaNumeros *p);
void pilha_push_op(PilhaOperadores *p, char op);
char pilha_pop_op(PilhaOperadores *p);

// Calculadora
double avaliar_posfixa(const char *expressao);
char* converter_infixa_posfixa(const char *infixa);
double calcular_infixa(const char *infixa);

// Utilitários
int precedencia(char op);
int eh_operador(char c);
bool eh_associativo_esquerda(char op);
```

## 📋 Exemplo de Execução

```
🧮 CALCULADORA COM PILHA - RPN

========================================
1. 🔢 Avaliar Expressão Pós-fixa
2. 🔄 Converter Infixa → Pós-fixa  
3. 🧮 Calcular Expressão Infixa
4. 📊 Demonstração Passo a Passo
5. 🚪 Sair
========================================

👉 Escolha uma opção: 1

📝 Digite a expressão pós-fixa: 3 4 + 2 *

🔍 Processando: "3 4 + 2 *"
   └─ Push 3.0       | Pilha: [3.0]
   └─ Push 4.0       | Pilha: [3.0, 4.0]
   └─ Operador +     | Pop 4.0 e 3.0, Push 7.0
   └─ Push 2.0       | Pilha: [7.0, 2.0]
   └─ Operador *     | Pop 2.0 e 7.0, Push 14.0

✅ Resultado: 14.0

----------------------------------------

👉 Escolha uma opção: 2

📝 Digite a expressão infixa: 3 + 4 * 2

🔄 Convertendo "3 + 4 * 2" para pós-fixa...

📊 Passo a passo:
   Token: 3         | Saída: "3 "           | Pilha Ops: []
   Token: +         | Saída: "3 "           | Pilha Ops: [+]
   Token: 4         | Saída: "3 4 "         | Pilha Ops: [+]
   Token: *         | Saída: "3 4 "         | Pilha Ops: [+, *]
   Token: 2         | Saída: "3 4 2 "       | Pilha Ops: [+, *]
   Fim da expr.     | Saída: "3 4 2 * + "   | Pilha Ops: []

✅ Resultado: "3 4 2 * + "

----------------------------------------

👉 Escolha uma opção: 3

📝 Digite a expressão infixa: (3 + 4) * 2 ^ 3

🔄 Convertendo para pós-fixa: "3 4 + 2 3 ^ *"
🧮 Calculando resultado...

✅ Resultado: 56.0
```

## 🚀 Código Base (Esqueleto)

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

#define MAX_SIZE 100
#define MAX_EXPR 200

typedef struct {
    double dados[MAX_SIZE];
    int topo;
} PilhaNumeros;

typedef struct {
    char dados[MAX_SIZE];
    int topo;
} PilhaOperadores;

// Protótipos
void pilha_init_num(PilhaNumeros *p);
void pilha_init_op(PilhaOperadores *p);
bool pilha_vazia_num(PilhaNumeros *p);
bool pilha_vazia_op(PilhaOperadores *p);
void pilha_push_num(PilhaNumeros *p, double valor);
double pilha_pop_num(PilhaNumeros *p);
void pilha_push_op(PilhaOperadores *p, char op);
char pilha_pop_op(PilhaOperadores *p);
char pilha_topo_op(PilhaOperadores *p);

double avaliar_posfixa(const char *expressao);
char* converter_infixa_posfixa(const char *infixa);
double calcular_infixa(const char *infixa);

int precedencia(char op);
bool eh_operador(char c);
bool eh_associativo_esquerda(char op);
double aplicar_operador(char op, double b, double a);

void demonstracao_passo_a_passo();
void menu_principal();

int main() {
    menu_principal();
    return 0;
}

// TODO: Implementar todas as funções
```

## 💡 Dicas para Implementação

### 🔸 Dica 1: Precedência de Operadores
```c
int precedencia(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default:  return 0;
    }
}
```

### 🔸 Dica 2: Algoritmo de Shunting Yard (Infixa → Pós-fixa)
```
Para cada token na expressão infixa:
1. Se é número: adicionar à saída
2. Se é operador:
   - Pop operadores da pilha com precedência ≥ atual
   - Push operador atual na pilha
3. Se é '(': push na pilha
4. Se é ')': pop até encontrar '('
5. No final: pop todos os operadores restantes
```

### 🔸 Dica 3: Avaliação Pós-fixa
```c
double avaliar_posfixa(const char *expr) {
    PilhaNumeros pilha;
    pilha_init_num(&pilha);
    
    // Para cada token:
    // - Se número: push na pilha
    // - Se operador: pop dois números, calcular, push resultado
    
    return pilha_pop_num(&pilha);  // Resultado final
}
```

### 🔸 Dica 4: Parsing de Números
```c
// Usar strtod para converter strings para double
char *endptr;
double num = strtod(token, &endptr);
if (endptr != token) {
    // É um número válido
}
```

## 🎯 Casos de Teste

### Teste 1: Expressões Pós-fixas Simples
```
Entrada: "5 3 +"
Esperado: 8.0

Entrada: "15 7 1 1 + - / 3 * 2 1 1 + + -"
Esperado: 5.0
```

### Teste 2: Conversão Infixa → Pós-fixa
```
Entrada: "a + b * c"
Esperado: "a b c * +"

Entrada: "(a + b) * c"
Esperado: "a b + c *"

Entrada: "a * b + c"
Esperado: "a b * c +"
```

### Teste 3: Expressões com Parênteses
```
Entrada: "(3 + 4) * 2"
Esperado: 14.0

Entrada: "2 ^ 3 ^ 2"
Esperado: 512.0 (associatividade à direita)
```

### Teste 4: Casos de Erro
```
Entrada: "3 + + 4"     → Erro de sintaxe
Entrada: "3 4"         → Números extras na pilha
Entrada: "+ 3 4"       → Operador sem operandos
```

## ⚠️ Tratamento de Erros

### 1. **Verificação de Pilha Vazia**
```c
if (pilha_vazia_num(&pilha)) {
    printf("Erro: Operador sem operandos suficientes\n");
    return NAN;  // Not a Number
}
```

### 2. **Verificação de Resultado Final**
```c
if (!pilha_vazia_num(&pilha)) {
    printf("Erro: Números extras na expressão\n");
    return NAN;
}
```

### 3. **Divisão por Zero**
```c
if (op == '/' && b == 0.0) {
    printf("Erro: Divisão por zero\n");
    return NAN;
}
```

## 🌟 Funcionalidades Extras

### 1. **Suporte a Números Negativos**
```c
// Distinguir '-' unário de '-' binário
if (token[0] == '-' && strlen(token) > 1) {
    // Número negativo
}
```

### 2. **Funções Matemáticas**
```c
// Adicionar suporte a sin, cos, sqrt, etc.
if (strcmp(token, "sin") == 0) {
    double x = pilha_pop_num(&pilha);
    pilha_push_num(&pilha, sin(x));
}
```

### 3. **Variáveis**
```c
// Suporte a variáveis (a, b, x, y)
typedef struct {
    char nome;
    double valor;
} Variavel;
```

## 🏆 Critérios de Avaliação

### ✅ Funcionalidade (70%)
- [ ] Avaliação de expressões pós-fixas
- [ ] Conversão infixa → pós-fixa
- [ ] Precedência correta de operadores
- [ ] Suporte a parênteses
- [ ] Tratamento de erros

### ✅ Qualidade do Código (20%)
- [ ] Código bem estruturado
- [ ] Comentários adequados
- [ ] Funções bem definidas
- [ ] Verificação de erros

### ✅ Interface (10%)
- [ ] Menu interativo
- [ ] Output claro
- [ ] Mensagens de erro informativas

## 🎁 Bônus (+1 ponto)

- **Demonstração visual** do funcionamento das pilhas
- **Suporte a funções** matemáticas (sin, cos, log)
- **Histórico** de cálculos realizados
- **Modo científico** com constantes (π, e)
- **Validação robusta** de entrada

## 📚 Conceitos Revisados

- ✅ Estrutura de dados Pilha
- ✅ Algoritmo Shunting Yard
- ✅ Notação polonesa reversa (RPN)
- ✅ Precedência e associatividade
- ✅ Parsing de expressões
- ✅ Tratamento de erros

## 🔗 Aplicações Reais

- **Compiladores:** Análise de expressões
- **Calculadoras:** HP, PostScript
- **Interpretadores:** Forth, PostScript
- **Sistemas embarcados:** Economia de memória

## 📝 Entrega

Crie os arquivos:
1. `calculadora.c` - Implementação completa
2. `calculadora.h` - Cabeçalhos e definições
3. `README.md` - Instruções de uso
4. `testes.txt` - Casos de teste utilizados

---
**🎯 Desafio:** Consegue implementar uma calculadora que processa expressões em tempo real, caractere por caractere?
