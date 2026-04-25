#ifndef DISCIPLINA_H
#define DISCIPLINA_H
#define MAX_DISC 50
#define MAX_VAGAS 40
typedef struct{
    int codigo;
    char nome[100];
    int semestre;
    int professor;
    int alunos[MAX_VAGAS];
    int qtdAlunos;
} Disciplina;
extern Disciplina disciplinas[MAX_DISC];
extern int qtdDisc;
void cadastrarDisciplina();
void matricularAluno();
void listarDisciplinas();
#endif
