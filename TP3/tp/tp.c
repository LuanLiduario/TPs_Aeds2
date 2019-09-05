#include "tp.h"
//Funções
void preencherTabela(char **tabela){
    //A função apenas insere na tabela nas posições dos caracteres alfanumerico o codigo morse equivalente a eles.
    tabela['A']=tabela['a']=strdup(".-");
    tabela['B']=tabela['b']=strdup("-...");
    tabela['C']=tabela['c']=strdup("-.-.");
    tabela['D']=tabela['d']=strdup("-..");
    tabela['E']=tabela['e']=strdup(".");
    tabela['F']=tabela['f']=strdup("..-.");
    tabela['G']=tabela['g']=strdup("--.");
    tabela['H']=tabela['h']=strdup("....");
    tabela['I']=tabela['i']=strdup("..");
    tabela['J']=tabela['j']=strdup(".---");
    tabela['K']=tabela['k']=strdup("-.-");
    tabela['L']=tabela['l']=strdup(".-..");
    tabela['M']=tabela['m']=strdup("--");
    tabela['N']=tabela['n']=strdup("-.");
    tabela['O']=tabela['o']=strdup("---");
    tabela['P']=tabela['p']=strdup(".--.");
    tabela['Q']=tabela['q']=strdup("--.-");
    tabela['R']=tabela['r']=strdup(".-.");
    tabela['S']=tabela['s']=strdup("...");
    tabela['T']=tabela['t']=strdup("-");
    tabela['U']=tabela['u']=strdup("..-");
    tabela['V']=tabela['v']=strdup("...-");
    tabela['W']=tabela['w']=strdup(".--");
    tabela['X']=tabela['x']=strdup("-..-");
    tabela['Y']=tabela['y']=strdup("-.--");
    tabela['Z']=tabela['z']=strdup("--..");
    tabela['0']=tabela['0']=strdup("-----");
    tabela['1']=strdup(".----");
    tabela['2']=strdup("..---");
    tabela['3']=strdup("...--");
    tabela['4']=strdup("....-");
    tabela['5']=strdup(".....");
    tabela['6']=strdup("-....");
    tabela['7']=strdup("--...");
    tabela['8']=strdup("---..");
    tabela['9']=strdup("----.");
    tabela[' ']=strdup("/");
}

No * arvore(No *arvores){
    //A função arvore é responsavel por montar a arvore,ela chama a função insereMorse,
    //para inserir os nos necessarios na arvore e depois retornamos a arvore.
    insereMorse("E",".",&arvores,0);
    insereMorse("I","..",&arvores,0);
    insereMorse("S","...",&arvores,0);
    insereMorse("H","....",&arvores,0);
    insereMorse("5",".....",&arvores,0);
    insereMorse("4","....-",&arvores,0);
    insereMorse("V","...-",&arvores,0);
    insereMorse("3","...--",&arvores,0);
    insereMorse("U","..-",&arvores,0);
    insereMorse("F","..-.",&arvores,0);
    insereMorse("2","..---",&arvores,0);
    insereMorse("A",".-",&arvores,0);
    insereMorse("R",".-.",&arvores,0);
    insereMorse("L",".-..",&arvores,0);
    insereMorse("W",".--",&arvores,0);
    insereMorse("P",".--.",&arvores,0);
    insereMorse("J",".---",&arvores,0);
    insereMorse("1",".----",&arvores,0);
    insereMorse("T","-",&arvores,0);
    insereMorse("M","--",&arvores,0);
    insereMorse("O","---",&arvores,0);
    insereMorse("0","-----",&arvores,0);
    insereMorse("9","----.",&arvores,0);
    insereMorse("8","---..",&arvores,0);
    insereMorse("G","--.",&arvores,0);
    insereMorse("Q","--.-",&arvores,0);
    insereMorse("Z","--..",&arvores,0);
    insereMorse("7","--...",&arvores,0);
    insereMorse("N","-.",&arvores,0);
    insereMorse("K","-.-",&arvores,0);
    insereMorse("Y","-.--",&arvores,0);
    insereMorse("C","-.-.",&arvores,0);
    insereMorse("D","-..",&arvores,0);
    insereMorse("X","-..-",&arvores,0);
    insereMorse("B","-...",&arvores,0);
    insereMorse("6","-....",&arvores,0);
    return arvores;
}

void criarArvoreMorse(No **arvores) {
    //Apenas inicializa a arvore.
    *arvores = NULL;
}

void insereMorse(char* txt,char* cod, No **arv,int i) {
    //A função insere morse recebe o txt que equivale ao caracter alfanumerico que sera inserido.
    //Também recebe cod que equivale ao codigo morse deste caracter
    //a arvore onde sera inserido o no
    //e por fim a varivel i serve para saber a posição que estamos na string do codigo, inicialmete sera 0
    //e cada chamada recursiva realizada é somado 1 em i
    int tam;
    tam = (strlen(cod));
    //tam é o tamanho do codigo morse
    if(*arv==NULL){
        //fazemos o malloc neste ponto para alocar os espaços vazios na arvore
        *arv = (No*)malloc(sizeof(No));
        (*arv)->codigo = '\0';
        (*arv)->texto = '\0';
    }
    if (i == tam) {
        //se na chamada atual o i equivaler o tamanho da string significa que encontrou o lugar que o No deverá ser inserido.
        //Alocamos espaço pro No e inserimos o txt e cod na arvore
        *arv = (No*)malloc(sizeof(No));
        (*arv)->texto = txt;
        (*arv)->codigo=cod;
        (*arv)->esq = NULL;
        (*arv)->dir = NULL;
        return;
    }
    if (cod[i] == '.') {
        //caso a string na posição i for '.' significa que o No deve ser inserido na esquerda
        //e se soma 1 em i para comparar na proxima posição da string ou alocar o No
        insereMorse(txt,cod, &(*arv)->esq,i+1);
        return;
    } else if (cod[i]=='-'){
         //caso a string na posição i for '-' significa que o No deve ser inserido na direita
        //e se soma 1 em i para comparar na proxima posição da string ou alocar o No
        insereMorse(txt,cod, &(*arv)->dir,i+1);
        return;
        }
    else {
        printf("Erro : Registro ja existe na arvore\n");
    }
}

void pre_ordem(No *arv) {
    //verifica se é final da arvore.
    if (arv != NULL) {
            //verifica se é um espeço vazio da arvore
        if(arv->texto!=NULL && arv->codigo!=NULL){
            printf("%s %s\n", arv->texto,arv->codigo);
        }
    //primeiro andamos a arvore ate o ultimo no a esquerda e imprimindo eles
        pre_ordem(arv->esq);
    //quando encontra o null a esquerda vai voltando os Nos verificando se existe Nos a direita,
    //caso exista imprimimos esses Nos e verificamos se estes nos tem Nos a sua esquerda.
        pre_ordem(arv->dir);
    }
}

void pesquisar(char *cod, No *arv,int i) {
    //Para não haver erros na pesquisas, verificamos como o string chega.
    if(cod!=NULL&&strcmp(cod,"") != 0 && strcmp(cod," ") != 0&&strcmp(cod,"\n")!=0){
            //A exemplo de insereMorse a função pesquisar utiliza a variavel i para saber a posição da string do codigo morse
            //que deve ser comparada.
        //caso o código morse recebido na posição i for . chamamos a função novamente, só que indo para esquerda da árvore e incrementamos 1 em i
        // caso for - vamos para direita.
        if (cod[i] == '.') {
            pesquisar(cod, arv->esq,i+1);
        } else if (cod[i] == '-')
            pesquisar(cod, arv->dir,i+1);
        else {
            //Se não for nem . nem -, significa que chegamos no fim da string e que chagamos ao final da pesquisa
            //se o texto for diferente de NULL significa que o No foi encontrado
            //e imprimimos a caracter alfanumerico .
            if(arv->texto!=NULL){
                printf("%s",arv->texto);
                return;
            }else{
                printf("Erro : Nao encontrado");
                return;
            }
        }
   }
    return;
}


