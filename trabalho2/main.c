#include <stdio.h>
#include <stdlib.h>

#include "GustavoBatista20242160040.h"

int menu();
int lerPosicao();
void mostrarRetornoInsercao(int ret);
void listarTodasEstruturas(int ordenado);
void listarTodosNumerosOrdenados();
int totalElementos();

int menu()
{
    int op;

    printf("\n===== TRABALHO 2 - PONTEIROS =====\n");
    printf("1 - Inserir elemento\n");
    printf("2 - Listar todos os numeros\n");
    printf("3 - Listar numeros ordenados por estrutura auxiliar\n");
    printf("4 - Listar todos os numeros ordenados\n");
    printf("5 - Excluir elemento\n");
    printf("6 - Aumentar tamanho de uma estrutura auxiliar\n");
    printf("7 - Sair\n");
    printf("Opcao: ");
    scanf("%d", &op);

    return op;
}

int lerPosicao()
{
    int posicao;
    printf("Informe a posicao da estrutura principal (1 a 10): ");
    scanf("%d", &posicao);
    return posicao;
}

void mostrarRetornoInsercao(int ret)
{
    if (ret == SUCESSO)
        printf("Elemento inserido com sucesso.\n");
    else if (ret == SEM_ESPACO)
        printf("Nao ha mais espaco nessa estrutura auxiliar.\n");
    else if (ret == SEM_ESTRUTURA_AUXILIAR)
        printf("Nao existe estrutura auxiliar nessa posicao.\n");
    else if (ret == POSICAO_INVALIDA)
        printf("Posicao invalida.\n");
    else
        printf("Erro ao inserir elemento.\n");
}

int totalElementos()
{
    int i, qtd, total = 0;

    for (i = 1; i <= 10; i++)
    {
        qtd = getQuantidadeElementosEstruturaAuxiliar(i);
        if (qtd > 0)
            total += qtd;
    }

    return total;
}

void listarTodasEstruturas(int ordenado)
{
    int i, j, qtd, tamanho, ret;
    int *vetorAux;

    for (i = 1; i <= 10; i++)
    {
        tamanho = getTamanhoEstruturaAuxiliar(i);

        printf("\nPosicao %d:\n", i);

        if (tamanho == SEM_ESTRUTURA_AUXILIAR)
        {
            printf("  Sem estrutura auxiliar.\n");
        }
        else
        {
            qtd = getQuantidadeElementosEstruturaAuxiliar(i);

            printf("  Tamanho total: %d\n", tamanho);

            if (qtd == ESTRUTURA_AUXILIAR_VAZIA)
            {
                printf("  Quantidade usada: 0\n");
                printf("  Elementos: vazio\n");
            }
            else if (qtd > 0)
            {
                vetorAux = (int *)malloc(sizeof(int) * qtd);

                if (vetorAux == NULL)
                {
                    printf("  Erro de memoria.\n");
                    return;
                }

                if (ordenado)
                    ret = getDadosOrdenadosEstruturaAuxiliar(i, vetorAux);
                else
                    ret = getDadosEstruturaAuxiliar(i, vetorAux);

                if (ret == SUCESSO)
                {
                    printf("  Quantidade usada: %d\n", qtd);
                    printf("  Elementos: ");
                    for (j = 0; j < qtd; j++)
                        printf("%d ", vetorAux[j]);
                    printf("\n");
                }

                free(vetorAux);
            }
        }
    }
}

void listarTodosNumerosOrdenados()
{
    int i, total, ret;
    int *vetorAux;

    total = totalElementos();

    if (total == 0)
    {
        printf("Todas as estruturas auxiliares estao vazias.\n");
        return;
    }

    vetorAux = (int *)malloc(sizeof(int) * total);

    if (vetorAux == NULL)
    {
        printf("Erro de memoria.\n");
        return;
    }

    ret = getDadosOrdenadosDeTodasEstruturasAuxiliares(vetorAux);

    if (ret == SUCESSO)
    {
        printf("Numeros ordenados: ");
        for (i = 0; i < total; i++)
            printf("%d ", vetorAux[i]);
        printf("\n");
    }
    else
    {
        printf("Todas as estruturas auxiliares estao vazias.\n");
    }

    free(vetorAux);
}

int main()
{
    int op, sair = 0;
    int posicao, valor, tamanho, ret;

    inicializar();

    while (!sair)
    {
        op = menu();

        switch (op)
        {
        case 1:
            posicao = lerPosicao();

            if (getTamanhoEstruturaAuxiliar(posicao) == SEM_ESTRUTURA_AUXILIAR)
            {
                printf("Ainda nao existe estrutura auxiliar nessa posicao.\n");
                printf("Informe o tamanho total da estrutura auxiliar: ");
                scanf("%d", &tamanho);

                ret = criarEstruturaAuxiliar(posicao, tamanho);

                if (ret != SUCESSO)
                {
                    if (ret == POSICAO_INVALIDA)
                        printf("Posicao invalida.\n");
                    else if (ret == TAMANHO_INVALIDO)
                        printf("Tamanho invalido.\n");
                    else if (ret == JA_TEM_ESTRUTURA_AUXILIAR)
                        printf("Ja existe estrutura auxiliar nessa posicao.\n");
                    else
                        printf("Erro ao criar estrutura auxiliar.\n");
                    break;
                }
            }

            printf("Informe o numero a inserir: ");
            scanf("%d", &valor);

            ret = inserirNumeroEmEstrutura(posicao, valor);
            mostrarRetornoInsercao(ret);
            break;

        case 2:
            listarTodasEstruturas(0);
            break;

        case 3:
            listarTodasEstruturas(1);
            break;

        case 4:
            listarTodosNumerosOrdenados();
            break;

        case 5:
            posicao = lerPosicao();
            printf("Informe o numero que deseja excluir: ");
            scanf("%d", &valor);

            ret = excluirNumeroEspecificoDeEstrutura(posicao, valor);

            if (ret == SUCESSO)
                printf("Numero excluido com sucesso.\n");
            else if (ret == NUMERO_INEXISTENTE)
                printf("Numero nao encontrado.\n");
            else if (ret == ESTRUTURA_AUXILIAR_VAZIA)
                printf("Estrutura auxiliar vazia.\n");
            else if (ret == SEM_ESTRUTURA_AUXILIAR)
                printf("Sem estrutura auxiliar nessa posicao.\n");
            else if (ret == POSICAO_INVALIDA)
                printf("Posicao invalida.\n");
            break;

        case 6:
            posicao = lerPosicao();
            printf("Informe quantas posicoes deseja acrescentar: ");
            scanf("%d", &tamanho);

            ret = modificarTamanhoEstruturaAuxiliar(posicao, tamanho);

            if (ret == SUCESSO)
                printf("Tamanho alterado com sucesso.\n");
            else if (ret == NOVO_TAMANHO_INVALIDO)
                printf("Novo tamanho invalido.\n");
            else if (ret == SEM_ESTRUTURA_AUXILIAR)
                printf("Sem estrutura auxiliar nessa posicao.\n");
            else if (ret == POSICAO_INVALIDA)
                printf("Posicao invalida.\n");
            else
                printf("Erro ao alterar tamanho.\n");
            break;

        case 7:
            sair = 1;
            break;

        default:
            printf("Opcao invalida.\n");
        }
    }

    finalizar();
    return 0;
}
