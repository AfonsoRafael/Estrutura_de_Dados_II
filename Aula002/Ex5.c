#include <stdio.h>
#include <stdlib.h> // Para abs()

int main() {
    int matriz[3][3];
    int soma = 0;
    int maiorAbsoluto;
    
    // loop para ler os numeros
    printf("Digite os valores da matriz 3x3:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("Matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    
    // loop para mostrar os numeros
    printf("\nMatriz digitada:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
    
    // abs mostra o valor absoluto ou modulo, e se for o maior salva
    maiorAbsoluto = abs(matriz[0][0]);
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            soma += matriz[i][j];
            if(abs(matriz[i][j]) > maiorAbsoluto) {
                maiorAbsoluto = abs(matriz[i][j]);
            }
        }
    }
    
    printf("\nSoma de todos os elementos: %d", soma);
    printf("\nMaior valor absoluto: %d\n", maiorAbsoluto);
    
    return 0;
}