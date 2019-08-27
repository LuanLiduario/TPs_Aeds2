#include "Usuario.h"

//LEMBRAR DE COLOCAR int argc, char *argv[]
void main (){
    //Criando um ponteiro de descritor de lista usuario
    tipoListaUser *lista;
    lista = FLVazia();
    //chama a função que le o arquivo de texto
    leArquivo("teste.txt", lista);
}
