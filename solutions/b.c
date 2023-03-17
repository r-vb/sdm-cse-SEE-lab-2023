#include <stdio.h>

struct BOOK{
    char title[30];
    int edition, price;
};

void read(struct BOOK arr[], int num_books);
void display(struct BOOK arr[], int num_books);
void compute(struct BOOK arr[], int num_books);

int main()
{
        int num_books;

    printf("\nEnter number of books: ");
    scanf("%d",&num_books);

        struct BOOK arr[num_books];

    read(arr,num_books);
    display(arr,num_books);
    compute(arr,num_books);
return 0;
}

void read(struct BOOK arr[], int num_books)
{
        int i;
    printf("\nEnter details %d books--\n",num_books);
    for ( i = 0; i < num_books; i++)
    {
        printf("Enter TITLE: ");
        scanf("%s",&arr->title);
    }
    
}

void display(struct BOOK arr[], int num_books)
{

}

void compute(struct BOOK arr[], int num_books)
{

}