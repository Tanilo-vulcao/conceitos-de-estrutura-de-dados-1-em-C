#include <stdio.h>

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
