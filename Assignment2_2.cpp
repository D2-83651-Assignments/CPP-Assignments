// Q2. Imagine a tollbooth at a bridge. Cars passing by the booth are expected to pay a fifty-cent toll.
// Mostly they do, but sometimes a car goes by without paying.
// The tollbooth keeps track of the number of cars that have gone by and of the total amount of money
// collected. Model this tollbooth with a class called tollbooth.
// The two data items are a type unsigned int to hold the total number of cars, and a type double to
// hold the total amount of money collected.
// A constructor initializes all data members to 0. A member function called payingCar() increments
// the car total and adds 0.50 to the cash total. An other function, called nopayCar()
// increments the car total but adds nothing to the cash total. Finally, a member function called
// printOnConsole() displays the two totals and number of paying as well as non paying cars total.

#include <iostream>
using namespace std;

class Toolbooth
{

private:
    unsigned int paidCars;
    unsigned int unPaidCars;
    double collectedAmount;
    int totalCars;

public:
    Toolbooth()
    {
        paidCars = 0;
        unPaidCars = 0;
        collectedAmount = 0;
        totalCars = 0;
    }

    void payingCar()
    {
        collectedAmount += 0.50;
        paidCars++;
        totalCars++;
    }

    void noPayCar()
    {
        totalCars++;
        unPaidCars++;
    }

    void displayInformationOfCars()
    {
        cout<<"\nPaid car(s) : "<<paidCars;
        cout<<"\nUnpaid car(s) : "<<unPaidCars;
        cout<<"\nTotal car(s) :"<<totalCars;
        cout<<"\nCollected amount : "<<collectedAmount;
    }

    int menu()
    {
        int choice;
        cout << "\n1. Paid cars";
        cout << "\n2. Unpaid cars";
        cout << "\n3. Display paid and unpaid car(s)";
        cout<<"\nEnter choice : ";
        cin >> choice;
        return choice;
    }
};

int main()
{
    int choice;
    Toolbooth t;
    while ((choice = t.menu()) != 0)
    {
        switch (choice)
        {
        case 1:
        {
            t.payingCar();
            break;
        }
        case 2:
        {
            t.noPayCar();
            break;
        }
        case 3:
        {
            t.displayInformationOfCars();
            break;
        }
        default:
            cout << "\nYou have entered wrong choice!!";
            break;
        }
    }

    return 0;
}