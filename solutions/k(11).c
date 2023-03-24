/* 11. */
/* To simulate stack/queue using dynamic memory allocation methods */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Stack Implementation

typedef struct Stack {
    int top;
    int* data;
} Stack;

Stack* create_stack() {
    Stack* new_stack = (Stack*) malloc(sizeof(Stack));
    new_stack->top = -1;
    new_stack->data = (int*) malloc(MAX_SIZE * sizeof(int));
    return new_stack;
}

void push(Stack* stack, int value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack->top++;
    stack->data[stack->top] = value;
}

int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow!\n");
        return -1;
    }
    int value = stack->data[stack->top];
    stack->top--;
    return value;
}

void display_stack(Stack* stack) {
    if (stack->top == -1) {
        printf("The stack is empty.\n");
    } else {
        printf("The stack is: ");
        for (int i = stack->top; i >= 0; i--) {
            printf("%d ", stack->data[i]);
        }
        printf("\n");
    }
}

// Queue Implementation

typedef struct Queue {
    int front;
    int rear;
    int* data;
} Queue;

Queue* create_queue() {
    Queue* new_queue = (Queue*) malloc(sizeof(Queue));
    new_queue->front = -1;
    new_queue->rear = -1;
    new_queue->data = (int*) malloc(MAX_SIZE * sizeof(int));
    return new_queue;
}

void enqueue(Queue* queue, int value) {
    if (queue->rear == MAX_SIZE - 1) {
        printf("Queue overflow!\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->data[queue->rear] = value;
}

int dequeue(Queue* queue) {
    if (queue->front == -1 || queue->front > queue->rear) {
        printf("Queue underflow!\n");
        return -1;
    }
    int value = queue->data[queue->front];
    queue->front++;
    return value;
}

void display_queue(Queue* queue) {
    if (queue->front == -1 || queue->front > queue->rear) {
        printf("The queue is empty.\n");
    } else {
        printf("The queue is: ");
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->data[i]);
        }
        printf("\n");
    }
}

// Driver Code
int main() 
{
    Stack* stack = create_stack();
    Queue* queue = create_queue();
    int choice = 0;
    int value = 0;

    while (1) {
        printf("1. Push/Enqueue element\n");
        printf("2. Pop/Dequeue element\n");
        printf("3. Display stack\n");
        printf("4. Display queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be pushed/enqueued: ");
                scanf("%d", &value);
                push(stack, value);
                enqueue(queue, value);
            break;
        case 2:
            printf("Popped element from stack: %d\n", pop(stack));
            printf("Dequeued element from queue: %d\n", dequeue(queue));
            break;
        case 3:
            display_stack(stack);
            break;
        case 4:
            display_queue(queue);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice!\n");
    }
}
return 0;
}