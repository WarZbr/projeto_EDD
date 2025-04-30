
/**
 * main.c - Programa principal para o Quick Sort iterativo
 * 
 * A estratégia iterativa do algoritmo Quicksort oferece uma vantagem ao estabelecer
 * limites para o tamanho da pilha. Em contraste com a abordagem recursiva, que insere
 * duas partições na pilha de execução em ordem arbitrária, a versão iterativa verifica
 * os tamanhos das partições antes de adicionar à pilha. Além disso, ao adotar uma política
 * que prioriza a inserção dos índices da partição maior do vetor antes dos índices da
 * partição menor, permite que o lado menor seja processado antes do lado maior. Como
 * resultado, o tamanho da pilha é da ordem de O(log(n)).
 * 
 * COMENTÁRIO SOBRE A ESTRATÉGIA:
 * A estratégia mencionada faz total sentido e foi implementada neste programa. Ao analisarmos
 * o comportamento do Quick Sort recursivo, cada chamada recursiva adiciona um novo frame à pilha
 * de execução. No pior caso, isso pode levar a uma pilha com tamanho O(n), causando overflow
 * para arrays muito grandes.
 * 
 * Na implementação iterativa, ao inserirmos a partição maior primeiro na pilha e processarmos
 * a menor imediatamente, garantimos que a pilha nunca terá mais que log(n) elementos. Isso ocorre 
 * porque a cada iteração escolhemos processar a menor partição, que terá no máximo metade do tamanho
 * da partição original. Essa estratégia evita o estouro de pilha e otimiza o uso de memória,
 * mantendo sempre o menor número possível de chamadas pendentes.
 * 
 * Esta estratégia foi implementada na função quicksort_iterative(), onde comparamos os tamanhos
 * das partições esquerda e direita, e empilhamos a maior primeiro para processar a menor antes.
 */


#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "quicksort.h"

int main() {
    int n;

    scanf("%d", &n);
    
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Erro ao alocar memória\n");
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    quicksort_iterative(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
    free(arr);
    
    return 0;
}