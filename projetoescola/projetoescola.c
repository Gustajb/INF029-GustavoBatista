#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM_ALUNOS 50
#define TAM_PROFESSORES 50
#define TAM_DISCPLINAS 10
#define TAM_ALUNOS_DISCIPLINA 50

// quantidade na lista
int qtdAlunos = 0;
int qtdProfessores = 0;
int qtdDisciplinas = 0;

// struct aluno
typedef struct{
    char nome[50];
    int matricula;
    char sexo[10];
    char dataNascimento[11];
    char cpf[15];
}Aluno;

// struct professor
typedef struct{
    char nome[50];
    int id;
    char sexo[10];
    char dataNascimento[11];
    char cpf[15];
    char disciplina[50];
}Professor;

typedef struct{
    int id;
    char nome[50];
    int semestre;
    char professor[50];
    int alunos[TAM_ALUNOS_DISCIPLINA];
    int qtdAlunos;
}Disciplina;

// lista de alunos
Aluno listaAlunos[TAM_ALUNOS];
Professor listaProfessores[TAM_PROFESSORES];
Disciplina listaDisciplinas[TAM_DISCPLINAS];

// DECLARAÇÃO DAS FUNÇÕES
void separador();
int menu(void);
int menu_aluno(void);
int menu_professor(void);
int menu_disciplina(void);
int menu_relatorios(void);
void cadastrar_aluno();
void listar_aluno();
void atualizar_aluno();
void excluir_aluno();
void cadastrar_professor();
void listar_professores();
void atualizar_professor();
void excluir_professor();
void cadastrar_disciplina();
void listar_disciplinas();
void atualizar_disciplina();
void excluir_disciplina();
void inserir_aluno_disciplina();
void excluir_aluno_disciplina();
void listar_uma_disciplina();
void listar_alunos_por_sexo();
void ordenar_alunos_nome();
void ordenar_alunos_data();
void listar_professores_por_sexo();
void ordenar_professores_nome();
void ordenar_professores_data();
void aniversariantes_mes();
void buscar_pessoas();
void alunos_menos_3_disciplinas();
void disciplinas_mais_40_alunos();
int data_valida(char data[]);
int valor_data(char data[]);
int cpf_valido(char cpf[]);
int matricula_aluno_existe(int matricula);
int id_professor_existe(int id);
int id_disciplina_existe(int id);
void limpar_entrada();

int main(){
    int sair = 0;
    int opcao;
    int opcao_aluno;
    int opcao_professor;
    int opcao_disciplina;
    int opcao_relatorios;

    // laço do menu principal
    while (sair != 1){
        opcao = menu();

        switch(opcao){
            // menu de alunos
            case 1:
                opcao_aluno = 0;

                while(opcao_aluno != 5){
                    opcao_aluno = menu_aluno();

                    if (opcao_aluno == 1){
                        cadastrar_aluno();
                    }
                    if (opcao_aluno == 2){
                        listar_aluno();
                    }
                    if (opcao_aluno == 3){
                        atualizar_aluno();
                    }
                    if (opcao_aluno == 4){
                        excluir_aluno();
                    }
                    if (opcao_aluno == 5){
                        break;
                    }
                }
                break;

            // menu de professores
            case 2:
                opcao_professor = 0;

                while(opcao_professor != 5){
                    opcao_professor = menu_professor();

                    if (opcao_professor == 1){
                        cadastrar_professor();
                    }
                    if (opcao_professor == 2){
                        listar_professores();
                    }
                    if (opcao_professor == 3){
                        atualizar_professor();
                    }
                    if (opcao_professor == 4){
                        excluir_professor();
                    }
                    if (opcao_professor == 5){
                        break;
                    }
                }
                break;

            // menu de disciplinas
            case 3:
                opcao_disciplina = 0;

                while(opcao_disciplina != 8){
                    printf("\nModulo Disciplina\n");
                    opcao_disciplina = menu_disciplina();

                    if (opcao_disciplina == 1){
                        cadastrar_disciplina();
                    }
                    if (opcao_disciplina == 2){
                        listar_disciplinas();
                    }
                    if (opcao_disciplina == 3){
                        atualizar_disciplina();
                    }
                    if (opcao_disciplina == 4){
                        excluir_disciplina();
                    }
                    if (opcao_disciplina == 5){
                        inserir_aluno_disciplina();
                    }
                    if (opcao_disciplina == 6){
                        excluir_aluno_disciplina();
                    }
                    if (opcao_disciplina == 7){
                        listar_uma_disciplina();
                    }
                    if (opcao_disciplina == 8){
                        break;
                    }
                }
                break;

            // relatórios
            case 4:
                opcao_relatorios = 0;

                while(opcao_relatorios != 12){
                    opcao_relatorios = menu_relatorios();

                    if (opcao_relatorios == 1){
                        listar_alunos_por_sexo();
                    }
                    if (opcao_relatorios == 2){
                        ordenar_alunos_nome();
                    }
                    if (opcao_relatorios == 3){
                        ordenar_alunos_data();
                    }
                    if (opcao_relatorios == 4){
                        listar_professores_por_sexo();
                    }
                    if (opcao_relatorios == 5){
                        ordenar_professores_nome();
                    }
                    if (opcao_relatorios == 6){
                        ordenar_professores_data();
                    }
                    if (opcao_relatorios == 7){
                        aniversariantes_mes();
                    }
                    if (opcao_relatorios == 8){
                        buscar_pessoas();
                    }
                    if (opcao_relatorios == 9){
                        alunos_menos_3_disciplinas();
                    }
                    if (opcao_relatorios == 10){
                        disciplinas_mais_40_alunos();
                    }
                    if (opcao_relatorios == 11){
                        listar_uma_disciplina();
                    }
                    if (opcao_relatorios == 12){
                        break;
                    }
                }
                break;

            case 5:
                sair = 1;
                break;

            default:
                printf("Opcao invalida.\n");
                break;
        }
    }

    return 0;
}

int menu(){
    int opcao;
    printf("\n1-Aluno\n");
    printf("2-Professor\n");
    printf("3-Disciplina\n");
    printf("4-Relatorios\n");
    printf("5-Sair\n");
    printf("Escolha: ");
    scanf(" %d", &opcao);
    return opcao;
}

int menu_aluno(){
    int opcao_aluno;
    printf("\n1-Cadastrar aluno\n");
    printf("2-Listar alunos\n");
    printf("3-Atualizar aluno\n");
    printf("4-Excluir aluno\n");
    printf("5-Voltar\n");
    printf("Escolha: ");
    scanf(" %d", &opcao_aluno);
    return opcao_aluno;
}

void cadastrar_aluno(){
    if(qtdAlunos >= TAM_ALUNOS){
        printf("A lista de alunos esta cheia.\n");
        return;
    }

    printf("Digite a matricula do aluno: ");
    scanf(" %d", &listaAlunos[qtdAlunos].matricula);

    if(matricula_aluno_existe(listaAlunos[qtdAlunos].matricula)){
        printf("Essa matricula ja esta cadastrada.\n");
        return;
    }

    printf("Digite o nome do aluno: ");
    scanf(" %49[^\n]", listaAlunos[qtdAlunos].nome);

    do{
        printf("Digite o sexo (M/F): ");
        scanf(" %9s", listaAlunos[qtdAlunos].sexo);
        listaAlunos[qtdAlunos].sexo[0] = (char)toupper((unsigned char)listaAlunos[qtdAlunos].sexo[0]);
    }while(strcmp(listaAlunos[qtdAlunos].sexo, "M") != 0 && strcmp(listaAlunos[qtdAlunos].sexo, "F") != 0);

    do{
        printf("Digite a data de nascimento (DD/MM/AAAA): ");
        scanf(" %10s", listaAlunos[qtdAlunos].dataNascimento);
        if(!data_valida(listaAlunos[qtdAlunos].dataNascimento)){
            printf("Data invalida.\n");
        }
    }while(!data_valida(listaAlunos[qtdAlunos].dataNascimento));

    do{
        printf("Digite o CPF (somente numeros): ");
        scanf(" %14s", listaAlunos[qtdAlunos].cpf);
        if(!cpf_valido(listaAlunos[qtdAlunos].cpf)){
            printf("CPF invalido. Informe 11 numeros.\n");
        }
    }while(!cpf_valido(listaAlunos[qtdAlunos].cpf));

    qtdAlunos++;
    printf("Aluno cadastrado com sucesso!\n");
}

void listar_aluno(){
    if(qtdAlunos == 0){
        printf("Nao ha alunos cadastrados.\n");
        return;
    }

    for(int i = 0; i < qtdAlunos; i++){
        separador();
        printf("Aluno: %s\n", listaAlunos[i].nome);
        printf("Matricula: %d\n", listaAlunos[i].matricula);
        printf("Sexo: %s\n", listaAlunos[i].sexo);
        printf("Data de nascimento: %s\n", listaAlunos[i].dataNascimento);
        printf("CPF: %s\n", listaAlunos[i].cpf);
        separador();
    }
}

void atualizar_aluno(){
    int matriculaBusca;

    if(qtdAlunos == 0){
        printf("Nao ha alunos para atualizar.\n");
        return;
    }

    printf("Digite a matricula do aluno que quer atualizar: ");
    scanf(" %d", &matriculaBusca);

    for(int i = 0; i < qtdAlunos; i++){
        if(listaAlunos[i].matricula == matriculaBusca){
            printf("Atualize o nome do aluno: ");
            scanf(" %49[^\n]", listaAlunos[i].nome);

            do{
                printf("Atualize o sexo (M/F): ");
                scanf(" %9s", listaAlunos[i].sexo);
                listaAlunos[i].sexo[0] = (char)toupper((unsigned char)listaAlunos[i].sexo[0]);
            }while(strcmp(listaAlunos[i].sexo, "M") != 0 && strcmp(listaAlunos[i].sexo, "F") != 0);

            do{
                printf("Atualize a data de nascimento (DD/MM/AAAA): ");
                scanf(" %10s", listaAlunos[i].dataNascimento);
            }while(!data_valida(listaAlunos[i].dataNascimento));

            do{
                printf("Atualize o CPF (somente numeros): ");
                scanf(" %14s", listaAlunos[i].cpf);
            }while(!cpf_valido(listaAlunos[i].cpf));

            printf("Atualize a matricula do aluno: ");
            scanf(" %d", &listaAlunos[i].matricula);

            printf("Aluno atualizado com sucesso!\n");
            return;
        }
    }

    printf("Aluno nao encontrado.\n");
}

void excluir_aluno(){
    int matriculaExcluir;

    if(qtdAlunos == 0){
        printf("Nao ha alunos para excluir.\n");
        return;
    }

    printf("Digite a matricula do aluno que voce quer excluir: ");
    scanf(" %d", &matriculaExcluir);

    for(int i = 0; i < qtdAlunos; i++){
        if(listaAlunos[i].matricula == matriculaExcluir){
            for(int d = 0; d < qtdDisciplinas; d++){
                for(int j = 0; j < listaDisciplinas[d].qtdAlunos; j++){
                    if(listaDisciplinas[d].alunos[j] == matriculaExcluir){
                        for(int k = j; k < listaDisciplinas[d].qtdAlunos - 1; k++){
                            listaDisciplinas[d].alunos[k] = listaDisciplinas[d].alunos[k + 1];
                        }
                        listaDisciplinas[d].qtdAlunos--;
                        j--;
                    }
                }
            }

            for(int j = i; j < qtdAlunos - 1; j++){
                listaAlunos[j] = listaAlunos[j + 1];
            }
            qtdAlunos--;
            printf("Aluno excluido com sucesso!\n");
            return;
        }
    }

    printf("Aluno nao encontrado.\n");
}

// PROFESSOR
int menu_professor(){
    int opcao_professor;
    printf("\n1- Cadastrar professor\n");
    printf("2- Listar professores\n");
    printf("3- Atualizar professor\n");
    printf("4- Excluir professor\n");
    printf("5- Voltar\n");
    printf("Escolha: ");
    scanf(" %d", &opcao_professor);
    return opcao_professor;
}

void cadastrar_professor(){
    if(qtdProfessores >= TAM_PROFESSORES){
        printf("A lista de professores esta cheia.\n");
        return;
    }

    printf("Digite a matricula/id do professor: ");
    scanf(" %d", &listaProfessores[qtdProfessores].id);

    if(id_professor_existe(listaProfessores[qtdProfessores].id)){
        printf("Essa matricula/id ja esta cadastrado.\n");
        return;
    }

    printf("Digite o nome do professor: ");
    scanf(" %49[^\n]", listaProfessores[qtdProfessores].nome);

    do{
        printf("Digite o sexo (M/F): ");
        scanf(" %9s", listaProfessores[qtdProfessores].sexo);
        listaProfessores[qtdProfessores].sexo[0] = (char)toupper((unsigned char)listaProfessores[qtdProfessores].sexo[0]);
    }while(strcmp(listaProfessores[qtdProfessores].sexo, "M") != 0 && strcmp(listaProfessores[qtdProfessores].sexo, "F") != 0);

    do{
        printf("Digite a data de nascimento (DD/MM/AAAA): ");
        scanf(" %10s", listaProfessores[qtdProfessores].dataNascimento);
    }while(!data_valida(listaProfessores[qtdProfessores].dataNascimento));

    do{
        printf("Digite o CPF (somente numeros): ");
        scanf(" %14s", listaProfessores[qtdProfessores].cpf);
    }while(!cpf_valido(listaProfessores[qtdProfessores].cpf));

    printf("Digite a disciplina do professor: ");
    scanf(" %49[^\n]", listaProfessores[qtdProfessores].disciplina);

    qtdProfessores++;
    printf("Professor cadastrado com sucesso!\n");
}

void listar_professores(){
    if(qtdProfessores == 0){
        printf("Nao ha professores cadastrados.\n");
        return;
    }

    for(int i = 0; i < qtdProfessores; i++){
        separador();
        printf("Professor: %s\n", listaProfessores[i].nome);
        printf("Matricula/ID: %d\n", listaProfessores[i].id);
        printf("Sexo: %s\n", listaProfessores[i].sexo);
        printf("Data de nascimento: %s\n", listaProfessores[i].dataNascimento);
        printf("CPF: %s\n", listaProfessores[i].cpf);
        printf("Disciplina: %s\n", listaProfessores[i].disciplina);
        separador();
    }
}

void atualizar_professor(){
    int id_professorBusca;

    if(qtdProfessores == 0){
        printf("Nao ha professores para atualizar.\n");
        return;
    }

    printf("Digite o id/matricula do professor: ");
    scanf(" %d", &id_professorBusca);

    for(int i = 0; i < qtdProfessores; i++){
        if(id_professorBusca == listaProfessores[i].id){
            printf("Atualize o nome do professor: ");
            scanf(" %49[^\n]", listaProfessores[i].nome);

            do{
                printf("Atualize o sexo (M/F): ");
                scanf(" %9s", listaProfessores[i].sexo);
                listaProfessores[i].sexo[0] = (char)toupper((unsigned char)listaProfessores[i].sexo[0]);
            }while(strcmp(listaProfessores[i].sexo, "M") != 0 && strcmp(listaProfessores[i].sexo, "F") != 0);

            do{
                printf("Atualize a data de nascimento (DD/MM/AAAA): ");
                scanf(" %10s", listaProfessores[i].dataNascimento);
            }while(!data_valida(listaProfessores[i].dataNascimento));

            do{
                printf("Atualize o CPF (somente numeros): ");
                scanf(" %14s", listaProfessores[i].cpf);
            }while(!cpf_valido(listaProfessores[i].cpf));

            printf("Atualize a disciplina do professor: ");
            scanf(" %49[^\n]", listaProfessores[i].disciplina);

            printf("Professor atualizado com sucesso!\n");
            return;
        }
    }

    printf("Professor nao encontrado.\n");
}

void excluir_professor(){
    int id_professorExcluir;

    if(qtdProfessores == 0){
        printf("Nao ha professores para excluir.\n");
        return;
    }

    printf("Digite o id/matricula do professor que quer excluir: ");
    scanf(" %d", &id_professorExcluir);

    for(int i = 0; i < qtdProfessores; i++){
        if(id_professorExcluir == listaProfessores[i].id){
            for(int j = i; j < qtdProfessores - 1; j++){
                listaProfessores[j] = listaProfessores[j + 1];
            }
            qtdProfessores--;
            printf("Professor excluido com sucesso!\n");
            return;
        }
    }

    printf("Professor nao encontrado.\n");
}

// DISCIPLINA
int menu_disciplina(void){
    int opcao_disciplina;
    printf("1- Cadastrar disciplina\n");
    printf("2- Listar disciplinas\n");
    printf("3- Atualizar disciplina\n");
    printf("4- Excluir disciplina\n");
    printf("5- Inserir aluno na disciplina\n");
    printf("6- Excluir aluno da disciplina\n");
    printf("7- Listar uma disciplina com alunos\n");
    printf("8- Voltar\n");
    printf("Escolha: ");
    scanf(" %d", &opcao_disciplina);
    return opcao_disciplina;
}

void cadastrar_disciplina(){
    if(qtdDisciplinas >= TAM_DISCPLINAS){
        printf("A lista de disciplinas esta cheia.\n");
        return;
    }

    printf("Digite o codigo da disciplina: ");
    scanf(" %d", &listaDisciplinas[qtdDisciplinas].id);

    if(id_disciplina_existe(listaDisciplinas[qtdDisciplinas].id)){
        printf("Esse codigo ja esta cadastrado.\n");
        return;
    }

    printf("Digite o nome da disciplina: ");
    scanf(" %49[^\n]", listaDisciplinas[qtdDisciplinas].nome);

    printf("Digite o semestre: ");
    scanf(" %d", &listaDisciplinas[qtdDisciplinas].semestre);

    printf("Digite o professor da disciplina: ");
    scanf(" %49[^\n]", listaDisciplinas[qtdDisciplinas].professor);

    listaDisciplinas[qtdDisciplinas].qtdAlunos = 0;
    qtdDisciplinas++;
    printf("Disciplina cadastrada com sucesso!\n");
}

void listar_disciplinas(){
    if(qtdDisciplinas == 0){
        printf("Nao ha disciplinas cadastradas.\n");
        return;
    }

    for(int i = 0; i < qtdDisciplinas; i++){
        separador();
        printf("Disciplina: %s\n", listaDisciplinas[i].nome);
        printf("Codigo: %d\n", listaDisciplinas[i].id);
        printf("Semestre: %d\n", listaDisciplinas[i].semestre);
        printf("Professor: %s\n", listaDisciplinas[i].professor);
        separador();
    }
}

void atualizar_disciplina(){
    int disciplinaAtualizar;

    if(qtdDisciplinas == 0){
        printf("Nao ha disciplinas para atualizar.\n");
        return;
    }

    printf("Digite o id/codigo da disciplina que quer atualizar: ");
    scanf(" %d", &disciplinaAtualizar);

    for(int i = 0; i < qtdDisciplinas; i++){
        if(disciplinaAtualizar == listaDisciplinas[i].id){
            printf("Atualize o nome da disciplina: ");
            scanf(" %49[^\n]", listaDisciplinas[i].nome);

            printf("Atualize o semestre: ");
            scanf(" %d", &listaDisciplinas[i].semestre);

            printf("Atualize o professor da disciplina: ");
            scanf(" %49[^\n]", listaDisciplinas[i].professor);

            printf("Disciplina atualizada com sucesso!\n");
            return;
        }
    }

    printf("Disciplina nao encontrada.\n");
}

void excluir_disciplina(){
    int id_disciplinaExcluir;

    if(qtdDisciplinas == 0){
        printf("Nao ha disciplinas para excluir.\n");
        return;
    }

    printf("Digite o id/codigo da disciplina que quer excluir: ");
    scanf(" %d", &id_disciplinaExcluir);

    for(int i = 0; i < qtdDisciplinas; i++){
        if(id_disciplinaExcluir == listaDisciplinas[i].id){
            for(int j = i; j < qtdDisciplinas - 1; j++){
                listaDisciplinas[j] = listaDisciplinas[j + 1];
            }
            qtdDisciplinas--;
            printf("Disciplina excluida com sucesso!\n");
            return;
        }
    }

    printf("Disciplina nao encontrada.\n");
}

void inserir_aluno_disciplina(){
    int id_disciplina;
    int matricula;

    if(qtdDisciplinas == 0 || qtdAlunos == 0){
        printf("E necessario ter pelo menos uma disciplina e um aluno cadastrados.\n");
        return;
    }

    printf("Digite o codigo da disciplina: ");
    scanf(" %d", &id_disciplina);

    for(int i = 0; i < qtdDisciplinas; i++){
        if(listaDisciplinas[i].id == id_disciplina){
            printf("Digite a matricula do aluno: ");
            scanf(" %d", &matricula);

            for(int j = 0; j < qtdAlunos; j++){
                if(listaAlunos[j].matricula == matricula){
                    if(listaDisciplinas[i].qtdAlunos >= TAM_ALUNOS_DISCIPLINA){
                        printf("A disciplina esta cheia.\n");
                        return;
                    }

                    for(int k = 0; k < listaDisciplinas[i].qtdAlunos; k++){
                        if(listaDisciplinas[i].alunos[k] == matricula){
                            printf("Aluno ja esta matriculado nessa disciplina.\n");
                            return;
                        }
                    }

                    listaDisciplinas[i].alunos[listaDisciplinas[i].qtdAlunos] = matricula;
                    listaDisciplinas[i].qtdAlunos++;
                    printf("Aluno inserido na disciplina com sucesso!\n");
                    return;
                }
            }

            printf("Aluno nao encontrado.\n");
            return;
        }
    }

    printf("Disciplina nao encontrada.\n");
}

void excluir_aluno_disciplina(){
    int id_disciplina;
    int matricula;

    printf("Digite o codigo da disciplina: ");
    scanf(" %d", &id_disciplina);

    for(int i = 0; i < qtdDisciplinas; i++){
        if(listaDisciplinas[i].id == id_disciplina){
            printf("Digite a matricula do aluno: ");
            scanf(" %d", &matricula);

            for(int j = 0; j < listaDisciplinas[i].qtdAlunos; j++){
                if(listaDisciplinas[i].alunos[j] == matricula){
                    for(int k = j; k < listaDisciplinas[i].qtdAlunos - 1; k++){
                        listaDisciplinas[i].alunos[k] = listaDisciplinas[i].alunos[k + 1];
                    }
                    listaDisciplinas[i].qtdAlunos--;
                    printf("Aluno excluido da disciplina com sucesso!\n");
                    return;
                }
            }

            printf("Aluno nao esta matriculado nessa disciplina.\n");
            return;
        }
    }

    printf("Disciplina nao encontrada.\n");
}

void listar_uma_disciplina(){
    int id_disciplina;

    if(qtdDisciplinas == 0){
        printf("Nao ha disciplinas cadastradas.\n");
        return;
    }

    printf("Digite o codigo da disciplina: ");
    scanf(" %d", &id_disciplina);

    for(int i = 0; i < qtdDisciplinas; i++){
        if(listaDisciplinas[i].id == id_disciplina){
            separador();
            printf("Disciplina: %s\n", listaDisciplinas[i].nome);
            printf("Codigo: %d\n", listaDisciplinas[i].id);
            printf("Semestre: %d\n", listaDisciplinas[i].semestre);
            printf("Professor: %s\n", listaDisciplinas[i].professor);
            printf("Alunos matriculados: %d\n", listaDisciplinas[i].qtdAlunos);

            for(int j = 0; j < listaDisciplinas[i].qtdAlunos; j++){
                for(int k = 0; k < qtdAlunos; k++){
                    if(listaAlunos[k].matricula == listaDisciplinas[i].alunos[j]){
                        printf("- %s (Matricula: %d)\n", listaAlunos[k].nome, listaAlunos[k].matricula);
                    }
                }
            }
            separador();
            return;
        }
    }

    printf("Disciplina nao encontrada.\n");
}

// RELATORIOS
int menu_relatorios(void){
    int opcao_relatorios;
    printf("\n1- Listar alunos por sexo\n");
    printf("2- Listar alunos ordenados por nome\n");
    printf("3- Listar alunos ordenados por data de nascimento\n");
    printf("4- Listar professores por sexo\n");
    printf("5- Listar professores ordenados por nome\n");
    printf("6- Listar professores ordenados por data de nascimento\n");
    printf("7- Aniversariantes do mes\n");
    printf("8- Buscar pessoas pelo nome\n");
    printf("9- Alunos matriculados em menos de 3 disciplinas\n");
    printf("10- Disciplinas com mais de 40 alunos\n");
    printf("11- Listar uma disciplina com alunos\n");
    printf("12- Voltar\n");
    printf("Escolha: ");
    scanf(" %d", &opcao_relatorios);
    return opcao_relatorios;
}

void listar_alunos_por_sexo(){
    char sexo[10];

    printf("Digite o sexo (M/F): ");
    scanf(" %9s", sexo);
    sexo[0] = (char)toupper((unsigned char)sexo[0]);

    for(int i = 0; i < qtdAlunos; i++){
        if(strcmp(listaAlunos[i].sexo, sexo) == 0){
            printf("Aluno: %s | Matricula: %d | Sexo: %s\n", listaAlunos[i].nome, listaAlunos[i].matricula, listaAlunos[i].sexo);
        }
    }
}

void ordenar_alunos_nome(){
    Aluno lista[TAM_ALUNOS];
    Aluno aux;

    for(int i = 0; i < qtdAlunos; i++){
        lista[i] = listaAlunos[i];
    }

    for(int i = 0; i < qtdAlunos - 1; i++){
        for(int j = 0; j < qtdAlunos - 1 - i; j++){
            if(strcmp(lista[j].nome, lista[j + 1].nome) > 0){
                aux = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = aux;
            }
        }
    }

    for(int i = 0; i < qtdAlunos; i++){
        printf("Aluno: %s | Matricula: %d\n", lista[i].nome, lista[i].matricula);
    }
}

void ordenar_alunos_data(){
    Aluno lista[TAM_ALUNOS];
    Aluno aux;

    for(int i = 0; i < qtdAlunos; i++){
        lista[i] = listaAlunos[i];
    }

    for(int i = 0; i < qtdAlunos - 1; i++){
        for(int j = 0; j < qtdAlunos - 1 - i; j++){
            if(valor_data(lista[j].dataNascimento) > valor_data(lista[j + 1].dataNascimento)){
                aux = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = aux;
            }
        }
    }

    for(int i = 0; i < qtdAlunos; i++){
        printf("Aluno: %s | Data: %s\n", lista[i].nome, lista[i].dataNascimento);
    }
}

void listar_professores_por_sexo(){
    char sexo[10];

    printf("Digite o sexo (M/F): ");
    scanf(" %9s", sexo);
    sexo[0] = (char)toupper((unsigned char)sexo[0]);

    for(int i = 0; i < qtdProfessores; i++){
        if(strcmp(listaProfessores[i].sexo, sexo) == 0){
            printf("Professor: %s | Matricula: %d | Sexo: %s\n", listaProfessores[i].nome, listaProfessores[i].id, listaProfessores[i].sexo);
        }
    }
}

void ordenar_professores_nome(){
    Professor lista[TAM_PROFESSORES];
    Professor aux;

    for(int i = 0; i < qtdProfessores; i++){
        lista[i] = listaProfessores[i];
    }

    for(int i = 0; i < qtdProfessores - 1; i++){
        for(int j = 0; j < qtdProfessores - 1 - i; j++){
            if(strcmp(lista[j].nome, lista[j + 1].nome) > 0){
                aux = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = aux;
            }
        }
    }

    for(int i = 0; i < qtdProfessores; i++){
        printf("Professor: %s | Matricula: %d\n", lista[i].nome, lista[i].id);
    }
}

void ordenar_professores_data(){
    Professor lista[TAM_PROFESSORES];
    Professor aux;

    for(int i = 0; i < qtdProfessores; i++){
        lista[i] = listaProfessores[i];
    }

    for(int i = 0; i < qtdProfessores - 1; i++){
        for(int j = 0; j < qtdProfessores - 1 - i; j++){
            if(valor_data(lista[j].dataNascimento) > valor_data(lista[j + 1].dataNascimento)){
                aux = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = aux;
            }
        }
    }

    for(int i = 0; i < qtdProfessores; i++){
        printf("Professor: %s | Data: %s\n", lista[i].nome, lista[i].dataNascimento);
    }
}

void aniversariantes_mes(){
    int mes;

    printf("Digite o mes (1-12): ");
    scanf(" %d", &mes);

    if(mes < 1 || mes > 12){
        printf("Mes invalido.\n");
        return;
    }

    printf("\nAlunos aniversariantes:\n");
    for(int i = 0; i < qtdAlunos; i++){
        int mesNascimento;
        if(sscanf(listaAlunos[i].dataNascimento, "%*d/%d/%*d", &mesNascimento) == 1 && mesNascimento == mes){
            printf("Aluno: %s | Data: %s\n", listaAlunos[i].nome, listaAlunos[i].dataNascimento);
        }
    }

    printf("\nProfessores aniversariantes:\n");
    for(int i = 0; i < qtdProfessores; i++){
        int mesNascimento;
        if(sscanf(listaProfessores[i].dataNascimento, "%*d/%d/%*d", &mesNascimento) == 1 && mesNascimento == mes){
            printf("Professor: %s | Data: %s\n", listaProfessores[i].nome, listaProfessores[i].dataNascimento);
        }
    }
}

void buscar_pessoas(){
    char busca[50];
    int encontrou = 0;

    printf("Digite pelo menos 3 letras do nome: ");
    scanf(" %49[^\n]", busca);

    if(strlen(busca) < 3){
        printf("Digite no minimo 3 letras.\n");
        return;
    }

    for(int i = 0; busca[i] != '\0'; i++){
        busca[i] = (char)tolower((unsigned char)busca[i]);
    }

    printf("\nAlunos encontrados:\n");
    for(int i = 0; i < qtdAlunos; i++){
        char nome[50];
        strcpy(nome, listaAlunos[i].nome);
        for(int j = 0; nome[j] != '\0'; j++){
            nome[j] = (char)tolower((unsigned char)nome[j]);
        }
        if(strstr(nome, busca) != NULL){
            printf("Aluno: %s | Matricula: %d\n", listaAlunos[i].nome, listaAlunos[i].matricula);
            encontrou = 1;
        }
    }

    printf("\nProfessores encontrados:\n");
    for(int i = 0; i < qtdProfessores; i++){
        char nome[50];
        strcpy(nome, listaProfessores[i].nome);
        for(int j = 0; nome[j] != '\0'; j++){
            nome[j] = (char)tolower((unsigned char)nome[j]);
        }
        if(strstr(nome, busca) != NULL){
            printf("Professor: %s | Matricula: %d\n", listaProfessores[i].nome, listaProfessores[i].id);
            encontrou = 1;
        }
    }

    if(!encontrou){
        printf("Nenhuma pessoa encontrada.\n");
    }
}

void alunos_menos_3_disciplinas(){
    for(int i = 0; i < qtdAlunos; i++){
        int quantidade = 0;

        for(int j = 0; j < qtdDisciplinas; j++){
            for(int k = 0; k < listaDisciplinas[j].qtdAlunos; k++){
                if(listaDisciplinas[j].alunos[k] == listaAlunos[i].matricula){
                    quantidade++;
                    break;
                }
            }
        }

        if(quantidade < 3){
            printf("Aluno: %s | Matricula: %d | Disciplinas: %d\n", listaAlunos[i].nome, listaAlunos[i].matricula, quantidade);
        }
    }
}

void disciplinas_mais_40_alunos(){
    int encontrou = 0;

    for(int i = 0; i < qtdDisciplinas; i++){
        if(listaDisciplinas[i].qtdAlunos > 40){
            printf("Disciplina: %s | Codigo: %d | Alunos: %d\n", listaDisciplinas[i].nome, listaDisciplinas[i].id, listaDisciplinas[i].qtdAlunos);
            encontrou = 1;
        }
    }

    if(!encontrou){
        printf("Nenhuma disciplina extrapola 40 vagas.\n");
    }
}

int data_valida(char data[]){
    int dia, mes, ano;
    int dias_mes;

    if(strlen(data) != 10 || data[2] != '/' || data[5] != '/'){
        return 0;
    }

    if(sscanf(data, "%d/%d/%d", &dia, &mes, &ano) != 3){
        return 0;
    }

    if(ano < 1900 || mes < 1 || mes > 12 || dia < 1){
        return 0;
    }

    if(mes == 2){
        dias_mes = ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0) ? 29 : 28;
    }else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
        dias_mes = 30;
    }else{
        dias_mes = 31;
    }

    return dia <= dias_mes;
}

int cpf_valido(char cpf[]){
    int soma = 0;
    int resto;
    int digito1;
    int digito2;

    if(strlen(cpf) != 11){
        return 0;
    }

    for(int i = 0; i < 11; i++){
        if(!isdigit((unsigned char)cpf[i])){
            return 0;
        }
    }

    for(int i = 0; i < 9; i++){
        soma += (cpf[i] - '0') * (10 - i);
    }
    resto = soma % 11;
    digito1 = (resto < 2) ? 0 : 11 - resto;

    soma = 0;
    for(int i = 0; i < 10; i++){
        soma += (cpf[i] - '0') * (11 - i);
    }
    resto = soma % 11;
    digito2 = (resto < 2) ? 0 : 11 - resto;

    if((cpf[9] - '0') != digito1 || (cpf[10] - '0') != digito2){
        return 0;
    }

    return 1;
}

int valor_data(char data[]){
    int dia, mes, ano;

    if(sscanf(data, "%d/%d/%d", &dia, &mes, &ano) != 3){
        return 0;
    }

    return ano * 10000 + mes * 100 + dia;
}

int matricula_aluno_existe(int matricula){
    for(int i = 0; i < qtdAlunos; i++){
        if(listaAlunos[i].matricula == matricula){
            return 1;
        }
    }
    return 0;
}

int id_professor_existe(int id){
    for(int i = 0; i < qtdProfessores; i++){
        if(listaProfessores[i].id == id){
            return 1;
        }
    }
    return 0;
}

int id_disciplina_existe(int id){
    for(int i = 0; i < qtdDisciplinas; i++){
        if(listaDisciplinas[i].id == id){
            return 1;
        }
    }
    return 0;
}

void limpar_entrada(){
    int c;
    while((c = getchar()) != '\n' && c != EOF){}
}

void separador(){
    printf("----------------------------\n");
}
