// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Gustavo Batista
//  email: gustavobatistagb09@gmail.com
//  Matrícula: 20242160040
//  Semestre: 2026.1

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016 - 17/10/2025

// #################################################

#include <stdio.h>
#include "trabalho1.h" 
#include <stdlib.h>

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
  int datavalida = 1;

  //quebrar a string data em strings sDia, sMes, sAno
  DataQuebrada dq = quebraData(data);

  if (dq.valido == 0) datavalida = 0;
  else if (dq.iAno < 1) datavalida = 0;
  else if (dq.iMes < 1 || dq.iMes > 12) datavalida = 0;
  else {
      int bissexto = ((dq.iAno % 4 == 0 && dq.iAno % 100 != 0) || (dq.iAno % 400 == 0));
      int diasMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
      
      if (bissexto) diasMes[2] = 29;
      
      if (dq.iDia < 1 || dq.iDia > diasMes[dq.iMes]) {
          datavalida = 0;
      }
  }

  //printf("%s\n", data);

  if (datavalida)
      return 1;
  else
      return 0;
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{
      //verifique se a data final não é menor que a data inicial
      DataQuebrada d1 = quebraData(datainicial);
      DataQuebrada d2 = quebraData(datafinal);
      
      int isMaior = 0;
      if (d1.iAno > d2.iAno) isMaior = 1;
      else if (d1.iAno == d2.iAno && d1.iMes > d2.iMes) isMaior = 1;
      else if (d1.iAno == d2.iAno && d1.iMes == d2.iMes && d1.iDia > d2.iDia) isMaior = 1;
      
      if (isMaior) {
          dma.retorno = 4;
          return dma;
      }
      
      //calcule a distancia entre as datas
      int dAno = d2.iAno - d1.iAno;
      int dMes = d2.iMes - d1.iMes;
      int dDia = d2.iDia - d1.iDia;

      if (dDia < 0) {
          dMes--;
          int mesAnterior = d2.iMes - 1;
          int anoAnterior = d2.iAno;
          if (mesAnterior == 0) {
              mesAnterior = 12;
              anoAnterior--;
          }
          
          int bissexto = ((anoAnterior % 4 == 0 && anoAnterior % 100 != 0) || (anoAnterior % 400 == 0));
          int diasMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
          if (bissexto) diasMes[2] = 29;
          
          dDia += diasMes[mesAnterior];
      }

      if (dMes < 0) {
          dAno--;
          dMes += 12;
      }

      //se tudo der certo
      dma.qtdAnos = dAno;
      dma.qtdMeses = dMes;
      dma.qtdDias = dDia;
      dma.retorno = 1;
      return dma;
      
    }
    
}

char desacentuar(char ch) {
    unsigned char c = (unsigned char)ch;
    
    if (c == 225 || c == 224 || c == 226 || c == 227 || c == 228) return 'a';
    if (c == 193 || c == 192 || c == 194 || c == 195 || c == 196) return 'A';
    
    if (c == 233 || c == 232 || c == 234 || c == 235) return 'e';
    if (c == 201 || c == 200 || c == 202 || c == 203) return 'E';
    
    if (c == 237 || c == 236 || c == 238 || c == 239) return 'i';
    if (c == 205 || c == 204 || c == 206 || c == 207) return 'I';
    
    if (c == 243 || c == 242 || c == 244 || c == 245 || c == 246) return 'o';
    if (c == 211 || c == 210 || c == 212 || c == 213 || c == 214) return 'O';
    
    if (c == 250 || c == 249 || c == 251 || c == 252) return 'u';
    if (c == 218 || c == 217 || c == 219 || c == 220) return 'U';
    
    return ch;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;
    
    char target = desacentuar(c);
    if (!isCaseSensitive && target >= 'A' && target <= 'Z') {
        target += 32;
    }

    for (int i = 0; texto[i] != '\0'; i++) {
        char current = desacentuar(texto[i]);
        
        if (!isCaseSensitive && current >= 'A' && current <= 'Z') {
            current += 32;
        }
        
        if (current == target) {
            qtdOcorrencias++;
        }
    }

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = 0;
    int k = 0;
    int lenTexto = 0, lenBusca = 0;

    while (strTexto[lenTexto] != '\0') lenTexto++;
    while (strBusca[lenBusca] != '\0') lenBusca++;

    for (int i = 0; i <= lenTexto - lenBusca; i++) {
        int match = 1;
        for (int j = 0; j < lenBusca; j++) {
            if (strTexto[i + j] != strBusca[j]) {
                match = 0;
                break;
            }
        }
        if (match) {
            posicoes[k] = i + 1;
            posicoes[k + 1] = i + lenBusca;
            k += 2;
            qtdOcorrencias++;
        }
    }

    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
    int invertido = 0;
    while (num > 0) {
        invertido = invertido * 10 + (num % 10);
        num /= 10;
    }
    return invertido;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias = 0;
    int tempBusca = numerobusca;
    long fatorBusca = 1;

    while (tempBusca > 0) {
        fatorBusca *= 10;
        tempBusca /= 10;
    }

    int tempBase = numerobase;
    while (tempBase > 0) {
        if (tempBase % fatorBusca == numerobusca) {
            qtdOcorrencias++;
            tempBase /= fatorBusca; 
        } else {
            tempBase /= 10; 
        }
    }
    
    return qtdOcorrencias;
}

/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 */

 int q7(char matriz[8][10], char palavra[5])
 {
     int achou = 0;
     int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
     int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
     int len = 0;

     while (palavra[len] != '\0') len++;

     for (int i = 0; i < 8; i++) {
         for (int j = 0; j < 10; j++) {
             if (matriz[i][j] == palavra[0]) {
                 for (int dir = 0; dir < 8; dir++) {
                     int k;
                     int r = i + dx[dir];
                     int c = j + dy[dir];
                     
                     for (k = 1; k < len; k++) {
                         if (r < 0 || r >= 8 || c < 0 || c >= 10) break;
                         if (matriz[r][c] != palavra[k]) break;
                         r += dx[dir];
                         c += dy[dir];
                     }
                     
                     if (k == len) {
                         achou = 1;
                         return achou;
                     }
                 }
             }
         }
     }
     
     return achou;
 }



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
    char sMes[3];
    char sAno[5];
    int i; 

    for (i = 0; data[i] != '/'; i++){
        sDia[i] = data[i];  
    }
    if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
        sDia[i] = '\0';  // coloca o barra zero no final
    }else {
        dq.valido = 0;
    return dq;
  }  
    

    int j = i + 1; //anda 1 cada para pular a barra
    i = 0;

    for (; data[j] != '/'; j++){
        sMes[i] = data[j];
        i++;
    }

    if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
        sMes[i] = '\0';  // coloca o barra zero no final
    }else {
        dq.valido = 0;
    return dq;
  }
    

    j = j + 1; //anda 1 cada para pular a barra
    i = 0;
    
    for(; data[j] != '\0'; j++){
        sAno[i] = data[j];
        i++;
    }

    if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
        sAno[i] = '\0';  // coloca o barra zero no final
    }else {
        dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

    dq.valido = 1;
    
  return dq;
}
