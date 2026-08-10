#include <stdio.h>
#include <stdlib.h>

/*
descricao do que foi feito

foi criada uma estrutura para armazenar cada acao realizada
na alteracao do preco de um produto. A estrutura possui uma
variavel do tipo float para armazenar o preco_antigo e um
ponteiro para apontar para a proxima acao da pilha.

Foi feito um typedef para renomear a estrutura para Acao.

Foi criada a funcao empilhar_acao, que recebe como parametros
o ponteiro do topo da pilha e o preco antigo. A funcao aloca
dinamicamente um novo no e verifica se a alocacao falhou.
Depois o preco antigo e armazenado no novo no e o novo no
passa a apontar para o antigo topo da pilha. Por fim, o topo
passa a apontar para o novo no.

Tambem foi criada a funcao desfazer, que recebe o ponteiro
do topo e o preco atual. Primeiro e verificado se a pilha
esta vazia. Caso esteja vazia, nao existe nenhuma alteracao
para desfazer.

Caso exista uma acao, um ponteiro auxiliar recebe o no que
esta no topo. O preco antigo desse no e armazenado em uma
variavel. Depois o topo passa a apontar para o proximo no,
o no antigo e liberado e o preco antigo e retornado.

Na main e criado o preco inicial do produto e depois sao
realizadas algumas alteracoes. Antes de cada alteracao,
o preco atual e colocado na pilha para que possa ser
recuperado posteriormente.

Quando a funcao desfazer e chamada, a ultima alteracao
realizada e desfeita primeiro. Isso acontece porque a pilha
utiliza o principio LIFO, ou seja, o ultimo elemento que
entrou e o primeiro que sai.
*/

// cria a estrutura que representa uma acao de alteracao
struct acao {
    float preco_antigo;    // guarda o preco antes da alteracao
    struct acao *prox;     // aponta para a proxima acao
};

typedef struct acao Acao;  // renomeia a estrutura para Acao


// funcao utilizada para adicionar uma acao na pilha
void empilhar_acao(Acao **topo, float preco_antigo) {

    // aloca memoria para um novo no
    Acao *novo = (Acao *) malloc(sizeof(Acao));

    // verifica se a alocacao falhou
    if (novo == NULL) {
        printf("Alocacao da memoria falhou\n");
        exit(1);
    }

    // armazena o preco antigo no novo no
    novo->preco_antigo = preco_antigo;

    // o novo no aponta para o antigo topo
    novo->prox = *topo;

    // atualiza o topo da pilha
    *topo = novo;
}


// funcao utilizada para desfazer a ultima alteracao
float desfazer(Acao **topo, float preco_atual) {

    // verifica se nao existem acoes na pilha
    if (*topo == NULL) {
        printf("Nao existem acoes para desfazer\n");

        // retorna o preco atual sem alterar
        return preco_atual;
    }

    // ponteiro auxiliar recebe o topo
    Acao *p = *topo;

    // guarda o preco antigo que sera restaurado
    float preco_restaurado = p->preco_antigo;

    // o topo passa a apontar para o proximo no
    *topo = p->prox;

    // libera a memoria do no retirado
    free(p);

    // retorna o preco que sera restaurado
    return preco_restaurado;
}


int main() {

    // cria o ponteiro que representa o topo da pilha
    Acao *topo;

    // inicializa a pilha como vazia
    topo = NULL;

    // define o preco inicial do produto
    float preco = 100.00;

    // antes de alterar, guarda o preco antigo na pilha
    empilhar_acao(&topo, preco);

    // altera o preco para 120
    preco = 120.00;

    // guarda o preco antigo antes da nova alteracao
    empilhar_acao(&topo, preco);

    // altera o preco para 150
    preco = 150.00;

    // guarda o preco antigo antes da nova alteracao
    empilhar_acao(&topo, preco);

    // altera o preco para 180
    preco = 180.00;

    printf("Preco atual: %.2f\n", preco);

    // desfaz a ultima alteracao: 180 para 150
    preco = desfazer(&topo, preco);
    printf("Depois do desfazer: %.2f\n", preco);

    // desfaz a alteracao anterior: 150 para 120
    preco = desfazer(&topo, preco);
    printf("Depois do desfazer: %.2f\n", preco);

    // desfaz a primeira alteracao: 120 para 100
    preco = desfazer(&topo, preco);
    printf("Depois do desfazer: %.2f\n", preco);

    return 0;
}
