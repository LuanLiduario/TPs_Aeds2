#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<sys/time.h>
//struct apenas com chave int
typedef struct{
    int chave;
}Pequeno;
//struct com chave int e matriz de char de 50 por 50
typedef struct{
    int chave;
    char mstring[50][50];
}Grande;

//Assinaturas de funções
void realizaOperacoes(int tipoStruct,int t,int v,int ordena);
double tempo();
//Pequeno
Pequeno* alocarVetorPequeno(Pequeno *vetor,int t);
int vetorPequenoVazio(Pequeno *vetor);
void printVetorPequeno(Pequeno *vetor,int t);
Pequeno *preencherVetorPequeno(Pequeno *vetor,int t,int v);
void selecaoVetorPequeno (int t, Pequeno *vetor);
void insercaoVetorPequeno (int t, Pequeno *vetor);
void shellsortVetorPequeno(Pequeno *vetor, int t);
//quicksort
void particionarVetorPequeno(int esq, int dir,int *i, int *j, Pequeno * vetor,long int *mov,long int*comparacao);
void ordenarVetorPequeno(int esq, int dir, Pequeno * vetor,long int *mov,long int*comparacao);
void quicksortVetorPequeno(Pequeno *vetor, int t);
//heapsort
void refazerVetorPequeno(int esq, int dir, Pequeno *a,long int *comparacao,long int * mov);
void construirVetorPequeno(Pequeno * a, int n,long int * comparacao,long int *mov);
void heapsortVetorPequeno(Pequeno *a, int n);
//mergesort
void mergeVetorPequeno(Pequeno *vetor, int t,long int *mov,long int *comparacao);
void mergeSortVetorPequeno(Pequeno *vetor, int t,long int * mov,long int * comparacao);
//grande
Grande* alocarVetorGrande(Grande *vetor,int t);
int vetorGrandeVazio(Grande *vetor);
void printVetorGrande(Grande *vetor,int t);
Grande *preencherVetorGrande(Grande *vetor,int t,int v);
void selecaoVetorGrande (int t, Grande *vetor);
void insercaoVetorGrande (int t, Grande *vetor);
void shellsortVetorGrande(Grande *vetor, int t);
//quicksort
void particionarVetorGrande(int esq, int dir,int *i, int *j, Grande * vetor,long int *mov,long int*comparacao);
void ordenarVetorGrande(int esq, int dir, Grande * vetor,long int *mov,long int*comparacao);
void quicksortVetorGrande(Grande *vetor, int t);
//heapsort
void refazerVetorGrande(int esq, int dir, Grande *a,long int *comparacao,long int * mov);
void construirVetorGrande(Grande * a, int n,long int * comparacao,long int *mov);
void heapsortVetorGrande(Grande *a, int n);
//mergesort
void mergeVetorGrande(Grande *vetor, int t,long int *mov,long int *comparacao);
void mergeSortVetorGrande(Grande *vetor, int t,long int * mov,long int * comparacao);


