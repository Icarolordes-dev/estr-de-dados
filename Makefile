# Makefile para Repositório de Estruturas de Dados
# Compila todos os exemplos práticos e exercícios

# Configurações do compilador
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
LDFLAGS = -lm

# Diretórios
EXEMPLOS_DIR = exemplos-praticos
BUILD_DIR = build
BIN_DIR = bin

# Cores para output
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[1;33m
BLUE = \033[0;34m
NC = \033[0m # No Color

# Criar diretórios se não existirem
$(shell mkdir -p $(BUILD_DIR) $(BIN_DIR))

# Encontrar todos os arquivos .c
PONTEIROS_SOURCES = $(wildcard $(EXEMPLOS_DIR)/ponteiros/*.c)
ALOCACAO_SOURCES = $(wildcard $(EXEMPLOS_DIR)/alocacao-dinamica/*.c)
PILHAS_FILAS_SOURCES = $(wildcard $(EXEMPLOS_DIR)/pilhas-filas/*.c)
LISTAS_SOURCES = $(wildcard $(EXEMPLOS_DIR)/listas/*.c)
GRAFOS_SOURCES = $(wildcard $(EXEMPLOS_DIR)/grafos/*.c)

# Gerar nomes dos executáveis
PONTEIROS_BINS = $(PONTEIROS_SOURCES:$(EXEMPLOS_DIR)/ponteiros/%.c=$(BIN_DIR)/%)
ALOCACAO_BINS = $(ALOCACAO_SOURCES:$(EXEMPLOS_DIR)/alocacao-dinamica/%.c=$(BIN_DIR)/%)
PILHAS_FILAS_BINS = $(PILHAS_FILAS_SOURCES:$(EXEMPLOS_DIR)/pilhas-filas/%.c=$(BIN_DIR)/%)
LISTAS_BINS = $(LISTAS_SOURCES:$(EXEMPLOS_DIR)/listas/%.c=$(BIN_DIR)/%)
GRAFOS_BINS = $(GRAFOS_SOURCES:$(EXEMPLOS_DIR)/grafos/%.c=$(BIN_DIR)/%)

ALL_BINS = $(PONTEIROS_BINS) $(ALOCACAO_BINS) $(PILHAS_FILAS_BINS) $(LISTAS_BINS) $(GRAFOS_BINS)

# Regra padrão
.PHONY: all clean help run-examples test ponteiros alocacao pilhas-filas listas grafos

all: banner $(ALL_BINS)
	@echo "${GREEN}✅ Todos os exemplos compilados com sucesso!${NC}"
	@echo "${BLUE}📁 Executáveis disponíveis em: ${BIN_DIR}/${NC}"

banner:
	@echo "${BLUE}"
	@echo "╔════════════════════════════════════════════════════════════════════════╗"
	@echo "║                    🎯 ESTRUTURAS DE DADOS EM C                        ║"
	@echo "║                       Compilando Exemplos Práticos                    ║"
	@echo "╚════════════════════════════════════════════════════════════════════════╝"
	@echo "${NC}"

# Regras de compilação por categoria
ponteiros: $(PONTEIROS_BINS)
	@echo "${GREEN}✅ Exemplos de ponteiros compilados!${NC}"

alocacao: $(ALOCACAO_BINS)
	@echo "${GREEN}✅ Exemplos de alocação dinâmica compilados!${NC}"

pilhas-filas: $(PILHAS_FILAS_BINS)
	@echo "${GREEN}✅ Exemplos de pilhas e filas compilados!${NC}"

listas: $(LISTAS_BINS)
	@echo "${GREEN}✅ Exemplos de listas ligadas compilados!${NC}"

grafos: $(GRAFOS_BINS)
	@echo "${GREEN}✅ Exemplos de grafos compilados!${NC}"

# Regras de compilação específicas
$(BIN_DIR)/%: $(EXEMPLOS_DIR)/ponteiros/%.c
	@echo "${YELLOW}🔨 Compilando ponteiros: $(notdir $<)${NC}"
	@$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BIN_DIR)/%: $(EXEMPLOS_DIR)/alocacao-dinamica/%.c
	@echo "${YELLOW}🔨 Compilando alocação dinâmica: $(notdir $<)${NC}"
	@$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BIN_DIR)/%: $(EXEMPLOS_DIR)/pilhas-filas/%.c
	@echo "${YELLOW}🔨 Compilando pilhas/filas: $(notdir $<)${NC}"
	@$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BIN_DIR)/%: $(EXEMPLOS_DIR)/listas/%.c
	@echo "${YELLOW}🔨 Compilando listas: $(notdir $<)${NC}"
	@$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BIN_DIR)/%: $(EXEMPLOS_DIR)/grafos/%.c
	@echo "${YELLOW}🔨 Compilando grafos: $(notdir $<)${NC}"
	@$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

# Executar exemplos
run-examples: all
	@echo "${BLUE}🚀 Executando demonstrações...${NC}"
	@echo ""
	@echo "${GREEN}=== PONTEIROS BÁSICOS ===${NC}"
	@if [ -f "$(BIN_DIR)/ponteiros_basico" ]; then \
		echo "Digite 0 para sair" | $(BIN_DIR)/ponteiros_basico; \
	fi
	@echo ""
	@echo "${GREEN}=== PILHAS E FILAS ===${NC}"
	@if [ -f "$(BIN_DIR)/pilhas_filas_basico" ]; then \
		echo "0" | $(BIN_DIR)/pilhas_filas_basico; \
	fi
	@echo ""
	@echo "${GREEN}=== LISTAS LIGADAS ===${NC}"
	@if [ -f "$(BIN_DIR)/listas_ligadas" ]; then \
		echo "0" | $(BIN_DIR)/listas_ligadas; \
	fi

# Executar exemplo específico
run-%: $(BIN_DIR)/%
	@echo "${GREEN}🚀 Executando: $<${NC}"
	@./$<

# Testes básicos
test: all
	@echo "${BLUE}🧪 Executando testes básicos...${NC}"
	@passed=0; total=0; \
	for bin in $(ALL_BINS); do \
		if [ -f "$$bin" ]; then \
			echo "${YELLOW}Testando: $$(basename $$bin)${NC}"; \
			total=$$((total + 1)); \
			if echo "0" | timeout 5s "$$bin" >/dev/null 2>&1; then \
				echo "${GREEN}✅ Passou${NC}"; \
				passed=$$((passed + 1)); \
			else \
				echo "${RED}❌ Falhou${NC}"; \
			fi; \
		fi; \
	done; \
	echo ""; \
	echo "${BLUE}📊 Resultado: $$passed/$$total testes passaram${NC}"

# Debug: compilar com símbolos de debug
debug: CFLAGS += -DDEBUG -O0
debug: all
	@echo "${BLUE}🐛 Versão debug compilada com símbolos${NC}"

# Release: compilar otimizado
release: CFLAGS += -O2 -DNDEBUG
release: all
	@echo "${GREEN}🚀 Versão release compilada otimizada${NC}"

# Verificar vazamentos de memória (requer valgrind)
memcheck: all
	@echo "${BLUE}🔍 Verificando vazamentos de memória...${NC}"
	@if command -v valgrind >/dev/null 2>&1; then \
		for bin in $(ALL_BINS); do \
			if [ -f "$$bin" ]; then \
				echo "${YELLOW}Verificando: $$(basename $$bin)${NC}"; \
				echo "0" | timeout 10s valgrind --leak-check=full --error-exitcode=1 "$$bin" >/dev/null 2>&1 && \
				echo "${GREEN}✅ Sem vazamentos${NC}" || \
				echo "${RED}❌ Vazamentos detectados${NC}"; \
			fi; \
		done; \
	else \
		echo "${RED}❌ Valgrind não encontrado. Instale com: sudo apt-get install valgrind${NC}"; \
	fi

# Limpeza
clean:
	@echo "${YELLOW}🧹 Limpando arquivos compilados...${NC}"
	@rm -rf $(BUILD_DIR) $(BIN_DIR)
	@echo "${GREEN}✅ Limpeza concluída!${NC}"

# Informações sobre os exemplos
info:
	@echo "${BLUE}📋 INFORMAÇÕES DOS EXEMPLOS${NC}"
	@echo ""
	@echo "${GREEN}📁 Ponteiros:${NC}"
	@ls -la $(EXEMPLOS_DIR)/ponteiros/*.c 2>/dev/null | sed 's/^/  /' || echo "  Nenhum arquivo encontrado"
	@echo ""
	@echo "${GREEN}📁 Alocação Dinâmica:${NC}"
	@ls -la $(EXEMPLOS_DIR)/alocacao-dinamica/*.c 2>/dev/null | sed 's/^/  /' || echo "  Nenhum arquivo encontrado"
	@echo ""
	@echo "${GREEN}📁 Pilhas e Filas:${NC}"
	@ls -la $(EXEMPLOS_DIR)/pilhas-filas/*.c 2>/dev/null | sed 's/^/  /' || echo "  Nenhum arquivo encontrado"
	@echo ""
	@echo "${GREEN}📁 Listas Ligadas:${NC}"
	@ls -la $(EXEMPLOS_DIR)/listas/*.c 2>/dev/null | sed 's/^/  /' || echo "  Nenhum arquivo encontrado"
	@echo ""
	@echo "${GREEN}📁 Grafos:${NC}"
	@ls -la $(EXEMPLOS_DIR)/grafos/*.c 2>/dev/null | sed 's/^/  /' || echo "  Nenhum arquivo encontrado"

# Instalar dependências (Ubuntu/Debian)
install-deps:
	@echo "${BLUE}📦 Instalando dependências...${NC}"
	@sudo apt-get update
	@sudo apt-get install -y gcc make gdb valgrind
	@echo "${GREEN}✅ Dependências instaladas!${NC}"

# Criar arquivo zip para distribuição
dist: clean all
	@echo "${BLUE}📦 Criando distribuição...${NC}"
	@zip -r estruturas-de-dados-$(shell date +%Y%m%d).zip . -x "*.git*" "$(BUILD_DIR)/*" "*.zip"
	@echo "${GREEN}✅ Arquivo zip criado!${NC}"

# Verificar estilo de código (requer cppcheck)
check-style:
	@echo "${BLUE}🎨 Verificando estilo de código...${NC}"
	@if command -v cppcheck >/dev/null 2>&1; then \
		cppcheck --enable=all --std=c99 $(EXEMPLOS_DIR)/**/*.c; \
	else \
		echo "${YELLOW}⚠️ cppcheck não encontrado. Instale com: sudo apt-get install cppcheck${NC}"; \
	fi

# Gerar documentação (requer doxygen)
docs:
	@echo "${BLUE}📚 Gerando documentação...${NC}"
	@if command -v doxygen >/dev/null 2>&1; then \
		doxygen Doxyfile 2>/dev/null || echo "${YELLOW}⚠️ Arquivo Doxyfile não encontrado${NC}"; \
	else \
		echo "${YELLOW}⚠️ doxygen não encontrado. Instale com: sudo apt-get install doxygen${NC}"; \
	fi

# Menu de ajuda
help:
	@echo "${BLUE}"
	@echo "╔════════════════════════════════════════════════════════════════════════╗"
	@echo "║                    🎯 MAKEFILE - ESTRUTURAS DE DADOS                  ║"
	@echo "╚════════════════════════════════════════════════════════════════════════╝"
	@echo "${NC}"
	@echo "${GREEN}Comandos disponíveis:${NC}"
	@echo ""
	@echo "${YELLOW}📦 Compilação:${NC}"
	@echo "  make all              - Compila todos os exemplos"
	@echo "  make ponteiros        - Compila exemplos de ponteiros"
	@echo "  make alocacao         - Compila exemplos de alocação dinâmica"
	@echo "  make pilhas-filas     - Compila exemplos de pilhas e filas"
	@echo "  make listas           - Compila exemplos de listas ligadas"
	@echo "  make grafos           - Compila exemplos de grafos"
	@echo "  make debug            - Compila com símbolos de debug"
	@echo "  make release          - Compila otimizado para produção"
	@echo ""
	@echo "${YELLOW}🚀 Execução:${NC}"
	@echo "  make run-examples     - Executa demonstrações automáticas"
	@echo "  make run-<exemplo>    - Executa exemplo específico"
	@echo "  make test             - Executa testes básicos"
	@echo ""
	@echo "${YELLOW}🔍 Análise:${NC}"
	@echo "  make memcheck         - Verifica vazamentos de memória (valgrind)"
	@echo "  make check-style      - Verifica estilo de código (cppcheck)"
	@echo ""
	@echo "${YELLOW}📚 Informações:${NC}"
	@echo "  make info             - Lista arquivos dos exemplos"
	@echo "  make help             - Mostra esta ajuda"
	@echo ""
	@echo "${YELLOW}🛠️ Utilitários:${NC}"
	@echo "  make clean            - Remove arquivos compilados"
	@echo "  make install-deps     - Instala dependências (Ubuntu/Debian)"
	@echo "  make dist             - Cria arquivo zip para distribuição"
	@echo "  make docs             - Gera documentação (doxygen)"
	@echo ""
	@echo "${BLUE}💡 Exemplos de uso:${NC}"
	@echo "  make ponteiros && make run-ponteiros_basico"
	@echo "  make all test"
	@echo "  make debug memcheck"
	@echo ""

# Evitar conflitos com arquivos de mesmo nome
.PHONY: all clean help run-examples test ponteiros alocacao pilhas-filas listas grafos debug release memcheck info install-deps dist check-style docs banner

# Mostrar ajuda por padrão se nenhum alvo for especificado
.DEFAULT_GOAL := help
