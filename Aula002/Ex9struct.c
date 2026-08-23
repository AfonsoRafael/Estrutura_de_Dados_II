#include <stdio.h>
#include <string.h>

struct Aluno {
    char nome[50];
    char disciplina[30];
    float nota1, nota2;
};

int main() {
    struct Aluno alunos[5];
    float media, maiorMedia = 0;
    int aprovados = 0, reprovados = 0;
    char alunoMaior[50];
    
    for(int i = 0; i < 5; i++) {
        printf("\nAluno %d:\n", i+1);
        printf("Nome: ");
        scanf(" %[^\n]", alunos[i].nome);
        printf("Disciplina: ");
        scanf(" %[^\n]", alunos[i].disciplina);
        printf("Nota 1: ");
        scanf("%f", &alunos[i].nota1);
        printf("Nota 2: ");
        scanf("%f", &alunos[i].nota2);
    }
    
    printf("\nResultados:\n");
    for(int i = 0; i < 5; i++) {
        media = (alunos[i].nota1 + alunos[i].nota2) / 2.0;
        
        printf("%s (%.2f) - ", alunos[i].nome, media);
        if(media >= 7.0) {
            printf("Aprovado\n");
            aprovados++;
        } else {
            printf("Reprovado\n");
            reprovados++;
        }
        
        if(media > maiorMedia) {
            maiorMedia = media;
            strcpy(alunoMaior, alunos[i].nome);
        }
    }
    
    printf("\nAprovados: %d", aprovados);
    printf("\nReprovados: %d", reprovados);
    printf("\nMaior média: %s (%.2f)\n", alunoMaior, maiorMedia);
    
    return 0;
}