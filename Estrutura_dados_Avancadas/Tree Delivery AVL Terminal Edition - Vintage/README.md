# Tree Delivery: AVL Edition (Terminal & Web)

## Sobre o Jogo

**Tree Delivery: AVL Edition** é um jogo educativo criado com base em metodologias de engenharia reversa do jogo original "Tree Delivery" (desenvolvido originalmente em Unity para BST). O projeto conta com duas versões (Terminal em C e Interface Gráfica em HTML/JS), servindo como um *upgrade* de mecânica, transferindo a responsabilidade do rebalanceamento da árvore AVL diretamente para o jogador.

## Contexto do Projeto

* **Disciplina:** Estruturas de Dados II

* **Curso:** Ciência da Computação

* **Tema:** Design de Jogos Educativos sobre Árvores Avançadas por meio da Engenharia Reversa e Reuso de Modelos.

* **Objetivo:** Transformar a experiência passiva do jogo original em uma mecânica ativa focada em Árvores AVL.

## Proposta Educacional e Objetivo de Aprendizagem

O principal objetivo acadêmico é consolidar o aprendizado prático das **Árvores AVL**. Em vez de apenas estudar e memorizar no papel as regras de balanceamento, o jogador atua como o "algoritmo vivo". Ele precisa identificar Fatores de Balanceamento (FB) em tempo real e aplicar as operações corretas de Rotações (Simples e Duplas) para manter o custo computacional otimizado em `O(log n)`. O jogo converte abstrações matemáticas em um desafio dinâmico com risco de falha.

## Conceitos de Estrutura de Dados Utilizados

* **Nós e Chaves:** Representam os locais de entrega e os números das caixas.

* **Ordenação via Árvores Binárias de Busca (BST):** A base da ordenação (esquerda < raiz < direita).

* **Altura da Árvore:** Profundidade calculada dinamicamente para cada galho.

* **Fator de Balanceamento (FB):** A métrica central. Permitida apenas nos limites de `-1, 0, e 1`.

* **Rotações Simples (LL e RR):** Manobras básicas para correção de desequilíbrios lineares.

* **Rotações Duplas (LR e RL):** Manobras combinadas para correção de desequilíbrios em "joelho" (ziguezague).

## Funcionamento e Mecânica do Jogo

O jogo funciona em um *core loop* contínuo de entregas:

1. O sistema gera aleatoriamente um valor numérico para uma "caixa".

2. A caixa é inserida na estrutura seguindo a lógica estrita de **ordenação BST** (navegando com setas na versão web ou aprovação automática na versão C).

3. O jogo calcula recursivamente a altura e o FB de todos os nós no caminho percorrido.

4. **Intervenção do Jogador:** Se o jogo detectar um nó com FB > 1 ou FB < -1, a rotina para e o foco é dado ao desequilíbrio.

5. O jogador deve analisar visualmente a árvore e decidir qual das 4 rotações (LL, RR, LR, RL) resolve o colapso.

## Sistema de Acertos e Punições

* **Acertos:** Executar a rotação correta recompensa o jogador com **+20 pontos**. A árvore é estabilizada e a rodada segue.

* **Erros:** Escolher a manobra errada custa **1 Vida**. A estrutura sofre um impacto e é deixada em um estado desequilibrado.

* **Condição de Vitória:** Entregar com sucesso o número máximo de caixas preservando as propriedades e a altura ótima da árvore AVL.

* **Condição de Derrota:** Perder todas as vidas disponíveis, permitindo que a estrutura entre em colapso e cause a "degradação algorítmica para O(n)".

## Tecnologias Utilizadas

Este projeto possui duas implementações para diferentes contextos de uso:

* **Versão Web (Gráfica e Interativa):** Desenvolvida em HTML5, CSS3 e JavaScript Vanilla. Renderização de vetores dinâmicos utilizando SVG.

* **Versão Terminal (Console):** Desenvolvida em C (Padrão ANSI) puro.

## Como Executar

### Opção 1: Versão Web (HTML/JS) - *Recomendada*
A versão web oferece uma interface gráfica completa com animações e interface visual detalhada.

1. Crie um novo arquivo de texto no seu computador.
2. Cole todo o código-fonte HTML fornecido no arquivo.
3. Salve o arquivo com a extensão `.html` (por exemplo: `tree_delivery_avl.html`).
4. Dê um duplo clique no arquivo para abri-lo diretamente no seu navegador web preferido (Chrome, Edge, Firefox, Safari, etc.).
5. **Nenhuma instalação ou servidor local é necessário.** Jogue utilizando as setas direcionais e os botões de 1 a 4 do teclado (ou clicando com o mouse).

### Opção 2: Versão Terminal (C)
A versão em C é ideal para visualizar o funcionamento interno via terminal clássico.

1. Abra a sua IDE de preferência (Dev-C++ ou Code::Blocks).
2. Crie um novo arquivo de código-fonte (`.c`) vazio.
3. Cole o código-fonte em C fornecido.
4. Salve o arquivo (ex: `tree_delivery_avl.c`).
5. Compile o programa (geralmente pressionando `F9`).
6. Execute o arquivo compilado (geralmente `F10` ou o botão de Play).
7. Interaja digitando os números das opções e pressionando a tecla `ENTER`.