#include <stdio.h>
#include <string.h>
#include "professor.h"
#include "utils.h"

Professor professores[MAX];
int qtdProf = 0;

void cadastrarProfessor(){
    Professor p;
    printf("Matricula: "); scanf("%d",&p.matricula);
    limparBuffer();
    printf("Nome: "); fgets(p.nome,100,stdin);
    printf("Sexo: "); scanf(" %c",&p.sexo);
    printf("Data: "); scanf("%s",p.data);
    printf("CPF: "); scanf("%s",p.cpf);
    professores[qtdProf++] = p;
}

void listarProfessores(){
    for(int i=0;i<qtdProf;i++)
        printf("%d - %s", professores[i].matricula, professores[i].nome);
}
