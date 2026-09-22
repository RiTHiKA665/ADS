#include <stdio.h>
#define MAX 10

int stack[MAX];
int left = -1;
int right = MAX;

/* Push at Left */
void pushLeft(int value)
{
    if (left + 1 == right)
    {
        printf("Stack Overflow!\n");
        return;
    }

    left++;
    stack[left] = value;
    printf("%d pushed at Left.\n", value);
}

/* Push at Right */
void pushRight(int value)
{
    if (left + 1 == right)
    {
        printf("Stack Overflow!\n");
        return;
    }

    right--;
    stack[right] = value;
    printf("%d pushed at Right.\n", value);
}

/* Pop from Left */
void popLeft()
{
    if (left == -1)
    {
        printf("Left Stack is Empty!\n");
        return;
    }

    printf("%d popped from Left.\n", stack[left]);
    left--;
}

/* Pop from Right */
void popRight()
{
    if (right == MAX)
    {
        printf("Right Stack is Empty!\n");
        return;
    }

    printf("%d popped from Right.\n", stack[right]);
    right++;
}

/* Display */
void display()
{
    int i;

    if (left == -1 && right == MAX)
    {
        printf("Stack is Empty!\n");
        return;
    }

    printf("Elements: ");

    /* Elements inserted from Left */
    for (i = left; i >= 0; i--)
        printf("%d ", stack[i]);

    /* Elements inserted from Right */
    for (i = right; i < MAX; i++)
        printf("%d ", stack[i]);

    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- DOUBLE ENDED STACK ---\n");
        printf("1. Push Left\n");
        printf("2. Push Right\n");
        printf("3. Pop Left\n");
        printf("4. Pop Right\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                pushLeft(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                pushRight(value);
                break;

            case 3:
                popLeft();
                break;

            case 4:
                popRight();
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
