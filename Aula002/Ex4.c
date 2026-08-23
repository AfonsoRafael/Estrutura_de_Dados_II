#include <stdio.h>

int main() {
    int numeros[10];
    
    printf("Digite 10 números inteiros:\n");
    for(int i = 0; i < 10; i++) {
        printf("Número %d: ", i+1);
        scanf("%d", &numeros[i]);
    }
    
    printf("\nOrdem inversa: ");
    for(int i = 9; i >= 0; i--) {
        printf("%d ", numeros[i]);
    }
    printf("\n");
    
    return 0;
}