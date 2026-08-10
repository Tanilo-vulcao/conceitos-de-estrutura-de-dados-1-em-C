#include <stdio.h>

/*
descricao do que foi feito

foi criado um vetor contendo 8 precos de pacotes turisticos
que inicialmente estao desordenados.

Para organizar esses valores foi utilizado o algoritmo
Bubble Sort. Esse algoritmo percorre o vetor comparando
dois elementos vizinhos. Caso o elemento da esquerda seja
maior que o elemento da direita, os dois valores sao trocados.

Para realizar a troca foi criada uma variavel auxiliar
chamada temp, que armazena temporariamente um dos valores
para que ele nao seja perdido durante a troca.

Foram utilizados dois comandos for. O primeiro controla
a quantidade de vezes que o vetor sera percorrido. O segundo
faz as comparacoes entre os elementos vizinhos.

A cada passagem pelo vetor, o maior valor que ainda nao
esta na posicao correta vai sendo levado para o final.
Por isso, a quantidade de comparacoes necessarias diminui
a cada nova passagem.

Depois que o vetor esta completamente ordenado, um outro
for percorre o vetor e imprime todos os precos em ordem
crescente.

Na main sao declarados o vetor, a variavel auxiliar e as
variaveis de controle dos lacos. Depois o Bubble Sort e
executado e o resultado e exibido na tela.
*/

// questao 3

int main() {

    // cria o vetor com os precos dos 8 pacotes
    float precos[8] = {
        1500.00,
        800.00,
        2300.00,
        1200.00,
        500.00,
        1800.00,
        950.00,
        2100.00
    };

    // variavel auxiliar utilizada durante as trocas
    float temp;

    // variaveis utilizadas para controlar os lacos
    int i, j;


    // primeiro for controla as passagens pelo vetor
    for (i = 0; i < 7; i++) {

        // segundo for realiza as comparacoes entre
        // elementos vizinhos
        for (j = 0; j < 7 - i; j++) {

            // verifica se o elemento atual e maior
            // que o proximo elemento
            if (precos[j] > precos[j + 1]) {

                // guarda temporariamente o valor atual
                temp = precos[j];

                // coloca o menor valor na posicao atual
                precos[j] = precos[j + 1];

                // coloca o maior valor na proxima posicao
                precos[j + 1] = temp;
            }
        }
    }


    // imprime uma mensagem antes de mostrar
    // o vetor ordenado
    printf("Precos em ordem crescente:\n");


    // percorre o vetor depois da ordenacao
    for (i = 0; i < 8; i++) {

        // imprime cada preco com duas casas decimais
        printf("R$ %.2f\n", precos[i]);
    }

    return 0;
}
