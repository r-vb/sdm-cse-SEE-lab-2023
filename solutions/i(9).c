/* 9. */
/* Write a C program to implement an input-restricted doubly ended queue. */

#include <stdio.h>

#define MAX_SIZE 100

int deque[MAX_SIZE];
int front = -1, rear = -1;

// Function to check if the deque is full
int isFull()
{
    return ((front == 0 && rear == MAX_SIZE - 1) || front == rear + 1);
}

// Function to check if the deque is empty
int isEmpty()
{
    return (front == -1);
}

// Function to insert an element at the rear end of the deque
void insertRear(int value)
{
    if (isFull())
    {
        printf("Deque is full.\n");
        return;
    }

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (rear == MAX_SIZE - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    deque[rear] = value;
}

// Function to delete an element from the front end of the deque
int deleteFront()
{
    int value;

    if (isEmpty())
    {
        printf("Deque is empty.\n");
        return -1;
    }

    value = deque[front];

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == MAX_SIZE - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }

    return value;
}

// Function to delete an element from the rear end of the deque
int deleteRear()
{
    int value;

    if (isEmpty())
    {
        printf("Deque is empty.\n");
        return -1;
    }

    value = deque[rear];

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
    {
        rear = MAX_SIZE - 1;
    }
    else
    {
        rear--;
    }

    return value;
}

// Function to display the contents of the deque
void display()
{
    int i;

    if (isEmpty())
    {
        printf("Deque is empty.\n");
        return;
    }

    printf("Contents of deque are:\n");
    i = front;

    while (1)
    {
        printf("%d ", deque[i]);

        if (i == rear)
        {
            break;
        }

        if (i == MAX_SIZE - 1)
        {
            i = 0;
        }
        else
        {
            i++;
        }
    }

    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("1. Insert at rear\n2. Delete from front\n3. Delete from rear\n4. Display\n5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                insertRear(value);
                break;

            case 2:
                value = deleteFront();
                if (value != -1)
                {
                    printf("Deleted value is: %d\n", value);
                }
                break;

            case 3:
                value = deleteRear();
                if (value != -1)
                {
                    printf("Deleted value is: %d\n", value);
                }
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    printf("\n");
    }
return 0;
}