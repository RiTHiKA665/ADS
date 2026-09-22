#include <stdio.h>
#define MAX 20
int stack[MAX];
int minStack[MAX];
int maxStack[MAX];
int top = -1;
void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    top++;
    stack[top] = value;

    if (top == 0)
    {
        minStack[top] = value;
        maxStack[top] = value;
    }
    else
    {
        // Store minimum
        if (value < minStack[top - 1])
            minStack[top] = value;
        else
            minStack[top] = minStack[top - 1];

        // Store maximum
        if (value > maxStack[top - 1])
            maxStack[top] = value;
        else
            maxStack[top] = maxStack[top - 1];
    }
}

int pop()
{
    int value;

    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    value = stack[top];
    top--;

    return value;
}

int getMin()
{
    if (top == -1)
        return -1;

    return minStack[top];
}

int getMax()
{
    if (top == -1)
        return -1;

    return maxStack[top];
}

void display()
{
    int i;

    printf("Stack: ");

    for (i = top; i >= 0; i--)
        printf("%d ", stack[i]);

    printf("\n");
}

int main()
{
    int n, i, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter element: ");
        scanf("%d", &value);
        push(value);
    }

    display();

    printf("Minimum = %d\n", getMin());
    printf("Maximum = %d\n", getMax());

    printf("\nPopped = %d\n", pop());

    printf("Minimum = %d\n", getMin());
    printf("Maximum = %d\n", getMax());

    return 0;
}
