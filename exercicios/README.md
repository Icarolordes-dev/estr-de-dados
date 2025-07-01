# 🎯 EXERCÍCIOS PRÁTICOS - ESTRUTURAS DE DADOS

## 📚 Sobre os Exercícios

Este diretório contém exercícios práticos organizados por tópico, desde conceitos básicos até aplicações avançadas. Cada exercício inclui:

- **Descrição clara** do problema
- **Exemplos** de entrada e saída
- **Dicas** para resolução
- **Níveis de dificuldade** (🟢 Fácil, 🟡 Médio, 🔴 Difícil)
- **Aplicações práticas** do conceito

## 📋 Lista de Exercícios

### 🔗 Ponteiros e Referências
1. [**Troca de Ponteiros**](exercicio01-troca-ponteiros.md) 🟢
   - Implementar funções de troca usando ponteiros
   - Passagem por referência vs valor

2. [**Aritmética de Ponteiros**](exercicio02-aritmetica-ponteiros.md) 🟡
   - Navegação em arrays usando ponteiros
   - Comparação de endereços

3. [**Ponteiros para Ponteiros**](exercicio03-ponteiros-duplos.md) 🟡
   - Manipulação de matrizes dinâmicas
   - Alocação multidimensional

### 💾 Alocação Dinâmica
4. [**Array Dinâmico Redimensionável**](exercicio04-array-dinamico.md) 🟡
   - Implementar estrutura que cresce automaticamente
   - Gerenciamento eficiente de memória

5. [**Sistema de Cadastro Dinâmico**](exercicio05-cadastro-dinamico.md) 🔴
   - CRUD completo com alocação dinâmica
   - Busca e ordenação

### 📚 Pilhas (Stacks)
6. [**Calculadora com Pilha**](exercicio06-calculadora-pilha.md) 🟡
   - Avaliar expressões matemáticas
   - Conversão infixa para pós-fixa

7. [**Verificador de Parênteses**](exercicio07-parenteses-pilha.md) 🟢
   - Validar expressões com símbolos balanceados
   - Aplicação prática de pilhas

8. [**Histórico de Navegação**](exercicio08-historico-pilha.md) 🟡
   - Simular histórico de browser
   - Operações de voltar/avançar

### 🚶 Filas (Queues)
9. [**Sistema de Atendimento**](exercicio09-fila-atendimento.md) 🟢
   - Simular fila de banco/hospital
   - Prioridades e tempos de espera

10. [**Buffer Circular**](exercicio10-buffer-circular.md) 🟡
    - Implementar fila circular eficiente
    - Aplicação em sistemas de comunicação

11. [**Scheduler de Processos**](exercicio11-scheduler-filas.md) 🔴
    - Simular escalonamento de CPU
    - Múltiplas filas de prioridade

### 🔗 Listas Ligadas
12. [**Lista de Tarefas**](exercicio12-lista-tarefas.md) 🟡
    - Todo list com inserção/remoção
    - Busca e modificação de itens

13. [**Lista Duplamente Ligada**](exercicio13-lista-dupla.md) 🟡
    - Navegação bidirecional
    - Editor de texto simples

14. [**Lista Circular**](exercicio14-lista-circular.md) 🔴
    - Implementar jogo da batata quente
    - Aplicações em round-robin

### 🌐 Grafos
15. [**Rede Social Simples**](exercicio15-rede-social.md) 🟡
    - Representar amizades
    - Buscar conexões

16. [**Mapa de Cidades**](exercicio16-mapa-cidades.md) 🔴
    - Encontrar rotas entre cidades
    - Algoritmo de menor caminho

17. [**Detecção de Ciclos**](exercicio17-ciclos-grafo.md) 🔴
    - Identificar dependências circulares
    - Aplicação em sistemas

### 🏗️ Projetos Integradores
18. [**Sistema de Biblioteca**](exercicio18-biblioteca.md) 🔴
    - Combinar múltiplas estruturas
    - Sistema completo de gerenciamento

19. [**Jogo da Memória**](exercicio19-jogo-memoria.md) 🟡
    - Interface interativa
    - Estruturas para pontuação

20. [**Analisador de Logs**](exercicio20-analisador-logs.md) 🔴
    - Processar grandes volumes de dados
    - Otimização de performance

## 🎯 Como Usar os Exercícios

### 1. **Escolha por Nível**
```
🟢 INICIANTE: Comece com exercícios básicos
🟡 INTERMEDIÁRIO: Após dominar os conceitos
🔴 AVANÇADO: Para desafios complexos
```

### 2. **Metodologia Sugerida**
1. **Leia** o problema completamente
2. **Analise** os exemplos de entrada/saída
3. **Planeje** a solução no papel
4. **Implemente** passo a passo
5. **Teste** com diferentes casos
6. **Otimize** se necessário

### 3. **Recursos de Apoio**
- **Exemplos práticos** em `/exemplos-praticos/`
- **Aulas teóricas** em `/aulas/`
- **Código base** nos exercícios quando fornecido

### 4. **Compilação e Teste**
```bash
# Compilar
gcc exercicio.c -o exercicio -Wall -Wextra

# Executar
./exercicio

# Debug (se necessário)
gcc -g exercicio.c -o exercicio
gdb ./exercicio
```

## 📊 Acompanhamento de Progresso

### ✅ Checklist de Exercícios

**Ponteiros e Alocação:**
- [ ] Exercício 01 - Troca de Ponteiros
- [ ] Exercício 02 - Aritmética de Ponteiros  
- [ ] Exercício 03 - Ponteiros Duplos
- [ ] Exercício 04 - Array Dinâmico
- [ ] Exercício 05 - Cadastro Dinâmico

**Estruturas Lineares:**
- [ ] Exercício 06 - Calculadora com Pilha
- [ ] Exercício 07 - Verificador de Parênteses
- [ ] Exercício 08 - Histórico de Navegação
- [ ] Exercício 09 - Sistema de Atendimento
- [ ] Exercício 10 - Buffer Circular
- [ ] Exercício 11 - Scheduler de Processos

**Listas Dinâmicas:**
- [ ] Exercício 12 - Lista de Tarefas
- [ ] Exercício 13 - Lista Duplamente Ligada
- [ ] Exercício 14 - Lista Circular

**Grafos:**
- [ ] Exercício 15 - Rede Social
- [ ] Exercício 16 - Mapa de Cidades
- [ ] Exercício 17 - Detecção de Ciclos

**Projetos:**
- [ ] Exercício 18 - Sistema de Biblioteca
- [ ] Exercício 19 - Jogo da Memória
- [ ] Exercício 20 - Analisador de Logs

## 🏆 Sistema de Pontuação

| Dificuldade | Pontos | Bônus |
|-------------|--------|-------|
| 🟢 Fácil | 1 ponto | +0.5 se otimizado |
| 🟡 Médio | 2 pontos | +1 se comentado |
| 🔴 Difícil | 3 pontos | +1.5 se completo |

**Metas:**
- **🥉 Bronze:** 15 pontos (conceitos básicos)
- **🥈 Prata:** 25 pontos (proficiência)
- **🥇 Ouro:** 35 pontos (excelência)

## 💡 Dicas Gerais

### 🚀 Para Maximizar o Aprendizado:
1. **Não copie soluções** - entenda o processo
2. **Teste casos extremos** - arrays vazios, valores nulos
3. **Comente seu código** - explique o raciocínio
4. **Meça performance** - compare algoritmos
5. **Revise regularmente** - conceitos fundamentais

### 🔧 Ferramentas Úteis:
- **Valgrind:** Detectar vazamentos de memória
- **GDB:** Debug step-by-step
- **Profilers:** Analisar performance
- **Visualizadores:** Entender estruturas

### 📚 Referências Complementares:
- [Visualgo](https://visualgo.net) - Visualização de algoritmos
- [GeeksforGeeks](https://geeksforgeeks.org) - Tutoriais detalhados
- [LeetCode](https://leetcode.com) - Prática adicional

## 🎓 Critérios de Avaliação

### ✅ O que Será Avaliado:
- **Corretude:** O código funciona conforme especificado?
- **Eficiência:** Complexidade temporal e espacial adequada?
- **Legibilidade:** Código bem estruturado e comentado?
- **Robustez:** Trata casos especiais e erros?
- **Estilo:** Segue boas práticas de programação?

### 📝 Formato de Entrega:
1. **Código fonte** comentado
2. **Arquivo README** explicando a solução
3. **Casos de teste** usados
4. **Análise de complexidade** (quando solicitado)

---

**💪 Lembre-se:** A prática leva à perfeição! Cada exercício resolvido é um passo a mais na sua jornada como programador.
