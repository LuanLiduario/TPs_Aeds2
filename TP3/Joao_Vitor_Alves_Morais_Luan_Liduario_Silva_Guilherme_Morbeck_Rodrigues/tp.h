#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
//Struct
//A struct é o registro que será inserido nos Nos da árvore que será montada.
typedef struct No{
    //texto equivale aos carscteres alfanumericos.
    char *texto;
    //código equivale ao código morse do caracter alfanumerico.
    char *codigo;
    //esq e dir são ponteiros para outro No, utilizados para montar a árvore.
    struct No * esq;
    struct No * dir;
}No;
//Assinaturas de funções
void preencherTabela(char**);
No* arvore(No *);
void criarArvoreMorse();
void insereMorse(char*,char*,No**,int);
void pre_ordem(No*);
void pesquisar(char *, No *,int);

