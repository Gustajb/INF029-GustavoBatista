#include <stdio.h>
#include <string.h>
#include "aluno.h"
#include "utils.h"

Aluno alunos[MAX];
int qtdAlunos = 0;

void cadastrarAluno(){
    Aluno a;
    printf("Matricula: "); scanf("%d",&a.matricula);
    limparBuffer();
    printf("Nome: "); fgets(a.nome,100,stdin);
    printf("Sexo: "); scanf(" %c",&a.sexo);
    printf("Data: "); scanf("%s",a.data);
    printf("CPF: "); scanf("%s",a.cpf);
    alunos[qtdAlunos++] = a;
}

void listarAlunos(){
    for(int i=0;i<qtdAlunos;i++)
        printf("%d - %s", alunos[i].matricula, alunos[i].nome);
}

void excluirAluno(){
    int mat;
    printf("Matricula: "); scanf("%d",&mat);
    for(int i=0;i<qtdAlunos;i++){
        if(alunos[i].matricula==mat){
            alunos[i]=alunos[qtdAlunos-1];
            qtdAlunos--;
            return;
        }
    }
}
