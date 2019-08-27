#include "tp.h"
void main(){
    //declaramos variaveis para receber os comandos do usuário
    int tipoStruct=0,t=0,v=0,ordena=0;
    //a variavel tipoStruct recebe um inteiro que equivale ao tipo de struct que o usuário deseja
    printf("Algoritmo de Ordenacao:\n");
    printf("Digite o tamanho da struct:\n");
    printf("1-struct pequena\n2-struct grande\n");
    setbuf(stdin,NULL);
    scanf("%d",&tipoStruct);
    //a variavel v primeiro recebe um inteiro que equivale ao tamanho do vetor que o usuário deseja
    printf("Digite o tamanho do vetor:\n");
    printf("1-vetor de 20\n2-vetor de 500\n3-vetor de 5000\n4-vetor de 10000\n5-vetor de 200000\n");
    setbuf(stdin,NULL);
    scanf("%d",&v);
    //O switch atribui a varivel t o tamanho equivalente ao inteiro que a varivel v recebeu
    switch (v) {
        case 1:
            t=20;
            break;
        case 2:
            t=500;
            break;
        case 3:
            t=5000;
            break;
        case 4:
            t=10000;
            break;
        case 5:
            t=200000;
            break;
        default:
            printf("tamanho de vetor incorreto\n");
            break;
    }
    //Atribuimos 0 a varivel v para ela ser reutilizada
    v=0;
    //agora a variavel v recebe um inteiro que equivale ao tipo de preenhimento do vetor que o usuário deseja
    printf("Digite o tipo de preenchimento do vetor:\n");
    printf("1-Crescente\n2-Descrescente\n3-Aleatorio\n");
    setbuf(stdin,NULL);
    scanf("%d",&v);
    //a variavel ordena recebe um inteiro que equivale ao tipo de ordenação que o usuário deseja aplicar no vetor
    printf("Digite o tipo de ordenacao:\n");
    printf("1-Selecao\n2-Insercao\n3-Shellsort\n4-Quicksort\n5-Heapsort\n6-Mergesort\n");
    setbuf(stdin,NULL);
    scanf("%d",&ordena);
    //Agora a função realizaOperacoes recebe os inteiros que o usuário digitou e realiza as operações
    realizaOperacoes(tipoStruct,t,v,ordena);
}


