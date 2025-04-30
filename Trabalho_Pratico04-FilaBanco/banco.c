#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

#define MAX_ATENDIDOS 1000

int main() {
    t_queue filaGeral;
    t_queue filaPrioridade;
    Client cliente;
    Client atendidos[MAX_ATENDIDOS];
    int numAtendidos = 0;
    int prioridadesConsecutivas = 0;
    char nomeCliente[MAX_NAME];
    char comando;
    
    queue_init(&filaGeral);
    queue_init(&filaPrioridade);
    
    while (1) {
        scanf("%c", &comando);
        
        if (comando == 'g' || comando == 'p') {
            scanf(" %[^\n]", nomeCliente);
            
            cliente.type = comando;
            strcpy(cliente.name, nomeCliente);
            
            if (comando == 'g') {
                queue_enqueue(&filaGeral, cliente);
            } else {
                queue_enqueue(&filaPrioridade, cliente);
            }
        } 
        else if (comando == 's') {
            if (queue_is_empty(&filaPrioridade)) {
                if (!queue_is_empty(&filaGeral)) {
                    queue_dequeue(&filaGeral, &cliente);
                    atendidos[numAtendidos++] = cliente;
                    prioridadesConsecutivas = 0;
                }
            } 
            else if (prioridadesConsecutivas >= 3 && !queue_is_empty(&filaGeral)) {
                queue_dequeue(&filaGeral, &cliente);
                atendidos[numAtendidos++] = cliente;
                prioridadesConsecutivas = 0;
            } 
            else {
                queue_dequeue(&filaPrioridade, &cliente);
                atendidos[numAtendidos++] = cliente;
                prioridadesConsecutivas++;
            }
        } 
        else if (comando == 'f') {
            for (int i = 0; i < numAtendidos; i++) {
                printf("%s\n", atendidos[i].name);
            }
            break;
        }
        
        getchar();
    }
    
    return 0;
}