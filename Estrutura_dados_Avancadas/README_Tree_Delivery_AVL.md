# Tree Delivery --- Upgrade para Árvore AVL

## Sobre o projeto

Este projeto utiliza o **Tree Delivery** como modelo base para uma
atividade prática da disciplina de **Estruturas de Dados II -- Ciência
da Computação**.

O Tree Delivery é um jogo educativo desenvolvido com a **Unity Engine**,
no qual o jogador percorre uma representação 2D de uma **Árvore Binária
de Busca (BST)** e realiza entregas nos nós corretos, enfrentando
obstáculos, armadilhas e veículos controlados por IA.

A proposta deste trabalho é realizar uma análise do modelo existente e
propor um **upgrade de mecânica baseado em Árvore AVL**, aproximando os
conceitos teóricos de Estruturas de Dados II da experiência prática do
jogador.

------------------------------------------------------------------------

## Estrutura de Dados Escolhida

### Árvore AVL

A estrutura escolhida para o upgrade é a **Árvore AVL**.

A nova mecânica será baseada principalmente em:

-   Fator de Balanceamento;
-   Identificação de desequilíbrios;
-   Rotações simples;
-   Rotações duplas;
-   Manutenção do balanceamento da árvore.

Em uma Árvore AVL, o fator de balanceamento dos nós deve permanecer
entre **-1, 0 e 1**.

Quando ocorre um desequilíbrio, o jogador deverá identificar o problema
e realizar a rotação adequada para corrigir a estrutura.

------------------------------------------------------------------------

## Relação com o Tree Delivery

O jogo original utiliza uma Árvore Binária de Busca como parte central
de sua experiência.

A proposta é aproveitar essa estrutura existente e acrescentar uma nova
camada de interação:

**No jogo original:**

> O jogador navega pela árvore e entrega os pacotes nos nós corretos.

**Na proposta de upgrade:**

> O jogador realiza operações na árvore, identifica desequilíbrios e
> precisa executar as rotações necessárias para manter a estrutura
> balanceada.

Dessa forma, o conceito de balanceamento deixa de ser apenas um conteúdo
teórico e passa a fazer parte diretamente do gameplay.

------------------------------------------------------------------------

## Exemplo da Nova Mecânica

Ao inserir os valores:

`30 → 20 → 10`

a árvore pode ficar da seguinte forma:

``` text
    30
   /
  20
 /
10
```

O jogador deverá identificar que a árvore está desequilibrada.

Nesse caso, será necessária uma **rotação simples à direita**:

``` text
   20
  /  10    30
```

Após a correção, a árvore volta a apresentar uma estrutura balanceada.

------------------------------------------------------------------------

## Tecnologia

O projeto original foi desenvolvido utilizando:

-   **Unity Engine**
-   **C#**
-   Estrutura de dados baseada em **Árvore Binária de Busca (BST)**

O upgrade proposto utiliza os conceitos de **Árvore AVL**, especialmente
fator de balanceamento e rotações.

------------------------------------------------------------------------

## Mapeamento dos Conceitos

  -----------------------------------------------------------------------
  Conceito de Estruturas de Dados II  Aplicação no jogo
  ----------------------------------- -----------------------------------
  Nó / Chave                          Representa uma posição e um valor
                                      dentro da árvore

  Altura da árvore                    Representa a profundidade da
                                      estrutura

  Fator de Balanceamento              Indica o nível de equilíbrio de
                                      cada nó

  Rotação simples                     Operação utilizada para corrigir
                                      determinados desequilíbrios

  Rotação dupla                       Operação utilizada para corrigir
                                      casos mais complexos

  Árvore AVL                          Estrutura que deve permanecer
                                      balanceada durante as operações
  -----------------------------------------------------------------------

------------------------------------------------------------------------

## Core Loop Proposto

O jogador deverá:

1.  Receber ou selecionar um valor;
2.  Inserir ou remover o valor na árvore;
3.  Verificar o estado da estrutura;
4.  Identificar possíveis desequilíbrios;
5.  Analisar o fator de balanceamento;
6.  Escolher a rotação adequada;
7.  Executar a correção;
8.  Continuar o percurso e os objetivos do jogo.

------------------------------------------------------------------------

## Condição de Vitória

Concluir os objetivos propostos pelo jogo realizando corretamente as
operações e mantendo a Árvore AVL balanceada.

## Condição de Derrota

A partida poderá ser prejudicada ou encerrada quando o jogador realizar
uma operação incorreta ou deixar a estrutura em uma situação que viole
as propriedades de uma Árvore AVL.

------------------------------------------------------------------------

## Objetivo Acadêmico

O objetivo da proposta é transformar conceitos de **Estruturas de Dados
II** em uma experiência de aprendizagem ativa.

Em vez de apenas estudar as propriedades de uma Árvore AVL de forma
teórica, o jogador deverá identificar problemas de balanceamento e tomar
decisões para corrigi-los durante a partida.

Assim, o gameplay passa a funcionar como uma forma prática de
compreender:

-   Fator de Balanceamento;
-   Rotações;
-   Balanceamento de árvores;
-   Inserção e remoção;
-   Manutenção das propriedades de uma Árvore AVL.

------------------------------------------------------------------------

## Referência do Modelo Original

**Tree Delivery**

GitHub: https://github.com/pstultgens/Tree-Delivery

Jogo: https://pstultgens.itch.io/tree-delivery

Projeto original desenvolvido com Unity Engine como jogo educativo
voltado ao aprendizado de Árvores Binárias de Busca.

------------------------------------------------------------------------

## Contexto

**Disciplina:** Estruturas de Dados II\
**Curso:** Ciência da Computação\
**Tema:** Design de Jogos Educativos sobre Árvores Avançadas por meio da
Engenharia Reversa e Reuso de Modelos
