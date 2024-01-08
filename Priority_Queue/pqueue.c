#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 50

struct priority_queue
{
    int A[QUEUE_SIZE + 1];
    int cnt;
};

typedef struct priority_queue pqueue;

void initialize(pqueue *p)
{
    p->cnt = 0;
}

void insert(pqueue *p, int key)
{
    if (p->cnt == QUEUE_SIZE)
        printf("Queue is full");
    else
    {
        p->cnt++;
        p->A[p->cnt] = key;
        int iter = p->cnt;

        while (iter != 1 && p->A[iter] < p->A[iter / 2])
        {
            int temp = p->A[iter];
            p->A[iter] = p->A[iter / 2];
            p->A[iter / 2] = temp;
            iter = iter / 2;
        }
    }
}

void print_heap(pqueue *p)
{
    printf("\n");
    if (p->cnt == 0)
    {
        printf("Queue is empty");
    }
    else
    {
        int i;
        for (i = 1; i <= p->cnt; i++)
        {
            printf("%5d", p->A[i]);
        }
    }
}

int delete_heap(pqueue *p)
{

    if (p->cnt == 0)
    {
        printf("Queue is Empty\n");
        return -100;
    }
    else
    {
        int x = p->A[1];
        p->A[1] = p->A[p->cnt];
        p->cnt--;
        int iter = 1;

        while (2 * iter <= p->cnt && (p->A[iter] > p->A[2 * iter] || p->A[iter] > p->A[2 * iter + 1]))
        {
            if (p->A[2 * iter] < p->A[2 * iter + 1])
            {

                int temp = p->A[iter];
                p->A[iter] = p->A[2 * iter];
                p->A[2 * iter] = temp;
                iter = 2 * iter;
            }
            else
            {
                int temp = p->A[iter];
                p->A[iter] = p->A[2 * iter + 1];
                p->A[2 * iter + 1] = temp;
                iter = 2 * iter + 1;
            }
        }
        return x;
    }
}

int main()
{
    pqueue p;

    initialize(&p);
    insert(&p, 15);
    insert(&p, 30);
    insert(&p, 18);
    insert(&p, 19);
    insert(&p, 33);
    insert(&p, 45);
    insert(&p, 5);

    print_heap(&p);
    delete_heap(&p);
    print_heap(&p);
    delete_heap(&p);
    print_heap(&p);
    delete_heap(&p);
    print_heap(&p);

    return 0;
}
