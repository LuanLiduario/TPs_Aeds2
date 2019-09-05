#include "tp.h"
void main(){
    //Variaveis que utilizamos ao decorrer do c�digo.
    char *tabela[128];
    char *msg;
    int op=0,menu=1;
    char *aux;
    int t=0,j=0;
    No *arvores;
    //Preenchemos a tabela.
    preencherTabela(tabela);
    //Alocamos espa�o para as strings.
    msg=(char*)malloc(sizeof(char)*500);
    aux=(char*)malloc(sizeof(char)*10);
    strcpy(aux,"");
    //Criamos a arvore.
    criarArvoreMorse(&arvores);
    arvores=arvore(arvores);
    //Caso queira utilizar a pre ordem basta retirar as barras da linha seguinte
    pre_ordem(arvores);
    while(menu!=0){
        printf("\nMenu:\n1-Codigo Morse para texto\n2-Texto para codigo morse\nOutro numero-Sair\nDigite:");
        scanf("%d",&op);
        switch(op){
            case 1:
                printf("\nDECODIFICAR CODIGO MORSE PARA TEXTO :");
                printf("\nOBS: Utilize . e - para escrever seu codigo morse,");
                printf("\nEspacos entre . ou - serao considerados como fim do codigo morse de um caracter.\nE / sera considerado o final de uma palavra,");
                printf("\npara melhor desempenho do programa coloque um espaco depois das /\nDigite a mensagem:\n");
                setbuf(stdin,NULL);
                fgets(msg,500,stdin);
                printf("\nMensagem Decodificada:\n");
                t= strlen(msg);
                //O for a seguir serve para percorremos a mensagem digitada pelo usuario.
                for(int i=0;i<t;i++){
                    if(msg[i]=='/'){
                        //se econtrar / na string significa que acabou a palavra anterior e printamos um espa�o.
                        printf(" ");
                        strcpy(aux,"");
                    }else if(msg[i]==' '||msg[i]=='\n'||msg[i]=='\0'){
                        //Caso a posi��o for ' ' ou \n ou \0 significa que acabou o c�digo de uma letra ou encontramos o fim da string
                        //ent�o aux recebe \0 na posi��o j enves de receber o caracter da mensagem
                        aux[j]='\0';
                        if(strlen(aux)<=5){
                            //como os codigos morses diponiveis na arvore tem no maximo 5 caracteres verificamos o tamanho da string aux.
                            //mandamos aux para fun��o pesquisar e la sera impresso o caracter alfanumerico correspondente a aux
                            pesquisar(aux,arvores,0);
                        }else{
                            printf("Codigo morse invalido");
                            break;
                        }
                        //ap�s aux ser mandado para pesquisa, apagamos aux e zeramos j para poder pegar o codigo da pr�xima letra.
                        j=0;
                        strcpy(aux,"");
                    }else{
                        //Caso ainda a msg na posi��o n�o for um separador de palavras e nem foi realizado uma pesquisa
                        //aux na posi��o j recebe msg na posi��o i, ou seja aux serve para pegar o c�digo morse de cada letra
                        aux[j]=msg[i];
                        j++;
                    }
                }
                //depois de msg ser decodificada, apagamos a string
                strcpy(msg,"");
                break;
            case 2:
                printf("\nCODIFICAR TEXTO PARA CODIGO MORSE :");
                printf("\nObs: Nao utilize caracteres especiais, ou de pontuacao.\nDigite a mensagem:\n");
                setbuf(stdin,NULL);
                fgets(msg,500,stdin);
                printf("\nMensagem Codificada:\n");
                t= strlen(msg)-1;
                char c;
                //O for a seguir serve para percorremos a mensagem digitada pelo usuario.
                for(int i=0;i<t;i++){
                    //c recebe o caracter na posi��o i de msg
                    c=msg[i];
                    if(tabela[c]!=NULL){
                        //caso n�o seja null na posi��o 'c' na tabela
                        //imprimimos a string salva na tabela na posi��o c
                        printf("%s ",tabela[c]);
                    }else{
                        printf("\nErro: Caracter nao encontrado \n");
                        break;
                    }
                }
                strcpy(msg,"");
                break;
            default:
                printf("\n Obrigado por utilizar o sistema de conversao de codigo morse\n");
                menu=0;
        }
    }
}


