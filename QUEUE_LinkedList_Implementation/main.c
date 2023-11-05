#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

struct node
{
    int data;
    struct node *next;
};

typedef struct
{
    int cnt;
    struct node *front;
    struct node *rear;
} queue;

void initialize_q(queue *q)
{
    q->cnt = 0;
    q->front = q->rear = NULL;
}

int isFull(queue *q)
{
    return q->cnt == QUEUE_SIZE;
}

int isEmpty(queue *q)
{
    return q->cnt == 0;
}

void enqueue(queue *q, int x)
{
    if (isFull(q))
    {
        printf("Queue is full\n");
        return;
    }
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    if (isEmpty(q))
    {
        q->front = q->rear = temp;
    }
    else
    {
        q->rear->next = temp;
        q->rear = temp;
    }
    q->cnt++;
}

int dequeue(queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    int x = q->front->data;
    struct node *temp = q->front;
    q->front = q->front->next;
    free(temp);
    q->cnt--;

    return x;
}

void printElement(queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    else
    {
        struct node *temp = q->front;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    queue q;
    initialize_q(&q);

    enqueue(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 8);
    enqueue(&q, 6);

    printf("Elements in the queue: ");
    printElement(&q);

    int dequeuedElement = dequeue(&q);
    if (dequeuedElement != -1)
    {
        printf("Dequeued element: %d\n", dequeuedElement);
    }

    printf("Elements in the queue after dequeue: ");
    printElement(&q);

    return 0;
}
