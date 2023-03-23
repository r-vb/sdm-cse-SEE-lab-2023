/* 3. */

/* Remember to create a text file named student as in: student.txt
    Else it won't work!! */

#include <stdio.h>
#include <wchar.h>

int main()
{
        char ch, name[10];
        int marks, i, n;
        FILE *fp;

    printf("Enter no. of students: ");
    scanf("%d",&n);

        i = 1;
    fp = fopen("student.txt","w");
        while ( i <= n )
        {
            printf("Enter respective name & marks of student %d: ",i);
            scanf("%s%d",name,&marks);

            fprintf(fp,"%s\t%d\n",name,marks);
        i++;
        }   
    fclose(fp);

    fp = fopen("student.txt","r");
        while ( (ch = fgetc(fp)) != EOF )
        {
            printf("%c",ch);
        }
    fclose(fp);
return 0;
}