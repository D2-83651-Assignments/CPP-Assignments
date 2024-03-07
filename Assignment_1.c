// Q1. Write a menu driven program for Date in a C. Declare a structure Date having data members
// day, month, year. Implement the following functions.
// void initDate(struct Date* ptrDate);
// void printDateOnConsole(struct Date* ptrDate);
// void acceptDateFromConsole(struct Date* ptrDate);

#include <stdio.h>

struct Date
{
    int day;
    int month;
    int year;
};

void initDate(struct Date *ptrDate)
{
    ptrDate->day = 01;
    ptrDate->month = 01;
    ptrDate->year = 2001;
}

void printDateOnConsole(struct Date *ptrDate)
{
    printf("Date : ");
    printf("%d-%d-%d", ptrDate->day, ptrDate->month, ptrDate->year);
}

void acceptDateFromConsole(struct Date *ptrDate)
{
    printf("Enter Day, MOnth, Year : ");
    scanf("%d%d%d",&ptrDate->day, &ptrDate->month, &ptrDate->year);
}


int menu()
{
    int choice;
    printf("\n1. Default Date : \n");
    printf("2. Display Date : \n");
    printf("3. Enter Date : \n");
    printf("Enter choice : \n");
    scanf("%d",&choice);
    return choice;

}

int main()
{
    struct Date d1;
    int choice;

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            initDate(&d1);           
            break;
        case 2:
            printDateOnConsole(&d1);
            break;
        case 3:
            acceptDateFromConsole(&d1);
            break;
        default:
            printf("You have entered wrong choice!!");
            break;
        }
    }
    printf("Thank You!");
}
