#ifndef PROFESSOR_H
#define PROFESSOR_H
#define MAX 100
typedef struct{
    int matricula;
    char nome[100];
    char sexo;
    char data[11];
    char cpf[15];
} Professor;
extern Professor professores[MAX];
extern int qtdProf;
void cadastrarProfessor();
void listarProfessores();
#endif
