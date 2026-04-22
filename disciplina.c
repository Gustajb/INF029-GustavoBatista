#include <stdio.h>
#include <string.h>
#include "disciplina.h"
#include "utils.h"

Disciplina disciplinas[MAX_DISC];
int qtdDisc = 0;

void cadastrarDisciplina(){
    Disciplina d;

    printf("Codigo: ");
    scanf("%d",&d.codigo);

    limparBuffer();
    printf("Nome: ");
    fgets(d.nome,100,stdin);

    printf("Semestre: ");
    scanf("%d",&d.semestre);

    printf("Indice professor: ");
    scanf("%d",&d.professor);

    d.qtdAlunos = 0;

    if(qtdDisc < MAX_DISC){
        disciplinas[qtdDisc++] = d;
    } else {
        printf("Limite de disciplinas atingido!\n");
    }
}

void matricularAluno(){
    int cod, mat;
    printf("Codigo disciplina: "); scanf("%d",&cod);
    printf("Matricula aluno: "); scanf("%d",&mat);

    for(int i=0;i<qtdDisc;i++){
        if(disciplinas[i].codigo==cod){
            if(disciplinas[i].qtdAlunos < MAX_VAGAS){
                disciplinas[i].alunos[disciplinas[i].qtdAlunos++] = mat;
            }
        }
    }
}

void listarDisciplinas(){
    for(int i=0;i<qtdDisc;i++)
        printf("%d - %s (%d alunos)\n",
        disciplinas[i].codigo,
        disciplinas[i].nome,
        disciplinas[i].qtdAlunos);
}
