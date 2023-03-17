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
    printf("\nEnter details of %d bookss--\n",num_books);
    for ( i = 0; i < num_books; i++)
    {
        printf("TITLE of Book %d: ",i+1);
        scanf("%s",arr[i].title);
        printf("Enter EDITION: ");
        scanf("%d",&arr[i].edition);
        printf("Enter PRICE: ");
        scanf("%d",&arr[i].price);
    }    
}

void display(struct BOOK arr[], int num_books)
{
        int i;
    printf("\nDetails of %d books--\n",num_books);
    for ( i = 0; i < num_books; i++)
    {
        printf("Book Title %d: %s\n",i+1,arr[i].title);
        printf("Edition: %d\n",arr[i].edition);
        printf("Price: %d\n",arr[i].price);
    }    
}

void compute(struct BOOK arr[], int num_books)
{        int i=0, lar;
    lar = i;
    for (i = 1; i < num_books; i++){
            if (arr[lar].price <= arr[i].price){
                    lar = i;
            }            
    }
    printf("\n\nDetails of Book worth highest price is:\n");
        printf("Book %d details-\n",lar+1);
        printf("Title: ");      printf("%s\n",arr[lar].title);
        printf("Edition: ");    printf("%d\n",arr[lar].edition);
        printf("Price: ");      printf("%d\n",arr[lar].price);
}