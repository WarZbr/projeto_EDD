#include <stdio.h>
#include <string.h>
#include "queue.h"

void queue_init(t_queue *queue) {
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
}

int queue_is_empty(t_queue *queue) {
    return (queue->size == 0);
}

int queue_is_full(t_queue *queue) {
    return (queue->size == MAX_QUEUE);
}

int queue_size(t_queue *queue) {
    return queue->size;
}

int queue_enqueue(t_queue *queue, Client client) {
    if (queue_is_full(queue)) {
        return 0;
    }
    
    strcpy(queue->data[queue->rear].name, client.name);
    queue->data[queue->rear].type = client.type;
    
    queue->rear = (queue->rear + 1) % MAX_QUEUE;
    queue->size++;
    
    return 1;
}

int queue_dequeue(t_queue *queue, Client *client) {
    if (queue_is_empty(queue)) {
        return 0;
    }
    
    strcpy(client->name, queue->data[queue->front].name);
    client->type = queue->data[queue->front].type;
    
    queue->front = (queue->front + 1) % MAX_QUEUE;
    queue->size--;
    
    return 1;
}

int queue_front(t_queue *queue, Client *client) {
    if (queue_is_empty(queue)) {
        return 0;
    }
    
    strcpy(client->name, queue->data[queue->front].name);
    client->type = queue->data[queue->front].type;
    
    return 1;
}