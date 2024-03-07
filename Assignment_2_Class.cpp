/*Q2. Write a menu driven program for Date in a CPP language using structure and also using class.
Date is having data members day, month, year. Implement the following functions.
void initDate();
void printDateOnConsole();
void acceptDateFromConsole();
bool isLeapYear();
*/

#include <iostream>
using namespace std;
class Date
{
private:
    int day;
    int month;
    int year;

public:
    void initDate()
    {
        this->day = 1;
        this->month = 1;
        this->year = 2001;
    }

    void printDateOnConsole()
    {
        cout << "Date : " << day << "," << month << "," << year;
    }

    void acceptDateFromConsole()
    {
        cout << "Enter Date : ";
        cin >> day;
        cin >> month;
        cin >> year;
    }

    bool isLeapYear()
    {
        if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            return 1;
        }
        else 
        {
            return 0;
        }
    }

    int menu()
    {
        int choice;
        cout << "\n1. Print Date." << endl;
        cout << "\n2. Accept Date from user." << endl;
        cout << "\n3. Check you have entered year is leap year or not." << endl;
        cout << "Enter choice : ";
        cin >> choice;
        return choice;
    }
};

int main()
{
    Date d;
    int choice;
    bool leapYear;
    d.initDate();
    while ((choice = d.menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            d.printDateOnConsole();
            break;
        case 2:
            d.acceptDateFromConsole();
            break;
        case 3:
        {
            leapYear = d.isLeapYear();
            if(leapYear == 1)
            {
                cout<<"You have entered year is leap year.";
            }
            else
            {
                cout<<"You have entered year is not leap year";
            }
            break;
        }
        default:
            cout << "You have entered wrong choice!!" << endl;
            break;
        }
    }
    cout << "Thank You";
    return 0;
}