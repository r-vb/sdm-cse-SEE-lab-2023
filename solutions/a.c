#include <stdio.h>
#include <stdlib.h>
#define SIZE 30

struct player
{
    int score_1, score_2, score_3;
    char name[SIZE];
};

void read();
void display();
void compute();

int main()
{
        int choice, num_players;
    printf("Enter number of players: ");
    scanf("%d",&num_players);
return 0;
}