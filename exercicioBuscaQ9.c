#include <stdio.h>   // biblioteca padrão utilizada para entrada e saída de dados no código
#define MAX 15      //aqui e definido o tamanho maximo para o tamanho do vetor com 15 possicoes

//A funcao faz a busca linear no vetor em busca do codigo digitado
int busca_linear(int codigo_barra, int* vgalpao){
    int i;  //cria a variavel auxiliar para percorre as posicoes do vetor

    for(i= 0; i<MAX; i++){   // percorre o vetor do índice 0 até o índice MAX - 1
        if(codigo_barra == vgalpao[i]){  //compara se encontrou o item buscado
            return i;            //retorna o indice onde esta o item buscado
        }
    }

    return -  1;      //se ao final nao encontrar retorna -1
}

int main(){

    // cria o vetor de tamanho MAX definido acima, e preenche com os 15 codigos de barras
    int vgalpao[MAX] = {101, 205, 312, 450, 523, 601, 712, 845,
                        901, 1020, 1150, 1234, 1350, 1400, 1500};

    int codigo;    //variavel para guardar o codigo digitado pelo operador
    int resultado; // variavel para guardar o retorno da funcao

    printf("Digite o codigo de barras: ");  //pede para digitar o codigo buscado
    scanf("%d", &codigo);  //le o codigo digitado pelo operador

    resultado = busca_linear(codigo, vgalpao);  //chama a funcao e atribui o resultado a variavel

    printf("Indice: %d\n", resultado);          //mostra o resultado da funcao

}