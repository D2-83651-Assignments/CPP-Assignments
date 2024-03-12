#include <iostream>
using namespace std;
class Date
{
    int day;
    int month;
    int year;

public:
    Date()
    {
        day = 1;
        month = 1;
        year = 2001;
    }

    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void set_Day(int day)
    {
        this->day = day;
    }

    void set_Month(int month)
    {
        this->month = month;
    }

    void set_Year(int year)
    {
        this->year = year;
    }

    int get_Day()
    {
        return day;
    }

    int get_Month()
    {
        return month;
    }

    int get_Year()
    {
        return year;
    }

    void acceptDate()
    {
        cout << "\nEnter day : ";
        cin >> day;
        cout << "\nEnter month : ";
        cin >> month;
        cout << "\nEnter Year : ";
        cin >> year;
    }

    void display()
    {
        cout << "Date - " << day << "/" << month << "/" << year << endl;
    }

    bool is_Leap_Year()
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

class Employee
{
    int empId;
    string name;
    double salary;
    string department;
    Date joining;

public:
    Employee()
    {
        salary = 0.0;
        department = "";
    }

    Employee(double salary, string department, int day, int month, int year) : joining(day,month,year)
    {
        this->salary = salary;
        this->department = department;
    }

    void acceptEmployeeDetails()
    {
        cout<<"\n-----------------------------------";
        cout<<"\nEnter employee id : ";
        cin>>empId;
        cout << "\nEnter employee salary : ";
        cin>>salary;
        cout << "\nEnter employee department : ";
        cin.ignore();
        getline(cin,department);
        cout << "\nEnter Employee's Date of birth : ";
        joining.acceptDate();
        cout<<"\n-----------------------------------\n";
    }

    void display()
    {
        joining.display();
    }

    void setJoining(Date date)
    {
        this->joining=date;
    }

    Date getJoining()
    {
        return joining;
    }
};

class Person
{
    string name;
    string address;
    Date birth_Date;

public:
    Person(){}

    Person(string name, string address, int day, int month, int year) : birth_Date(day, month, year)
    {
        this->name = name;
        this->address = address;
    }

    void set_Name(string name)
    {
        this->name = name;
    }

    string get_Name()
    {
        return name;
    }

    void set_Address(string address)
    {
        this->address = address;
    }

    string get_Address()
    {
        return address;
    }

    void setBirth_Date(Date date)
    {
        this->birth_Date = date;
    }

    Date get_Birth_Date()
    {
        return birth_Date;
    }

    void acceptPersonDetails()
    {
        cout<<"\n-----------------------------------";
        cout << "\nEnter Person name : ";
        cin.ignore();
        getline(cin,name);
        cout << "\nEnter Person address : ";
        cin.ignore();
        getline(cin,address);
        cout << "\nEnter Person Date of birth : ";
        birth_Date.acceptDate();
        cout<<"\n-----------------------------------\n";
    }

    void display()
    {
        birth_Date.display();
    }
        
    void set_Birth_Date(int day, int month, int year)
    {
        birth_Date.set_Day(day);
        birth_Date.set_Month(month);
        birth_Date.set_Year(year);
    }    
};

int main()
{
    Employee e;
    e.acceptEmployeeDetails();
    e.display();

    Person p;
    p.acceptPersonDetails();
    p.display();


    return 0;
}