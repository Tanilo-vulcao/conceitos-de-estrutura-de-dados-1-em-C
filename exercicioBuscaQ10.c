#include <stdio.h>

/*
descricao do que foi feito

foi criado um vetor com 1000 IDs de clientes que estao
rigorosamente ordenados de forma crescente.

Como o vetor ja esta ordenado, foi utilizada a busca
binaria para localizar um determinado ID de forma mais
rapida.

Foi criada uma funcao chamada busca_binaria, que recebe
como parametros o vetor de IDs, o tamanho do vetor e o
ID que deve ser procurado.

Dentro da funcao sao criadas duas variaveis, inicio e fim,
que representam os limites da parte do vetor que ainda
sera pesquisada.

Enquanto inicio for menor ou igual a fim, e calculada a
posicao do elemento que esta no meio da regiao de busca.

Depois o valor que esta no meio e comparado com o ID
procurado.

Caso sejam iguais, significa que o ID foi encontrado e
a posicao e retornada.

Caso o ID procurado seja maior que o elemento do meio,
significa que ele so pode estar na metade direita do vetor.
Por isso, inicio recebe meio + 1.

Caso o ID procurado seja menor, significa que ele so pode
estar na metade esquerda. Nesse caso, fim recebe meio - 1.

Esse processo continua ate encontrar o ID ou ate a regiao
de busca acabar.

Caso o ID nao seja encontrado, a funcao retorna -1.

Na main e criado o vetor com 1000 IDs ordenados, depois
e solicitado ao usuario o ID que deseja procurar. A funcao
de busca binaria e chamada e o resultado e armazenado em
uma variavel.

Por fim, e feita uma verificacao. Se o resultado for
diferente de -1, o cliente foi encontrado e esta ativo
na base. Caso contrario, o ID nao foi encontrado.

A principal vantagem da busca binaria e que ela elimina
aproximadamente metade dos elementos a cada comparacao,
sendo muito mais eficiente que procurar elemento por
elemento em um vetor grande.
*/

// questao 5


// funcao que realiza a busca binaria
int busca_binaria(int ids[], int tamanho, int id_procurado) {

    // define a primeira posicao da regiao de busca
    int inicio = 0;

    // define a ultima posicao da regiao de busca
    int fim = tamanho - 1;


    // continua enquanto existir uma regiao valida
    // para realizar a busca
    while (inicio <= fim) {

        // calcula a posicao do elemento do meio
        int meio = (inicio + fim) / 2;


        // verifica se o elemento do meio e
        // o ID que estamos procurando
        if (ids[meio] == id_procurado) {

            // retorna a posicao encontrada
            return meio;
        }


        // verifica se o ID procurado e maior
        // que o elemento do meio
        if (id_procurado > ids[meio]) {

            // descarta a metade esquerda
            // e continua pela metade direita
            inicio = meio + 1;

        } else {

            // descarta a metade direita
            // e continua pela metade esquerda
            fim = meio - 1;
        }
    }


    // se chegar aqui significa que o ID
    // nao foi encontrado no vetor
    return -1;
}


int main() {

    // cria um vetor para armazenar os 1000 IDs
    int ids[1000];

    // variavel que vai receber o ID procurado
    int id_procurado;

    // variavel que vai armazenar o resultado da busca
    int resultado;


    // preenche o vetor com IDs em ordem crescente
    for (int i = 0; i < 1000; i++) {

        // cria IDs de 1000 ate 1999
        ids[i] = 1000 + i;
    }


    // solicita ao usuario o ID que deseja procurar
    printf("Digite o ID do cliente: ");
    scanf("%d", &id_procurado);


    // chama a funcao de busca binaria
    // e guarda o resultado
    resultado = busca_binaria(ids, 1000, id_procurado);


    // verifica se o resultado foi diferente de -1
    if (resultado != -1) {

        // significa que o ID foi encontrado
        printf("Cliente encontrado!\n");

        // informa que o cliente esta na base
        printf("ID %d esta ativo na base de dados.\n",
               id_procurado);

        // mostra a posicao onde o ID foi encontrado
        printf("Posicao no vetor: %d\n", resultado);

    } else {

        // significa que o ID nao foi encontrado
        printf("Cliente nao encontrado.\n");

        // informa que o cliente nao esta na base
        printf("O ID %d nao esta ativo na base de dados.\n",
               id_procurado);
    }


    return 0;
}
