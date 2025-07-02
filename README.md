# 📚 Estruturas de Dados - Repositório Didático

[![C](https://img.shields.io/badge/Linguagem-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Estruturas de Dados](https://img.shields.io/badge/Disciplina-Estruturas%20de%20Dados-green.svg)](https://github.com)
[![Didático](https://img.shields.io/badge/Objetivo-Didático-orange.svg)](https://github.com)

> 🎯 **Missão**: Criar um repositório completo e didático sobre Estruturas de Dados em C, baseado nas aulas ao vivo da disciplina.

## 👨‍🎓 Dados do Estudante

- **Nome**: João da Silva
- **Curso**: Engenharia de Software
- **Disciplina**: Estruturas de Dados
- **Professor**: Prof. Maria Oliveira
- **Período**: 2025.1

## 🎬 Aulas Ao Vivo - Cronograma

| Aula | Tópico | Status | Link do Vídeo |
|------|--------|--------|---------------|
| **01** | [Base Conceitual Necessária](./aulas/aula01-base-conceitual.md) | ✅ | [YouTube](https://www.youtube.com/watch?v=6rGPCNk8Mmg) |
| **02** | [Ponteiros](./aulas/aula02-ponteiros.md) | ✅ | [YouTube](https://www.youtube.com/watch?v=iuP_nUu2HCc) |
| **03** | [Riscos de Ponteiros e Alocação Dinâmica](./aulas/aula03-alocacao-dinamica.md) | ✅ | [YouTube](https://www.youtube.com/watch?v=U4b8vh-P3CI) |
| **04** | [Pilhas e Filas](./aulas/aula04-pilhas-filas.md) | ✅ | [YouTube](https://www.youtube.com/watch?v=m50hOwEw8BU) |
| **05** | [Listas Dinâmicas](./aulas/aula05-listas-dinamicas.md) | ✅ | [YouTube](https://www.youtube.com/watch?v=0aoF8fQjchM) |
| **06** | [Pilhas e Filas com Listas Dinâmicas](./aulas/aula06-pilhas-filas-dinamicas.md) | ✅ | [YouTube](https://www.youtube.com/watch?v=KMGw4HBC8uc) |
| **07** | [Introdução aos Grafos](./aulas/aula07-intro-grafos.md) | ✅ | [YouTube](https://www.youtube.com/watch?v=YCezlrveh20) |
| **08** | [Representação Computacional de Grafos](./aulas/aula08-representacao-grafos.md) | ✅ | [YouTube](https://www.youtube.com/watch?v=N9vwfokVd98) |

## 📁 Estrutura do Repositório

```
📦 estr-de-dados/
├── 📁 aulas/                    # Conteúdo detalhado de cada aula
├── 📁 exemplos-praticos/        # Códigos demonstrativos
│   ├── 📁 ponteiros/           # Exemplos de ponteiros
│   ├── 📁 pilhas-filas/        # Implementações de pilhas e filas
│   ├── 📁 listas/              # Listas ligadas e dinâmicas
│   └── 📁 grafos/              # Implementações de grafos
├── 📁 exercicios/              # Exercícios práticos
├── 📁 projetos/                # Projetos integradores
├── 📁 recursos/                # Materiais auxiliares
└── 📄 README.md               # Este arquivo
```

## 🚀 Como Usar Este Repositório

### 1. **Navegação Sequencial** 
Siga a ordem das aulas para um aprendizado progressivo:
```bash
aulas/aula01-base-conceitual.md → aula02-ponteiros.md → ...
```

### 2. **Prática Hands-on**
```bash
cd exemplos-praticos/
gcc exemplo.c -o exemplo
./exemplo
```

### 3. **Exercícios**
Cada tópico possui exercícios graduais em `exercicios/`

### 4. **Projetos**
Projetos integradores para consolidar o conhecimento

## 🎯 Objetivos de Aprendizado

Ao final deste repositório, você será capaz de:

- ✅ **Entender** a diferença entre dados e informação
- ✅ **Dominar** ponteiros e alocação dinâmica em C
- ✅ **Implementar** pilhas, filas e listas dinâmicas
- ✅ **Modelar** problemas reais usando grafos
- ✅ **Escolher** a estrutura de dados adequada para cada problema
- ✅ **Aplicar** trade-offs entre tempo e espaço

## 🔧 Compilação e Execução

### Pré-requisitos
```bash
# Ubuntu/Debian
sudo apt update && sudo apt install gcc build-essential

# Verificar instalação
gcc --version
```

### Compilação Básica
```bash
gcc arquivo.c -o programa
./programa
```

### Compilação com Debug
```bash
gcc -g -Wall -Wextra arquivo.c -o programa
```

## 📖 Conceitos Fundamentais

### 🔑 Princípios Chave
- **LIFO** (Last-In, First-Out) - Pilhas
- **FIFO** (First-In, First-Out) - Filas  
- **Trade-offs** - Tempo vs. Espaço
- **Alocação Dinâmica** - Flexibilidade de memória

### 🏗️ Estruturas Implementadas
- **Vetores** (Arrays)
- **Listas Ligadas** (Linked Lists)
- **Pilhas** (Stacks) 
- **Filas** (Queues)
- **Grafos** (Graphs)

## 🎨 Metodologia Didática

Este repositório foi criado com foco em:

1. **📝 Teoria Clara**: Explicações conceituais detalhadas
2. **🔬 Exemplos Práticos**: Código comentado e executável  
3. **🎯 Aplicações Reais**: Conexão com problemas do mundo real
4. **🧩 Exercícios Graduais**: Do básico ao avançado
5. **🚀 Projetos Integradores**: Consolidação do conhecimento

## 🤝 Contribuição

Este é um repositório de estudos. Sinta-se livre para:
- 🐛 Reportar bugs nos códigos
- 💡 Sugerir melhorias
- 📚 Adicionar exemplos
- 🎯 Propor exercícios

## 📚 Referências e Recursos

- [Livros Recomendados](./recursos/bibliografia.md)
- [Links Úteis](./recursos/links-uteis.md)
- [Ferramentas de Desenvolvimento](./recursos/ferramentas.md)

## 📝 Notas Importantes

> ⚠️ **Atenção**: Este repositório é para fins didáticos. Os códigos são focados em clareza e compreensão, não necessariamente em otimização para produção.

---

📅 **Última atualização**: Janeiro 2025  
🎓 **Status**: Em desenvolvimento ativo