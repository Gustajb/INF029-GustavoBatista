#include <stdio.h>
#include "utils.h"
void limparBuffer(){ int c; while((c=getchar())!='\n' && c!=EOF); }
int validarSexo(char s){ return (s=='M'||s=='F'||s=='m'||s=='f'); }
