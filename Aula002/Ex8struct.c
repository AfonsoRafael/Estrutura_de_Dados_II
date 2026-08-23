#include <stdio.h>

struct Produto {
    char nome[50];
    float preco;
    int qtde;
};

int main() {
    struct Produto produtos[5];
    float maiorValor = 0;
    int posMaior = 0;
    
    // adicionando produtos
    for(int i = 0; i < 5; i++) {
        printf("\nProduto %d:\n", i+1);
        printf("Nome: ");
        scanf(" %[^\n]", produtos[i].nome);
        printf("Preco: ");
        scanf("%f", &produtos[i].preco);
        printf("Quantidade: ");
        scanf("%d", &produtos[i].qtde);
    }
    
    printf("\nTotal por produto:\n");
    for(int i = 0; i < 5; i++) {
        float total = produtos[i].preco * produtos[i].qtde;
        printf("%s: R$ %.2f\n", produtos[i].nome, total);
        
        if(total > maiorValor) {
            maiorValor = total;
            posMaior = i;
        }
    }
    
    printf("\nMaior valor em estoque: %s - R$ %.2f\n", 
           produtos[posMaior].nome, maiorValor);
    
    return 0;
}