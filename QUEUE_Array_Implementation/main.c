#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 20

typedef struct
{
    int cnt;
    int data[QUEUE_SIZE];
    int rear, front;
} queue;

void initialize(queue *q)
{
    q->cnt = 0;
    q->front = 0;
    q->rear = -1;
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
        printf("Queue is full\n");
    else
    {
        q->rear = (q->rear + 1) % QUEUE_SIZE;
        q->data[q->rear] = x;
        q->cnt++;
    }
}

int dequeue(queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1; // Return -1 to indicate failure to dequeue
    }
    else
    {
        int x = q->data[q->front];
        q->front = (q->front + 1) % QUEUE_SIZE;
        q->cnt--;
        return x;
    }
}

void printElements(queue *q)
{
    if (isEmpty(q))
        printf("Queue is empty\n");
    else
    {
        int i = q->front;
        for (int count = 0; count < q->cnt; count++)
        {
            printf("%d ", q->data[i]);
            i = (i + 1) % QUEUE_SIZE;
        }
        printf("\n");
    }
}

int main()
{
    queue q;
    initialize(&q);

    enqueue(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 8);
    enqueue(&q, 6);

    printf("Elements in the queue: ");
    printElements(&q);

    int dequeuedElement = dequeue(&q);
    if (dequeuedElement != -1)
    {
        printf("Dequeued element: %d\n", dequeuedElement);
    }

    printf("Elements in the queue after dequeue: ");
    printElements(&q);
    return 0;
}
