#include<stdio.h>

struct PLAYERS
{
    char name[30];
    int score_1, score_2, score_3;
};

void read(struct PLAYERS arr[], int num_players);
void display(struct PLAYERS arr[], int num_players);
void compute(struct PLAYERS arr[], int num_players);

int main()
{
        int n, num_players;
    
    printf("\nEnter number of players: ");
    scanf("%d",&num_players);

        struct PLAYERS arr[num_players];
    
    read(arr,num_players);
    display(arr,num_players);
    compute(arr,num_players);
return 0;
}

void read(struct PLAYERS arr[], int num_players)
{
        int i;
    printf("\nEnter details of %d players--\n",num_players);
    for ( i = 0; i < num_players; i++)
    {
        printf("Enter the name of PLAYER %d: ",i+1);
        scanf("%s",arr[i].name);
        printf("Enter score 1: ");
        scanf("%d",&arr[i].score_1);
        printf("Enter score 2: ");
        scanf("%d",arr[i].score_2);
        printf("Enter score 3: ");
        scanf("%d",&arr[i].score_3);
    }    
}

void display(struct PLAYERS arr[], int num_players)
{
        int i;
    printf("\nDetails of %d players--\n",num_players);
    for ( i = 0; i < num_players; i++)
    {
        printf("Name of PLAYER %d: %s\n",i+1,arr[i].name);
        printf("Score 1: %d\n",arr[i].score_1);
        printf("Score 2: %d\n",arr[i].score_2);
        printf("Score 3: %d\n",arr[i].score_3);
    }    
}

void compute(struct PLAYERS arr[], int num_players)
{
        int i, avg=0;
    printf("\nAveerage scores of each player--\n");
    for(i=0; i < num_players; i++)
    {
            avg = arr[i].score_1 + arr[i].score_2 + arr[i].score_3;
        printf("Player [%d] name: %s\n",i+1,arr[i].name);
        printf("Average score is: %d\n",avg);
    }
}