#ifndef QUEUE_H
#define QUEUE_H

#define MAX_NAME 50
#define MAX_QUEUE 100

typedef struct {
    char name[MAX_NAME];
    char type;
} Client;

typedef struct {
    Client data[MAX_QUEUE];
    int front;
    int rear;
    int size;
} t_queue;

void queue_init(t_queue *queue);
int queue_is_empty(t_queue *queue);
int queue_is_full(t_queue *queue);
int queue_size(t_queue *queue);
int queue_enqueue(t_queue *queue, Client client);
int queue_dequeue(t_queue *queue, Client *client);
int queue_front(t_queue *queue, Client *client);

#endif