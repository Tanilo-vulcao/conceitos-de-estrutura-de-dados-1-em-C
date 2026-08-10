#include <stdio.h>   // biblioteca padrão utilizada para entrada e saída de dados no código
#include <stdlib.h>  // biblioteca padrão utilizada para alocação dinâmica de memória
#include <string.h>  // biblioteca utilizada para trabalhar com strings e copiar o nome do turista

//a implementacao da fila vai usar uma lista encadeada para armazenar cada visitante 
//Estrutura que armazena as informações de cada turista.
struct nofila{
    char nome[21];  //vetor de caracteres para armazenar o nome do visitante, com ate 20 caracteres
    int idade;
    struct nofila* prox; // O ponteiro prox que aponta para o próximo nó da fila.
};
typedef struct nofila No; // Renomeia struct nofila para No, facilitando sua utilização no código.

//essa estrutura cria os dois ponteiros inicio e fim que aponta para o primeiro o ultimo visitante da fila
struct fila {
    No* ini;
    No* fim;
};
typedef struct fila Fila; //renomeia a estrutura para Fila

//a funcao tem como objetivo alocar a estrutura da fila e iniciliza os ponteiros dala com valor NULL
Fila* cria(void){
    Fila* f = (Fila*) malloc(sizeof(Fila)); //aloca dinamicamente a memoria para a estrutura
    
    if(f == NULL){  //verifca se a alocacao falhou
    printf("Erro ao alocar memoria!\n");
    exit(1);
}

    f->ini = f->fim = NULL; //inicializa como vazia a fila deixando os dois ponteiros com valores NULL
    return f;    //retona o ponteiro da estrutura Fila que foi criada
}

//funcao auxiliar insere no fim, ela que ira aplicar a logica de fila para cada novo elemento
No* ins_fim (No* fim, char  nome[], int idade){  //recebe os parametro e o ponteiro que armazena o endereco do nó final da fila
    No* p = (No*) malloc(sizeof(No)); //aloca dinamicamente cada novo nó na memoria

    if(p == NULL){      //verifica se a alocacao falhou
    printf("Erro ao alocar memoria!\n");
    exit(1);
}

    strcpy(p->nome, nome); //copia o texto recebido, atraves da funcao "strcpy" para o vetor char criado para armazena o nome
    p->idade = idade;      
    p->prox = NULL;
    if(fim != NULL){    //verifica se a fila nao esta vazia
        fim->prox = p; //fim agora passa a apontar para o novo nó 
        return p;     //retorna o ponteiro que idica o novo ultimo nó
    }else {
    return p;   //retorna o ponteiro que indica o novo ultimo nó se cair no else
    }
}


//funcao auxiliar retira do inicio que tambem ira aplicar a logica de fila para retirar um elemento
No* ret_ini(No* ini){ //recebe o ponteiro que armazena o endereco do nó inicial da fila
    No* p = ini->prox; //cria uma variavel auxiliar do tipo "No*" "p" para guarda o endereco do novo inicio
    free(ini);     //libera a memoria do nó que estava no inicio da fila
    return p;      //retorna o novo endereco do inicio da fila
}

//a funcao que sera chamada para adicionar um novo turista na fila
void enfileirar_turista (Fila* f, char nome[], int idade){ // recebe o ponteiro da estrura fila como parametro assim como o nome e a idade
    f->fim = ins_fim(f->fim, nome, idade); //o ponteiro fim que referencia o endereco do nó final da fila recebe o endereco do novo nó criado
    if(f->ini == NULL){ //verifica se a lista esta vazia
        f->ini = f->fim; //se tiver vazia o ponteiro que guarda o endereco de memoria do nó inicial tambem aponta para o novo nó
    }
}

//a funcao verifica se o ponteiro ini que indica o nó do inicio da fila esta NULL antes de remover
int vazia(Fila* f){  //recebe o ponteiro do tipo "Fila*" "f" como parametro
    return (f->ini == NULL); //verifica o ponteiro que refericia o inicio se ele esta NULL
}

//a funcao faz a remocao do turista que esta no inicio da fila
void atender_turista (Fila* f){   //recebe como parametro o ponteiro do tipo "Fila*" "f"
    if (vazia(f)){     //verifica se a fila esta vazia chamando a funcao "vazia" e passa o ponteiro de f como parametro
        printf("Fila vazia\n"); //mostra mensagem de que a fila esta vazia
        exit(1);  //para a execucao do programa
    }
    f->ini = ret_ini(f->ini); //o ponteiro ini de f recebe o novo endereco do inicio da fila retornado pela funcao "ret_ini"
    if(f->ini == NULL){  //verifica se a fila ficou vazia apos a remocao de um turista
        f->fim = NULL;   //atribui NULL para o ponteiro fim que idica que a lista ficou vazia
    } 
}

//a funcao libera toda a memoria alocada dinamicamente por cada nó, e tambem da estrutura Fila
void libera (Fila* f){

    //cria uma variavel auxiliar do tipo "No*" "q" que ira armazenar o endereco de memoria do nó inicial 
    No* q = f->ini;

    //verifica se ainda nao chegou ao fim da fila
    while (q != NULL){

        // cria outra variavel auxiliar do tipo "No*" "t" que armazena o endereco do proximo nó
        No* t = q->prox; 
    
        free(q);  //libera a memoria do nó atual
        q = t;    //q recebe o proximo nó
    }
    free(f);  //libera a memoria alocada para toda a estrutura Fila
}

//a funcao imprime os dados armazenados nos campos de cada nó da estrutura
void imprime (Fila* f) //recebe o ponteiro do tipo "Fila*" "f"
{
   No* q; //cria a variavel auxiliar do tipo "No*" "q" para ajudar a percorre toda a fila
   for (q=f->ini; q!=NULL; q=q->prox)   //for para percorre a fila toda
      printf("%s %d\n",q->nome, q->idade); //mostra na tela as imformacoes de cada turista

    printf("\n");
}

int main(){
    //cria um ponteiro do tipo "Fila*" "f" e chama a funcao que aloca dinamicamente estrutura na memoria e retorna seu ponteiro 
    Fila* f = cria(); 

    enfileirar_turista(f, "Joao silva", 34); //enfileira um turista
    enfileirar_turista(f, "Lucas lucas", 59); //enfileira um turista
    enfileirar_turista(f, "gabriel senhor", 56); //enfileira um turista
    imprime(f);  //mostra os dados dos turistas da fila

    atender_turista(f); //atende o primeiro turita da fila
    printf("Fila atulizada:\n"); //um printf apenas para separar na tela as imformacoes de uma remocao
    imprime(f);  //mostra os dados dos turistas da fila apos remocao


    atender_turista(f); //atende o primeiro turita da nova fila
    printf("Fila Atualizada\n"); //um printf apenas para separar na tela as imformacoes de uma remocao
    imprime(f);  //mostra os dados dos turistas da fila apos remocao


    libera(f); //libera a memoria alocada dinamicamente

}
