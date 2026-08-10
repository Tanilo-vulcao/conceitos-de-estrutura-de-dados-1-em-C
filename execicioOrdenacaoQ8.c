#include <stdio.h>

/*
descricao do que foi feito

foi criado um vetor contendo os horarios de chegada de
10 fornecedores. Os horarios sao representados por
minutos decorridos desde o inicio do dia.

Por exemplo, o valor 480 representa 08:00, pois 8 horas
correspondem a 480 minutos.

Como os horarios estao desordenados, foi utilizado o
algoritmo Insertion Sort para coloca-los em ordem
cronologica crescente.

O Insertion Sort funciona considerando inicialmente o
primeiro elemento como ordenado. Depois ele pega o
proximo elemento, armazena seu valor em uma variavel
chamada chave e compara com os elementos anteriores.

Enquanto o elemento anterior for maior que a chave,
ele e deslocado uma posicao para a direita. Quando a
posicao correta e encontrada, a chave e colocada nela.

Esse processo continua ate que todos os elementos do
vetor estejam ordenados.

Na main e criado o vetor com os 10 horarios, uma variavel
para armazenar a chave e as variaveis de controle dos
lacos. Depois o algoritmo percorre o vetor e organiza
os horarios.

Por fim, o vetor e percorrido novamente e os horarios
ordenados sao exibidos na tela.
*/

// questao 4

int main() {

    // cria o vetor contendo os horarios dos fornecedores
    // os valores representam minutos decorridos no dia
    int horarios[10] = {
        540,
        480,
        720,
        510,
        660,
        495,
        600,
        750,
        570,
        525
    };

    // variavel utilizada para guardar temporariamente
    // o elemento que sera colocado na posicao correta
    int chave;

    // variaveis utilizadas para controlar os lacos
    int i, j;


    // comeca pelo segundo elemento do vetor,
    // pois o primeiro elemento ja e considerado ordenado
    for (i = 1; i < 10; i++) {

        // guarda o valor atual na variavel chave
        chave = horarios[i];

        // j recebe a posicao anterior a chave
        j = i - 1;


        // enquanto j nao chegar antes do inicio do vetor
        // e o elemento anterior for maior que a chave
        while (j >= 0 && horarios[j] > chave) {

            // desloca o elemento maior uma posicao
            // para a direita
            horarios[j + 1] = horarios[j];

            // volta uma posicao para continuar
            // procurando o local correto da chave
            j--;
        }

        // depois que a posicao correta foi encontrada,
        // coloca a chave nessa posicao
        horarios[j + 1] = chave;
    }


    // mostra uma mensagem antes do resultado
    printf("Horarios em ordem cronologica:\n");


    // percorre o vetor ja ordenado
    for (i = 0; i < 10; i++) {

        // imprime os horarios em minutos
        printf("%d minutos\n", horarios[i]);
    }

    return 0;
}
