#include <stdio.h>
#include <string.h>

struct Funcionario {
    char nome[50];
    char cargo[30];
    float salario;
};

void cadastrar(struct Funcionario f[], int n);
void listar(struct Funcionario f[], int n);
void maiorSalario(struct Funcionario f[], int n);
void mediaSalarial(struct Funcionario f[], int n);
void acimaMedia(struct Funcionario f[], int n);

int main() {
    struct Funcionario funcionarios[10];
    int opcao;
    
    do {
        printf("\n=== SISTEMA RH ===\n");
        printf("1 - Cadastrar funcionarios\n");
        printf("2 - Listar todos\n");
        printf("3 - Maior salario\n");
        printf("4 - Média salarial\n");
        printf("5 - Funcionarios acima da media\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                cadastrar(funcionarios, 10);
                break;
            case 2:
                listar(funcionarios, 10);
                break;
            case 3:
                maiorSalario(funcionarios, 10);
                break;
            case 4:
                mediaSalarial(funcionarios, 10);
                break;
            case 5:
                acimaMedia(funcionarios, 10);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 0);
    
    return 0;
}

void cadastrar(struct Funcionario f[], int n) {
    for(int i = 0; i < n; i++) {
        printf("\nFuncionario %d:\n", i+1);
        printf("Nome: ");
        scanf(" %[^\n]", f[i].nome);
        printf("Cargo: ");
        scanf(" %[^\n]", f[i].cargo);
        printf("Salario: ");
        scanf("%f", &f[i].salario);
    }
    printf("Cadastro concluido!\n");
}

void listar(struct Funcionario f[], int n) {
    printf("\nLISTA DE FUNCIONARIOS:\n");
    for(int i = 0; i < n; i++) {
        printf("%d - %s | %s | R$ %.2f\n", 
               i+1, f[i].nome, f[i].cargo, f[i].salario);
    }
}

void maiorSalario(struct Funcionario f[], int n) {
    float maior = f[0].salario;
    int pos = 0;
    
    for(int i = 1; i < n; i++) {
        if(f[i].salario > maior) {
            maior = f[i].salario;
            pos = i;
        }
    }
    
    printf("\nMaior salario:\n");
    printf("%s | %s | R$ %.2f\n", f[pos].nome, f[pos].cargo, f[pos].salario);
}

void mediaSalarial(struct Funcionario f[], int n) {
    float soma = 0;
    float media;
    
    for(int i = 0; i < n; i++) {
        soma += f[i].salario;
    }
    
    media = soma / n;
    printf("\nMedia salarial geral: R$ %.2f\n", media);
}

void acimaMedia(struct Funcionario f[], int n) {
    float soma = 0;
    float media;
    
    for(int i = 0; i < n; i++) {
        soma += f[i].salario;
    }
    
    media = soma / n;
    
    printf("\nFuncionarios acima da media (R$ %.2f):\n", media);
    int encontrou = 0;
    for(int i = 0; i < n; i++) {
        if(f[i].salario > media) {
            printf("%s | %s | R$ %.2f\n", f[i].nome, f[i].cargo, f[i].salario);
            encontrou = 1;
        }
    }
    
    if(!encontrou) {
        printf("Nenhum funcionario acima da media.\n");
    }
}