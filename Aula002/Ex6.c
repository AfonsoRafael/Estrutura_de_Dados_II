#include <stdio.h>

int main() {
    int matriz[4][4];
    int somaDiagonal = 0;
    
    printf("Digite os valores da matriz 4x4:\n");
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            printf("Matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    
    printf("\nDiagonal principal: ");
    for(int i = 0; i < 4; i++) {
        printf("%d ", matriz[i][i]);
        somaDiagonal += matriz[i][i];
    }
    
    printf("\nSoma da diagonal principal: %d\n", somaDiagonal);
    
    return 0;
}