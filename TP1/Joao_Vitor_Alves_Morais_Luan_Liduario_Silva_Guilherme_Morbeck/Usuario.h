#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    //Criando a estrutura mesnsagem
    long int idDestinario;
    int prioridade;
    char *conteudo;
}Mensagem;

typedef struct ListaMensagem{
    //Criando a estrututa para implementar uma lista de mensagens
    Mensagem mensagem;
    struct ListaMensagem *proximo;
}ListaMensagem;

typedef struct {
    //Descritor da lista de mensagens
    ListaMensagem *primeiro;
    ListaMensagem *ultimo;
}tipoListaMensagem;

typedef struct{
    //Criando a estrutura usuario
    long int id;
    tipoListaMensagem mensagens;
}Usuario;

typedef struct ListaUsuario{
    //Criando a estrututa para implementar uma lista de usuarios
    Usuario usuario;
    struct ListaUsuario *proximo;
}ListaUsuario;

typedef struct {
    //Descritor da lista de usuario
    ListaUsuario *primeiro;
    ListaUsuario *ultimo;
}tipoListaUser;

//Assinaturas das funções
tipoListaUser* FLVazia();

int listaVazia (tipoListaUser *lista);

void leArquivo(char *nomeArq,tipoListaUser *lista);

void confereOperacao(char *comando, tipoListaUser *lista);

int confereId(long int id, tipoListaUser *lista);

void insereUsuario (long int id, tipoListaUser *lista);

tipoListaMensagem criarCaixaEntradaVazia();

void removeUsuario(long int id, tipoListaUser *lista);

void removeMensagem(tipoListaMensagem *lista);

void consultaID(long int id, tipoListaUser *lista);

void mostra(tipoListaMensagem *lista);

Usuario *retornaUser(long int id, tipoListaUser *lista);

void insereMensagem (Mensagem m, tipoListaMensagem *lista);

int caixaEntradaVazia(tipoListaMensagem *lista);
