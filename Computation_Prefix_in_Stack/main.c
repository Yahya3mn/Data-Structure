#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define STACK_SIZE 20

typedef struct
{
    double data[STACK_SIZE];
    int top;
} stack;

void initialize(stack *stk)
{
    stk->top = -1;
}

void push(stack *stk, double x)
{
    if (stk->top == STACK_SIZE - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        stk->data[++stk->top] = x;
    }
}

double pop(stack *stk)
{
    if (stk->top == -1)
    {
        printf("Stack is empty\n");
        return -100.0;
    }
    else
    {
        return stk->data[stk->top--];
    }
}

double Evaluate_Prefix_Expression(char *exp)
{
    stack s;
    initialize(&s);
    int j = strlen(exp) - 1;
    while (j >= 0)
    {
        if (exp[j] == ' ')
        {
            j--;
            continue;
        }
        if (isdigit(exp[j]) || (exp[j] == '-' && isdigit(exp[j - 1])))
        {
            double num = 0;
            int sign = 1;
            if (exp[j] == '-')
            {
                sign = -1;
                j--;
            }
            while (j >= 0 && (isdigit(exp[j]) || exp[j] == '.'))
            {
                if (exp[j] == '.')
                {
                    num /= 10;
                }
                else
                {
                    num = num * 10 + (double)(exp[j] - '0');
                }
                j--;
            }
            j++; // Move back to the first digit of the number
            num *= sign;
            push(&s, num);
        }
        else
        {
            double n1 = pop(&s), n2 = pop(&s);
            switch (exp[j])
            {
            case '+':
                push(&s, n1 + n2);
                break;
            case '-':
                push(&s, n1 - n2);
                break;
            case '*':
                push(&s, n1 * n2);
                break;
            case '/':
                push(&s, n1 / n2);
                break;
            }
        }
        j--;
    }
    return pop(&s);
}

int main()
{
    char exprsn[] = "- 2 / 5 * 4 ^ 32";
    printf("%lf\n", Evaluate_Prefix_Expression(exprsn));

    return 0;
}
