#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
//Struct
//A struct � o registro que ser� inserido nos Nos da �rvore que ser� montada.
typedef struct No{
    //texto equivale aos carscteres alfanumericos.
    char *texto;
    //c�digo equivale ao c�digo morse do caracter alfanumerico.
    char *codigo;
    //esq e dir s�o ponteiros para outro No, utilizados para montar a �rvore.
    struct No * esq;
    struct No * dir;
}No;
//Assinaturas de fun��es
void preencherTabela(char**);
No* arvore(No *);
void criarArvoreMorse();
void insereMorse(char*,char*,No**,int);
void pre_ordem(No*);
void pesquisar(char *, No *,int);

