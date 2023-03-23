/* 7. */
/* Circular Queue Implementation */
#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

struct queue
{
    int arr[SIZE], f, r;
    int count;
};

void insert(struct queue *cq, int ele)
{
    if (cq->count == SIZE)
        printf("Circular is Queue\n");
    else{
        cq->r = (cq->r+1)%SIZE;
        cq->arr[cq->r] = ele;
        cq->count++;
    }
}

int delete(struct queue *cq)
{
        int ele;
    if (cq->count == 0)
    {
        printf("Circular Queue is empty\n");
        return -1;
    }
    else{
        ele = cq->arr[cq->f];
        cq->f = (cq->f+1)%SIZE;
        cq->count--;
        return ele;
    }
}

void display(struct queue cq)
{
        int i, j;  
    if (cq.count == 0)
        printf("Circular Queue is empty\n");
    else{
        j = cq.f;
        for ( i = 0; i < cq.count; i++)
        {
            printf("%d\n",cq.arr[j]);
            j = (j+1)%SIZE;
        }
    }
}

int main()
{
        struct queue cq;
        cq.f = 0;
        cq.r = -1;
        cq.count = 0;
        int choice, ele;
    printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
    while (1)
    {
        printf("Enter choice of option: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to be inserted: ");
            scanf("%d",&ele);
            insert(&cq,ele);
            break;
        case 2:
            ele = delete(&cq);
            printf("Deleted element is %d\n");
            break;
        case 3:
            printf("Circular Queue elements are:--\n");
            display(cq);
            break;
        case 4: exit(0);
        default: printf("Invalid Input!!\n");
                exit(0);
        }
    }
return 0;
}