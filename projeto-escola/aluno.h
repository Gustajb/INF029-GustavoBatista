#ifndef ALUNO_H
#define ALUNO_H
#define MAX 100
typedef struct{
    int matricula;
    char nome[100];
    char sexo;
    char data[11];
    char cpf[15];
} Aluno;
extern Aluno alunos[MAX];
extern int qtdAlunos;
void cadastrarAluno();
void listarAlunos();
void excluirAluno();
#endif
