#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 5

int front = -1, rear = -1;
int elm, i;
int queue[MAX]; // Fixed typo: 'queen' -> 'queue'

void enqueue(int);
int dequeue();
void display();
void search();
int peek();
bool IsEmpty();
bool IsFull();

int main() {
    int ch;
    while (1) {
        printf("\n 1. Enqueue");
        printf("\n 2. Dequeue");
        printf("\n 3. Display");
        printf("\n 4. Search");
        printf("\n 5. Peek");
        printf("\n 6. IsEmpty");
        printf("\n 7. IsFull");
        printf("\n 8. Exit");
        printf("\n Enter your choice ");
        scanf("%d", &ch);

        switch(ch) { 
            case 1:
                if (rear == MAX - 1)
                    printf("Queue Overflow");
                else {
                    printf("Enter the value to insert ");
                    scanf("%d", &elm);
                    enqueue(elm);
                    printf("%d inserted into the queue successfully\n", elm);
                }
                break;

            case 2:
                elm = dequeue();
                if (elm == -1)
                    printf("Queue Underflow");
                else
                    printf("%d deleted from queue\n", elm);
                break;

            case 3:
                display();
                break;

            case 4:
                search();
                break;

            case 5:
                elm = peek();
                if (elm == -1)
                    printf("Queue is Empty");
                else
                    printf("Queue is Not Empty");
                break;

            case 6:
                if (IsEmpty())
                    printf("Queue is Empty");
                else
                    printf("Queue is not empty");
                break;

            case 7:
                if (IsFull())
                    printf("Queue is full");
                else
                    printf("Queue is not full");
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid choice");
        }
    }
}
void enqueue(int n) {
    if (front == -1 && rear == -1) {
        front++;
        rear++;
        queue[rear] = n; 
    }
    else {
        rear++;
        queue[rear] = n;
    }
}

int dequeue() {
    int n;
    if (front == -1 && rear == -1)
        return -1;
    else {
        n = queue[front];
        if (front == rear) { 
            front = -1;
            rear = -1;
        }
        else {
            front++;
        }
        return n;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("The updated list is \n");
    for (i = front; i <= rear; i++) { 
        printf("%d ", queue[i]);
    }
}

void search() {
    int flag = 0;
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Enter element to search: "); 
    scanf("%d", &elm);                   

    for (i = front; i <= rear; i++) {
        if (elm == queue[i]) {
            printf("%d found in the Queue", elm);
            flag++;
            break;
        }
    }
    if (flag == 0) {
        printf("%d not found in the Queue\n", elm);
    }
}

int peek() {
    if (front == -1 && rear == -1)
        return -1;
    else
        return queue[front];
}

bool IsEmpty() {
    if (front == -1 && rear == -1)
        return true;
    else
        return false;
}

bool IsFull() {
    if (rear == MAX - 1)
        return true;
    else
        return false;
}
