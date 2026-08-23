#include <stdio.h>

int main() {
    int numeros[10];
    int maior, menor, posMaior, posMenor;
    
    // loop para ler os numeros
    printf("Digite 10 números inteiros:\n");
    for(int i = 0; i < 10; i++) {
        printf("Número %d: ", i+1);
        scanf("%d", &numeros[i]);
    }
    
    maior = menor = numeros[0];
    posMaior = posMenor = 0;
    
    // loop para verificar qual e maior e qual e menor
    for(int i = 1; i < 10; i++) {
        if(numeros[i] > maior) {
            maior = numeros[i];
            posMaior = i;
        }
        if(numeros[i] < menor) {
            menor = numeros[i];
            posMenor = i;
        }
    }
    
    printf("\nMaior valor: %d (posição %d)", maior, posMaior);
    printf("\nMenor valor: %d (posição %d)\n", menor, posMenor);
    
    return 0;
}