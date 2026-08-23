#include <stdio.h>

int main() {
    float notas[4][3]; // 4 alunos, 3 avaliações
    float mediaAluno;
    
    printf("Digite as notas dos 4 alunos (3 notas cada):\n");
    for(int i = 0; i < 4; i++) {
        printf("\nAluno %d:\n", i+1);
        for(int j = 0; j < 3; j++) {
            printf("Nota %d: ", j+1);
            scanf("%f", &notas[i][j]);
        }
    }
    
    printf("\nMédias por aluno:\n");
    for(int i = 0; i < 4; i++) {
        mediaAluno = (notas[i][0] + notas[i][1] + notas[i][2]) / 3.0;
        printf("Aluno %d: %.2f\n", i+1, mediaAluno);
    }
    
    return 0;
}