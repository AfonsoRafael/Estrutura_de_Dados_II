#include <stdio.h>

int main() {
    int numeros[10];
    int soma = 0;
    float media;
    
    // loop para ler os inteiros
    printf("Digite 10 números inteiros:\n");
    for(int i = 0; i < 10; i++) {
        printf("Número %d: ", i+1);
        scanf("%d", &numeros[i]);
        soma += numeros[i];
    }
    
    media = soma / 10.0;
    
    // loop para mostrar os numeros
    printf("\nNúmeros digitados: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", numeros[i]);
    }
    // mostrar o resultado final
    printf("\nSoma total: %d", soma);
    printf("\nMédia: %.2f\n", media);
    
    return 0;
}