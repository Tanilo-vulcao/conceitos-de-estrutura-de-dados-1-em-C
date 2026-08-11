#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// cria a estrutura que armazena os dados de cada caixa
// e tambem o ponteiro que aponta para o proximo no
struct caixa {
    char codigo_rastreio[50];  // guarda o codigo de rastreio
    struct caixa *prox;         // aponta para o proximo no
};

typedef struct caixa Caixa;     // renomeia a estrutura para Caixa


// funcao responsavel por empilhar uma nova caixa
void empilhar_caixa(Caixa **topo, char codigo[]) {

    // aloca dinamicamente memoria para um novo no
    Caixa *novo = (Caixa *) malloc(sizeof(Caixa));

    // verifica se a alocacao da memoria falhou
    if (novo == NULL) {
        printf("Alocacao da memoria falhou\n");
        exit(1);
    }

    // copia o codigo recebido para o campo do novo no
    strcpy(novo->codigo_rastreio, codigo);

    // o novo no aponta para o antigo topo da pilha
    novo->prox = *topo;

    // o novo no passa a ser o topo da pilha
    *topo = novo;

    printf("Caixa %s empilhada\n", codigo);
}


// funcao responsavel por retirar uma caixa do topo
void desempilhar_caixa(Caixa **topo) {

    // verifica se a pilha esta vazia
    if (*topo == NULL) {
        printf("A pilha esta vazia\n");
        return;
    }

    // ponteiro auxiliar recebe o no que esta no topo
    Caixa *p = *topo;

    // mostra qual caixa esta sendo retirada
    printf("Caixa %s retirada\n", p->codigo_rastreio);

    // o topo passa a apontar para o proximo no
    *topo = p->prox;

    // libera a memoria do no retirado
    free(p);
}


int main() {

    // cria o ponteiro que representa o topo da pilha
    Caixa *topo;

    // inicializa a pilha como vazia
    topo = NULL;

    // adiciona a primeira caixa
    empilhar_caixa(&topo, "CX001");

    // adiciona a segunda caixa
    empilhar_caixa(&topo, "CX002");

    // adiciona a terceira caixa
    empilhar_caixa(&topo, "CX003");

    // retira a ultima caixa adicionada
    desempilhar_caixa(&topo);

    // retira a proxima caixa
    desempilhar_caixa(&topo);

    // retira a ultima caixa restante
    desempilhar_caixa(&topo);

    return 0;
}
