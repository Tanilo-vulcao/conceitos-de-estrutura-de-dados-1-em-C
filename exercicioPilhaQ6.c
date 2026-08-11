#include <stdio.h>
#include <stdlib.h>

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
