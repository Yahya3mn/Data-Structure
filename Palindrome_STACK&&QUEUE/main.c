#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define SIZE 100
#define STACK_SIZE 100
#define QUEUE_SIZE 100

struct node
{
    int data;
    struct node *next;
};

typedef struct
{
    int cnt;
    struct node *top;
}stack;

typedef struct
{
    int cnt;
    struct node *front;
    struct node *rear;
}queue;

void initialize_Stack(stack *stk)
{
    stk->cnt = 0;
    stk->top = NULL;
}
void initialize_Queue(queue *q)
{
    q->cnt = 0;
    q->front = q->rear = NULL;
}

int isFull_Stack(stack *stk)
{
    if(stk->cnt == STACK_SIZE)
        return 1;
    else
        return 0;
}

int isEmpty_Stack(stack *stk)
{
    if(stk->cnt == 0)
        return 1;
    else
        return 0;
}

void push_Stack(stack *stk,int x)
{
    if(isFull_Stack(stk))
    {
        printf("Stack is full\n");
    }
    else
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));

        temp->data = x;
        temp->next = stk->top;
        stk->top = temp;
        stk->cnt++;
    }
}

int pop_Stack(stack *stk)
{
    if(isEmpty_Stack(stk))
    {
        printf("Stack is empty\n");
        return -100;
    }
    else{
        struct node *temp = stk->top;
        stk->top = stk->top->next;
        int x = temp->data;
        free(temp);
        stk->cnt--;
        return x;
    }
}

int isFull_Queue(queue *q)
{
    if(q->cnt == QUEUE_SIZE)
        return 1;
    else{
        return 0;
    }
}

int isEmpty_Queue(queue *q)
{
    if(q->cnt == 0)
        return 1;
    else
        return 0;
}

void enqueue(queue *q, int c)
{
    if(isFull_Queue(q)){
        printf("Queue is full\n");
    }
    else{
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = c;
        temp->next = NULL;
        if(isEmpty_Queue(q))
        {
            q->front = q->rear = temp;
        }
        else
        {
            q->rear = q->rear->next = temp;
        }
        q->cnt++;
    }
}

int dequeue(queue *q)
{
    if(isEmpty_Queue(q)){
        printf("Queue is empty\n");
        return -100;
    }
    else
    {
        struct node *temp = q->front;
        int x = temp->data;
        q->front = temp->next;
        free(temp);
        q->cnt--;
        return x;
    }
}

int main()
{
    char ifade[SIZE];
    queue q;
    stack s;

    int i = 0, mismatches = 0;

    initialize_Stack(&s);
    initialize_Queue(&q);

    printf("Bir ifade giriniz...\n");
    gets(ifade);

    for(i = 0; i != strlen(ifade); i++){
        if(isalpha(ifade[i])){
            enqueue(&q, tolower(ifade[i]));
            push_Stack(&s, tolower(ifade[i]));
        }
    }

    while(!isEmpty_Queue(&q)){
        if(pop_Stack(&s) != dequeue(&q)){
            mismatches = 1;
            break;
        }
    }

    if(mismatches == 1){
        printf("Girdiginiz ifade palindrome degildir\n");
    }
    else{
        printf("Girdiginiz ifade palindromedur\n");
    }
    getch();
    return 0;
}
