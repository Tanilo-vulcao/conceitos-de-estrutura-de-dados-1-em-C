#include <stdio.h>

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
