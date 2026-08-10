#include <stdio.h>   // biblioteca padrão utilizada para entrada e saída de dados no código
#include <stdlib.h>  // biblioteca padrão utilizada para alocação dinâmica de memória

//criar a estrutura que vai armazenar os dados de cada nó da lista
//e tambem o ponteiro que aponta para o nó seguinte ou para NULL, que indica o fim da lista
struct lista {
    int id;                  //variavel onde sera guardado o valor
    int qtd;                 //variavel onde sera gardado a quantidade
    float preco;             //variavel onde sera guardado o preço
    struct lista* prox;      //ponteiro para o proximo nó ou que indica fim da lista.
};
typedef struct lista Clista; // renomeia a estrutura para um nome mas simples.

//a funcao inicializa a lista para retornar um lista vazia;
Clista* inicializa (void){
    return NULL;
}

//a funcao aloca dinamicamente um novo nó, "Clista",
//e atribui seu valores e seu ponteiro
Clista* inserir (Clista* cl, int id, int qtd, float preco ){
    Clista* novo = (Clista*) malloc(sizeof(Clista));
    if(novo == NULL){ //verifica se a alocacao falhou
        printf("Alocacao da memoria falhou");
        exit(1);
    }
    //atribui os valores
    novo->id = id;
    novo->qtd = qtd;
    novo->preco = preco;

    novo->prox = cl; //faz o novo nó apontar para o antigo início da lista.

    printf("Voce adicinou ao carrinho\nproduto ID = %d\nQuantidade = %d\nValor = %.2f\n\n", id,qtd,preco);
    return novo; //retorna o ponteiro para o novo nó
}

//a funcao percorre cada nó da lista ate chegar no seu fim calculando o valor de cada nó,
//ela pega a cada execucao do while, as variaveis preco e quantidade do nó e as multiplica,
//entao soma da varivel auxiliar t, que por sua vez o resultado e acumulado na mesma
//por fim é imprimido o resultado na tela ao final da excucao.
void totalC(Clista* cl){
    float t = 0; //variavel auxiliar para acumular o valor total
    Clista* p = cl; //variavel auxiliar do tipo ponteiro Clista que recebe o ponteiro de cl para percorrer a lista

    while (p != NULL){ //verifica se a lista chegou ao final
       t = t + p->qtd * p->preco; //faz a multiplicacao e soma
       p = p->prox; //varivel auxiliar recebe o ponteiro do proximo nó
    }   

    printf("Valor total do carrinho e = %.2f\n\n", t);
    return;
}


//como cada nó e alocado dinamicamente na lista,
//essa funcao tem como objetivo liberar a memoria ocupada pelos nós apos o uso da lista
void libera (Clista* cl){
    Clista* p = cl; //variavel auxiliar do tipo ponteiro Clista que recebe o mesmo endereco armazenado em cl
    Clista* t;      //variavel auxiliar do tipo ponteiro Clista que auxilia p a percorrer a lista
    while (p != NULL){ //verifica se chegou ao final da lista
        t = p->prox; //t recebe o ponteiro do proximo nó de p
        free(p);    //libera a memória alocada dinamicamente para aquele nó
        p = t;      //passa para p o endereço do próximo nó, que faz continuar a percorrer a lista.
        printf ("Memoria liberada\n\n");
    }
}

int main (){
    Clista* c;                  //criar a variável ponteiro do tipo Clista que será usada para apontar para o início da lista.
    c = inicializa();          //atribui NULL a c
    c = inserir(c,3,4,56.00);  //cria e atribui os valores ao nó
    c = inserir(c,2,3,20);     //cria e atribui os valores ao nó
    c = inserir(c,4,5,100);   //cria e atribui os valores ao nó
    totalC(c);                //calcula e exibi o valor total do carrinho

    libera(c);                // libera a memoria ultilizada pela lista
}