#include <stdio.h>   // biblioteca padrão utilizada para entrada e saída de dados no código
#include <stdlib.h>  // biblioteca padrão utilizada para alocação dinâmica de memória
#include <string.h>  // biblioteca utilizada para trabalhar com strings e copiar o nome do pedido

//cria a estrutura que sera reponsavel por armazenar os dados de cada pedido da fila
struct nopedido{
    int numero_pedido;
    char nome_prato[21];  //vetor de caracteres para armazenar o nome do pedido, com ate 20 caracteres
    struct nopedido* prox; // O ponteiro prox que aponta para o próximo nó da fila.
};
typedef struct nopedido Np;  // Renomeia struct nopedido para Np, facilitando sua utilização no código a seguir.

//essa estrutura cria os dois ponteiros inicio e fim que aponta para o primeiro o ultimo pedido da fila
struct fila{
    Np* ini;
    Np* fim;
};
typedef struct fila Filap; //renomeia a estrutura para Filap

//a funcao tem como objetivo alocar a estrutura da fila e inicializa os ponteiros dala com valor NULL
Filap* cria(void){
    Filap* fp = (Filap*) malloc(sizeof(Filap)); //aloca dinamicamente a memoria para estrutura Filap
    
    if(fp == NULL){  //verifca se a alocacao falhou
    printf("Erro ao alocar memoria!\n");
    exit(1);
}

    fp->ini = fp->fim = NULL; //inicializa como vazia a lista deixando os dois ponteiros com valores NULL
    return fp;    //retona o ponteiro da estrutura "Filap" que foi criada
}

//funcao auxiliar que insere um novo pedido no fim da fila
Np* ins_pd (Np* fim, char  nome_prato[]){  //recebe o parametro do tipo vetor de string e o ponteiro que armazena o endereco do nó final da fila
    Np* pp = (Np*) malloc(sizeof(Np)); //aloca dinamicamente cada novo nó "Np" na memoria

    if(pp == NULL){      //verifica se a alocacao falhou
    printf("Erro ao alocar memoria!\n");
    exit(1);
}

    strcpy(pp->nome_prato, nome_prato); //copia o texto recebido, atraves da funcao "strcpy" para o vetor de string criado para armazena o nome   
    pp->prox = NULL;
    if(fim != NULL){    //verifica se a fila nao esta vazia
        pp->numero_pedido = fim->numero_pedido + 1;  //atribui o numero do pedido em ordem crescente, pegando o numero atual do ultimo pedido e adicionando mais 1
        fim->prox = pp; //fim agora passa a apontar para o novo nó 
        return pp;     //retorna o ponteiro que idica o novo ultimo nó
    } else {
        pp->numero_pedido = 1; //se tiver vazia a fila e adicinado o numero 1 apenas, pois e o primeiro pedido
        return pp;   //retorna o ponteiro que idica o novo ultimo nó se cair no else
    }
}


//funcao auxiliar retira do inicio que tambem ira aplicar a logica de fila para retirar um pedido da fila
Np* ret_pd(Np* ini){ //recebe o ponteiro que armazena o endereco do nó inicial da fila
    Np* pd = ini->prox; //cria uma variavel auxiliar do tipo "Np*" "pd" para guarda o endereco do novo inicio

    //mostra na tela o pedido retirado e que deve ser preparado 
    printf("Proximo pedido a ser preparado\nNumero do pedido: %d\nNome do pedido: %s\n\n", ini->numero_pedido, ini ->nome_prato);

    free(ini);     //libera a memoria do pedido que estava no inicio da fila
    return pd;      //retorna o novo endereco do inicio da fila
}

//a funcao que sera chamada para adicionar um novo pedido na fila
void adicionar_pedido (Filap* pp, char nome_prato[]){ // recebe o ponteiro da estrura "Filap*" como parametro, assim como nome do pedido
    pp->fim = ins_pd(pp->fim, nome_prato); //o ponteiro fim que referencia o endereco do nó final da fila recebe o endereco do novo nó criado
    if(pp->ini == NULL){ //verifica se a fila esta vazia
        pp->ini = pp->fim; //se tiver vazia o ponteiro que guarda o endereco de memoria do nó inicial tambem aponta para o novo nó
    }
}

//a funcao verifica se o ponteiro ini que indica o nó do inicio da fila esta NULL antes de remover
int vazia(Filap* pp){  //recebe o ponteiro do tipo "Filap*" como parametro
    return (pp->ini == NULL); //verifica se o ponteiro que refericia o inicio esta NULL
}

//a funcao faz a remocao do pedido que esta no inicio da fila
void  desenfileirar_pedido(Filap* pp){ //recebe como parametro o ponteiro do tipo "Filap*"
    if (vazia(pp)){  //verifica se a fila esta vazia chamando a funcao "vazia" e passa o ponteiro "pp" como parametro
        printf("Nenhum pedido na fila\n"); //mostra mensagem de que a fila esta vazia
        exit(1);  //para a execucao do programa
    }
    
    pp->ini = ret_pd(pp->ini); //o ponteiro ini de "pp" recebe o novo endereco do inicio da fila retonado pela funcao "ret_pd"
    if(pp->ini == NULL){  //verifica se a fila ficou vazia apos a remocao de um pedido
        pp->fim = NULL;   //atribui NULL para o ponteiro fim que idica que a lista ficou vazia
    } 
}

//a funcao libera toda a memoria alocada dinamicamente por cada nó e pela estrutura Filap
void libera (Filap* fp){

    //cria uma variavel auxiliar do tipo "Np*" "pp" que ira armazenar o endereco de memoria do nó inicial 
    Np* pp = fp->ini;

    //verifica se ainda nao chegou ao fim da fila
    while (pp != NULL){

        // cria outra variavel auxiliar do tipo "No*" "t" que armazena o endereco do proximo nó
        Np* t = pp->prox; 
    
        free(pp);  //libera a memoria do nó atual
        pp = t;    //"pp" recebe o proximo nó
    }
    free(fp);  //libera a memoria alocada para toda a estrutura "Filap"
}

int main(){

    //cria um ponteiro do tipo "Filap*" "fp" e chama a funcao que aloca dinamicamente a estrutura na memoria e retorna seu ponteiro 
    Filap* fp = cria();

    adicionar_pedido(fp, "Feijao e arroz");         //adiciona um novo pedido a fila passando o ponteiro da estrutura "Filap*" e o nome do pedido como parametro
    adicionar_pedido(fp, "Bife acebolado");        //adiciona um novo pedido a fila passando o ponteiro da estrutura "Filap*" e o nome do pedido como parametro
    adicionar_pedido(fp, "bisteca suina");        //adiciona um novo pedido a fila passando o ponteiro da estrutura "Filap*" e o nome do pedido como parametro
    adicionar_pedido(fp, "Mostadela com acai");  //adiciona um novo pedido a fila passando o ponteiro da estrutura "Filap*" e o nome do pedido como parametro
    desenfileirar_pedido(fp);   //retira o 1 pedido da fila e mostra na tela suas informacoes
    desenfileirar_pedido(fp);   //retira o 2 pedido da fila e mostra na tela suas informacoes
    desenfileirar_pedido(fp);   //retira o 3 pedido da fila e mostra na tela suas informacoes
    desenfileirar_pedido(fp);   //retira o 4 pedido da fila e mostra na tela suas informacoes
    desenfileirar_pedido(fp);   //tenta retira mas um pedido, mas a fila esta vazia entao mostra a mensagem e encera a execucao do programa


    libera(fp); //libera a memoria alocada dinamicamente se ainda tiver pedidos na fila

}