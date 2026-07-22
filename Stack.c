#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int a[MAX];
int i, elm, top = -1;

void main() {
    int ch;
    void push();
    void pop();
    void peek();
    void display();  
    void search();
    void IsEmpty();  
    void IsFull();    

    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Search\n");
        printf("6. IsEmpty\n");
        printf("7. IsFull\n");
        printf("8. Exit\n");
        printf("select ur choice\n");
        scanf("%d", &ch);  

        switch (ch) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                search();
                break;
            case 6:
                IsEmpty();
                break;
            case 7:
                IsFull();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}

void push() {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    printf("Enter the element to push: ");
    scanf("%d", &elm);
    top++;
    a[top] = elm;
    printf("%d pushed into the stack successfully...\n", elm);
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow...\n");
        return;
    }
    elm = a[top];
    top--;
    printf("%d popped from stack successfully...\n", elm);
}

void peek() {
    if (top == -1) {
        printf("Stack is empty...\n");
        return;
    }
    printf("Peek element is %d\n", a[top]);
}

void display() {
    if (top == -1) {
        printf("Stack is empty...\n");
        return;
    }
    printf("Stack list is...\n");
    for (i = top; i >= 0; i--) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void search() {
    int flag = 0;
    int pos;
    if (top == -1) {
        printf("Stack is empty...\n");
        return;
    }
    printf("Enter the element to search: ");
    scanf("%d", &elm);
    pos = 1;
    for (i = top; i >= 0; i--) {
        if (elm == a[i]) {
            printf("%d found at position %d\n", elm, pos);
            flag++;
        }
        pos++;
    }
    if (flag == 0) {
        printf("%d not found in the stack..\n", elm);
    }
}

void IsEmpty() {
    if (top == -1)
        printf("True\n");
    else
        printf("False\n");
}

void IsFull() {
    if (top == MAX - 1)
        printf("True\n");
    else
        printf("False\n");
}
