#ifndef __QUEUE_H__
#define __QUEUE_H__

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int datatype;

typedef struct node
{
    datatype data;
    struct node *next;
}node_t;

typedef struct queue
{
    node_t *head;
    node_t *tail;
}queue_t;


void queue_init(queue_t *pq);
void queue_push(queue_t *pq, datatype x);
void queue_pop(queue_t *pq);
void queue_destroy(queue_t *pq);
datatype queue_front(queue_t *pq);
datatype queue_back(queue_t *pq);
unsigned int queue_size(queue_t *pq);
bool queue_empty(queue_t *pq);

void queue_print(queue_t *pq);

#endif /*__QUEUE_H__*/