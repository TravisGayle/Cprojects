//Travis Gayle
//cse 20211
//
#include <stdio.h>
#include <math.h>

int wins[] =
 { 6, 8, 6, 8, 5, 5, 6, 6, 8, 7, 4,
   6, 7, 7, 6, 7, 8, 6, 3, 9, 9, 10,
   8, 9, 10, 7, 9, 7, 5, 9, 10, 6, 6,
   3, 6, 7, 6, 6, 8, 7, 7, 8, 7, 9,
   8, 7, 8, 9, 9, 10, 4, 7, 7, 9, 9,
   8, 2, 7, 6, 5, 2, 5, 5, 2, 9, 7,
   9, 8, 7, 8, 10, 8, 8, 11, 10, 8, 9,
   11, 9, 7, 9, 5, 6, 7, 7, 5, 5, 8,
   12, 12, 9, 10, 10, 11, 6, 9, 8, 7, 9,
   5, 9, 5, 10, 5, 6, 9, 10, 3, 7, 6,
   8, 8, 12, 9 };

int losses[] =
 { 3, 1, 2, 0, 3, 4, 1, 0, 1, 0, 1,
   0, 0, 0, 2, 1, 1, 1, 1, 0, 0, 1,
   1, 1, 0, 2, 1, 1, 4, 0, 0, 2, 2,
   5, 3, 1, 2, 2, 1, 2, 2, 0, 2, 1,
   2, 2, 0, 0, 0, 0, 4, 2, 2, 0, 1,
   2, 8, 3, 4, 5, 8, 5, 5, 7, 1, 2,
   0, 2, 2, 2, 1, 2, 3, 0, 2, 3, 3,
   1, 3, 4, 2, 6, 4, 5, 5, 6, 6, 4,
   0, 1, 3, 3, 1, 1, 5, 3, 3, 6, 3,
   7, 3, 6, 3, 7, 6, 3, 3, 9, 6, 6,
   5, 5, 1, 4 };

void yearRecord(int year);
void winningRecord();
void losingRecord();
void undisputed();

int main()
{
        int choice;
        int year;

        printf("What would you like to do involving the ND football record from 1900 - present?\nEnter: \n1: Display record for a given year \n2: Display how many years the team had a losing record \n3: Display how many years the team had a winning record \n4: Display how many years the team had an undefeated season \nChoice: ");
        scanf("%i", &choice);

        while ((choice != 1) && (choice != 2) && (choice != 3) && (choice != 4))
        {
                printf("Please choose a valid number between 1, 2, 3, & 4: ");
                scanf("%i", &choice);
        }
        if (choice == 1)
        {
                printf("Please enter the year in which you would like to see Notre Dame football's overall record: ");
scanf("%i", &year);

                yearRecord(year);
        }
        else if(choice == 2)
        {
                losingRecord();
        }
        else if (choice == 3)
        {
                winningRecord();
        }
        else
        {
                undisputed();
        }

        return 0;
}
void yearRecord(int year)
{
        int season;

        season = year - 1900;
        printf("Notre Dame football had %i wins and %i losses in %i.", wins[season], losses[season], year);
        printf("\n");
}
void losingRecord()
{
        int i = 0;
        int season = 0;

        while (i <= 114)
        {
                if (losses[i] > wins[i])
                {
                        season++;

                }
                i++;
        }
        printf(" Notre Dame football had a total of %i losing seasons.", season);
        printf("\n");
}
void winningRecord()
{
        int i;
        int season = 0;

        for (i=0;i<=114;i++)
        {
                if(wins[i] > losses[i])
                        season++;
        }
        printf(" Notre Dame football had a total of %i winning seasons.", season);
        printf("\n");
}
void undisputed()
{
        int i;
        int season = 0;
        for (i=0;i<=114;i++)
        {
                if (losses[i] == 0)
                        season++;
        }
        printf("Notre Dame football had a total of %i seasons where they went undefeated.", season);
        printf("\n");
}


