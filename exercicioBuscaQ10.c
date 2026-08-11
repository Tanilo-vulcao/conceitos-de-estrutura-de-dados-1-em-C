#include <stdio.h>

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
