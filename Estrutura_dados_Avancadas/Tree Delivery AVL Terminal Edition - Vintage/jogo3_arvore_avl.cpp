#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura do Nó da Árvore AVL (representando um local de entrega)
typedef struct Node {
    int key; // Número da caixa
    int height;
    struct Node *left;
    struct Node *right;
} Node;

// Variáveis globais para o jogo
int score = 0;
int lives = 3;

// Função para limpar a tela de forma multiplataforma
void clearScreen() {
    system("cls || clear");
}

// Função para obter a altura do nó
int getHeight(Node *n) {
    if (n == NULL) return 0;
    return n->height;
}

// Função para obter o maior entre dois números
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Função para criar um novo nó (nova caixa entregue)
Node* createNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // Nó novo é inicialmente adicionado como folha
    return node;
}

// Função para calcular o Fator de Balanceamento
int getBalance(Node *n) {
    if (n == NULL) return 0;
    return getHeight(n->left) - getHeight(n->right);
}

// Imprime a árvore horizontalmente para facilitar a visualização no terminal
void printTree(Node *root, int space) {
    if (root == NULL) return;
    space += 7;
    printTree(root->right, space);
    printf("\n");
    for (int i = 7; i < space; i++) printf(" ");

    int fb = getBalance(root);
    printf("%d(FB:%d)\n", root->key, fb);

    printTree(root->left, space);
}

// Rotação Simples a Direita (LL)
Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Rotação Simples a Esquerda (RR)
Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Função de inserção que integra a mecânica do jogo
Node* insertGame(Node* node, int key) {
    // 1. Inserção normal de Árvore Binária de Busca
    if (node == NULL) return createNode(key);

    if (key < node->key)
        node->left = insertGame(node->left, key);
    else if (key > node->key)
        node->right = insertGame(node->right, key);
    else
        return node; // Não permitimos caixas duplicadas

    // 2. Atualiza a altura do nó atual
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // 3. Verifica o Fator de Balanceamento
    int balance = getBalance(node);

    // Se o nó ficou desbalanceado, aciona o minigame de correção
    if (balance > 1 || balance < -1) {
        printf("\n======================================================\n");
        printf(" [!] ALERTA: DESEQUILIBRIO DETECTADO! [!]\n");
        printf(" A entrega da caixa %d causou um colapso na arvore!\n", key);
        printf(" O no %d esta com Fator de Balanceamento de %d.\n", node->key, balance);
        printf("======================================================\n\n");

        printf("Visualizacao da subarvore afetada:\n");
        printTree(node, 0);
        printf("\n------------------------------------------------------\n");

        // Determina qual é a rotação correta baseada na teoria da AVL
        int expected_answer = 0;
        if (balance > 1 && key < node->left->key) expected_answer = 1;      // LL -> Rot Dir
        else if (balance < -1 && key > node->right->key) expected_answer = 2; // RR -> Rot Esq
        else if (balance > 1 && key > node->left->key) expected_answer = 3;   // LR -> Rot Esq-Dir
        else if (balance < -1 && key < node->right->key) expected_answer = 4; // RL -> Rot Dir-Esq

        int choice = 0;
        printf("Escolha a manobra de rotacao para consertar o galho:\n");
        printf("1 - Rotacao Simples a Esquerda (Caso LL)\n");
        printf("2 - Rotacao Simples a Direita (Caso RR)\n");
        printf("3 - Rotacao Dupla Direita-Esquerda (Caso LR)\n");
        printf("4 - Rotacao Dupla Esquerda-Direita (Caso RL)\n");
        printf("\nSua escolha: ");

        while (choice < 1 || choice > 4) {
            scanf("%d", &choice);
            if(choice < 1 || choice > 4) printf("Escolha invalida! Digite de 1 a 4: ");
        }

        // Sistema de Acertos e Erros
        if (choice == expected_answer) {
            printf("\n=> EXCELENTE! Manobra executada com perfeicao. A arvore foi estabilizada!\n");
            score += 20;
        } else {
            lives--;
            printf("\n=> ERRO! A manobra incorreta causou danos a arvore.\n");
            printf("A rotacao correta era a opcao %d. O sistema forcou a correcao automatica para evitar perda total.\n", expected_answer);
            printf("Vidas restantes: %d\n", lives);
        }

        printf("\nPressione ENTER para continuar...");
        getchar(); // Limpar buffer
        getchar(); // Pausa

        // Aplica a rotação correta independentemente para o jogo poder continuar
        if (expected_answer == 1) return rightRotate(node);
        if (expected_answer == 2) return leftRotate(node);
        if (expected_answer == 3) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (expected_answer == 4) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }

    return node; // Retorna o nó (balanceado)
}

int main() {
    Node *root = NULL;
    srand(time(NULL));
    int caixas_entregues = 0;
    int max_caixas = 15; // Objetivo para vencer

    clearScreen();
    printf("==================================================\n");
    printf("        TREE DELIVERY: AVL TERMINAL EDITION       \n");
    printf("==================================================\n");
    printf("Bem-vindo ao simulador de entregas florestais!\n");
    printf("Sua missao e entregar %d caixas na Arvore AVL.\n", max_caixas);
    printf("Se as caixas pesarem muito para um lado, a arvore\n");
    printf("vai desequilibrar. Voce deve escolher as rotacoes\n");
    printf("corretas para salvar o ecossistema algoritmico!\n\n");
    printf("Pressione ENTER para comecar...");
    getchar();

    while (lives > 0 && caixas_entregues < max_caixas) {
        clearScreen();
        printf("================ STATUS =================\n");
        printf(" Pontos: %d  |  Vidas: %d  |  Caixas: %d/%d\n", score, lives, caixas_entregues, max_caixas);
        printf("=========================================\n\n");

        if (root != NULL) {
            printf("Arvore atual (deitada - Raiz a esquerda):\n");
            printTree(root, 0);
            printf("\n-----------------------------------------\n");
        }

        int nova_caixa = (rand() % 90) + 10; // Gera caixa entre 10 e 99
        printf(">>> Uma nova caixa chegou: [ %d ]\n", nova_caixa);
        printf("Entregando...\n");

        // Pausa dramática simulada
        printf("Pressione ENTER para processar a insercao...");
        getchar();

        root = insertGame(root, nova_caixa);
        caixas_entregues++;
    }

    clearScreen();
    printf("================ FIM DE JOGO ================\n");
    if (lives == 0) {
        printf(" [ DERROTA ] A arvore colapsou devido a multiplas rotacoes incorretas.\n");
        printf(" A complexidade do sistema degradou para O(n)!\n");
    } else {
        printf(" [ VITORIA ] Parabens, Mestre das Estruturas!\n");
        printf(" Voce manteve a arvore balanceada perfeitamente. O(log n) garantido!\n");
    }
    printf("\n Pontuacao Final: %d pontos\n", score);
    printf(" Caixas Entregues: %d\n", caixas_entregues);
    printf("=============================================\n");

    return 0;
}
