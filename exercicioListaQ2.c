#include <stdio.h>   // biblioteca padrão utilizada para entrada e saída de dados no código
#include <stdlib.h>  // biblioteca padrão utilizada para alocação dinâmica de memória

#define MAX 3 //aqui e definido um numero maximo para o tamanho do vetor 

//criada a estrutura necessaria para armmazenar os valores de cada parada
struct paradas {
    int nParada;
    char bairro[81]; //vetor de caracteres para armazenar o nome do bairro, com ate 80 caracteres
    int prazoMin;
};
typedef struct paradas Parada, *Pparada; //renomeia a estrutura para um nome mas simples assim como criado o tipo ponteiro dela

//a funcao faz a inicializacao de cada ponteiro do vetor para NULL
void inicializar (Pparada* p){
    int i;
    for(i=0; i<MAX; i++){
        p[i] = NULL;
    }
}


//a funcao faz o preenchimento do vetor de paradas onde atravez do tamanho maximo definido em MAX,
//e feita toda a atribuicao de cada indici do vetor, cada parada apontada pelo indice e alocado dinamicamente, com o tipo da estrutura criada acima,
void preecherP (Pparada* p){
    int i;  //variavel auxiliar para percorre o vetor
    for (i=0; i<MAX; i++){
        if( p[i] == NULL){ //verifica se esta NULL o ponteiro daquela possicao que sera preenchida
            p[i] = (Pparada) malloc(sizeof(Parada)); //aloca dinamicamente a memoria
            if(p[i]==NULL){ //verifica se a alocacao de uma parada falhou
                printf("Memoria da parada %d nao alocada!", i+1);
                exit(1);
            }

            //trecho em que cada informacao do vetor é coletada e guardada
            p[i]->nParada = i+1; //tribui o numero da parada usando i como referencia e convertendo o 0, de i, para 1

            //coleta os dados digitados pelo teclado
            printf("Digite o bairro da %d parada: ", i+1);

            //O trecho " %80[^\n]", faz com que o espaco adicinal colocado antes de %80 ignore os espacos em branco que ja estejam no 
            //fluxo de entrada antes de inicar a leitura, depois %80,
            //indica que o limite de coleta dessa strig e de ate 80 caracteres e o [^\n] informa que assim que o usuario aperta enter,
            //indica a parada da leitura 
            scanf(" %80[^\n]", p[i]->bairro);

            printf("Digite o tempo em minutos da %d parada: ", i+1);
            scanf("%d", &p[i]->prazoMin);
            printf("\n");
        }
    }
}


//a funcao tem como ojetivo remover uma parada, ela recebe o ponteiro do vetor,
//e o numero da parada a ser removida
void removeP (int i, Pparada* p){

    //verifica se a parada informada é valida e nao ultrapassa o tamanho do vetor para nao acessar memoria indevida
     if(i < 1 || i > MAX){
        printf("Numero de parada invalido!\n\n");
        return;
    }

    i=i-1; // subtrai o numero da parada informada para o numero real do indice do vetor que contem a parada

    if (p [i] != NULL){ //verifica se nao esta NULL
        free(p[i]); //libera a memoria alocada dinamicamente para aquela parada
        

        //desloca as paradas seguintes uma posição para a esquerda
        for(int j = i; j < MAX - 1; j++){
            p[j] = p[j + 1];
        }

        //ultima possicao fica NULL
        p[MAX-1] = NULL; //faz o ponteiro daquela posição do vetor apontar para NULL

        printf("Parada %d removida!\n\n", i+1); //confirma a remocao e mostra a parada removida
    }
}

//a funcao percorre todas a posicoes do vetor e ela recebe o ponteiro da estrutura como parametro
//a função imprime todas as paradas que ainda estão armazenadas no vetor
void imprime (Pparada* p){
    int i; //variavel auxiliar para percorrer as posicoes do vetor
    for(i=0; i<MAX; i++){
        if (p[i] != NULL){ //verifica se nao esta NULL

            //imprime o valor dos campos
            printf("Numero da parada: %d\n", p[i]->nParada);
            printf("Bairro: %s\n", p[i]-> bairro);
            printf("Prazo em minutos da parada: %d\n", p[i]->prazoMin);
         }
    }
    printf("\n");
}

//a funcao libera toda a memoria alocada para as paradas que ainda estao no vetor
void liberaTudo(Pparada* p){
    int i; //variavel auxiliar para percorrer o vetor

    for(i = 0; i < MAX; i++){
        if(p[i] != NULL){ //verifica se existe uma parada naquela posicao
            free(p[i]); //libera a memoria alocada para a parada
            p[i] = NULL; //faz o ponteiro apontar para NULL
        }
    }
}

int main(){
    Pparada p [MAX];  //cria uma variavel ponteiro do tipo Pparada para cada possiçao do vetor com o tamanho sendo passado pela definicao MAX
    inicializar(p);  //inicializa o ponteiro de cada parada do vetor para NULL
    preecherP(p);   //aloca e preenche cada possicao do vetor 
    imprime(p);    //imprime as imformacoes contida no vetor
    removeP(2, p); //remove uma parada do vetor
    imprime(p);    //imprime as imformacoes contida no vetor
    liberaTudo(p); //libera a memoria alocada dinamicamente para cada parada

} 