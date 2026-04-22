#include <stdio.h>
#include <string.h>
#include "aluno.h"
#include "disciplina.h"
#include "utils.h"

void aniversariantesMes(){
    char mes[3];
    printf("Mes: "); scanf("%s",mes);

    for(int i=0;i<qtdAlunos;i++){
        if(strncmp(&alunos[i].data[3],mes,2)==0)
            printf("%s", alunos[i].nome);
    }
}

void buscaNome(){
    char busca[100];
    limparBuffer();
    fgets(busca,100,stdin);

    for(int i=0;i<qtdAlunos;i++){
        if(strstr(alunos[i].nome,busca))
            printf("%s", alunos[i].nome);
    }
}

void alunosMenos3Disciplinas(){
    int cont;

    for(int i=0;i<qtdAlunos;i++){
        cont=0;

        for(int j=0;j<qtdDisc;j++){
            for(int k=0;k<disciplinas[j].qtdAlunos;k++){
                if(disciplinas[j].alunos[k]==alunos[i].matricula)
                    cont++;
            }
        }

        if(cont<3)
            printf("%s", alunos[i].nome);
    }
}

void disciplinasLotadas(){
    for(int i=0;i<qtdDisc;i++){
        if(disciplinas[i].qtdAlunos > 40)
            printf("%s\n", disciplinas[i].nome);
    }
}
