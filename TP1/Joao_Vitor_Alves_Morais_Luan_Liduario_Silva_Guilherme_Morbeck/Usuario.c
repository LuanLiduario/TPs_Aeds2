#include "Usuario.h"

tipoListaUser *FLVazia() {
    //Cria a lista vazia de usuarios
    //Aloca espa
    tipoListaUser *lista = (tipoListaUser*)malloc(sizeof(tipoListaUser));
    lista->primeiro = (ListaUsuario*) malloc(sizeof(ListaUsuario));
    lista->ultimo = lista->primeiro;
    lista->primeiro->proximo = NULL;
    return lista;
}

int listaVazia (tipoListaUser *lista){
    //confere se a lista usuario esta vazia ou não
    if (lista->primeiro == lista->ultimo){
        return 0;
    }else{
        return 1;
    }
}

int caixaEntradaVazia(tipoListaMensagem *lista){
    //Confere se a lista esta vazia ou não caso o primeiro elemento apontar para o ultimo
    //significa que a lista esta vazia e se retorna 1
    if (lista->primeiro == lista->ultimo){
        return 0;
    }else{
        return 1;
    }
}

void leArquivo(char *nomeArq, tipoListaUser *lista){
    //Abre o arquivo de texto
    FILE *arq = fopen(nomeArq, "r");
    if(arq == NULL) printf("\nERRO NA ABERTURA DO ARQUIVO\n\n\n");
    char linha[250];
    char c;
    int i=0;
    //Enquanto não encontrar o final do arquivo a varivel c recebe um caracter do arquivo
    while(!feof(arq)){
        c = fgetc(arq);
        if(c != '\n'){
        //Caso o caracter encontrado não indique uma quebra de linha, o vetor linha na posição i recebe c
            linha[i] = c;
            i++;
        }else{
            //Caso o caracter encontrado  indique uma quebra de linha, o vetor linha na posição i recebe \0,para indicar o final da string
            getchar();
            linha[i] = '\0';
            printf("%s\n", linha);
            //A função confereOperacao executa a operação pedida na linha de comando e depois apaga a linha de comando para ler o comando abaixo
            confereOperacao(linha, lista);
            strcpy(linha, "");
            i=0;
        }
    }
    //Fecha o arquivo
    fclose(arq);
}

void confereOperacao(char *comando, tipoListaUser *lista){
    char confere[9];
    char msg[232];
    int i=0, j=0,prioridade;
    long int id;
    Usuario *user=(Usuario*)malloc(sizeof(Usuario));
    //O vetor comando recebe a linha toda de comando
    //O vetor confere recebe a primeira palavra da linha de comando que corresponde o comando que deve ser executado
    while(comando[i] != ' '){
        confere[i]= comando[i];
        i++;
    }
    confere[i]='\0';
    if (strcmp(confere, "CADASTRA") == 0 || strcmp(confere, "Cadastra") == 0 || strcmp(confere, "cadastra") == 0){
        i++;
        //Caso o comando que esta na string confere seja cadastrar ,zera o vetor confere para encontrar o id que deve ser cadastrado
        strcpy(confere, "");
        while(comando[i] != '\0'){
            confere[j]= comando[i];
            j++;
            i++;
        }
        confere[j]='\0';
        //Converte a string confere em long int
        id = atol(confere);
        //Confere se o id existe ou não
        if(confereId(id, lista)==1){
            //caso não exista o id na lista, inserimos o id na lista
            insereUsuario(id, lista);
        }else{
            //caso exista o id na lista imprimi erro
            printf("ERRO:CONTA %ld JA EXISTENTE\n",id);
        }
    }else if(strcmp(confere, "REMOVE") == 0 || strcmp(confere, "Remove") == 0 || strcmp(confere, "remove") == 0){
        i++;
        //Caso o comando que esta na string confere seja remove ,zera o vetor confere para encontrar o id que deve ser removido
        strcpy(confere, "");
        while(comando[i] != '\0'){
            confere[j]= comando[i];
            j++;
            i++;
        }
        confere[j]='\0';
        //Converte a string confere em long int
        id = atol(confere);
         //Confere se o id existe ou não
        if(confereId(id, lista)==0){
            //caso exista o id esteja na lista removemos ele da lista
            removeUsuario(id, lista);
            printf("OK: CONTA %ld REMOVIDA\n",id);
        }else{
            //caso não exista o id esteja na lista imprimi erro
            printf("ERRO:CONTA %ld NAO EXISTE\n",id);
        }
    }else if(strcmp(confere, "ENTREGA") == 0 || strcmp(confere, "Entrega") == 0 || strcmp(confere, "entrega") == 0){
        i++;
        //Caso o comando que esta na string confere seja Entrega ,zera o vetor confere para encontrar o id que deve receber a mensagem
        strcpy(confere, "");
        while(comando[i] != ' '){
            confere[j]= comando[i];
            j++;
            i++;
        }
        id = atol(confere);
        i++;
        j=0;
        strcpy(confere, "");
        //zera o vetor confere novamente para encontrar a prioridade da mensagem
        while(comando[i] != ' '){
            confere[j]= comando[i];
            j++;
            i++;
        }
        confere[j]='\0';
        j=0;
        prioridade = atoi(confere);
        i++;
        //O vetor msg recebe os cacteres das posições equivalentes da string comando, verificando se é um F,caso seja verifica se
        //as duas proximas posições da string comando, se as proximas for I e M, o laço é parado para que se coloque o \0 e envie a mensagem sem a palavra FIM
        while(comando[i] != '\n'){
            msg[j]= comando[i];
            //caso
            if(msg[j]=='F' && comando[i+1]=='I' && comando[i+2]){
                msg[j]='\0';
                break;
            }
            j++;
            i++;

        }
        //aloca espaço na memoria para m receber a mensagem que será entregue
        ListaMensagem *m = (ListaMensagem*)malloc (sizeof(ListaMensagem));
        m->mensagem.idDestinario=id;
        m->mensagem.prioridade=prioridade;
        m->mensagem.conteudo = msg;
        //Retorna o usuario que recebera a mensagem
        user = retornaUser(id,lista);
        if(user == NULL){
            printf("ERRO: CONTA %ld NAO EXISTE\n",id);
            return;
        }else{
            //Chama uma função para mandar a mesagem
            insereMensagem(m->mensagem,&user->mensagens);
            //printf("TESTE do conteudo da  primeira mensagem do primeiro usuario apos inserir a mensagem: %s\n",lista->primeiro->proximo->usuario.mensagens.primeiro->proximo->mensagem.conteudo); //TESTE
        }

    }else if(strcmp(confere, "CONSULTA") == 0 || strcmp(confere, "Consulta") == 0 || strcmp(confere, "consulta") == 0){
        i++;
        //printf("TESTE do conteudo da  primeira mensagem do primeiro usuario antes de chamar a funcao consultaID: %s\n",lista->primeiro->proximo->usuario.mensagens.primeiro->proximo->mensagem.conteudo); //TESTE
        strcpy(confere, "");
        while(comando[i] != '\0'){
            confere[j]= comando[i];
            j++;
            i++;
        }
        id = atol(confere);
        if(confereId(id, lista)==0){
            consultaID(id,lista);
        }
        else{
            printf("ERRO: CONTA %ld NAO EXISTE\n",id);
        }
    }
}

int confereId(long int id, tipoListaUser *lista){
    ListaUsuario *aux = lista->primeiro->proximo;
    if(listaVazia(lista)== 0){
           // Caso a lista esteja vazia retorna o valor 1
        return 1;
    }
    while(aux != NULL){
            //Percorre a lista para verificar o id
        if(aux->usuario.id == id){
           // Caso o id esteja na lista retorna o valor 0
            return 0;
        }
        aux = aux->proximo;
    }
    //Caso não encotrar o id na lista retorna o valor 1
    return 1;
}

void insereUsuario (long int id, tipoListaUser *lista){
    //Cria uma varivel do tipo usuario que recebe o id para ser cadastrado e recebe a caixa de entrada vazia
    Usuario user;
    user.id = id;
    user.mensagens = criarCaixaEntradaVazia();
    //alocamento dinâmico da memória para o proximo item da lista
    lista->ultimo->proximo = (ListaUsuario*) malloc(sizeof(ListaUsuario));
    //Inserindo um novo usuario
    //O espaço de mémoria alocado será preenchido pelo novo usuario que apontara para null
    lista->ultimo = lista->ultimo->proximo;
    lista->ultimo->usuario = user;
    lista->ultimo->proximo = NULL;
    printf("OK: CONTA %ld CADASTRADA\n",id);
}


tipoListaMensagem criarCaixaEntradaVazia() {
    //Cria uma varivel que será o descritor da lista de mensagens
    tipoListaMensagem lista;
    //Aloca espaço na memoria para o primeiro elemento da lista
    lista.primeiro = (ListaMensagem*) malloc(sizeof(ListaMensagem));
    lista.ultimo = lista.primeiro;
    lista.primeiro->proximo = NULL;
    //retorna lista vazia
    return lista;
}

void removeUsuario(long int id, tipoListaUser *lista){
    //Aloca espaço na memoria para uma varivel auxiliar que percorre a lista
    ListaUsuario *aux = (ListaUsuario*) malloc (sizeof(ListaUsuario));
    aux = lista->primeiro;
    ListaUsuario *aux2 = aux;
    //Até que se encontre o id que quer ser excluido se percorre a lista de usuarios
    while(aux->usuario.id != id){
        aux2 = aux;
        aux = aux->proximo;
    }
    if(aux == NULL){
        return;
    }
    //A variavel auxiliar dois recebe o ponteiro proximo da varivel que deve ser excluida e é excluida a varivel auxiliar
    aux2->proximo = aux->proximo;
    free (aux);

}

void removeMensagem(tipoListaMensagem *lista){
    //Aloca um espaço na memoria para a varivel auxiliar que ira percorrer a lista de mensagem até encontrar na proxima posição NULL
    ListaMensagem *aux = lista->primeiro;
    if (caixaEntradaVazia(lista)==0){
        return;
    }
    while (aux->proximo != lista->ultimo){
        aux = aux->proximo;
    }
    //Se exclui o ultimo da lista de mensagens
    lista->ultimo = aux;
    aux = aux->proximo;
    free (aux);
}

void insereMensagem(Mensagem x, tipoListaMensagem *lista){
    //Aloca espaço na memoria para uma varivel auxiliar que ira percorrer a lista de mensagem
    ListaMensagem *aux = (ListaMensagem*)malloc(sizeof(ListaMensagem));
    aux= lista->primeiro;
    //Aloca espaço na memoria para uma varivel  que ira receber a nova mensagem
    ListaMensagem *m = (ListaMensagem*) malloc (sizeof(ListaMensagem));
    m->mensagem = x;
    m->proximo=NULL;
    while(aux->proximo!= NULL){
        //Se insere as mensagem de forma ordenada,ou seja se verifica se proxima mensagem  da lista é de prioridade igual ou menor que a nova mensagem
        if(aux->proximo->mensagem.prioridade <= m->mensagem.prioridade){
            m->proximo = (ListaMensagem*) malloc (sizeof(ListaMensagem));
            m->proximo=aux->proximo;
            aux->proximo = m;
            return;
        }
        aux = aux->proximo;
    }
    //caso não se encontre prioridade menor ou igual siginifica que será o ultimo da lista ou seja tem maior prioridade
    aux->proximo=(ListaMensagem*) malloc (sizeof(ListaMensagem));
    aux->proximo->mensagem=x ;
    aux->proximo->proximo = NULL;
    lista->ultimo=aux->proximo;
}

void consultaID(long int id, tipoListaUser *lista){
    //printf("TESTE do conteudo da  primeira mensagem do primeiro usuario na funcao consultaID : %s\n",lista->primeiro->proximo->usuario.mensagens.primeiro->proximo->mensagem.conteudo); //TESTE
   //Aloca espaço na memoria para uma varivel auuxiliar que ira percorrer a lista de usuários
    ListaUsuario *aux = (ListaUsuario*)malloc(sizeof(ListaUsuario));
    aux=lista->primeiro;
    while(aux->usuario.id != id || aux == NULL){
        aux = aux->proximo;

    }
    if (aux == NULL){
        printf("ERRO: CONTA %ld NAO EXISTE\n", id);
    }else{
        //chama uma função para mostrar a ultima mensagem da lista e depois outra que irá remove-la
        mostra(&aux->usuario.mensagens);
        removeMensagem(&aux->usuario.mensagens);
    }
}

void mostra(tipoListaMensagem *lista){
    //Aloca espaço na memoria para uma varivel auxiliar que irá percorrer a lista de mensagens
    ListaMensagem *aux = (ListaMensagem*)malloc(sizeof(ListaMensagem));
    aux=lista->primeiro;
    if (caixaEntradaVazia(lista)==0){
        printf("CAIXA DE ENTRADA VAZIA\n");
        return;
    }
    while (aux->proximo != NULL){
        aux = aux->proximo;

    }
    //Imprime o conteuda da ultima mensagem da lista de mensagens
     printf("%s\n",aux->mensagem.conteudo);
}
Usuario *retornaUser(long int id,tipoListaUser *lista){
    //Aloca espaço para um ponteiro de usuario e para uma varivel auxiliar que irá percorrer a lista de usuarios
    Usuario *user = (Usuario*)malloc(sizeof(Usuario));
    ListaUsuario *aux = lista->primeiro->proximo;
    if(confereId(id,lista)==0){
        while(aux != NULL){
            if(aux->usuario.id == id){
               user=&aux->usuario;
               //Retorna o usuario
                return user;
            }
            aux = aux->proximo;
        }
    }else{
        printf("ERRO: CONTA %ld NAO EXISTE\n",id);
        return NULL;
    }
}
