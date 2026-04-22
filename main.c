#include <stdio.h>
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"
#include "relatorios.h"

int main(){
    int op = -1;

    do{
        printf("\n1-Aluno\n2-Professor\n3-Disciplina\n4-Relatorios\n0-Sair\n");
        scanf("%d",&op);

        switch(op){
            case 1:{
                int a;
                printf("1-Cadastrar\n2-Listar\n3-Excluir\n");
                scanf("%d",&a);
                if(a==1) cadastrarAluno();
                if(a==2) listarAlunos();
                if(a==3) excluirAluno();
                break;
            }

            case 2:{
                int p;
                printf("1-Cadastrar\n2-Listar\n");
                scanf("%d",&p);
                if(p==1) cadastrarProfessor();
                if(p==2) listarProfessores();
                break;
            }

            case 3:{
                int d;
                printf("1-Cadastrar\n2-Matricular\n3-Listar\n");
                scanf("%d",&d);
                if(d==1) cadastrarDisciplina();
                if(d==2) matricularAluno();
                if(d==3) listarDisciplinas();
                break;
            }

            case 4:{
                int r;
                printf("1-Aniversariantes\n2-Busca\n3-<3 disciplinas\n4-Lotadas\n");
                scanf("%d",&r);

                if(r==1) aniversariantesMes();
                if(r==2) buscaNome();
                if(r==3) alunosMenos3Disciplinas();
                if(r==4) disciplinasLotadas();
                break;
            }
        }

    }while(op!=0);

    return 0;
}
