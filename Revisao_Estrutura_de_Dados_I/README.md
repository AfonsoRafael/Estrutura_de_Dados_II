```
O codigo faz alocação dinamica de memoria, usando malloc para criar uma memoria dinamicamente alocada, nesse exemplo não tem o realloc para realocar a memoria, e o free libera o espaço
```

#include <stdio.h>

#include<stdlib.h>//malloc, free, realloc



int main()

{

  int n,i;

  int *medicoes;

   

   

  printf("Quantas medições você deseja realizar hoje? ");

  scanf("%d", &n);

  // alocacao dinamica de memoria

  medicoes = (int*)malloc(n*sizeof(int)); 

  // verifica se a alocacao teve sucesso

   

  if(medicoes ==NULL){

    printf("Sistema sem memória!");

    return 1;// significa que foi encerrado com erro

  }

  for(i=0;i<n;i++){

    printf("Digite a medicao: ");

    scanf("%d",&medicoes[i]);

  }

  for(i=0;i<n;i++){

    printf("%d - %d - %p\n",i,medicoes[i],*(medicoes+i));

  }

  //Liberar memoria alocada, importante para limpar a memoria do computador

  // por que se não fizer isso mesmo depois do programa encerrar a memoria

  //estara ocupada

  free(medicoes);

  medicoes = NULL;

  return 0; 

}
