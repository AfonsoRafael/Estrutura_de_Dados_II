#include <stdio.h>

int main() {
    int numeros[20];
    int somaPares = 0, qtdPares = 0;
    
    printf("Digite 20 números inteiros:\n");
    for(int i = 0; i < 20; i++) {
        printf("Número %d: ", i+1);
        scanf("%d", &numeros[i]);
    }
    
    printf("\nNúmeros pares: ");
    for(int i = 0; i < 20; i++) {
        if(numeros[i] % 2 == 0) {
            printf("%d ", numeros[i]);
            somaPares += numeros[i];
            qtdPares++;
        }
    }
    
    printf("\nQuantidade de pares: %d", qtdPares);
    printf("\nSoma dos pares: %d\n", somaPares);
    
    return 0;
}