#include"queue.h"

void queue_init(queue_t *pq)
{
    assert(pq);

    pq->head = NULL;
    pq->tail = NULL;
}

void queue_push(queue_t *pq, datatype x)
{
    assert(pq);

    node_t *newnode = (node_t *)malloc(sizeof(node_t));
    if (newnode == NULL)
    {
        printf("malloc fail\n");
        exit(-1);
    }
    newnode->data = x;
    newnode->next = NULL;

    if (pq->head == NULL)
    {
        pq->head = newnode;
        pq->tail = newnode;
    }
    else
    {
        pq->tail->next = newnode;
        pq->tail = newnode;
    }
}

void queue_pop(queue_t *pq)
{
    assert(pq);
    assert(pq->head);

    node_t *next = pq->head->next;
    free(pq->head);
    pq->head = next;
    if (pq->head == NULL)
    {
        pq->tail = NULL;
    }
}

void queue_destroy(queue_t *pq)
{
    assert(pq);

    node_t *cur = pq->head;
    node_t *next = NULL;
    while (cur)
    {
        next = cur->next;
        free(cur);
        cur = next;
    }

    pq->head = NULL;
    pq->tail = NULL;
}

datatype queue_front(queue_t *pq)
{
    assert(pq);
    assert(pq->head);

    return pq->head->data;
}

datatype queue_back(queue_t *pq)
{
    assert(pq);
    assert(pq->head);
    
    return pq->tail->data;
}

unsigned int queue_size(queue_t *pq)
{
    assert(pq);

    unsigned int count = 0;

    node_t *cur = pq->head;
    while (cur)
    {
        count++;
        cur = cur->next;
    }

    return count;
}

bool queue_empty(queue_t *pq)
{
    assert(pq);

    return pq->head == NULL;
}

void queue_print(queue_t *pq)
{
    assert(pq);

    while (!queue_empty(pq))
    {
        datatype data = queue_front(pq);
        queue_pop(pq);
        printf("%d\t", data);
    }
    printf("\n");
}
