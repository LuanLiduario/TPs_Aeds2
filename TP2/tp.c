#include "tp.h"
//Funções
void realizaOperacoes(int tipoStruct,int t,int v,int ordena){
    // declaramos a varivel op que receberá um inteiro do usuário
    int op=0;
    // declaramos as variaveis comparar e movi apenas para contar as comparações e movimentações do mergeSort
    long int comparar=0,movi=0;
    // declaramos t1,t2 e result para receber tempo
    double t1,t2,result=0;
    //Neste if comparamos o inteiro que o usuário informou para o tipo de struct que desejava
    if(tipoStruct==1){
        //Caso tipo de struct for 1,ou seja pequena o algoritmo vai declarar um ponteiro do tipo Pequeno
        Pequeno *vetor=NULL;
        //O vetor recebe um vetor do tipo pequeno alocado com tamanho t
        vetor=alocarVetorPequeno(vetor,t);
        //O vetor recebe um vetor do tipo pequeno preeenchido
        vetor=preencherVetorPequeno(vetor,t,v);
        //Neste if verefica se o vetor foi preenchido ou não caso não tenha sido preenchido para a execução da função
        if(vetorPequenoVazio(vetor)==0){
            free(vetor);
            return;
        }
        //A variavel op recebe um inteiro para vereficar se o usuário deseja ou não que o vetor seja impresso na tela
        printf("Deseja o print do vetor inicial? \n 1-Sim \n Outro numero-Nao\n");
        scanf("%d",&op);
        if(op==1){
            //caso op receba 1, chama a função printVetorPequeno que irá imprimir o vetor na tela
            printf("Vetor Inicialmente:");
            printVetorPequeno(vetor,t);
        }
        //A variavel op recebe 0 para ser reutilizada
        op=0;
        //No switch comparamos o inteiro que o usuário informou para o tipo de ordenação que desejava
        //e chamamos a função de ordenação equivalente ao inteiro
        //t1 receberá o tempo antes da função de ordenação
        //t2 receberá o tempo depois da função de ordenação
        switch (ordena) {
            case 1:
                t1 = tempo();
                selecaoVetorPequeno(t,vetor);
                t2 = tempo();
                break;
            case 2:
                t1 = tempo();
                insercaoVetorPequeno(t,vetor);
                t2 = tempo();
                break;
            case 3:
                t1 = tempo();
                shellsortVetorPequeno(vetor,t);
                t2 = tempo();
                break;
            case 4:
                t1 = tempo();
                quicksortVetorPequeno(vetor,t);
                t2 = tempo();
                break;
            case 5:
                t1 = tempo();
                heapsortVetorPequeno(vetor,t);
                t2 = tempo();
                break;
            case 6:
                t1 = tempo();
                mergeSortVetorPequeno(vetor,t,&movi,&comparar);
                t2 = tempo();
                printf("Comparacao : %ld\n",comparar);
                printf("Movimentacao : %ld\n",movi);
                break;
            default:
                printf("tipo de ordenacao incorreta\n");
                free(vetor);
                return;
            }
        //result recebe a diferença entre o tempo inicial e final para sabermos o tempo de execução
        result=t2-t1;
        printf("Tempo Gasto : %lf microsegundos \n",result);
        printf("Deseja o print do vetor ordenado? \n 1-Sim\n Outro numero-Nao\n");
        //A variavel op recebe um inteiro para vereficar se o usuário deseja ou não que o vetor seja impresso na tela
        scanf("%d",&op);
        if(op==1){
            printf("Vetor Ordenado:");
            printVetorPequeno(vetor,t);
        }
        free(vetor);
        return;
    }else if(tipoStruct==2){
        //Caso tipo de struct for 2,ou seja grande o algoritmo vai declarar um ponteiro do tipo Grande
        //E a exemplo ao if anterior faz as mesmas operações, mas utilizando vetor do  tipo Grande
        Grande *vetor=NULL;
        vetor=alocarVetorGrande(vetor,t);
        vetor=preencherVetorGrande(vetor,t,v);
        if(vetorGrandeVazio(vetor)==0){
            return;
        }
        //A variavel op recebe um inteiro para vereficar se o usuário deseja ou não que o vetor seja impresso na tela
        printf("Deseja o print do vetor incial? \n 1-Sim\n Outro numero-Nao\n");
        scanf("%d",&op);
        if(op==1){
            printf("Vetor Inicialmente:");
            printVetorGrande(vetor,t);
        }
        switch (ordena) {
            case 1:
                t1=tempo();
                selecaoVetorGrande(t,vetor);
                t2=tempo();
                break;
            case 2:
                t1=tempo();
                insercaoVetorGrande(t,vetor);
                t2=tempo();
                break;
            case 3:
                t1=tempo();
                shellsortVetorGrande(vetor,t);
                t2=tempo();
                break;
            case 4:
                t1=tempo();
                quicksortVetorGrande(vetor,t);
                t2=tempo();
                break;
            case 5:
                t1=tempo();
                heapsortVetorGrande(vetor,t);
                t2=tempo();
                break;
            case 6:
                t1=tempo();
                mergeSortVetorGrande(vetor,t,&movi,&comparar);
                t2=tempo();
                printf("Comparacao : %ld\n",comparar);
                printf("Movimentacao : %ld\n",movi);
                break;
            default:
                printf("tipo de ordenacao incorreta\n");
                free(vetor);
                return;
            }
        //printf("Tempo inicial : %lf \n",t2);
        //printf("Tempo final : %lf \n",t1);
        result=t2-t1;
        printf("Tempo Gasto : %lf microsegundos\n",result);
        op=0;
        printf("Deseja o print do vetor ordenado? \n 1-Sim\n Outro numero-Nao\n");
        scanf("%d",&op);
        if(op==1){
            printf("Vetor Ordenado:");
        printVetorGrande(vetor,t);
        }
        free(vetor);
        return;
    }else{
        //Caso seja informado algum inteiro errado para o tipo de struct a função avisa o erro e para a retorna oara main
        printf("Erro no tamanho da struct\n");
        return;
    }
}

 double tempo(){// função retorna tempo daquele momento desde 1 de janeiro de 1970
    struct timeval tv;
    gettimeofday(&tv,NULL);
    double micro = (double)(tv.tv_sec)+(double) (tv.tv_usec)/1000000.00;
    return micro;
}
//Funções para a struct do tipo pequeno (apenas chave int)
Pequeno* alocarVetorPequeno(Pequeno *vetor,int t){//aloca o espaço na memoria e retorna o vetor com o tamanho recebido
    vetor=(Pequeno*)malloc(sizeof(Pequeno)*t);
    return vetor;
}

int vetorPequenoVazio(Pequeno *vetor){//confere se o vetor está vazio ou não, retornando 0 para vazio e e 1 caso contrário
    if(vetor== NULL){
        return 0;
    }else{
        return 1;
    }
}

void printVetorPequeno(Pequeno *vetor,int t){
    for(int i=0;i<t;i++){//percorre o vetor e vai imprimindo posição por posição
        printf("%d-",vetor[i].chave);
    }
    printf("\n");
}

Pequeno *preencherVetorPequeno(Pequeno *vetor,int t,int v){
    if(v==1){//preenche o vetor de forma crescente
        for(int i=0;i<t;i++){//percorre o vetor a partir do indice  e vai preenchendo as chaves com o indice atual
        vetor[i].chave=i;
        }
    }
    else if(v==2){// preenche o vetor de forma decrescente
        int j=t-1;
        for(int i=0;i<t;i++){//percorre o vetor normal, mas preenche as chave com o valor inverso
        vetor[i].chave=j;
        j--;
        }
    }
    else if(v==3){
        for(int i=0;i<t;i++){//vai percorrendo o vetor e preenchendo as chaves de forma aleatória
        vetor[i].chave=rand()%205000;
        }
    }
    else{
        printf("Erro na escolha do preenchimento ");
        vetor=NULL;
        return vetor;
    }
    return vetor;
}

void selecaoVetorPequeno (int t, Pequeno *vetor){//percorre o vetor em busca do menor elemento e o coloca na primeira posicao, depois faz o mesmo com os n-1 itens restantes e assim por diante
    long int min=0;
    unsigned long int comparacao=0,mov=0;
    Pequeno aux;
    for (int i = 0; i < t-1; ++i) {
        min = i;
        for (int j = i+1; j < t; ++j){
            if (vetor[j].chave < vetor[min].chave)
                min = j;
                comparacao++;//aumenta 1 acada comparação feita
            }
        aux = vetor[i];
        vetor[i] = vetor[min];
        vetor[min] = aux;
        mov=mov+3;//auamenta as movimentações de 3 em 3, porque 3 movimentações acabaram de ser feitas e sempe sao feitas de 3 em 3
   }
   printf("Comparacao : %ld\n",comparacao);
   printf("Movimentacao : %ld\n",mov);
}

void insercaoVetorPequeno (int t, Pequeno *vetor){
   long int mov=0,comparacao=0;
   for (int j = 1; j < t; ++j) {//percorre o vetor começando do segundo elemento da lista
      Pequeno x = vetor[j];
      mov++;//incrementa um na variavel de movimentaçao
      int i;
      for (i = j-1; i >= 0 && vetor[i].chave > x.chave; --i){//analisa a posiçao anterior a que se está no vetor, se o anterior for maior os dois trocam de lugar e o i é decrementado
         vetor[i+1] = vetor[i];
         mov++;
         comparacao++;
      }
      comparacao++;
      vetor[i+1] = x;
      mov++;
      //printf("Teste:");
      //printVetorPequeno(vetor,t);
   }
  printf("Comparacao : %ld\n",comparacao);
  printf("Movimentacao : %ld\n",mov);
}

void shellsortVetorPequeno(Pequeno *vetor, int t){//analisa elementos com uma distancia de h (usando a sequencia de Knuth), se o elemento com indice menor for maior eles trocam de posiçao
    long int i , j;
    long int mov=0,comparacao=0;
    Pequeno aux;
    int h = 1;
    do {
        h = 3*h+1;//acha-se o numero da sequencia mais perto de do tamanho do vetor, depois que todos sao analisados usando eassa distancia o h diminui pro valor anterior da sequencia
    } while(h < t);
    do {
    h /= 3;
    for(i = h; i < t; i++) {
        aux = vetor[i];
        mov++;
        j = i - h;
        while (j >= 0 && aux.chave < vetor[j].chave) {
            comparacao++;
            vetor[j + h] = vetor[j];
            mov++;
            j -= h;
        }
        vetor[j + h] = aux;
        mov++;
        }
    }while(h > 1);
    printf("Comparacao : %ld\n",comparacao);
    printf("Movimentacao : %ld\n",mov);
}

//Quicksort
void particionarVetorPequeno(int esq, int dir,int *i, int *j, Pequeno * vetor,long int *mov,long int*comparacao) {//divide o vetor em duas partições em relaçao ao pivo, deixando a esquerda os menores e a direita os maiores
    Pequeno x, w;
    *i = esq; *j = dir;
    x = vetor[(*i + *j) / 2]; //obtem o pivo
    (*mov)=(*mov)+1;
    do {
        while (x.chave > vetor[*i].chave){
            (*i)++;
            (*comparacao)=(*comparacao)+1;
        }
        while (x.chave < vetor[*j].chave) {
            (*j)--;
            (*comparacao)=(*comparacao)+1;
        };
        if (*i <= *j) {
            w = vetor[*i];
            vetor[*i] = vetor[*j];
            vetor[*j] = w;
            (*mov)=(*mov)+3;
            (*i)++;
            (*j)--;
        }
         //(*comparacao)=(*comparacao)+1;
    } while (*i <= *j);
}
void ordenarVetorPequeno(int esq, int dir, Pequeno * vetor,long int *mov,long int*comparacao) {
    int i, j;
    particionarVetorPequeno(esq, dir, &i, &j, vetor,mov,comparacao);//chama funçao particonar
    if (esq < j) ordenarVetorPequeno(esq, j, vetor,mov,comparacao);// pega o subvetor dos menores elementos e chama a função ordenar novamente
    if (i < dir) ordenarVetorPequeno(i, dir, vetor,mov,comparacao);// pega o subvetor dos maiores elementos e chama a função ordenar novamente
}
void quicksortVetorPequeno(Pequeno *vetor, int t) {
    long int mov=0,comparacao=0;
    ordenarVetorPequeno(0,t-1, vetor,&mov,&comparacao);//chama a funçao de ordenacao a primeira vez com o inicio, tamanho do vetor, o vetor e as variaveis de movimentacoes e comparacoes pra serem incrementadas
    printf("Comparacao : %ld\n",comparacao);
    printf("Movimentacao : %ld\n",mov);
}

//heapsort
void refazerVetorPequeno(int esq, int dir, Pequeno *a,long int *comparacao,long int * mov) {//refaz a heap garantindo que o pai seja maior que o dois filhos
    int i = esq;
    int j;
    Pequeno x;
    j = i * 2;
    x = a[i];
    (*mov)++;
    while (j <= dir) {
        if (j < dir) {
            if (a[j].chave < a[j+1].chave){
                  (*comparacao)++;
                  j++;
            }
        }
        if (x.chave >= a[j].chave){
            (*comparacao)++;
            break;
        }
        a[i] = a[j];
        (*mov)++;
        i = j;
        j = i * 2;
    }
    a[i] = x;
    (*mov)++;

}
void construirVetorPequeno(Pequeno * a, int n,long int * comparacao,long int *mov) {
    int esq;
    esq = n / 2 +1;
    while (esq >0) {
        esq--;
        refazerVetorPequeno(esq, n, a,comparacao,mov);
    }
}
void heapsortVetorPequeno(Pequeno *a, int n) {
    int esq, dir;
    long int mov=0,comparacao=0;
    Pequeno x;
    construirVetorPequeno(a, n-1,&comparacao,&mov); /* constroi o heap */
    esq = 0;
    dir = n-1;
    while (dir >= 1) {// pega o primeiro elemento coloca na ultima posicao (porque ele é o maior de todos) e chama a função para reconstrução da heap
    /* ordena o vetor */
        x = a[0];
        a[0] = a[dir];
        a[dir] = x;
        mov=mov+3;
        dir--;
        refazerVetorPequeno(esq, dir, a,&comparacao,&mov);
    }
    printf("Comparacao : %ld\n",comparacao);
    printf("Movimentacao : %ld\n",mov);
}
//mergesort
void mergeVetorPequeno(Pequeno *vetor, int t,long int *mov,long int *comparacao) {
    int mid;
    int i, j, k;
    Pequeno* tmp;
    tmp = (Pequeno*) malloc(t* sizeof(Pequeno));
    if (tmp == NULL) {
        exit(1);
    }
    mid = t / 2;
    i = 0;
    j = mid;
    k = 0;
    while (i < mid && j < t) {
        if (vetor[i].chave < vetor[j].chave) {
            (*comparacao)++;
            tmp[k] = vetor[i];
            (*mov)++;
            ++i;
        }
        else {
             (*comparacao)++;
            tmp[k] = vetor[j];
            (*mov)++;

            ++j;
        }
    ++k;
    }
    if (i == mid) {
        //(*comparacao)++;
        while (j < t) {
            tmp[k] = vetor[j];
            (*mov)++;

            ++j;
            ++k;
        }

    }
    else {
        while (i < mid) {
            tmp[k] = vetor[i];
             (*mov)++;
            ++i;
            ++k;
        }
    }
    for (i = 0; i < t; ++i) {
        vetor[i] = tmp[i];
         (*mov)++;
    }
    free(tmp);
}
void mergeSortVetorPequeno(Pequeno *vetor, int t,long int * mov,long int * comparacao) {
    int mid;
    if (t > 1) {//enquanto os elementos nao estiverem sozinhos, o vetor é divido ao meio
        mid = t / 2;
        mergeSortVetorPequeno(vetor, mid,mov,comparacao);// uma metade será divida
        mergeSortVetorPequeno(vetor + mid, t - mid,mov,comparacao);// segunda metade sendo dividida
        mergeVetorPequeno(vetor, t,mov,comparacao);// reconstrução do vetor já ordenando
    }
}
//Funções para a struct do tipo Grande (chave int,e matriz de char 50x50)
//OBS: OS PRINCIPIOS DESSAS FUNÇÕES SAO OS MESMOAS DAS FUNÇÕES ACIMA. A UNICA COISA DIFERENTE É O TIPO DO VETOR DE ENTRADA

Grande* alocarVetorGrande(Grande *vetor,int t){
    vetor=(Grande*)malloc(sizeof(Grande)*t);
    return vetor;
}

int vetorGrandeVazio(Grande *vetor){
    if(vetor== NULL){
        return 0;
    }else{
        return 1;
    }
}
void printVetorGrande(Grande vetor[],int t){
    for(int i=0;i<t;i++){
        printf("%d--",vetor[i].chave);
    }
    printf("\n");
}

Grande * preencherVetorGrande(Grande *vetor,int t,int v){
    if(v==1){
        for(int i=0;i<t;i++){
        vetor[i].chave=i;
        }
    }
    else if(v==2){
        int j=t-1;
        for(int i=0;i<t;i++){
        vetor[i].chave=j;
        j--;
        }
    }
    else if(v==3){
        for(int i=0;i<t;i++){
        vetor[i].chave=rand()%200000;
        }
    }
    else{
        printf("Erro na escolha do preenchimento ");
        vetor=NULL;
        return vetor;
    }
    return vetor;
}

void selecaoVetorGrande (int t, Grande *vetor){
    long int min=0,comparacao=0,mov=0;
    Grande aux;
    for (int i = 0; i < t-1; ++i) {
        min = i;
        for (int j = i+1; j < t; ++j){
            if (vetor[j].chave < vetor[min].chave)
                min = j;
                comparacao++;
            }
        aux = vetor[i];
        vetor[i] = vetor[min];
        vetor[min] = aux;
        mov=mov+3;
   }
    printf("Comparacao : %ld\n",comparacao);
    printf("Movimentacao : %ld\n",mov);
}
void insercaoVetorGrande (int t, Grande *vetor){
   long int mov=0,comparacao=0;
   for (int j = 1; j < t; ++j) {
      Grande aux = vetor[j];
      mov++;
      int i;
      for (i = j-1; i >= 0 && vetor[i].chave > aux.chave; --i){
         vetor[i+1] = vetor[i];
         comparacao++;
         mov++;
      }
      comparacao++;
      vetor[i+1] = aux;
      mov++;
   }
   printf("Comparacao : %ld\n",comparacao);
   printf("Movimentacao : %ld\n",mov);
}

void shellsortVetorGrande(Grande *vetor, int t){
    int i , j;
    long int mov=0,comparacao=0;
    Grande aux;
    int h = 1;
    do {
        h = 3*h+1;
    } while(h < t);
    do {
    h /= 3;
    for(i = h; i < t; i++) {
        aux = vetor[i];
        mov++;
        j = i - h;
        while (j >= 0 && aux.chave < vetor[j].chave) {
            comparacao++;
            vetor[j + h] = vetor[j];
            mov++;
            j -= h;
        }
        vetor[j + h] = aux;
        mov++;
        }
    }while(h > 1);
    printf("Comparacao : %ld\n",comparacao);
    printf("Movimentacao : %ld\n",mov);
}
//quicksort
void particionarVetorGrande(int esq, int dir,int *i, int *j, Grande * a,long int *mov,long int *comparacao) {
    Grande x, w;
    *i = esq;
    *j = dir;
    x = a[(*i + *j) / 2]; // obtem o pivo
    (*mov)++;
    do {
        while (x.chave > a[*i].chave) {
            (*i)++;
            (*comparacao)++;
        }
        while (x.chave < a[*j].chave) {
            (*j)--;
            (*comparacao)++;
        }
        if (*i <= *j) {
            w = a[*i];
            a[*i] = a[*j];
            a[*j] = w;
            (*mov)=(*mov)+3;
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}
void ordenarVetorGrande(int esq, int dir, Grande * a,long int *mov,long int *comparacao) {
    int i, j;
    particionarVetorGrande(esq, dir, &i, &j, a,mov,comparacao);
    if (esq < j) ordenarVetorGrande(esq, j, a,mov,comparacao);
    if (i < dir) ordenarVetorGrande(i, dir, a,mov,comparacao);
}
void quicksortVetorGrande(Grande *a, int t) {
    long int mov=0,comparacao=0;
    ordenarVetorGrande(0,t-1, a,&mov,&comparacao);
    printf("Comparacao : %ld\n",comparacao);
    printf("Movimentacao : %ld\n",mov);
}
//fim quicksort

//heapsort
void refazerVetorGrande(int esq, int dir, Grande *a,long int *comparacao,long int * mov) {
    int i = esq;
    int j;
    Grande x;
    j = i * 2;
    x = a[i];
    (*mov)++;
    while (j <= dir) {
        if (j < dir) {
            if (a[j].chave < a[j+1].chave){
                (*comparacao)++;
                j++;
            }
        }

        if (x.chave >= a[j].chave){
            (*comparacao)++;
            break;
        }
        //(*comparacao)++;
        a[i] = a[j];
        (*mov)++;
        i = j;
        j = i * 2;
    }
    a[i] = x;
    (*mov)++;

}
void construirVetorGrande(Grande * a, int n,long int * comparacao,long int *mov) {
    int esq;
    esq = n / 2 +1;
    while (esq >0) {
        esq--;
        refazerVetorGrande(esq, n, a,comparacao,mov);
    }
}
void heapsortVetorGrande(Grande *a, int n) {
    int esq, dir;
    long int mov=0,comparacao=0;
    Grande x;
    construirVetorGrande(a, n-1,&comparacao,&mov); /* constroi o heap */
    esq = 0;
    dir = n-1;
    while (dir >= 1) {
    /* ordena o vetor */
        x = a[0];
        a[0] = a[dir];
        a[dir] = x;
        mov=mov+3;
        dir--;
        refazerVetorGrande(esq, dir, a,&comparacao,&mov);
    }
    printf("Comparacao : %ld\n",comparacao);
    printf("Movimentacao : %ld\n",mov);
}
//mergesort
void mergeVetorGrande(Grande *vetor, int t,long int *mov,long int *comparacao) {
    int mid;
    int i, j, k;
    Grande* tmp;
    tmp = (Grande*) malloc(t* sizeof(Grande));
    if (tmp == NULL) {
        (*comparacao)++;
        exit(1);
    }
    mid = t / 2;
    i = 0;
    j = mid;
    k = 0;
    while (i < mid && j < t) {
        if (vetor[i].chave < vetor[j].chave) {
            (*comparacao)++;
            tmp[k] = vetor[i];
            (*mov)++;
            ++i;
        }
        else {
            (*comparacao)++;
            tmp[k] = vetor[j];
            (*mov)++;

            ++j;
        }
    ++k;
    }
    if (i == mid) {
        //(*comparacao)++;
        while (j < t) {
            tmp[k] = vetor[j];
            (*mov)++;

            ++j;
            ++k;
        }

    }
    else {
        while (i < mid) {
            tmp[k] = vetor[i];
             (*mov)++;
            ++i;
            ++k;
        }
    }
    for (i = 0; i < t; ++i) {
        vetor[i] = tmp[i];
         (*mov)++;
    }
    free(tmp);
}
void mergeSortVetorGrande(Grande *vetor, int t,long int * mov,long int * comparacao) {
    int mid;
    if (t > 1) {
        mid = t / 2;
        mergeSortVetorGrande(vetor, mid,mov,comparacao);
        mergeSortVetorGrande(vetor + mid, t - mid,mov,comparacao);
        mergeVetorGrande(vetor, t,mov,comparacao);
    }
}
